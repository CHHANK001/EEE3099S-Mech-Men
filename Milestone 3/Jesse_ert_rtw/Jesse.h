/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Jesse.h
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

#ifndef RTW_HEADER_Jesse_h_
#define RTW_HEADER_Jesse_h_
#ifndef Jesse_COMMON_INCLUDES_
#define Jesse_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Jesse_COMMON_INCLUDES_ */

#include "Jesse_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Left encoder' */
  codertarget_arduinobase_blo_l_T obj_e;/* '<Root>/Right motor forward' */
  codertarget_arduinobase_blo_l_T obj_j;/* '<Root>/Right motor back' */
  codertarget_arduinobase_blo_l_T obj_m;/* '<Root>/Left motor forward' */
  codertarget_arduinobase_blo_l_T obj_a;/* '<Root>/Left motor back' */
  codertarget_arduinobase_inter_T obj_ac;/* '<Root>/Right PWM' */
  codertarget_arduinobase_inter_T obj_b;/* '<Root>/Left PWM' */
  real_T reqTicks;                     /* '<Root>/Chart' */
  real_T i;                            /* '<Root>/Chart' */
  uint8_T is_active_c3_Jesse;          /* '<Root>/Chart' */
  uint8_T is_c3_Jesse;                 /* '<Root>/Chart' */
} DW_Jesse_T;

/* Parameters (default storage) */
struct P_Jesse_T_ {
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
  real_T DriveDist_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/DriveDist'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
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
struct tag_RTM_Jesse_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Jesse_T Jesse_P;

/* Block states (default storage) */
extern DW_Jesse_T Jesse_DW;

/* Model entry point functions */
extern void Jesse_initialize(void);
extern void Jesse_step(void);
extern void Jesse_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Jesse_T *const Jesse_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'Jesse'
 * '<S1>'   : 'Jesse/Chart'
 * '<S2>'   : 'Jesse/To wlwr'
 */
#endif                                 /* RTW_HEADER_Jesse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
