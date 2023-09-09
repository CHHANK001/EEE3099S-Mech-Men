/*
 * Simulation3Draft.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulation3Draft".
 *
 * Model version              : 5.10
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Sep  9 13:51:01 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Simulation3Draft_h_
#define RTW_HEADER_Simulation3Draft_h_
#ifndef Simulation3Draft_COMMON_INCLUDES_
#define Simulation3Draft_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* Simulation3Draft_COMMON_INCLUDES_ */

#include "Simulation3Draft_types.h"
#include <stddef.h>
#include <string.h>
#include "rtGetNaN.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum1[31];                     /* '<S128>/Sum1' */
  real32_T ImpAsg_InsertedFor_SensorVa[31];/* '<S129>/Lookup Obstacle Map' */
  real_T rotMat[9];                    /* '<S126>/Calculate Rotation Matrix' */
  real_T dv[9];
  real_T Switch[4];                    /* '<S5>/Switch' */
  real_T MathFunction_g[3];            /* '<S129>/Math Function' */
  real32_T ImpAsg_InsertedFor_LineArra[4];/* '<S67>/Look up Line Value' */
  real_T ImpAsg_InsertedFor_DistanceArra;/* '<S128>/Nearest Object' */
  real_T v;                            /* '<Root>/Line Following' */
  real_T data;                         /* '<Root>/Line Following' */
  real_T w;                            /* '<Root>/Line Following' */
  real_T MathFunction;                 /* '<S7>/Math Function' */
  real_T Gain_b;                       /* '<Root>/Gain' */
  real_T DiscreteTimeIntegrator_d;     /* '<S2>/Discrete-Time Integrator' */
  real_T rtb_rotMat_tmp_tmp;
  real_T LeftPWM;                      /* '<Root>/Left Motor LUT' */
  real_T Internal;                     /* '<S62>/Internal' */
  real_T RightPWM;                     /* '<Root>/Right Motor LUT' */
  real_T Internal_b;                   /* '<S70>/Internal' */
  real_T Product2;                     /* '<S7>/Product2' */
  real_T Product3;                     /* '<S7>/Product3' */
  real_T Product1;                     /* '<S7>/Product1' */
} B_Simulation3Draft_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S7>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S7>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S3>/Discrete-Time Integrator' */
  real_T Internal_DSTATE[3];           /* '<S62>/Internal' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S6>/Discrete-Time Integrator' */
  real_T Internal_DSTATE_n[3];         /* '<S70>/Internal' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_d;/* '<S2>/Discrete-Time Integrator1' */
  real_T dir;                          /* '<Root>/Line Following' */
  real_T SoftRealTime_RWORK;           /* '<S7>/Soft Real Time' */
  uint32_T state;                      /* '<Root>/Random Integer Generator' */
  uint32_T state_f[2];                 /* '<Root>/Random Integer Generator' */
  uint32_T state_p[625];               /* '<Root>/Random Integer Generator' */
  uint32_T method;                     /* '<Root>/Random Integer Generator' */
  comm_internal_RandomIntegerGe_T obj; /* '<Root>/Random Integer Generator' */
  uint8_T is_active_c1_Simulation3Draft;/* '<Root>/Line Following' */
  uint8_T is_c1_Simulation3Draft;      /* '<Root>/Line Following' */
  uint8_T temporalCounter_i1;          /* '<Root>/Line Following' */
  boolean_T objisempty;                /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty;           /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty_d;         /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty_f;         /* '<Root>/Random Integer Generator' */
  boolean_T method_not_empty;          /* '<Root>/Random Integer Generator' */
} DW_Simulation3Draft_T;

/* Parameters for system: '<S66>/For Each Subsystem' */
struct P_CoreSubsys_Simulation3Draft_T_ {
  real_T Gain1_Gain;                   /* Expression: mapForSim.scaleFactor
                                        * Referenced by: '<S68>/Gain1'
                                        */
  real_T Constant_Value;       /* Expression: size(mapForSim.lineFollowingMap,1)
                                * Referenced by: '<S68>/Constant'
                                */
  real_T Bias_Bias;                    /* Expression: -1
                                        * Referenced by: '<S68>/Bias'
                                        */
  real_T Saturation2_UpperSat;
                             /* Expression: size(mapForSim.lineFollowingMap,1)-1
                              * Referenced by: '<S68>/Saturation2'
                              */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S68>/Saturation2'
                                        */
  real_T Gain_Gain;                    /* Expression: mapForSim.scaleFactor
                                        * Referenced by: '<S68>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: -1
                                        * Referenced by: '<S68>/Bias1'
                                        */
  real_T Saturation3_UpperSat;
                             /* Expression: size(mapForSim.lineFollowingMap,2)-1
                              * Referenced by: '<S68>/Saturation3'
                              */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S68>/Saturation3'
                                        */
  real32_T DirectLookupTablenD_table[791911];/* Expression: mapForSim.lineFollowingMap
                                              * Referenced by: '<S68>/Direct Lookup Table (n-D)'
                                              */
};

