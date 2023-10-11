/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LineFollowing3.h
 *
 * Code generated for Simulink model 'LineFollowing3'.
 *
 * Model version                  : 5.33
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Oct  9 16:36:07 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LineFollowing3_h_
#define RTW_HEADER_LineFollowing3_h_
#ifndef LineFollowing3_COMMON_INCLUDES_
#define LineFollowing3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#include "MW_Ultrasonic.h"
#endif                                 /* LineFollowing3_COMMON_INCLUDES_ */

#include "LineFollowing3_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T w;                            /* '<Root>/Line Following' */
  real_T v;                            /* '<Root>/Line Following' */
  boolean_T sense4;                    /* '<Root>/sense4' */
  boolean_T sense3;                    /* '<Root>/sense3' */
  boolean_T sense2;                    /* '<Root>/sense2' */
  boolean_T sense1;                    /* '<Root>/sense1' */
} B_LineFollowing3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_bloc_j_T obj;/* '<Root>/sense4' */
  codertarget_arduinobase_bloc_j_T obj_h;/* '<Root>/sense3' */
  codertarget_arduinobase_bloc_j_T obj_b;/* '<Root>/sense2' */
  codertarget_arduinobase_bloc_j_T obj_m;/* '<Root>/sense1' */
  codertarget_arduinobase_blocks_T obj_hn;/* '<Root>/Right motor forward' */
  codertarget_arduinobase_blocks_T obj_d;/* '<Root>/Right motor back' */
  codertarget_arduinobase_blocks_T obj_k;/* '<Root>/Left motor forward' */
  codertarget_arduinobase_blocks_T obj_m4;/* '<Root>/Left motor back' */
  codertarget_arduinobase_intern_T obj_p;/* '<Root>/Right PWM' */
  codertarget_arduinobase_intern_T obj_f;/* '<Root>/Left PWM' */
  codertarget_arduinobase_inte_j_T obj_bs;/* '<Root>/Ultrasonic Sensor' */
  uint32_T state;                      /* '<Root>/Random Integer Generator' */
  uint32_T state_c[2];                 /* '<Root>/Random Integer Generator' */
  uint32_T state_m[625];               /* '<Root>/Random Integer Generator' */
  uint32_T method;                     /* '<Root>/Random Integer Generator' */
  uint8_T is_active_c1_LineFollowing3; /* '<Root>/Line Following' */
  uint8_T is_c1_LineFollowing3;        /* '<Root>/Line Following' */
  uint8_T temporalCounter_i1;          /* '<Root>/Line Following' */
} DW_LineFollowing3_T;

/* Parameters (default storage) */
struct P_LineFollowing3_T_ {
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
  real_T Gain_Gain;                    /* Expression: 1.1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LineFollowing3_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_LineFollowing3_T LineFollowing3_P;

/* Block signals (default storage) */
extern B_LineFollowing3_T LineFollowing3_B;

/* Block states (default storage) */
extern DW_LineFollowing3_T LineFollowing3_DW;

/* Model entry point functions */
extern void LineFollowing3_initialize(void);
extern void LineFollowing3_step(void);
extern void LineFollowing3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LineFollowing3_T *const LineFollowing3_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Distance' : Unused code path elimination
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
 * '<Root>' : 'LineFollowing3'
 * '<S1>'   : 'LineFollowing3/Line Following'
 */
#endif                                 /* RTW_HEADER_LineFollowing3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
