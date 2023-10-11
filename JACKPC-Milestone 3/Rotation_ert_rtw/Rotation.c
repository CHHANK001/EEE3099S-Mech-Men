/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Rotation.c
 *
 * Code generated for Simulink model 'Rotation'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Oct  5 16:11:46 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Rotation.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rotation_private.h"
#include "Rotation_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Rotation_IN_Default            (1U)
#define Rotation_IN_End                (2U)
#define Rotation_IN_Turn               (3U)

/* Block signals (default storage) */
B_Rotation_T Rotation_B;

/* Block states (default storage) */
DW_Rotation_T Rotation_DW;

/* Real-time model */
static RT_MODEL_Rotation_T Rotation_M_;
RT_MODEL_Rotation_T *const Rotation_M = &Rotation_M_;
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
  (Rotation_M->Timing.TaskCounters.TID[1])++;
  if ((Rotation_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Rotation_M->Timing.TaskCounters.TID[1] = 0;
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
void Rotation_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_vtow_idx_0;
  real_T rtb_w;
  real_T y;
  uint8_T tmp;
  if (Rotation_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<Root>/DriveRot' */
    Rotation_B.DriveRot = Rotation_P.DriveRot_Value;

    /* MATLABSystem: '<Root>/Left encoder' */
    if (Rotation_DW.obj.SampleTime != Rotation_P.Leftencoder_SampleTime) {
      Rotation_DW.obj.SampleTime = Rotation_P.Leftencoder_SampleTime;
    }

    /* MATLABSystem: '<Root>/Left encoder' */
    Rotation_B.LeftEncoderTick = readDigitalPin(2);

    /* Chart: '<Root>/Chart' */
    if (Rotation_DW.is_active_c3_Rotation == 0U) {
      Rotation_DW.is_active_c3_Rotation = 1U;
      Rotation_DW.is_c3_Rotation = Rotation_IN_Default;
      rtb_w = 1.5;
      Rotation_DW.degrees1tick = 0.14371385763665342;
      Rotation_DW.reqTicks = Rotation_B.DriveRot / Rotation_DW.degrees1tick;
    } else {
      switch (Rotation_DW.is_c3_Rotation) {
       case Rotation_IN_Default:
        rtb_w = 1.5;
        if ((Rotation_DW.i < Rotation_DW.reqTicks) &&
            (!Rotation_B.LeftEncoderTick)) {
          Rotation_DW.is_c3_Rotation = Rotation_IN_Turn;
          Rotation_DW.i++;
          Rotation_B.x = Rotation_DW.i;
          Rotation_B.tks = Rotation_DW.degrees1tick;
        } else if ((Rotation_DW.i == Rotation_DW.reqTicks) || (Rotation_DW.i >
                    Rotation_DW.reqTicks)) {
          Rotation_DW.is_c3_Rotation = Rotation_IN_End;
          rtb_w = 0.0;
        }
        break;

       case Rotation_IN_End:
        rtb_w = 0.0;
        break;

       default:
        /* case IN_Turn: */
        Rotation_DW.is_c3_Rotation = Rotation_IN_Default;
        rtb_w = 1.5;
        Rotation_DW.degrees1tick = 0.14371385763665342;
        Rotation_DW.reqTicks = Rotation_B.DriveRot / Rotation_DW.degrees1tick;
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

    /* Gain: '<S2>/vtow' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<S2>/change parameters'
     *  SignalConversion generated from: '<S2>/change parameters'
     */
    y = 1.0 / Rotation_P.wheelR;
    rtb_vtow_idx_0 = (Rotation_P.changeparameters_Gain[0] *
                      Rotation_P.Constant_Value +
                      Rotation_P.changeparameters_Gain[2] * rtb_w) * y;
    rtb_w = (Rotation_P.changeparameters_Gain[1] * Rotation_P.Constant_Value +
             Rotation_P.changeparameters_Gain[3] * rtb_w) * y;

    /* Lookup_n-D: '<Root>/Left Motor LUT' incorporates:
     *  Abs: '<Root>/Abs1'
     */
    Rotation_B.LeftPWM = Rotation_P.InputPWM[plook_u32d_binckan(fabs
      (rtb_vtow_idx_0), Rotation_P.WheelSpeed, 172U)];

    /* MATLABSystem: '<Root>/Left PWM' */
    obj = &Rotation_DW.obj_if;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
    if (Rotation_B.LeftPWM <= 255.0) {
      y = Rotation_B.LeftPWM;
    } else {
      y = 255.0;
    }

    if (!(y >= 0.0)) {
      y = 0.0;
    }

    MW_PWM_SetDutyCycle(Rotation_DW.obj_if.PWMDriverObj.MW_PWM_HANDLE, y);

    /* End of MATLABSystem: '<Root>/Left PWM' */
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Constant: '<Root>/Constant3'
     */
    if (rtb_vtow_idx_0 > Rotation_P.Switch_Threshold) {
      rtb_vtow_idx_0 = Rotation_P.Constant2_Value;
    } else {
      rtb_vtow_idx_0 = Rotation_P.Constant3_Value;
    }

    /* End of Switch: '<Root>/Switch' */

    /* MATLABSystem: '<Root>/Left motor back' */
    y = rt_roundd_snf(rtb_vtow_idx_0);
    if (y < 256.0) {
      if (y >= 0.0) {
        tmp = (uint8_T)y;
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
    obj = &Rotation_DW.obj_i;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);

    /* Lookup_n-D: '<Root>/Left Motor LUT1' incorporates:
     *  Abs: '<Root>/Abs'
     */
    y = Rotation_P.InputPWM[plook_u32d_binckan(fabs(rtb_w),
      Rotation_P.WheelSpeed, 172U)];

    /* MATLABSystem: '<Root>/Right PWM' */
    if (!(y <= 255.0)) {
      y = 255.0;
    }

    if (!(y >= 0.0)) {
      y = 0.0;
    }

    MW_PWM_SetDutyCycle(Rotation_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, y);

    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant5'
     */
    if (rtb_w > Rotation_P.Switch1_Threshold) {
      rtb_w = Rotation_P.Constant4_Value;
    } else {
      rtb_w = Rotation_P.Constant5_Value;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* MATLABSystem: '<Root>/Right motor back' */
    y = rt_roundd_snf(rtb_w);
    if (y < 256.0) {
      if (y >= 0.0) {
        tmp = (uint8_T)y;
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
    writeDigitalPin(6, (uint8_T)!(rtb_w != 0.0));
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Rotation_M->Timing.taskTime0;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (Rotation_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Rotation_M->Timing.clockTick1) * 0.1);

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
  Rotation_M->Timing.taskTime0 =
    ((time_T)(++Rotation_M->Timing.clockTick0)) * Rotation_M->Timing.stepSize0;
  if (Rotation_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Rotation_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void Rotation_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Rotation_M, 60.0);
  Rotation_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Rotation_M->Sizes.checksums[0] = (3100338549U);
  Rotation_M->Sizes.checksums[1] = (2312878943U);
  Rotation_M->Sizes.checksums[2] = (275965566U);
  Rotation_M->Sizes.checksums[3] = (369104294U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    Rotation_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Rotation_M->extModeInfo,
      &Rotation_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Rotation_M->extModeInfo, Rotation_M->Sizes.checksums);
    rteiSetTPtr(Rotation_M->extModeInfo, rtmGetTPtr(Rotation_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for Constant: '<Root>/DriveRot' */
    Rotation_B.DriveRot = Rotation_P.DriveRot_Value;

    /* Start for MATLABSystem: '<Root>/Left encoder' */
    Rotation_DW.obj.matlabCodegenIsDeleted = false;
    Rotation_DW.obj.SampleTime = Rotation_P.Leftencoder_SampleTime;
    Rotation_DW.obj.isInitialized = 1;
    digitalIOSetup(2, 0);
    Rotation_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left PWM' */
    Rotation_DW.obj_if.matlabCodegenIsDeleted = false;
    obj = &Rotation_DW.obj_if;
    Rotation_DW.obj_if.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(16U, 0.0, 0.0);
    Rotation_DW.obj_if.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor back' */
    Rotation_DW.obj_e.matlabCodegenIsDeleted = false;
    Rotation_DW.obj_e.isInitialized = 1;
    digitalIOSetup(5, 1);
    Rotation_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor forward' */
    Rotation_DW.obj_p.matlabCodegenIsDeleted = false;
    Rotation_DW.obj_p.isInitialized = 1;
    digitalIOSetup(4, 1);
    Rotation_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right PWM' */
    Rotation_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &Rotation_DW.obj_i;
    Rotation_DW.obj_i.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(17U, 0.0, 0.0);
    Rotation_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor back' */
    Rotation_DW.obj_d.matlabCodegenIsDeleted = false;
    Rotation_DW.obj_d.isInitialized = 1;
    digitalIOSetup(7, 1);
    Rotation_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor forward' */
    Rotation_DW.obj_b.matlabCodegenIsDeleted = false;
    Rotation_DW.obj_b.isInitialized = 1;
    digitalIOSetup(6, 1);
    Rotation_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Rotation_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Left encoder' */
  if (!Rotation_DW.obj.matlabCodegenIsDeleted) {
    Rotation_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left encoder' */

  /* Terminate for MATLABSystem: '<Root>/Left PWM' */
  obj = &Rotation_DW.obj_if;
  if (!Rotation_DW.obj_if.matlabCodegenIsDeleted) {
    Rotation_DW.obj_if.matlabCodegenIsDeleted = true;
    if ((Rotation_DW.obj_if.isInitialized == 1) &&
        Rotation_DW.obj_if.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_SetDutyCycle(Rotation_DW.obj_if.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_Close(Rotation_DW.obj_if.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left PWM' */
  /* Terminate for MATLABSystem: '<Root>/Left motor back' */
  if (!Rotation_DW.obj_e.matlabCodegenIsDeleted) {
    Rotation_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor back' */

  /* Terminate for MATLABSystem: '<Root>/Left motor forward' */
  if (!Rotation_DW.obj_p.matlabCodegenIsDeleted) {
    Rotation_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor forward' */

  /* Terminate for MATLABSystem: '<Root>/Right PWM' */
  obj = &Rotation_DW.obj_i;
  if (!Rotation_DW.obj_i.matlabCodegenIsDeleted) {
    Rotation_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Rotation_DW.obj_i.isInitialized == 1) &&
        Rotation_DW.obj_i.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_SetDutyCycle(Rotation_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_Close(Rotation_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right PWM' */

  /* Terminate for MATLABSystem: '<Root>/Right motor back' */
  if (!Rotation_DW.obj_d.matlabCodegenIsDeleted) {
    Rotation_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor back' */

  /* Terminate for MATLABSystem: '<Root>/Right motor forward' */
  if (!Rotation_DW.obj_b.matlabCodegenIsDeleted) {
    Rotation_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor forward' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
