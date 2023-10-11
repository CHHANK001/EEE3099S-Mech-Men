/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Jesse.c
 *
 * Code generated for Simulink model 'Jesse'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Oct  9 13:28:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Jesse.h"
#include "rtwtypes.h"
#include <math.h>
#include "Jesse_private.h"
#include "Jesse_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Jesse_IN_Default               ((uint8_T)1U)
#define Jesse_IN_Move                  ((uint8_T)2U)
#define Jesse_IN_Stop                  ((uint8_T)3U)

/* Block states (default storage) */
DW_Jesse_T Jesse_DW;

/* Real-time model */
static RT_MODEL_Jesse_T Jesse_M_;
RT_MODEL_Jesse_T *const Jesse_M = &Jesse_M_;
static void rate_scheduler(void);
uint32_T plook_u32d_binckan(real_T u, const real_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

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
  (Jesse_M->Timing.TaskCounters.TID[1])++;
  if ((Jesse_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Jesse_M->Timing.TaskCounters.TID[1] = 0;
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
void Jesse_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_vtow_idx_0;
  real_T rtb_vtow_idx_1;
  real_T u0;
  int32_T rtb_v;
  uint8_T tmp;
  boolean_T c_value;
  if (Jesse_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Left encoder' */
    if (Jesse_DW.obj.SampleTime != Jesse_P.Leftencoder_SampleTime) {
      Jesse_DW.obj.SampleTime = Jesse_P.Leftencoder_SampleTime;
    }

    c_value = readDigitalPin(2);

    /* Chart: '<Root>/Chart' incorporates:
     *  Constant: '<Root>/DriveDist'
     *  MATLABSystem: '<Root>/Left encoder'
     */
    if (Jesse_DW.is_active_c3_Jesse == 0U) {
      Jesse_DW.is_active_c3_Jesse = 1U;
      Jesse_DW.is_c3_Jesse = Jesse_IN_Default;
      rtb_v = -10;
      Jesse_DW.reqTicks = Jesse_P.DriveDist_Value / 0.0097389372261283587;
    } else {
      switch (Jesse_DW.is_c3_Jesse) {
       case Jesse_IN_Default:
        rtb_v = -10;
        if ((Jesse_DW.i < Jesse_DW.reqTicks) && (!c_value)) {
          Jesse_DW.is_c3_Jesse = Jesse_IN_Move;
          Jesse_DW.i++;
        } else if ((Jesse_DW.i == Jesse_DW.reqTicks) || (Jesse_DW.i >
                    Jesse_DW.reqTicks)) {
          Jesse_DW.is_c3_Jesse = Jesse_IN_Stop;
          rtb_v = 0;
        }
        break;

       case Jesse_IN_Move:
        Jesse_DW.is_c3_Jesse = Jesse_IN_Default;
        rtb_v = -10;
        Jesse_DW.reqTicks = Jesse_P.DriveDist_Value / 0.0097389372261283587;
        break;

       default:
        /* case IN_Stop: */
        rtb_v = 0;
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

    /* Gain: '<S2>/vtow' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<S2>/change parameters'
     *  SignalConversion generated from: '<S2>/change parameters'
     */
    u0 = 1.0 / Jesse_P.wheelR;
    rtb_vtow_idx_0 = (Jesse_P.changeparameters_Gain[0] * (real_T)rtb_v +
                      Jesse_P.changeparameters_Gain[2] * Jesse_P.Constant_Value)
      * u0;
    rtb_vtow_idx_1 = (Jesse_P.changeparameters_Gain[1] * (real_T)rtb_v +
                      Jesse_P.changeparameters_Gain[3] * Jesse_P.Constant_Value)
      * u0;

    /* MATLABSystem: '<Root>/Left PWM' */
    obj = &Jesse_DW.obj_b;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);

    /* Lookup_n-D: '<Root>/Left Motor LUT' incorporates:
     *  Abs: '<Root>/Abs1'
     */
    u0 = Jesse_P.InputPWM[plook_u32d_binckan(fabs(rtb_vtow_idx_0),
      Jesse_P.WheelSpeed, 172U)];

    /* MATLABSystem: '<Root>/Left PWM' */
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    MW_PWM_SetDutyCycle(Jesse_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, u0);

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Constant: '<Root>/Constant3'
     */
    if (rtb_vtow_idx_0 > Jesse_P.Switch_Threshold) {
      rtb_vtow_idx_0 = Jesse_P.Constant2_Value;
    } else {
      rtb_vtow_idx_0 = Jesse_P.Constant3_Value;
    }

    /* End of Switch: '<Root>/Switch' */

    /* MATLABSystem: '<Root>/Left motor back' */
    u0 = rt_roundd_snf(rtb_vtow_idx_0);
    if (u0 < 256.0) {
      if (u0 >= 0.0) {
        tmp = (uint8_T)u0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(5, tmp);

    /* End of MATLABSystem: '<Root>/Left motor back' */

    /* MATLABSystem: '<Root>/Left motor forward' incorporates:
     *  Logic: '<Root>/NOT'
     */
    writeDigitalPin(4, (uint8_T)!(rtb_vtow_idx_0 != 0.0));

    /* MATLABSystem: '<Root>/Right PWM' */
    obj = &Jesse_DW.obj_ac;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);

    /* Lookup_n-D: '<Root>/Left Motor LUT1' incorporates:
     *  Abs: '<Root>/Abs'
     */
    u0 = Jesse_P.InputPWM[plook_u32d_binckan(fabs(rtb_vtow_idx_1),
      Jesse_P.WheelSpeed, 172U)];

    /* MATLABSystem: '<Root>/Right PWM' */
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    MW_PWM_SetDutyCycle(Jesse_DW.obj_ac.PWMDriverObj.MW_PWM_HANDLE, u0);

    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant5'
     */
    if (rtb_vtow_idx_1 > Jesse_P.Switch1_Threshold) {
      rtb_vtow_idx_1 = Jesse_P.Constant4_Value;
    } else {
      rtb_vtow_idx_1 = Jesse_P.Constant5_Value;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* MATLABSystem: '<Root>/Right motor back' */
    u0 = rt_roundd_snf(rtb_vtow_idx_1);
    if (u0 < 256.0) {
      if (u0 >= 0.0) {
        tmp = (uint8_T)u0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(7, tmp);

    /* End of MATLABSystem: '<Root>/Right motor back' */

    /* MATLABSystem: '<Root>/Right motor forward' incorporates:
     *  Logic: '<Root>/NOT1'
     */
    writeDigitalPin(6, (uint8_T)!(rtb_vtow_idx_1 != 0.0));
  }

  rate_scheduler();
}

/* Model initialize function */
void Jesse_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Left encoder' */
    Jesse_DW.obj.matlabCodegenIsDeleted = false;
    Jesse_DW.obj.SampleTime = Jesse_P.Leftencoder_SampleTime;
    Jesse_DW.obj.isInitialized = 1;
    digitalIOSetup(2, 0);
    Jesse_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left PWM' */
    Jesse_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &Jesse_DW.obj_b;
    Jesse_DW.obj_b.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(16U, 0.0, 0.0);
    Jesse_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor back' */
    Jesse_DW.obj_a.matlabCodegenIsDeleted = false;
    Jesse_DW.obj_a.isInitialized = 1;
    digitalIOSetup(5, 1);
    Jesse_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor forward' */
    Jesse_DW.obj_m.matlabCodegenIsDeleted = false;
    Jesse_DW.obj_m.isInitialized = 1;
    digitalIOSetup(4, 1);
    Jesse_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right PWM' */
    Jesse_DW.obj_ac.matlabCodegenIsDeleted = false;
    obj = &Jesse_DW.obj_ac;
    Jesse_DW.obj_ac.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(17U, 0.0, 0.0);
    Jesse_DW.obj_ac.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor back' */
    Jesse_DW.obj_j.matlabCodegenIsDeleted = false;
    Jesse_DW.obj_j.isInitialized = 1;
    digitalIOSetup(7, 1);
    Jesse_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor forward' */
    Jesse_DW.obj_e.matlabCodegenIsDeleted = false;
    Jesse_DW.obj_e.isInitialized = 1;
    digitalIOSetup(6, 1);
    Jesse_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void Jesse_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Left encoder' */
  if (!Jesse_DW.obj.matlabCodegenIsDeleted) {
    Jesse_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left encoder' */

  /* Terminate for MATLABSystem: '<Root>/Left PWM' */
  obj = &Jesse_DW.obj_b;
  if (!Jesse_DW.obj_b.matlabCodegenIsDeleted) {
    Jesse_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Jesse_DW.obj_b.isInitialized == 1) && Jesse_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_SetDutyCycle(Jesse_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_Close(Jesse_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left PWM' */

  /* Terminate for MATLABSystem: '<Root>/Left motor back' */
  if (!Jesse_DW.obj_a.matlabCodegenIsDeleted) {
    Jesse_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor back' */

  /* Terminate for MATLABSystem: '<Root>/Left motor forward' */
  if (!Jesse_DW.obj_m.matlabCodegenIsDeleted) {
    Jesse_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor forward' */

  /* Terminate for MATLABSystem: '<Root>/Right PWM' */
  obj = &Jesse_DW.obj_ac;
  if (!Jesse_DW.obj_ac.matlabCodegenIsDeleted) {
    Jesse_DW.obj_ac.matlabCodegenIsDeleted = true;
    if ((Jesse_DW.obj_ac.isInitialized == 1) && Jesse_DW.obj_ac.isSetupComplete)
    {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_SetDutyCycle(Jesse_DW.obj_ac.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_Close(Jesse_DW.obj_ac.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right PWM' */

  /* Terminate for MATLABSystem: '<Root>/Right motor back' */
  if (!Jesse_DW.obj_j.matlabCodegenIsDeleted) {
    Jesse_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor back' */

  /* Terminate for MATLABSystem: '<Root>/Right motor forward' */
  if (!Jesse_DW.obj_e.matlabCodegenIsDeleted) {
    Jesse_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor forward' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
