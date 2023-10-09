#include "Line_following2.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[3];
  int_T i;

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  Line_following2_SetEventsForThisBaseStep(eventFlags);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  Line_following2_step0();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  isRateRunning[0]--;
  for (i = 1; i < 3; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 3; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;

#ifndef _MW_ARDUINO_LOOP_

      interrupts();

#endif;

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 1 :
        Line_following2_step1();

        /* Get model outputs here */
        break;

       case 2 :
        Line_following2_step2();

        /* Get model outputs here */
        break;

       default :
        break;
      }

#ifndef _MW_ARDUINO_LOOP_

      noInterrupts();

#endif;

      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.01;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_usbattach();
  MW_Arduino_Init();
  rtmSetErrorStatus(Line_following2_M, 0);
  Line_following2_initialize();
  noInterrupts();
  configureArduinoARM_M0plusTimer();
  runModel = rtmGetErrorStatus(Line_following2_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(Line_following2_M) == (NULL));
    MW_Arduino_Loop();
  }

  /* Terminate model */
  Line_following2_terminate();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}
