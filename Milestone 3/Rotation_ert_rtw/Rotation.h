/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Rotation.h
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

#ifndef RTW_HEADER_Rotation_h_
#define RTW_HEADER_Rotation_h_
#ifndef Rotation_COMMON_INCLUDES_
#define Rotation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Rotation_COMMON_INCLUDES_ */

#include "Rotation_types.h"
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
  real_T DriveRot;                     /* '<Root>/DriveRot' */
  real_T LeftPWM;                      /* '<Root>/Left Motor LUT' */
  real_T x;                            /* '<Root>/Chart' */
  real_T tks;                          /* '<Root>/Chart' */
  boolean_T LeftEncoderTick;           /* '<Root>/Left encoder' */
} B_Rotation_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Left encoder' */
  codertarget_arduinobase_blo_b_T obj_b;/* '<Root>/Right motor forward' */
  codertarget_arduinobase_blo_b_T obj_d;/* '<Root>/Right motor back' */
  codertarget_arduinobase_blo_b_T obj_p;/* '<Root>/Left motor forward' */
  codertarget_arduinobase_blo_b_T obj_e;/* '<Root>/Left motor back' */
  codertarget_arduinobase_inter_T obj_i;/* '<Root>/Right PWM' */
  codertarget_arduinobase_inter_T obj_if;/* '<Root>/Left PWM' */
  real_T degrees1tick;                 /* '<Root>/Chart' */
  real_T reqTicks;                     /* '<Root>/Chart' */
  real_T i;                            /* '<Root>/Chart' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  uint32_T is_c3_Rotation;             /* '<Root>/Chart' */
  uint8_T is_active_c3_Rotation;       /* '<Root>/Chart' */
} DW_Rotation_T;

/* Parameters (default storage) */
struct P_Rotation_T_ {
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
                                        * Referenced by: '<S2>/vtow'
                                        */
  real_T Leftencoder_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Left encoder'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DriveRot_Value;               /* Expression: pi/2
                                        * Referenced by: '<Root>/DriveRot'
                                        */
  real_T changeparameters_Gain[4];
                                /* Expression: [1 -axleLength/2; 1 axleLength/2]
                                 * Referenced by: '<S2>/change parameters'
                                 */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Rotation_T {
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
extern P_Rotation_T Rotation_P;

/* Block signals (default storage) */
extern B_Rotation_T Rotation_B;

/* Block states (default storage) */
extern DW_Rotation_T Rotation_DW;

/* Model entry point functions */
extern void Rotation_initialize(void);
extern void Rotation_step(void);
extern void Rotation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rotation_T *const Rotation_M;
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
 * '<Root>' : 'Rotation'
 * '<S1>'   : 'Rotation/Chart'
 * '<S2>'   : 'Rotation/To wlwr1'
 */
#endif                                 /* RTW_HEADER_Rotation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
