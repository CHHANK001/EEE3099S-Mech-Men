/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: one_meter.c
 *
 * Code generated for Simulink model 'one_meter'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Oct  4 13:15:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "one_meter.h"
#include "rtwtypes.h"
#include "one_meter_private.h"
#include <math.h>

/* Named constants for Chart: '<Root>/Chart' */
#define one_meter_IN_Default           ((uint8_T)1U)
#define one_meter_IN_Move              ((uint8_T)2U)
#define one_meter_IN_Stop              ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Chart1' */
#define one_meter_IN_Accumulate        ((uint8_T)1U)
#define one_meter_IN_Default_m         ((uint8_T)2U)

/* Block signals (default storage) */
B_one_meter_T one_meter_B;

/* Block states (default storage) */
DW_one_meter_T one_meter_DW;

/* Real-time model */
static RT_MODEL_one_meter_T one_meter_M_;
RT_MODEL_one_meter_T *const one_meter_M = &one_meter_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (one_meter_M->Timing.TaskCounters.TID[1])++;
  if ((one_meter_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    one_meter_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void one_meter_step(void)
{
  real_T tmp;
  real_T tmp_0;
  uint8_T tmp_1;
  boolean_T c_value;
  if (one_meter_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Left encoder' */
    if (one_meter_DW.obj.SampleTime != one_meter_P.Leftencoder_SampleTime) {
      one_meter_DW.obj.SampleTime = one_meter_P.Leftencoder_SampleTime;
    }

    c_value = readDigitalPin(2);

    /* Chart: '<Root>/Chart1' incorporates:
     *  MATLABSystem: '<Root>/Left encoder'
     */
    if (one_meter_DW.is_active_c1_one_meter == 0U) {
      one_meter_DW.is_active_c1_one_meter = 1U;
      one_meter_DW.is_c1_one_meter = one_meter_IN_Default_m;
    } else if (one_meter_DW.is_c1_one_meter == one_meter_IN_Accumulate) {
      one_meter_DW.is_c1_one_meter = one_meter_IN_Default_m;

      /* case IN_Default: */
    } else if (c_value) {
      one_meter_DW.is_c1_one_meter = one_meter_IN_Accumulate;
      one_meter_B.ticks++;
    }

    /* End of Chart: '<Root>/Chart1' */

    /* Chart: '<Root>/Chart' incorporates:
     *  Constant: '<Root>/DriveDist'
     */
    if (one_meter_DW.is_active_c3_one_meter == 0U) {
      one_meter_DW.is_active_c3_one_meter = 1U;
      one_meter_DW.is_c3_one_meter = one_meter_IN_Default;
      one_meter_DW.reqTicks = one_meter_P.DriveDist_Value /
        0.0097389372261283587;
    } else {
      switch (one_meter_DW.is_c3_one_meter) {
       case one_meter_IN_Default:
        if (one_meter_B.ticks < one_meter_DW.reqTicks) {
          one_meter_DW.is_c3_one_meter = one_meter_IN_Move;
          one_meter_B.v = 0.5;
        } else if ((one_meter_B.ticks == one_meter_DW.reqTicks) ||
                   (one_meter_B.ticks > one_meter_DW.reqTicks)) {
          one_meter_DW.is_c3_one_meter = one_meter_IN_Stop;
          one_meter_B.v = 0.0;
        }
        break;

       case one_meter_IN_Move:
        one_meter_B.v = 0.5;
        one_meter_DW.is_c3_one_meter = one_meter_IN_Default;
        one_meter_DW.reqTicks = one_meter_P.DriveDist_Value /
          0.0097389372261283587;
        break;

       default:
        /* case IN_Stop: */
        one_meter_B.v = 0.0;
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

    /* Gain: '<S3>/vtow' */
    tmp = 1.0 / one_meter_P.Towlwr_wheelR;

    /* MATLABSystem: '<Root>/Left motor' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<S3>/change parameters'
     *  Gain: '<S3>/vtow'
     *  SignalConversion generated from: '<S3>/change parameters'
     */
    tmp_0 = rt_roundd_snf((one_meter_P.changeparameters_Gain[0] * one_meter_B.v
      + one_meter_P.changeparameters_Gain[2] * one_meter_P.Constant_Value) * tmp);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        tmp_1 = (uint8_T)tmp_0;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(4, tmp_1);

    /* End of MATLABSystem: '<Root>/Left motor' */

    /* MATLABSystem: '<Root>/Right motor' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<S3>/change parameters'
     *  Gain: '<S3>/vtow'
     *  SignalConversion generated from: '<S3>/change parameters'
     */
    tmp = rt_roundd_snf((one_meter_P.changeparameters_Gain[1] * one_meter_B.v +
                         one_meter_P.changeparameters_Gain[3] *
                         one_meter_P.Constant_Value) * tmp);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_1 = (uint8_T)tmp;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(6, tmp_1);

    /* End of MATLABSystem: '<Root>/Right motor' */
  }

  rate_scheduler();
}

/* Model initialize function */
void one_meter_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Left encoder' */
  one_meter_DW.obj.matlabCodegenIsDeleted = false;
  one_meter_DW.obj.SampleTime = one_meter_P.Leftencoder_SampleTime;
  one_meter_DW.obj.isInitialized = 1;
  digitalIOSetup(2, 0);
  one_meter_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Left motor' */
  one_meter_DW.obj_m.matlabCodegenIsDeleted = false;
  one_meter_DW.obj_m.isInitialized = 1;
  digitalIOSetup(4, 1);
  one_meter_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Right motor' */
  one_meter_DW.obj_e.matlabCodegenIsDeleted = false;
  one_meter_DW.obj_e.isInitialized = 1;
  digitalIOSetup(6, 1);
  one_meter_DW.obj_e.isSetupComplete = true;
}

/* Model terminate function */
void one_meter_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Left encoder' */
  if (!one_meter_DW.obj.matlabCodegenIsDeleted) {
    one_meter_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left encoder' */

  /* Terminate for MATLABSystem: '<Root>/Left motor' */
  if (!one_meter_DW.obj_m.matlabCodegenIsDeleted) {
    one_meter_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor' */

  /* Terminate for MATLABSystem: '<Root>/Right motor' */
  if (!one_meter_DW.obj_e.matlabCodegenIsDeleted) {
    one_meter_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
