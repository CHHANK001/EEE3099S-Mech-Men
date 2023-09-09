#include "Simulation3Draft.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[3];

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
  Simulation3Draft_SetEventsForThisBaseStep(eventFlags);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  Simulation3Draft_step0();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  isRateRunning[0]--;
  if (eventFlags[2]) {
    if (need2runFlags[2]++) {
      IsrOverrun = 1;
      need2runFlags[2]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[2]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[2]++;

#ifndef _MW_ARDUINO_LOOP_

    interrupts();

#endif;

    /* Step the model for subrate "2" */
    switch (2)
    {
     case 2 :
      Simulation3Draft_step2();

      /* Get model outputs here */
      break;

     default :
      break;
    }

#ifndef _MW_ARDUINO_LOOP_

    noInterrupts();

#endif;

    need2runFlags[2]--;
    isRateRunning[2]--;
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
  rtmSetErrorStatus(Simulation3Draft_M, 0);
  Simulation3Draft_initialize();
  noInterrupts();
  configureArduinoARM_M0plusTimer();
  runModel = (rtmGetErrorStatus(Simulation3Draft_M) == (NULL)) &&
    !rtmGetStopRequested(Simulation3Draft_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    stopRequested = !((rtmGetErrorStatus(Simulation3Draft_M) == (NULL)) &&
                      !rtmGetStopRequested(Simulation3Draft_M));
    MW_Arduino_Loop();
  }

  /* Terminate model */
  Simulation3Draft_terminate();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}
