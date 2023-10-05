/*
 * Simulation5Draft.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulation5Draft".
 *
 * Model version              : 5.17
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Oct  4 14:48:33 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Simulation5Draft_h_
#define RTW_HEADER_Simulation5Draft_h_
#ifndef Simulation5Draft_COMMON_INCLUDES_
#define Simulation5Draft_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Simulation5Draft_COMMON_INCLUDES_ */

#include "Simulation5Draft_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S6>/Subsystem' */
typedef struct {
  int32_T sfEvent;                     /* '<S8>/Nearest Object' */
  uint8_T is_active_c5_mobileRoboticsTrai;/* '<S8>/Nearest Object' */
  boolean_T doneDoubleBufferReInit;    /* '<S8>/Nearest Object' */
} DW_CoreSubsys_Simulation5Draf_T;

/* Block signals (default storage) */
typedef struct {
  real_T Sum1[31];                     /* '<S8>/Sum1' */
  real32_T ImpAsg_InsertedFor_SensorVa[31];/* '<S9>/Lookup Obstacle Map' */
  real_T MathFunction[3];              /* '<S9>/Math Function' */
  real_T vtow[2];                      /* '<S4>/vtow' */
  real_T ImpAsg_InsertedFor_DistanceArra;
                       /* '<S8>/ImpAsg_InsertedFor_DistanceArray_at_inport_0' */
  real_T v;                            /* '<Root>/Line Folwing' */
  real_T w;                            /* '<Root>/Line Folwing' */
  real_T wr_b;                         /* '<Root>/Chart3' */
  real_T wr_f;                         /* '<Root>/Chart3' */
  real_T wl_b;                         /* '<Root>/Chart2' */
  real_T wl_f;                         /* '<Root>/Chart2' */
  boolean_T TmpRTBAtLineFolwingInport6;/* '<Root>/Random Integer Generator' */
  boolean_T sense4;                    /* '<Root>/sense4' */
  boolean_T sense3;                    /* '<Root>/sense3' */
  boolean_T sense2;                    /* '<Root>/sense2' */
  boolean_T sense1;                    /* '<Root>/sense1' */
  boolean_T RandomIntegerGenerator;    /* '<Root>/Random Integer Generator' */
} B_Simulation5Draft_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_blo_i_T obj; /* '<Root>/sense4' */
  codertarget_arduinobase_blo_i_T obj_h;/* '<Root>/sense3' */
  codertarget_arduinobase_blo_i_T obj_b;/* '<Root>/sense2' */
  codertarget_arduinobase_blo_i_T obj_m;/* '<Root>/sense1' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Right motor forward' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Right motor back' */
  codertarget_arduinobase_block_T obj_my;/* '<Root>/Left motor forward' */
  codertarget_arduinobase_block_T obj_do;/* '<Root>/Left motor back' */
  codertarget_arduinobase_inter_T obj_dc;/* '<Root>/Right PWM' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Left PWM' */
  real_T i;                            /* '<Root>/Line Folwing' */
  real_T n;                            /* '<Root>/Line Folwing' */
  real_T data1;                        /* '<Root>/Line Folwing' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T sfEvent;                     /* '<S6>/Calculate Rotation Matrix' */
  int32_T sfEvent_f;                   /* '<Root>/Line Folwing' */
  int32_T sfEvent_o;                   /* '<Root>/Chart3' */
  int32_T sfEvent_j;                   /* '<Root>/Chart2' */
  uint32_T state;                      /* '<Root>/Random Integer Generator' */
  uint32_T state_f[2];                 /* '<Root>/Random Integer Generator' */
  uint32_T state_p[625];               /* '<Root>/Random Integer Generator' */
  uint32_T method;                     /* '<Root>/Random Integer Generator' */
  uint32_T is_c1_Simulation5Draft;     /* '<Root>/Line Folwing' */
  uint32_T is_c4_Simulation5Draft;     /* '<Root>/Chart3' */
  uint32_T is_c2_Simulation5Draft;     /* '<Root>/Chart2' */
  comm_internal_RandomIntegerGe_T obj_ba;/* '<Root>/Random Integer Generator' */
  uint8_T is_active_c4_mobileRoboticsTrai;/* '<S6>/Calculate Rotation Matrix' */
  uint8_T is_active_c1_Simulation5Draft;/* '<Root>/Line Folwing' */
  uint8_T temporalCounter_i1;          /* '<Root>/Line Folwing' */
  uint8_T is_active_c4_Simulation5Draft;/* '<Root>/Chart3' */
  uint8_T is_active_c2_Simulation5Draft;/* '<Root>/Chart2' */
  boolean_T TmpRTBAtLineFolwingInport6_Buff;/* synthesized block */
  boolean_T objisempty;                /* '<Root>/sense4' */
  boolean_T objisempty_f;              /* '<Root>/sense3' */
  boolean_T objisempty_m;              /* '<Root>/sense2' */
  boolean_T objisempty_h;              /* '<Root>/sense1' */
  boolean_T doneDoubleBufferReInit;    /* '<S6>/Calculate Rotation Matrix' */
  boolean_T objisempty_l;              /* '<Root>/Right motor forward' */
  boolean_T objisempty_a;              /* '<Root>/Right motor back' */
  boolean_T objisempty_p;              /* '<Root>/Right PWM' */
  boolean_T objisempty_b;              /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty;           /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty_d;         /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty_f;         /* '<Root>/Random Integer Generator' */
  boolean_T method_not_empty;          /* '<Root>/Random Integer Generator' */
  boolean_T objisempty_k;              /* '<Root>/Left motor forward' */
  boolean_T objisempty_d;              /* '<Root>/Left motor back' */
  boolean_T objisempty_bx;             /* '<Root>/Left PWM' */
  DW_CoreSubsys_Simulation5Draf_T CoreSubsys[1];/* '<S6>/Subsystem' */
} DW_Simulation5Draft_T;

