/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: one_meter_version2.c
 *
 * Code generated for Simulink model 'one_meter_version2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Oct  4 16:12:26 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "one_meter_version2.h"
#include "rtwtypes.h"
#include <math.h>
#include "one_meter_version2_private.h"
#include "one_meter_version2_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define one_meter_version2_IN_Default  (1U)
#define one_meter_version2_IN_Move     (2U)
#define one_meter_version2_IN_Stop     (3U)

/* Named constants for Chart: '<Root>/Chart3' */
#define one_meter_version2_IN_back     (2U)
#define one_meter_version2_IN_forward  (3U)

/* Block signals (default storage) */
B_one_meter_version2_T one_meter_version2_B;

/* Block states (default storage) */
DW_one_meter_version2_T one_meter_version2_DW;

/* Real-time model */
static RT_MODEL_one_meter_version2_T one_meter_version2_M_;
RT_MODEL_one_meter_version2_T *const one_meter_version2_M =
  &one_meter_version2_M_;
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
  (one_meter_version2_M->Timing.TaskCounters.TID[1])++;
  if ((one_meter_version2_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    one_meter_version2_M->Timing.TaskCounters.TID[1] = 0;
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
void one_meter_version2_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  uint8_T tmp;
  if (one_meter_version2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S3>/vtow' */
    u0 = 1.0 / one_meter_version2_P.wheelR;

    /* Gain: '<S3>/vtow' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Gain: '<S3>/change parameters'
     */
    one_meter_version2_B.vtow[0] = (one_meter_version2_P.changeparameters_Gain[0]
      * one_meter_version2_P.Constant1_Value +
      one_meter_version2_P.changeparameters_Gain[2] *
      one_meter_version2_P.Constant_Value) * u0;
    one_meter_version2_B.vtow[1] = (one_meter_version2_P.changeparameters_Gain[1]
      * one_meter_version2_P.Constant1_Value +
      one_meter_version2_P.changeparameters_Gain[3] *
      one_meter_version2_P.Constant_Value) * u0;

    /* MATLABSystem: '<Root>/Left PWM' */
    obj = &one_meter_version2_DW.obj_b;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);

    /* Lookup_n-D: '<Root>/Left Motor LUT' */
    u0 = one_meter_version2_P.InputPWM[plook_u32d_binckan
      (one_meter_version2_B.vtow[0], one_meter_version2_P.WheelSpeed, 172U)];

    /* MATLABSystem: '<Root>/Left PWM' */
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    MW_PWM_SetDutyCycle(one_meter_version2_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        u0);

    /* MATLABSystem: '<Root>/Right PWM' */
    obj = &one_meter_version2_DW.obj_ac;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);

    /* Lookup_n-D: '<Root>/Left Motor LUT1' incorporates:
     *  Abs: '<Root>/Abs'
     */
    u0 = one_meter_version2_P.InputPWM[plook_u32d_binckan(fabs
      (one_meter_version2_B.vtow[1]), one_meter_version2_P.WheelSpeed, 172U)];

    /* MATLABSystem: '<Root>/Right PWM' */
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    MW_PWM_SetDutyCycle(one_meter_version2_DW.obj_ac.PWMDriverObj.MW_PWM_HANDLE,
                        u0);

    /* Chart: '<Root>/Chart3' */
    if (one_meter_version2_DW.is_active_c4_one_meter_version2 == 0U) {
      one_meter_version2_DW.is_active_c4_one_meter_version2 = 1U;
      one_meter_version2_DW.is_c4_one_meter_version2 =
        one_meter_version2_IN_Default;
    } else {
      switch (one_meter_version2_DW.is_c4_one_meter_version2) {
       case one_meter_version2_IN_Default:
        if (one_meter_version2_B.vtow[1] > 0.0) {
          one_meter_version2_DW.is_c4_one_meter_version2 =
            one_meter_version2_IN_forward;
          one_meter_version2_B.wr_f = 1.0;
          one_meter_version2_B.wr_b = 0.0;
        } else if (one_meter_version2_B.vtow[1] < 0.0) {
          one_meter_version2_DW.is_c4_one_meter_version2 =
            one_meter_version2_IN_back;
          one_meter_version2_B.wr_b = 1.0;
          one_meter_version2_B.wr_f = 0.0;
        }
        break;

       case one_meter_version2_IN_back:
        one_meter_version2_B.wr_b = 1.0;
        one_meter_version2_B.wr_f = 0.0;
        one_meter_version2_DW.is_c4_one_meter_version2 =
          one_meter_version2_IN_Default;
        break;

       default:
        /* case IN_forward: */
        one_meter_version2_B.wr_f = 1.0;
        one_meter_version2_B.wr_b = 0.0;
        one_meter_version2_DW.is_c4_one_meter_version2 =
          one_meter_version2_IN_Default;
        break;
      }
    }

    /* End of Chart: '<Root>/Chart3' */

    /* MATLABSystem: '<Root>/Right motor back' */
    u0 = rt_roundd_snf(one_meter_version2_B.wr_b);
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

    /* MATLABSystem: '<Root>/Right motor forward' */
    u0 = rt_roundd_snf(one_meter_version2_B.wr_f);
    if (u0 < 256.0) {
      if (u0 >= 0.0) {
        tmp = (uint8_T)u0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(6, tmp);

    /* End of MATLABSystem: '<Root>/Right motor forward' */

    /* MATLABSystem: '<Root>/Left encoder' */
    if (one_meter_version2_DW.obj.SampleTime !=
        one_meter_version2_P.Leftencoder_SampleTime) {
      one_meter_version2_DW.obj.SampleTime =
        one_meter_version2_P.Leftencoder_SampleTime;
    }

    /* MATLABSystem: '<Root>/Left encoder' */
    one_meter_version2_B.ticks = readDigitalPin(2);

    /* Constant: '<Root>/DriveDist' */
    one_meter_version2_B.DriveDist = one_meter_version2_P.DriveDist_Value;

    /* Chart: '<Root>/Chart' */
    if (one_meter_version2_DW.is_active_c3_one_meter_version2 == 0U) {
      one_meter_version2_DW.is_active_c3_one_meter_version2 = 1U;
      one_meter_version2_DW.is_c3_one_meter_version2 =
        one_meter_version2_IN_Default;
      one_meter_version2_DW.reqTicks = one_meter_version2_B.DriveDist /
        0.0097389372261283587;
    } else {
      switch (one_meter_version2_DW.is_c3_one_meter_version2) {
       case one_meter_version2_IN_Default:
        if ((one_meter_version2_DW.i < one_meter_version2_DW.reqTicks) &&
            (!one_meter_version2_B.ticks)) {
          one_meter_version2_DW.is_c3_one_meter_version2 =
            one_meter_version2_IN_Move;
          one_meter_version2_DW.i++;
          one_meter_version2_B.x = one_meter_version2_DW.i;
        } else if ((one_meter_version2_DW.i == one_meter_version2_DW.reqTicks) ||
                   (one_meter_version2_DW.i > one_meter_version2_DW.reqTicks)) {
          one_meter_version2_DW.is_c3_one_meter_version2 =
            one_meter_version2_IN_Stop;
        }
        break;

       case one_meter_version2_IN_Move:
        one_meter_version2_DW.is_c3_one_meter_version2 =
          one_meter_version2_IN_Default;
        one_meter_version2_DW.reqTicks = one_meter_version2_B.DriveDist /
          0.0097389372261283587;
        break;

       default:
        /* case IN_Stop: */
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */
    /* MATLABSystem: '<Root>/Left motor back' */
    writeDigitalPin(5, 0);

    /* MATLABSystem: '<Root>/Left motor forward' */
    writeDigitalPin(4, 0);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      one_meter_version2_M->Timing.taskTime0;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (one_meter_version2_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((one_meter_version2_M->Timing.clockTick1) * 0.1);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  one_meter_version2_M->Timing.taskTime0 =
    ((time_T)(++one_meter_version2_M->Timing.clockTick0)) *
    one_meter_version2_M->Timing.stepSize0;
  if (one_meter_version2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    one_meter_version2_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void one_meter_version2_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(one_meter_version2_M, 60.0);
  one_meter_version2_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  one_meter_version2_M->Sizes.checksums[0] = (2003080269U);
  one_meter_version2_M->Sizes.checksums[1] = (691025440U);
  one_meter_version2_M->Sizes.checksums[2] = (2310963621U);
  one_meter_version2_M->Sizes.checksums[3] = (3708122067U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    one_meter_version2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(one_meter_version2_M->extModeInfo,
      &one_meter_version2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(one_meter_version2_M->extModeInfo,
                        one_meter_version2_M->Sizes.checksums);
    rteiSetTPtr(one_meter_version2_M->extModeInfo, rtmGetTPtr
                (one_meter_version2_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for Constant: '<Root>/DriveDist' */
    one_meter_version2_B.DriveDist = one_meter_version2_P.DriveDist_Value;

    /* Start for MATLABSystem: '<Root>/Left PWM' */
    one_meter_version2_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &one_meter_version2_DW.obj_b;
    one_meter_version2_DW.obj_b.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(16U, 0.0, 0.0);
    one_meter_version2_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right PWM' */
    one_meter_version2_DW.obj_ac.matlabCodegenIsDeleted = false;
    obj = &one_meter_version2_DW.obj_ac;
    one_meter_version2_DW.obj_ac.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(17U, 0.0, 0.0);
    one_meter_version2_DW.obj_ac.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor back' */
    one_meter_version2_DW.obj_j.matlabCodegenIsDeleted = false;
    one_meter_version2_DW.obj_j.isInitialized = 1;
    digitalIOSetup(7, 1);
    one_meter_version2_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor forward' */
    one_meter_version2_DW.obj_e.matlabCodegenIsDeleted = false;
    one_meter_version2_DW.obj_e.isInitialized = 1;
    digitalIOSetup(6, 1);
    one_meter_version2_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left encoder' */
    one_meter_version2_DW.obj.matlabCodegenIsDeleted = false;
    one_meter_version2_DW.obj.SampleTime =
      one_meter_version2_P.Leftencoder_SampleTime;
    one_meter_version2_DW.obj.isInitialized = 1;
    digitalIOSetup(2, 0);
    one_meter_version2_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor back' */
    one_meter_version2_DW.obj_a.matlabCodegenIsDeleted = false;
    one_meter_version2_DW.obj_a.isInitialized = 1;
    digitalIOSetup(5, 1);
    one_meter_version2_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor forward' */
    one_meter_version2_DW.obj_m.matlabCodegenIsDeleted = false;
    one_meter_version2_DW.obj_m.isInitialized = 1;
    digitalIOSetup(4, 1);
    one_meter_version2_DW.obj_m.isSetupComplete = true;
  }
}

/* Model terminate function */
void one_meter_version2_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Left PWM' */
  obj = &one_meter_version2_DW.obj_b;
  if (!one_meter_version2_DW.obj_b.matlabCodegenIsDeleted) {
    one_meter_version2_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((one_meter_version2_DW.obj_b.isInitialized == 1) &&
        one_meter_version2_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_SetDutyCycle(one_meter_version2_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_Close(one_meter_version2_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left PWM' */

  /* Terminate for MATLABSystem: '<Root>/Right PWM' */
  obj = &one_meter_version2_DW.obj_ac;
  if (!one_meter_version2_DW.obj_ac.matlabCodegenIsDeleted) {
    one_meter_version2_DW.obj_ac.matlabCodegenIsDeleted = true;
    if ((one_meter_version2_DW.obj_ac.isInitialized == 1) &&
        one_meter_version2_DW.obj_ac.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_SetDutyCycle
        (one_meter_version2_DW.obj_ac.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_Close(one_meter_version2_DW.obj_ac.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right PWM' */

  /* Terminate for MATLABSystem: '<Root>/Right motor back' */
  if (!one_meter_version2_DW.obj_j.matlabCodegenIsDeleted) {
    one_meter_version2_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor back' */

  /* Terminate for MATLABSystem: '<Root>/Right motor forward' */
  if (!one_meter_version2_DW.obj_e.matlabCodegenIsDeleted) {
    one_meter_version2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor forward' */

  /* Terminate for MATLABSystem: '<Root>/Left encoder' */
  if (!one_meter_version2_DW.obj.matlabCodegenIsDeleted) {
    one_meter_version2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left encoder' */
  /* Terminate for MATLABSystem: '<Root>/Left motor back' */
  if (!one_meter_version2_DW.obj_a.matlabCodegenIsDeleted) {
    one_meter_version2_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor back' */

  /* Terminate for MATLABSystem: '<Root>/Left motor forward' */
  if (!one_meter_version2_DW.obj_m.matlabCodegenIsDeleted) {
    one_meter_version2_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor forward' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