/* Parameters for system: '<S128>/Look up Sensor Value' */
struct P_CoreSubsys_Simulation3Dr_le_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S129>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: mapForSim.scaleFactor
                                        * Referenced by: '<S131>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: size(mapForSim.obsMap,1)
                                        * Referenced by: '<S131>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: -1
                                        * Referenced by: '<S131>/Bias'
                                        */
  real_T Saturation_UpperSat;          /* Expression: size(mapForSim.obsMap,1)-1
                                        * Referenced by: '<S131>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S131>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: mapForSim.scaleFactor
                                        * Referenced by: '<S131>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: -1
                                        * Referenced by: '<S131>/Bias1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: size(mapForSim.obsMap,2)-1
                                        * Referenced by: '<S131>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S131>/Saturation1'
                                        */
  real32_T DirectLookupTablenD_table[791911];/* Expression: mapForSim.obsMap
                                              * Referenced by: '<S131>/Direct Lookup Table (n-D)'
                                              */
};

/* Parameters for system: '<S126>/Subsystem' */
struct P_CoreSubsys_Simulation3Dra_l_T_ {
  real_T Constant_Value[31];       /* Expression: minSenRange:senRes:maxSenRange
                                    * Referenced by: '<S128>/Constant'
                                    */
  P_CoreSubsys_Simulation3Dr_le_T CoreSubsys;/* '<S128>/Look up Sensor Value' */
};

