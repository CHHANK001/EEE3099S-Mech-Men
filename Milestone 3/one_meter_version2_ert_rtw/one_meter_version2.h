/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: one_meter_version2.h
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

#ifndef RTW_HEADER_one_meter_version2_h_
#define RTW_HEADER_one_meter_version2_h_
#ifndef one_meter_version2_COMMON_INCLUDES_
#define one_meter_version2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* one_meter_version2_COMMON_INCLUDES_ */

#include "one_meter_version2_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T vtow[2];                      /* '<S3>/vtow' */
  real_T DriveDist;                    /* '<Root>/DriveDist' */
  real_T wr_b;                         /* '<Root>/Chart3' */
  real_T wr_f;                         /* '<Root>/Chart3' */
  real_T x;                            /* '<Root>/Chart' */
  boolean_T ticks;                     /* '<Root>/Left encoder' */
} B_one_meter_version2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Left encoder' */
  codertarget_arduinobase_blo_h_T obj_e;/* '<Root>/Right motor forward' */
  codertarget_arduinobase_blo_h_T obj_j;/* '<Root>/Right motor back' */
  codertarget_arduinobase_blo_h_T obj_m;/* '<Root>/Left motor forward' */
  codertarget_arduinobase_blo_h_T obj_a;/* '<Root>/Left motor back' */
  codertarget_arduinobase_inter_T obj_ac;/* '<Root>/Right PWM' */
  codertarget_arduinobase_inter_T obj_b;/* '<Root>/Left PWM' */
  real_T reqTicks;                     /* '<Root>/Chart' */
  real_T i;                            /* '<Root>/Chart' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  uint32_T is_c4_one_meter_version2;   /* '<Root>/Chart3' */
  uint32_T is_c3_one_meter_version2;   /* '<Root>/Chart' */
  uint8_T is_active_c4_one_meter_version2;/* '<Root>/Chart3' */
  uint8_T is_active_c3_one_meter_version2;/* '<Root>/Chart' */
} DW_one_meter_version2_T;

/* Parameters (default storage) */
struct P_one_meter_version2_T_ {
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
  real_T wheelR;                       /* Variable: wheelR
                                        * Referenced by: '<S3>/vtow'
                                        */
  real_T Leftencoder_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Left encoder'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T changeparameters_Gain[4];
                                /* Expression: [1 -axleLength/2; 1 axleLength/2]
                                 * Referenced by: '<S3>/change parameters'
                                 */
  real_T DriveDist_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/DriveDist'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_one_meter_version2_T {
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
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_one_meter_version2_T one_meter_version2_P;

/* Block signals (default storage) */
extern B_one_meter_version2_T one_meter_version2_B;

/* Block states (default storage) */
extern DW_one_meter_version2_T one_meter_version2_DW;

/* Model entry point functions */
extern void one_meter_version2_initialize(void);
extern void one_meter_version2_step(void);
extern void one_meter_version2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_one_meter_version2_T *const one_meter_version2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/Switch' : Unused code path elimination
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
 * '<Root>' : 'one_meter_version2'
 * '<S1>'   : 'one_meter_version2/Chart'
 * '<S2>'   : 'one_meter_version2/Chart3'
 * '<S3>'   : 'one_meter_version2/To wlwr'
 */
#endif                                 /* RTW_HEADER_one_meter_version2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
