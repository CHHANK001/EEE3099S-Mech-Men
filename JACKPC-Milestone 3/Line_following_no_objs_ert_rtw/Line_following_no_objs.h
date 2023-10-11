/*
 * Line_following_no_objs.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Line_following_no_objs".
 *
 * Model version              : 5.22
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Oct  5 17:04:01 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Line_following_no_objs_h_
#define RTW_HEADER_Line_following_no_objs_h_
#ifndef Line_following_no_objs_COMMON_INCLUDES_
#define Line_following_no_objs_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#include "MW_Ultrasonic.h"
#endif                             /* Line_following_no_objs_COMMON_INCLUDES_ */

#include "Line_following_no_objs_types.h"
#include <string.h>
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T v;                            /* '<Root>/Line Folwing' */
  real_T w;                            /* '<Root>/Line Folwing' */
  boolean_T TmpRTBAtLineFolwingInport5;/* '<Root>/Random Integer Generator' */
  boolean_T sense4;                    /* '<Root>/sense4' */
  boolean_T sense3;                    /* '<Root>/sense3' */
  boolean_T sense2;                    /* '<Root>/sense2' */
  boolean_T sense1;                    /* '<Root>/sense1' */
} B_Line_following_no_objs_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_blo_k_T obj; /* '<Root>/sense4' */
  codertarget_arduinobase_blo_k_T obj_h;/* '<Root>/sense3' */
  codertarget_arduinobase_blo_k_T obj_b;/* '<Root>/sense2' */
  codertarget_arduinobase_blo_k_T obj_m;/* '<Root>/sense1' */
  codertarget_arduinobase_block_T obj_hn;/* '<Root>/Right motor forward' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Right motor back' */
  codertarget_arduinobase_block_T obj_k;/* '<Root>/Left motor forward' */
  codertarget_arduinobase_block_T obj_m4;/* '<Root>/Left motor back' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Right PWM' */
  codertarget_arduinobase_inter_T obj_f;/* '<Root>/Left PWM' */
  real_T i;                            /* '<Root>/Line Folwing' */
  codertarget_arduinobase_int_k_T obj_bs;/* '<Root>/Ultrasonic Sensor' */
  uint32_T state;                      /* '<Root>/Random Integer Generator' */
  uint32_T state_f[2];                 /* '<Root>/Random Integer Generator' */
  uint32_T state_p[625];               /* '<Root>/Random Integer Generator' */
  uint32_T method;                     /* '<Root>/Random Integer Generator' */
  comm_internal_RandomIntegerGe_T obj_ba;/* '<Root>/Random Integer Generator' */
  uint8_T is_active_c1_Line_following_no_;/* '<Root>/Line Folwing' */
  uint8_T is_c1_Line_following_no_objs;/* '<Root>/Line Folwing' */
  uint8_T temporalCounter_i1;          /* '<Root>/Line Folwing' */
  boolean_T TmpRTBAtLineFolwingInport5_Buff;/* synthesized block */
  boolean_T objisempty;                /* '<Root>/sense4' */
  boolean_T objisempty_f;              /* '<Root>/sense3' */
  boolean_T objisempty_m;              /* '<Root>/sense2' */
  boolean_T objisempty_h;              /* '<Root>/sense1' */
  boolean_T objisempty_d;              /* '<Root>/Ultrasonic Sensor' */
  boolean_T objisempty_n;              /* '<Root>/Right motor forward' */
  boolean_T objisempty_l;              /* '<Root>/Right motor back' */
  boolean_T objisempty_mf;             /* '<Root>/Right PWM' */
  boolean_T objisempty_b;              /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty;           /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty_d;         /* '<Root>/Random Integer Generator' */
  boolean_T state_not_empty_f;         /* '<Root>/Random Integer Generator' */
  boolean_T method_not_empty;          /* '<Root>/Random Integer Generator' */
  boolean_T objisempty_e;              /* '<Root>/Left motor forward' */
  boolean_T objisempty_hc;             /* '<Root>/Left motor back' */
  boolean_T objisempty_j;              /* '<Root>/Left PWM' */
} DW_Line_following_no_objs_T;

/* Parameters (default storage) */
struct P_Line_following_no_objs_T_ {
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
                                        * Referenced by: '<S2>/vtow'
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
  boolean_T TmpRTBAtLineFolwingInport5_Init;
                          /* Computed Parameter: TmpRTBAtLineFolwingInport5_Init
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Line_following_no_obj_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Line_following_no_objs_T Line_following_no_objs_P;

/* Block signals (default storage) */
extern B_Line_following_no_objs_T Line_following_no_objs_B;

/* Block states (default storage) */
extern DW_Line_following_no_objs_T Line_following_no_objs_DW;

/* External function called from main */
extern void Line_following_no_objs_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Line_following_no_objs_initialize(void);
extern void Line_following_no_objs_step0(void);
extern void Line_following_no_objs_step1(void);
extern void Line_following_no_objs_step2(void);
extern void Line_following_no_objs_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Line_following_no_ob_T *const Line_following_no_objs_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
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
 * '<Root>' : 'Line_following_no_objs'
 * '<S1>'   : 'Line_following_no_objs/Line Folwing'
 * '<S2>'   : 'Line_following_no_objs/To wlwr'
 */
#endif                                /* RTW_HEADER_Line_following_no_objs_h_ */
