/*
 * Drive.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Drive".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Sep  9 15:16:45 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Drive.h"
#include "rtwtypes.h"
#include <math.h>
#include "Drive_private.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_Drive_T Drive_DW;

/* Real-time model */
static RT_MODEL_Drive_T Drive_M_;
RT_MODEL_Drive_T *const Drive_M = &Drive_M_;
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

/* Model step function */
void Drive_step(void)
{
  /* local block i/o variables */
  real_T rtb_Internal;
  real_T rtb_Internal_h;
  real_T rtb_Product1;
  real_T rtb_Product2;
  real_T rtb_Product3;
  real_T rtb_Switch;
  real_T rtb_Gain2_h;
  real_T rtb_Gain3;
  real_T rtb_LeftPWM;
  real_T rtb_RightPWM;
  real_T rtb_IntegralGain;
  real_T rtb_Integrator;
  real_T rtb_Saturation;
  real_T rtb_Switch_c;
  real_T rtb_Switch_l;
  int8_T tmp;
  int8_T tmp_0;

  /* Gain: '<Root>/Gain' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<S2>/Gain5'
   *  Rounding: '<S2>/Rounding Function'
   */
  rtb_Integrator = 6.2831853071795862 * Drive_P.wheelR / Drive_P.ticksPerRot;
  rtb_Saturation = ceil(Drive_P.ticksPerRot / 360.0 *
                        Drive_DW.DiscreteTimeIntegrator_DSTATE) * rtb_Integrator;

  /* Gain: '<Root>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   *  Gain: '<S2>/Gain6'
   *  Rounding: '<S2>/Rounding Function1'
   */
  rtb_Integrator *= ceil(Drive_P.ticksPerRot / 360.0 *
    Drive_DW.DiscreteTimeIntegrator1_DSTATE);

  /* DiscreteStateSpace: '<S58>/Internal' */
  {
    rtb_Internal = (Drive_P.Internal_C[0])*Drive_DW.Internal_DSTATE[0] +
      (Drive_P.Internal_C[1])*Drive_DW.Internal_DSTATE[1]
      + (Drive_P.Internal_C[2])*Drive_DW.Internal_DSTATE[2];
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Gain: '<S59>/Gain'
   */
  if (Drive_P.LeftMotor_sensorType > Drive_P.Switch_Threshold) {
    rtb_Switch_c = Drive_P.Gain_Gain * Drive_DW.DiscreteTimeIntegrator_DSTATE_c;
  } else {
    rtb_Switch_c = rtb_Internal;
  }

  /* End of Switch: '<S3>/Switch' */

  /* DiscreteStateSpace: '<S62>/Internal' */
  {
    rtb_Internal_h = (Drive_P.Internal_C_i[0])*Drive_DW.Internal_DSTATE_c[0] +
      (Drive_P.Internal_C_i[1])*Drive_DW.Internal_DSTATE_c[1]
      + (Drive_P.Internal_C_i[2])*Drive_DW.Internal_DSTATE_c[2];
  }

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S63>/Gain'
   */
  if (Drive_P.RightMotor_sensorType > Drive_P.Switch_Threshold_b) {
    rtb_Switch_l = Drive_P.Gain_Gain_g *
      Drive_DW.DiscreteTimeIntegrator_DSTATE_n;
  } else {
    rtb_Switch_l = rtb_Internal_h;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Wheel Radius'
   *  Gain: '<S5>/Gain1'
   *  Sum: '<S5>/Common Mode'
   */
  rtb_IntegralGain = (rtb_Switch_c + rtb_Switch_l) * (Drive_P.Gain1_Gain *
    Drive_P.wheelR);

  /* Product: '<S5>/Product1' incorporates:
   *  Constant: '<S5>/Wheel Radius'
   *  Constant: '<S5>/Wheel Spacing'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Differential'
   */
  rtb_Product1 = Drive_P.wheelR / Drive_P.axleLength * (rtb_Switch_l -
    rtb_Switch_c);

  /* Product: '<S5>/Product2' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator2'
   *  Trigonometry: '<S5>/Comp_x'
   */
  rtb_Product2 = rtb_IntegralGain * cos(Drive_DW.DiscreteTimeIntegrator2_DSTATE);

  /* Product: '<S5>/Product3' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator2'
   *  Trigonometry: '<S5>/Comp_y'
   */
  rtb_Product3 = rtb_IntegralGain * sin(Drive_DW.DiscreteTimeIntegrator2_DSTATE);

  /* S-Function (sfun_time): '<S5>/Soft Real Time' */

  /* Level2 S-Function Block: '<S5>/Soft Real Time' (sfun_time) */
  {
    SimStruct *rts = Drive_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Sum: '<S1>/Subtract' incorporates:
   *  Constant: '<Root>/DriveDist'
   *  Gain: '<Root>/Gain2'
   *  Sum: '<Root>/Add'
   */
  rtb_IntegralGain = Drive_P.DriveDist_Value - (rtb_Saturation + rtb_Integrator)
    * Drive_P.Gain2_Gain;

  /* DiscreteIntegrator: '<S41>/Integrator' */
  rtb_Integrator = Drive_DW.Integrator_DSTATE;

  /* Sum: '<S50>/Sum' incorporates:
   *  Gain: '<S46>/Proportional Gain'
   */
  rtb_Saturation = Drive_P.PIDController_P * rtb_IntegralGain + rtb_Integrator;

  /* DeadZone: '<S34>/DeadZone' */
  if (rtb_Saturation > Drive_P.PIDController_UpperSaturationLi) {
    rtb_Integrator = rtb_Saturation - Drive_P.PIDController_UpperSaturationLi;
  } else if (rtb_Saturation >= Drive_P.PIDController_LowerSaturationLi) {
    rtb_Integrator = 0.0;
  } else {
    rtb_Integrator = rtb_Saturation - Drive_P.PIDController_LowerSaturationLi;
  }

  /* End of DeadZone: '<S34>/DeadZone' */

  /* Gain: '<S38>/Integral Gain' */
  rtb_IntegralGain *= Drive_P.PIDController_I;

  /* Switch: '<S32>/Switch1' incorporates:
   *  Constant: '<S32>/Clamping_zero'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant2'
   *  RelationalOperator: '<S32>/fix for DT propagation issue'
   */
  if (rtb_Integrator > Drive_P.Clamping_zero_Value) {
    tmp = Drive_P.Constant_Value_g;
  } else {
    tmp = Drive_P.Constant2_Value;
  }

  /* Switch: '<S32>/Switch2' incorporates:
   *  Constant: '<S32>/Clamping_zero'
   *  Constant: '<S32>/Constant3'
   *  Constant: '<S32>/Constant4'
   *  RelationalOperator: '<S32>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain > Drive_P.Clamping_zero_Value) {
    tmp_0 = Drive_P.Constant3_Value;
  } else {
    tmp_0 = Drive_P.Constant4_Value;
  }

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Clamping_zero'
   *  Logic: '<S32>/AND3'
   *  RelationalOperator: '<S32>/Equal1'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  Switch: '<S32>/Switch1'
   *  Switch: '<S32>/Switch2'
   */
  if ((Drive_P.Clamping_zero_Value != rtb_Integrator) && (tmp == tmp_0)) {
    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/Constant1'
     */
    rtb_Switch = Drive_P.Constant1_Value;
  } else {
    /* Switch: '<S32>/Switch' */
    rtb_Switch = rtb_IntegralGain;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Gain: '<S2>/Gain2' */
  rtb_Gain2_h = Drive_P.Gain2_Gain_g * rtb_Switch_c;

  /* Gain: '<S2>/Gain3' */
  rtb_Gain3 = Drive_P.Gain3_Gain * rtb_Switch_l;

  /* Gain: '<S6>/vtow' */
  rtb_Switch_c = 1.0 / Drive_P.Towlwr_wheelR;

  /* Saturate: '<S48>/Saturation' */
  if (rtb_Saturation > Drive_P.PIDController_UpperSaturationLi) {
    rtb_Saturation = Drive_P.PIDController_UpperSaturationLi;
  } else if (rtb_Saturation < Drive_P.PIDController_LowerSaturationLi) {
    rtb_Saturation = Drive_P.PIDController_LowerSaturationLi;
  }

  /* Lookup_n-D: '<Root>/Left Motor LUT' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S6>/change parameters'
   *  Gain: '<S6>/vtow'
   *  Saturate: '<S48>/Saturation'
   */
  rtb_LeftPWM = Drive_P.InputPWM[plook_u32d_binckan
    ((Drive_P.changeparameters_Gain[0] * rtb_Saturation +
      Drive_P.changeparameters_Gain[2] * Drive_P.Constant_Value) * rtb_Switch_c,
     Drive_P.WheelSpeed, 172U)];

  /* Lookup_n-D: '<Root>/Right Motor LUT' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S6>/change parameters'
   *  Gain: '<S6>/vtow'
   *  Saturate: '<S48>/Saturation'
   */
  rtb_RightPWM = Drive_P.InputPWM[plook_u32d_binckan
    ((Drive_P.changeparameters_Gain[1] * rtb_Saturation +
      Drive_P.changeparameters_Gain[3] * Drive_P.Constant_Value) * rtb_Switch_c,
     Drive_P.WheelSpeed, 172U)];

  /* Matfile logging */
  rt_UpdateTXYLogVars(Drive_M->rtwLogInfo, (Drive_M->Timing.t));

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE +=
    Drive_P.DiscreteTimeIntegrator_gainval * rtb_Gain2_h;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Drive_DW.DiscreteTimeIntegrator1_DSTATE +=
    Drive_P.DiscreteTimeIntegrator1_gainval * rtb_Gain3;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE_a +=
    Drive_P.DiscreteTimeIntegrator_gainva_n * rtb_Product2;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  Drive_DW.DiscreteTimeIntegrator1_DSTAT_b +=
    Drive_P.DiscreteTimeIntegrator1_gainv_f * rtb_Product3;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */
  Drive_DW.DiscreteTimeIntegrator2_DSTATE +=
    Drive_P.DiscreteTimeIntegrator2_gainval * rtb_Product1;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE_c +=
    Drive_P.DiscreteTimeIntegrator_gainv_nq * rtb_Internal;

  /* Update for DiscreteStateSpace: '<S58>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (Drive_P.Internal_A[0])*Drive_DW.Internal_DSTATE[0] +
      (Drive_P.Internal_A[1])*Drive_DW.Internal_DSTATE[1]
      + (Drive_P.Internal_A[2])*Drive_DW.Internal_DSTATE[2];
    xnew[0] += (Drive_P.Internal_B[0])*rtb_LeftPWM;
    xnew[1] = (Drive_P.Internal_A[3])*Drive_DW.Internal_DSTATE[0] +
      (Drive_P.Internal_A[4])*Drive_DW.Internal_DSTATE[1]
      + (Drive_P.Internal_A[5])*Drive_DW.Internal_DSTATE[2];
    xnew[1] += (Drive_P.Internal_B[1])*rtb_LeftPWM;
    xnew[2] = (Drive_P.Internal_A[6])*Drive_DW.Internal_DSTATE[0] +
      (Drive_P.Internal_A[7])*Drive_DW.Internal_DSTATE[1]
      + (Drive_P.Internal_A[8])*Drive_DW.Internal_DSTATE[2];
    xnew[2] += (Drive_P.Internal_B[2])*rtb_LeftPWM;
    (void) memcpy(&Drive_DW.Internal_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE_n +=
    Drive_P.DiscreteTimeIntegrator_gainva_m * rtb_Internal_h;

  /* Update for DiscreteStateSpace: '<S62>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (Drive_P.Internal_A_h[0])*Drive_DW.Internal_DSTATE_c[0] +
      (Drive_P.Internal_A_h[1])*Drive_DW.Internal_DSTATE_c[1]
      + (Drive_P.Internal_A_h[2])*Drive_DW.Internal_DSTATE_c[2];
    xnew[0] += (Drive_P.Internal_B_p[0])*rtb_RightPWM;
    xnew[1] = (Drive_P.Internal_A_h[3])*Drive_DW.Internal_DSTATE_c[0] +
      (Drive_P.Internal_A_h[4])*Drive_DW.Internal_DSTATE_c[1]
      + (Drive_P.Internal_A_h[5])*Drive_DW.Internal_DSTATE_c[2];
    xnew[1] += (Drive_P.Internal_B_p[1])*rtb_RightPWM;
    xnew[2] = (Drive_P.Internal_A_h[6])*Drive_DW.Internal_DSTATE_c[0] +
      (Drive_P.Internal_A_h[7])*Drive_DW.Internal_DSTATE_c[1]
      + (Drive_P.Internal_A_h[8])*Drive_DW.Internal_DSTATE_c[2];
    xnew[2] += (Drive_P.Internal_B_p[2])*rtb_RightPWM;
    (void) memcpy(&Drive_DW.Internal_DSTATE_c[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteIntegrator: '<S41>/Integrator' */
  Drive_DW.Integrator_DSTATE += Drive_P.Integrator_gainval * rtb_Switch;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Drive_M)!=-1) &&
        !((rtmGetTFinal(Drive_M)-Drive_M->Timing.t[0]) > Drive_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(Drive_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Drive_M)) {
      rtmSetErrorStatus(Drive_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Drive_M->Timing.clockTick0)) {
    ++Drive_M->Timing.clockTickH0;
  }

  Drive_M->Timing.t[0] = Drive_M->Timing.clockTick0 * Drive_M->Timing.stepSize0
    + Drive_M->Timing.clockTickH0 * Drive_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Drive_M->Timing.clockTick1++;
    if (!Drive_M->Timing.clockTick1) {
      Drive_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Drive_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Drive_M, 0,
                sizeof(RT_MODEL_Drive_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Drive_M->solverInfo, &Drive_M->Timing.simTimeStep);
    rtsiSetTPtr(&Drive_M->solverInfo, &rtmGetTPtr(Drive_M));
    rtsiSetStepSizePtr(&Drive_M->solverInfo, &Drive_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Drive_M->solverInfo, (&rtmGetErrorStatus(Drive_M)));
    rtsiSetRTModelPtr(&Drive_M->solverInfo, Drive_M);
  }

  rtsiSetSimTimeStep(&Drive_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Drive_M->solverInfo,"FixedStepDiscrete");
  Drive_M->solverInfoPtr = (&Drive_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Drive_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Drive_M points to
       static memory which is guaranteed to be non-NULL" */
    Drive_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Drive_M->Timing.sampleTimes = (&Drive_M->Timing.sampleTimesArray[0]);
    Drive_M->Timing.offsetTimes = (&Drive_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Drive_M->Timing.sampleTimes[0] = (0.0);
    Drive_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Drive_M->Timing.offsetTimes[0] = (0.0);
    Drive_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Drive_M, &Drive_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Drive_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Drive_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Drive_M, 10.0);
  Drive_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Drive_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Drive_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Drive_M->rtwLogInfo, (NULL));
    rtliSetLogT(Drive_M->rtwLogInfo, "tout");
    rtliSetLogX(Drive_M->rtwLogInfo, "");
    rtliSetLogXFinal(Drive_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Drive_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Drive_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Drive_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Drive_M->rtwLogInfo, 1);
    rtliSetLogY(Drive_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Drive_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Drive_M->rtwLogInfo, (NULL));
  }

  Drive_M->solverInfoPtr = (&Drive_M->solverInfo);
  Drive_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Drive_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Drive_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* states (dwork) */
  (void) memset((void *)&Drive_DW, 0,
                sizeof(DW_Drive_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Drive_M->NonInlinedSFcns.sfcnInfo;
    Drive_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Drive_M)));
    Drive_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Drive_M->Sizes.numSampTimes);
    Drive_M->NonInlinedSFcns.taskTimePtrs[0] = (&rtmGetTPtr(Drive_M)[0]);
    Drive_M->NonInlinedSFcns.taskTimePtrs[1] = (&rtmGetTPtr(Drive_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Drive_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Drive_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Drive_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Drive_M));
    rtssSetStepSizePtr(sfcnInfo, &Drive_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Drive_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &Drive_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Drive_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Drive_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Drive_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Drive_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Drive_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Drive_M->solverInfoPtr);
  }

  Drive_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&Drive_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    Drive_M->childSfunctions = (&Drive_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Drive_M->childSfunctions[0] = (&Drive_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: Drive/<S5>/Soft Real Time (sfun_time) */
    {
      SimStruct *rts = Drive_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Drive_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Drive_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Drive_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Drive_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Drive_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Drive_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Drive_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Drive_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Drive_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Drive_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Drive_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "Soft Real Time");
      ssSetPath(rts, "Drive/Robot Simulator/Soft Real Time");
      ssSetRTModel(rts,Drive_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Drive_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Drive_P.SoftRealTime_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Drive_DW.SoftRealTime_RWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Drive_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Drive_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Drive_DW.SoftRealTime_RWORK);
      }

      /* registration */
      sfun_time(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Drive_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Drive_M), Drive_M->Timing.stepSize0, (&rtmGetErrorStatus(Drive_M)));

  /* Start for S-Function (sfun_time): '<S5>/Soft Real Time' */
  /* Level2 S-Function Block: '<S5>/Soft Real Time' (sfun_time) */
  {
    SimStruct *rts = Drive_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE = Drive_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Drive_DW.DiscreteTimeIntegrator1_DSTATE = Drive_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE_a = Drive_P.RobotSimulator_startX;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  Drive_DW.DiscreteTimeIntegrator1_DSTAT_b = Drive_P.RobotSimulator_startY;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator2' */
  Drive_DW.DiscreteTimeIntegrator2_DSTATE = Drive_P.RobotSimulator_startTheta *
    0.017453292519943295;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE_c = Drive_P.DiscreteTimeIntegrator_IC_p;

  /* InitializeConditions for DiscreteStateSpace: '<S58>/Internal' */
  Drive_DW.Internal_DSTATE[0] = 0.0;
  Drive_DW.Internal_DSTATE[1] = 0.0;
  Drive_DW.Internal_DSTATE[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  Drive_DW.DiscreteTimeIntegrator_DSTATE_n = Drive_P.DiscreteTimeIntegrator_IC_a;

  /* InitializeConditions for DiscreteStateSpace: '<S62>/Internal' */
  Drive_DW.Internal_DSTATE_c[0] = 0.0;
  Drive_DW.Internal_DSTATE_c[1] = 0.0;
  Drive_DW.Internal_DSTATE_c[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  Drive_DW.Integrator_DSTATE = Drive_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void Drive_terminate(void)
{
  /* Terminate for S-Function (sfun_time): '<S5>/Soft Real Time' */
  /* Level2 S-Function Block: '<S5>/Soft Real Time' (sfun_time) */
  {
    SimStruct *rts = Drive_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}