/* Parameters for system: '<S8>/Look up Sensor Value' */
struct P_CoreSubsys_Simulation5Dra_l_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: mapForSim.scaleFactor
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: size(mapForSim.obsMap,1)
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: -1
                                        * Referenced by: '<S11>/Bias'
                                        */
  real_T Saturation_UpperSat;          /* Expression: size(mapForSim.obsMap,1)-1
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: mapForSim.scaleFactor
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: -1
                                        * Referenced by: '<S11>/Bias1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: size(mapForSim.obsMap,2)-1
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S11>/Saturation1'
                                        */
  real32_T DirectLookupTablenD_table[791911];/* Expression: mapForSim.obsMap
                                              * Referenced by: '<S11>/Direct Lookup Table (n-D)'
                                              */
};

/* Parameters for system: '<S6>/Subsystem' */
struct P_CoreSubsys_Simulation5Draft_T_ {
  real_T Constant_Value[31];       /* Expression: minSenRange:senRes:maxSenRange
                                    * Referenced by: '<S8>/Constant'
                                    */
  P_CoreSubsys_Simulation5Dra_l_T CoreSubsys;/* '<S8>/Look up Sensor Value' */
};

/* Parameters (default storage) */
struct P_Simulation5Draft_T_ {
  real_T InputPWM[173];                /* Variable: InputPWM
                                        * Referenced by:
                                        *   '<Root>/Left Motor LUT'
                                        *   '<Root>/Left Motor LUT1'
                                        */
  real_T WheelSpeed[173];              /* Variable: WheelSpeed
                                        * Referenced by:
                                        *   '<Root>/Left Motor LUT'
                                        *   '<Root>/Left Motor LUT1'
                                        */
  real_T Towlwr_wheelR;                /* Mask Parameter: Towlwr_wheelR
                                        * Referenced by: '<S4>/vtow'
                                        */
  real_T sense1_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/sense1'
                                        */
  real_T sense2_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/sense2'
                                        */
  real_T sense3_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/sense3'
                                        */
  real_T sense4_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/sense4'
                                        */
  real_T Constant_Value;               /* Expression: sensOff(:,1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: sensOff(:,2)
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T changeparameters_Gain[4];
                                /* Expression: [1 -axleLength/2; 1 axleLength/2]
                                 * Referenced by: '<S4>/change parameters'
                                 */
  boolean_T TmpRTBAtLineFolwingInport6_Init;
                          /* Computed Parameter: TmpRTBAtLineFolwingInport6_Init
                           * Referenced by:
                           */
  P_CoreSubsys_Simulation5Draft_T CoreSubsys;/* '<S6>/Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Simulation5Draft_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Simulation5Draft_T Simulation5Draft_P;

/* Block signals (default storage) */
extern B_Simulation5Draft_T Simulation5Draft_B;

/* Block states (default storage) */
extern DW_Simulation5Draft_T Simulation5Draft_DW;

/* External function called from main */
extern void Simulation5Draft_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Simulation5Draft_initialize(void);
extern void Simulation5Draft_step0(void);
extern void Simulation5Draft_step1(void);
extern void Simulation5Draft_step2(void);
extern void Simulation5Draft_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Simulation5Draft_T *const Simulation5Draft_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Simulation5Draft'
 * '<S1>'   : 'Simulation5Draft/Chart2'
 * '<S2>'   : 'Simulation5Draft/Chart3'
 * '<S3>'   : 'Simulation5Draft/Line Folwing'
 * '<S4>'   : 'Simulation5Draft/To wlwr'
 * '<S5>'   : 'Simulation5Draft/Ultrasonic Sensor'
 * '<S6>'   : 'Simulation5Draft/Ultrasonic Sensor/Look up Distance Value'
 * '<S7>'   : 'Simulation5Draft/Ultrasonic Sensor/Look up Distance Value/Calculate Rotation Matrix'
 * '<S8>'   : 'Simulation5Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem'
 * '<S9>'   : 'Simulation5Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value'
 * '<S10>'  : 'Simulation5Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Nearest Object'
 * '<S11>'  : 'Simulation5Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map'
 */
#endif                                 /* RTW_HEADER_Simulation5Draft_h_ */