/* Parameters (default storage) */
struct P_Simulation3Draft_T_ {
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
                                        * Referenced by: '<S7>/Wheel Spacing'
                                        */
  real_T lineLength;                   /* Variable: lineLength
                                        * Referenced by: '<S7>/Constant'
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
                                        *   '<S7>/Wheel Radius'
                                        */
  real_T LineSensor_envVal;            /* Mask Parameter: LineSensor_envVal
                                        * Referenced by: '<S5>/Scale to Environment'
                                        */
  real_T LineSensor_lineVal;           /* Mask Parameter: LineSensor_lineVal
                                        * Referenced by: '<S5>/Scale to Line'
                                        */
  real_T LeftMotor_sensorType;         /* Mask Parameter: LeftMotor_sensorType
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T RightMotor_sensorType;        /* Mask Parameter: RightMotor_sensorType
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T RobotSimulator_startTheta; /* Mask Parameter: RobotSimulator_startTheta
                                     * Referenced by: '<S7>/Discrete-Time Integrator2'
                                     */
  real_T RobotSimulator_startX;        /* Mask Parameter: RobotSimulator_startX
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real_T RobotSimulator_startY;        /* Mask Parameter: RobotSimulator_startY
                                        * Referenced by: '<S7>/Discrete-Time Integrator1'
                                        */
  real_T Towlwr_wheelR;                /* Mask Parameter: Towlwr_wheelR
                                        * Referenced by: '<S9>/vtow'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S63>/Gain'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S71>/Gain'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<S7>/Discrete-Time Integrator2'
                           */
  real_T Circle_Value;                 /* Expression: 2*pi
                                        * Referenced by: '<S7>/Circle'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S7>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S7>/Discrete-Time Integrator1'
                           */
  real_T Constant_Value[4];            /* Expression: sensOff(:,1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value[4];           /* Expression: sensOff(:,2)
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: sensOff(:,1)
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: sensOff(:,2)
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T changeparameters_Gain[4];
                                /* Expression: [1 -axleLength/2; 1 axleLength/2]
                                 * Referenced by: '<S9>/change parameters'
                                 */
  real_T DiscreteTimeIntegrator_gainva_a;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                           * Referenced by: '<S3>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator'
                                        */
  real_T Internal_A[9];                /* Computed Parameter: Internal_A
                                        * Referenced by: '<S62>/Internal'
                                        */
  real_T Internal_B[3];                /* Computed Parameter: Internal_B
                                        * Referenced by: '<S62>/Internal'
                                        */
  real_T Internal_C[3];                /* Computed Parameter: Internal_C
                                        * Referenced by: '<S62>/Internal'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                           * Referenced by: '<S6>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  real_T Internal_A_a[9];              /* Computed Parameter: Internal_A_a
                                        * Referenced by: '<S70>/Internal'
                                        */
  real_T Internal_B_e[3];              /* Computed Parameter: Internal_B_e
                                        * Referenced by: '<S70>/Internal'
                                        */
  real_T Internal_C_h[3];              /* Computed Parameter: Internal_C_h
                                        * Referenced by: '<S70>/Internal'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 1
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: (180/pi)
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: (180/pi)
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                           * Referenced by: '<S2>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_f;  /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_f;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_f
                           * Referenced by: '<S2>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator1'
                                        */
  real_T SoftRealTime_P1_Size[2];    /* Computed Parameter: SoftRealTime_P1_Size
                                      * Referenced by: '<S7>/Soft Real Time'
                                      */
  real_T SoftRealTime_P1;              /* Expression: x
                                        * Referenced by: '<S7>/Soft Real Time'
                                        */
  real32_T Switch_Threshold_j;         /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S5>/Switch'
                                        */
  P_CoreSubsys_Simulation3Dra_l_T CoreSubsys_c;/* '<S126>/Subsystem' */
  P_CoreSubsys_Simulation3Draft_T CoreSubsys;/* '<S66>/For Each Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Simulation3Draft_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
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
    time_T *taskTimePtrs[3];
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
    struct {
      uint16_T TID[3];
    } TaskCounters;

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
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Simulation3Draft_T Simulation3Draft_P;

/* Block signals (default storage) */
extern B_Simulation3Draft_T Simulation3Draft_B;

/* Block states (default storage) */
extern DW_Simulation3Draft_T Simulation3Draft_DW;

/* External function called from main */
extern void Simulation3Draft_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Simulation3Draft_initialize(void);
extern void Simulation3Draft_step0(void);
extern void Simulation3Draft_step2(void);
extern void Simulation3Draft_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Simulation3Draft_T *const Simulation3Draft_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add' : Unused code path elimination
 * Block '<S36>/AND3' : Unused code path elimination
 * Block '<S36>/Clamping_zero' : Unused code path elimination
 * Block '<S36>/Constant' : Unused code path elimination
 * Block '<S36>/Constant1' : Unused code path elimination
 * Block '<S36>/Constant2' : Unused code path elimination
 * Block '<S36>/Constant3' : Unused code path elimination
 * Block '<S36>/Constant4' : Unused code path elimination
 * Block '<S38>/DeadZone' : Unused code path elimination
 * Block '<S36>/Equal1' : Unused code path elimination
 * Block '<S36>/Relational Operator' : Unused code path elimination
 * Block '<S36>/Switch' : Unused code path elimination
 * Block '<S36>/Switch1' : Unused code path elimination
 * Block '<S36>/Switch2' : Unused code path elimination
 * Block '<S36>/fix for DT propagation issue' : Unused code path elimination
 * Block '<S36>/fix for DT propagation issue1' : Unused code path elimination
 * Block '<S42>/Integral Gain' : Unused code path elimination
 * Block '<S45>/Integrator' : Unused code path elimination
 * Block '<S50>/Proportional Gain' : Unused code path elimination
 * Block '<S52>/Saturation' : Unused code path elimination
 * Block '<S54>/Sum' : Unused code path elimination
 * Block '<S1>/Subtract' : Unused code path elimination
 * Block '<Root>/DriveDist' : Unused code path elimination
 * Block '<Root>/DriveRot' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<Root>/Gain3' : Unused code path elimination
 * Block '<S7>/Theta' : Unused code path elimination
 * Block '<S7>/Theta_dot' : Unused code path elimination
 * Block '<S7>/X' : Unused code path elimination
 * Block '<S7>/X_dot' : Unused code path elimination
 * Block '<S7>/Y' : Unused code path elimination
 * Block '<S7>/Y_dot' : Unused code path elimination
 * Block '<S100>/AND3' : Unused code path elimination
 * Block '<S100>/Clamping_zero' : Unused code path elimination
 * Block '<S100>/Constant' : Unused code path elimination
 * Block '<S100>/Constant1' : Unused code path elimination
 * Block '<S100>/Constant2' : Unused code path elimination
 * Block '<S100>/Constant3' : Unused code path elimination
 * Block '<S100>/Constant4' : Unused code path elimination
 * Block '<S102>/DeadZone' : Unused code path elimination
 * Block '<S100>/Equal1' : Unused code path elimination
 * Block '<S100>/Relational Operator' : Unused code path elimination
 * Block '<S100>/Switch' : Unused code path elimination
 * Block '<S100>/Switch1' : Unused code path elimination
 * Block '<S100>/Switch2' : Unused code path elimination
 * Block '<S100>/fix for DT propagation issue' : Unused code path elimination
 * Block '<S100>/fix for DT propagation issue1' : Unused code path elimination
 * Block '<S106>/Integral Gain' : Unused code path elimination
 * Block '<S109>/Integrator' : Unused code path elimination
 * Block '<S114>/Proportional Gain' : Unused code path elimination
 * Block '<S116>/Saturation' : Unused code path elimination
 * Block '<S118>/Sum' : Unused code path elimination
 * Block '<S8>/Subtract' : Unused code path elimination
 */

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
 * '<Root>' : 'Simulation3Draft'
 * '<S1>'   : 'Simulation3Draft/DistanceControl'
 * '<S2>'   : 'Simulation3Draft/Encoder'
 * '<S3>'   : 'Simulation3Draft/LeftMotor'
 * '<S4>'   : 'Simulation3Draft/Line Following'
 * '<S5>'   : 'Simulation3Draft/Line Sensor'
 * '<S6>'   : 'Simulation3Draft/RightMotor'
 * '<S7>'   : 'Simulation3Draft/Robot Simulator'
 * '<S8>'   : 'Simulation3Draft/RotControl'
 * '<S9>'   : 'Simulation3Draft/To wlwr'
 * '<S10>'  : 'Simulation3Draft/Ultrasonic Sensor'
 * '<S11>'  : 'Simulation3Draft/DistanceControl/PID Controller'
 * '<S12>'  : 'Simulation3Draft/DistanceControl/PID Controller/Anti-windup'
 * '<S13>'  : 'Simulation3Draft/DistanceControl/PID Controller/D Gain'
 * '<S14>'  : 'Simulation3Draft/DistanceControl/PID Controller/Filter'
 * '<S15>'  : 'Simulation3Draft/DistanceControl/PID Controller/Filter ICs'
 * '<S16>'  : 'Simulation3Draft/DistanceControl/PID Controller/I Gain'
 * '<S17>'  : 'Simulation3Draft/DistanceControl/PID Controller/Ideal P Gain'
 * '<S18>'  : 'Simulation3Draft/DistanceControl/PID Controller/Ideal P Gain Fdbk'
 * '<S19>'  : 'Simulation3Draft/DistanceControl/PID Controller/Integrator'
 * '<S20>'  : 'Simulation3Draft/DistanceControl/PID Controller/Integrator ICs'
 * '<S21>'  : 'Simulation3Draft/DistanceControl/PID Controller/N Copy'
 * '<S22>'  : 'Simulation3Draft/DistanceControl/PID Controller/N Gain'
 * '<S23>'  : 'Simulation3Draft/DistanceControl/PID Controller/P Copy'
 * '<S24>'  : 'Simulation3Draft/DistanceControl/PID Controller/Parallel P Gain'
 * '<S25>'  : 'Simulation3Draft/DistanceControl/PID Controller/Reset Signal'
 * '<S26>'  : 'Simulation3Draft/DistanceControl/PID Controller/Saturation'
 * '<S27>'  : 'Simulation3Draft/DistanceControl/PID Controller/Saturation Fdbk'
 * '<S28>'  : 'Simulation3Draft/DistanceControl/PID Controller/Sum'
 * '<S29>'  : 'Simulation3Draft/DistanceControl/PID Controller/Sum Fdbk'
 * '<S30>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tracking Mode'
 * '<S31>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tracking Mode Sum'
 * '<S32>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tsamp - Integral'
 * '<S33>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tsamp - Ngain'
 * '<S34>'  : 'Simulation3Draft/DistanceControl/PID Controller/postSat Signal'
 * '<S35>'  : 'Simulation3Draft/DistanceControl/PID Controller/preSat Signal'
 * '<S36>'  : 'Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S37>'  : 'Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S38>'  : 'Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S39>'  : 'Simulation3Draft/DistanceControl/PID Controller/D Gain/Disabled'
 * '<S40>'  : 'Simulation3Draft/DistanceControl/PID Controller/Filter/Disabled'
 * '<S41>'  : 'Simulation3Draft/DistanceControl/PID Controller/Filter ICs/Disabled'
 * '<S42>'  : 'Simulation3Draft/DistanceControl/PID Controller/I Gain/Internal Parameters'
 * '<S43>'  : 'Simulation3Draft/DistanceControl/PID Controller/Ideal P Gain/Passthrough'
 * '<S44>'  : 'Simulation3Draft/DistanceControl/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S45>'  : 'Simulation3Draft/DistanceControl/PID Controller/Integrator/Discrete'
 * '<S46>'  : 'Simulation3Draft/DistanceControl/PID Controller/Integrator ICs/Internal IC'
 * '<S47>'  : 'Simulation3Draft/DistanceControl/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S48>'  : 'Simulation3Draft/DistanceControl/PID Controller/N Gain/Disabled'
 * '<S49>'  : 'Simulation3Draft/DistanceControl/PID Controller/P Copy/Disabled'
 * '<S50>'  : 'Simulation3Draft/DistanceControl/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S51>'  : 'Simulation3Draft/DistanceControl/PID Controller/Reset Signal/Disabled'
 * '<S52>'  : 'Simulation3Draft/DistanceControl/PID Controller/Saturation/Enabled'
 * '<S53>'  : 'Simulation3Draft/DistanceControl/PID Controller/Saturation Fdbk/Disabled'
 * '<S54>'  : 'Simulation3Draft/DistanceControl/PID Controller/Sum/Sum_PI'
 * '<S55>'  : 'Simulation3Draft/DistanceControl/PID Controller/Sum Fdbk/Disabled'
 * '<S56>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tracking Mode/Disabled'
 * '<S57>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S58>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S59>'  : 'Simulation3Draft/DistanceControl/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S60>'  : 'Simulation3Draft/DistanceControl/PID Controller/postSat Signal/Forward_Path'
 * '<S61>'  : 'Simulation3Draft/DistanceControl/PID Controller/preSat Signal/Forward_Path'
 * '<S62>'  : 'Simulation3Draft/LeftMotor/Motor'
 * '<S63>'  : 'Simulation3Draft/LeftMotor/Radians to Degrees'
 * '<S64>'  : 'Simulation3Draft/LeftMotor/Motor/Input Delay'
 * '<S65>'  : 'Simulation3Draft/LeftMotor/Motor/Output Delay'
 * '<S66>'  : 'Simulation3Draft/Line Sensor/Look up Line Value'
 * '<S67>'  : 'Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem'
 * '<S68>'  : 'Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value'
 * '<S69>'  : 'Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Transform Sensor Offset'
 * '<S70>'  : 'Simulation3Draft/RightMotor/Motor'
 * '<S71>'  : 'Simulation3Draft/RightMotor/Radians to Degrees'
 * '<S72>'  : 'Simulation3Draft/RightMotor/Motor/Input Delay'
 * '<S73>'  : 'Simulation3Draft/RightMotor/Motor/Output Delay'
 * '<S74>'  : 'Simulation3Draft/Robot Simulator/MATLAB Function'
 * '<S75>'  : 'Simulation3Draft/RotControl/PID Controller'
 * '<S76>'  : 'Simulation3Draft/RotControl/PID Controller/Anti-windup'
 * '<S77>'  : 'Simulation3Draft/RotControl/PID Controller/D Gain'
 * '<S78>'  : 'Simulation3Draft/RotControl/PID Controller/Filter'
 * '<S79>'  : 'Simulation3Draft/RotControl/PID Controller/Filter ICs'
 * '<S80>'  : 'Simulation3Draft/RotControl/PID Controller/I Gain'
 * '<S81>'  : 'Simulation3Draft/RotControl/PID Controller/Ideal P Gain'
 * '<S82>'  : 'Simulation3Draft/RotControl/PID Controller/Ideal P Gain Fdbk'
 * '<S83>'  : 'Simulation3Draft/RotControl/PID Controller/Integrator'
 * '<S84>'  : 'Simulation3Draft/RotControl/PID Controller/Integrator ICs'
 * '<S85>'  : 'Simulation3Draft/RotControl/PID Controller/N Copy'
 * '<S86>'  : 'Simulation3Draft/RotControl/PID Controller/N Gain'
 * '<S87>'  : 'Simulation3Draft/RotControl/PID Controller/P Copy'
 * '<S88>'  : 'Simulation3Draft/RotControl/PID Controller/Parallel P Gain'
 * '<S89>'  : 'Simulation3Draft/RotControl/PID Controller/Reset Signal'
 * '<S90>'  : 'Simulation3Draft/RotControl/PID Controller/Saturation'
 * '<S91>'  : 'Simulation3Draft/RotControl/PID Controller/Saturation Fdbk'
 * '<S92>'  : 'Simulation3Draft/RotControl/PID Controller/Sum'
 * '<S93>'  : 'Simulation3Draft/RotControl/PID Controller/Sum Fdbk'
 * '<S94>'  : 'Simulation3Draft/RotControl/PID Controller/Tracking Mode'
 * '<S95>'  : 'Simulation3Draft/RotControl/PID Controller/Tracking Mode Sum'
 * '<S96>'  : 'Simulation3Draft/RotControl/PID Controller/Tsamp - Integral'
 * '<S97>'  : 'Simulation3Draft/RotControl/PID Controller/Tsamp - Ngain'
 * '<S98>'  : 'Simulation3Draft/RotControl/PID Controller/postSat Signal'
 * '<S99>'  : 'Simulation3Draft/RotControl/PID Controller/preSat Signal'
 * '<S100>' : 'Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S101>' : 'Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S102>' : 'Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S103>' : 'Simulation3Draft/RotControl/PID Controller/D Gain/Disabled'
 * '<S104>' : 'Simulation3Draft/RotControl/PID Controller/Filter/Disabled'
 * '<S105>' : 'Simulation3Draft/RotControl/PID Controller/Filter ICs/Disabled'
 * '<S106>' : 'Simulation3Draft/RotControl/PID Controller/I Gain/Internal Parameters'
 * '<S107>' : 'Simulation3Draft/RotControl/PID Controller/Ideal P Gain/Passthrough'
 * '<S108>' : 'Simulation3Draft/RotControl/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S109>' : 'Simulation3Draft/RotControl/PID Controller/Integrator/Discrete'
 * '<S110>' : 'Simulation3Draft/RotControl/PID Controller/Integrator ICs/Internal IC'
 * '<S111>' : 'Simulation3Draft/RotControl/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S112>' : 'Simulation3Draft/RotControl/PID Controller/N Gain/Disabled'
 * '<S113>' : 'Simulation3Draft/RotControl/PID Controller/P Copy/Disabled'
 * '<S114>' : 'Simulation3Draft/RotControl/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S115>' : 'Simulation3Draft/RotControl/PID Controller/Reset Signal/Disabled'
 * '<S116>' : 'Simulation3Draft/RotControl/PID Controller/Saturation/Enabled'
 * '<S117>' : 'Simulation3Draft/RotControl/PID Controller/Saturation Fdbk/Disabled'
 * '<S118>' : 'Simulation3Draft/RotControl/PID Controller/Sum/Sum_PI'
 * '<S119>' : 'Simulation3Draft/RotControl/PID Controller/Sum Fdbk/Disabled'
 * '<S120>' : 'Simulation3Draft/RotControl/PID Controller/Tracking Mode/Disabled'
 * '<S121>' : 'Simulation3Draft/RotControl/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S122>' : 'Simulation3Draft/RotControl/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S123>' : 'Simulation3Draft/RotControl/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S124>' : 'Simulation3Draft/RotControl/PID Controller/postSat Signal/Forward_Path'
 * '<S125>' : 'Simulation3Draft/RotControl/PID Controller/preSat Signal/Forward_Path'
 * '<S126>' : 'Simulation3Draft/Ultrasonic Sensor/Look up Distance Value'
 * '<S127>' : 'Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Calculate Rotation Matrix'
 * '<S128>' : 'Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem'
 * '<S129>' : 'Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value'
 * '<S130>' : 'Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Nearest Object'
 * '<S131>' : 'Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map'
 */
#endif                                 /* RTW_HEADER_Simulation3Draft_h_ */
