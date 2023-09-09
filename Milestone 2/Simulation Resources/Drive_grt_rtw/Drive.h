/*
 * Drive.h
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

#ifndef RTW_HEADER_Drive_h_
#define RTW_HEADER_Drive_h_
#ifndef Drive_COMMON_INCLUDES_
#define Drive_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* Drive_COMMON_INCLUDES_ */

#include "Drive_types.h"
#include <stddef.h>
#include <string.h>
#include <float.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S5>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S5>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S5>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S3>/Discrete-Time Integrator' */
  real_T Internal_DSTATE[3];           /* '<S58>/Internal' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S4>/Discrete-Time Integrator' */
  real_T Internal_DSTATE_c[3];         /* '<S62>/Internal' */
  real_T Integrator_DSTATE;            /* '<S41>/Integrator' */
  real_T SoftRealTime_RWORK;           /* '<S5>/Soft Real Time' */
} DW_Drive_T;

/* Parameters (default storage) */
struct P_Drive_T_ {
  real_T InputPWM[173];                /* Variable: InputPWM
                                        * Referenced by:
                                        *   '<Root>/Left Motor LUT'
                                        *   '<Root>/Right Motor LUT'
                                        */
  real_T WheelSpeed[173];              /* Variable: WheelSpeed
                                        * Referenced by:
                                        *   '<Root>/Left Motor LUT'
                                        *   '<Root>/Right Motor LUT'
                                        */
  real_T axleLength;                   /* Variable: axleLength
                                        * Referenced by: '<S5>/Wheel Spacing'
                                        */
  real_T lineLength;                   /* Variable: lineLength
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T ticksPerRot;                  /* Variable: ticksPerRot
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain1'
                                        *   '<S2>/Gain5'
                                        *   '<S2>/Gain6'
                                        */
  real_T wheelR;                       /* Variable: wheelR
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain1'
                                        *   '<S5>/Wheel Radius'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S38>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S41>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by:
                               *   '<S48>/Saturation'
                               *   '<S34>/DeadZone'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S46>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by:
                               *   '<S48>/Saturation'
                               *   '<S34>/DeadZone'
                               */
  real_T LeftMotor_sensorType;         /* Mask Parameter: LeftMotor_sensorType
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T RightMotor_sensorType;        /* Mask Parameter: RightMotor_sensorType
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T RobotSimulator_startTheta; /* Mask Parameter: RobotSimulator_startTheta
                                     * Referenced by: '<S5>/Discrete-Time Integrator2'
                                     */
  real_T RobotSimulator_startX;        /* Mask Parameter: RobotSimulator_startX
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real_T RobotSimulator_startY;        /* Mask Parameter: RobotSimulator_startY
                                        * Referenced by: '<S5>/Discrete-Time Integrator1'
                                        */
  real_T Towlwr_wheelR;                /* Mask Parameter: Towlwr_wheelR
                                        * Referenced by: '<S6>/vtow'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S59>/Gain'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 180/pi
                                        * Referenced by: '<S63>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S2>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S2>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                           * Referenced by: '<S5>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator1_gainv_f;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_f
                           * Referenced by: '<S5>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<S5>/Discrete-Time Integrator2'
                           */
  real_T Circle_Value;                 /* Expression: 2*pi
                                        * Referenced by: '<S5>/Circle'
                                        */
  real_T DiscreteTimeIntegrator_gainv_nq;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_nq
                           * Referenced by: '<S3>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator'
                                        */
  real_T Internal_A[9];                /* Computed Parameter: Internal_A
                                        * Referenced by: '<S58>/Internal'
                                        */
  real_T Internal_B[3];                /* Computed Parameter: Internal_B
                                        * Referenced by: '<S58>/Internal'
                                        */
  real_T Internal_C[3];                /* Computed Parameter: Internal_C
                                        * Referenced by: '<S58>/Internal'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T DiscreteTimeIntegrator_gainva_m;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                           * Referenced by: '<S4>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  real_T Internal_A_h[9];              /* Computed Parameter: Internal_A_h
                                        * Referenced by: '<S62>/Internal'
                                        */
  real_T Internal_B_p[3];              /* Computed Parameter: Internal_B_p
                                        * Referenced by: '<S62>/Internal'
                                        */
  real_T Internal_C_i[3];              /* Computed Parameter: Internal_C_i
                                        * Referenced by: '<S62>/Internal'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 1
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T SoftRealTime_P1_Size[2];    /* Computed Parameter: SoftRealTime_P1_Size
                                      * Referenced by: '<S5>/Soft Real Time'
                                      */
  real_T SoftRealTime_P1;              /* Expression: x
                                        * Referenced by: '<S5>/Soft Real Time'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S32>/Clamping_zero'
                                        */
  real_T DriveDist_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/DriveDist'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: (180/pi)
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: (180/pi)
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T changeparameters_Gain[4];
                                /* Expression: [1 -axleLength/2; 1 axleLength/2]
                                 * Referenced by: '<S6>/change parameters'
                                 */
  int8_T Constant_Value_g;             /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S32>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S32>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S32>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S32>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Drive_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct _ssPortInfo2 inputOutputPortInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Drive_T Drive_P;

/* Block states (default storage) */
extern DW_Drive_T Drive_DW;

/* Model entry point functions */
extern void Drive_initialize(void);
extern void Drive_step(void);
extern void Drive_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Drive_T *const Drive_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Drive'
 * '<S1>'   : 'Drive/DistanceControl'
 * '<S2>'   : 'Drive/Encoder'
 * '<S3>'   : 'Drive/LeftMotor'
 * '<S4>'   : 'Drive/RightMotor'
 * '<S5>'   : 'Drive/Robot Simulator'
 * '<S6>'   : 'Drive/To wlwr'
 * '<S7>'   : 'Drive/DistanceControl/PID Controller'
 * '<S8>'   : 'Drive/DistanceControl/PID Controller/Anti-windup'
 * '<S9>'   : 'Drive/DistanceControl/PID Controller/D Gain'
 * '<S10>'  : 'Drive/DistanceControl/PID Controller/Filter'
 * '<S11>'  : 'Drive/DistanceControl/PID Controller/Filter ICs'
 * '<S12>'  : 'Drive/DistanceControl/PID Controller/I Gain'
 * '<S13>'  : 'Drive/DistanceControl/PID Controller/Ideal P Gain'
 * '<S14>'  : 'Drive/DistanceControl/PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'Drive/DistanceControl/PID Controller/Integrator'
 * '<S16>'  : 'Drive/DistanceControl/PID Controller/Integrator ICs'
 * '<S17>'  : 'Drive/DistanceControl/PID Controller/N Copy'
 * '<S18>'  : 'Drive/DistanceControl/PID Controller/N Gain'
 * '<S19>'  : 'Drive/DistanceControl/PID Controller/P Copy'
 * '<S20>'  : 'Drive/DistanceControl/PID Controller/Parallel P Gain'
 * '<S21>'  : 'Drive/DistanceControl/PID Controller/Reset Signal'
 * '<S22>'  : 'Drive/DistanceControl/PID Controller/Saturation'
 * '<S23>'  : 'Drive/DistanceControl/PID Controller/Saturation Fdbk'
 * '<S24>'  : 'Drive/DistanceControl/PID Controller/Sum'
 * '<S25>'  : 'Drive/DistanceControl/PID Controller/Sum Fdbk'
 * '<S26>'  : 'Drive/DistanceControl/PID Controller/Tracking Mode'
 * '<S27>'  : 'Drive/DistanceControl/PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'Drive/DistanceControl/PID Controller/Tsamp - Integral'
 * '<S29>'  : 'Drive/DistanceControl/PID Controller/Tsamp - Ngain'
 * '<S30>'  : 'Drive/DistanceControl/PID Controller/postSat Signal'
 * '<S31>'  : 'Drive/DistanceControl/PID Controller/preSat Signal'
 * '<S32>'  : 'Drive/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S33>'  : 'Drive/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S34>'  : 'Drive/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S35>'  : 'Drive/DistanceControl/PID Controller/D Gain/Disabled'
 * '<S36>'  : 'Drive/DistanceControl/PID Controller/Filter/Disabled'
 * '<S37>'  : 'Drive/DistanceControl/PID Controller/Filter ICs/Disabled'
 * '<S38>'  : 'Drive/DistanceControl/PID Controller/I Gain/Internal Parameters'
 * '<S39>'  : 'Drive/DistanceControl/PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'Drive/DistanceControl/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'Drive/DistanceControl/PID Controller/Integrator/Discrete'
 * '<S42>'  : 'Drive/DistanceControl/PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'Drive/DistanceControl/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S44>'  : 'Drive/DistanceControl/PID Controller/N Gain/Disabled'
 * '<S45>'  : 'Drive/DistanceControl/PID Controller/P Copy/Disabled'
 * '<S46>'  : 'Drive/DistanceControl/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'Drive/DistanceControl/PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'Drive/DistanceControl/PID Controller/Saturation/Enabled'
 * '<S49>'  : 'Drive/DistanceControl/PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'Drive/DistanceControl/PID Controller/Sum/Sum_PI'
 * '<S51>'  : 'Drive/DistanceControl/PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'Drive/DistanceControl/PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'Drive/DistanceControl/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'Drive/DistanceControl/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'Drive/DistanceControl/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'Drive/DistanceControl/PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'Drive/DistanceControl/PID Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'Drive/LeftMotor/Motor'
 * '<S59>'  : 'Drive/LeftMotor/Radians to Degrees'
 * '<S60>'  : 'Drive/LeftMotor/Motor/Input Delay'
 * '<S61>'  : 'Drive/LeftMotor/Motor/Output Delay'
 * '<S62>'  : 'Drive/RightMotor/Motor'
 * '<S63>'  : 'Drive/RightMotor/Radians to Degrees'
 * '<S64>'  : 'Drive/RightMotor/Motor/Input Delay'
 * '<S65>'  : 'Drive/RightMotor/Motor/Output Delay'
 * '<S66>'  : 'Drive/Robot Simulator/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Drive_h_ */
