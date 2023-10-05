/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: one_meter.h
 *
 * Code generated for Simulink model 'one_meter'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Oct  4 13:15:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_one_meter_h_
#define RTW_HEADER_one_meter_h_
#ifndef one_meter_COMMON_INCLUDES_
#define one_meter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* one_meter_COMMON_INCLUDES_ */

#include "one_meter_types.h"
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
  real_T ticks;                        /* '<Root>/Chart1' */
  real_T v;                            /* '<Root>/Chart' */
} B_one_meter_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Left encoder' */
  codertarget_arduinobase_blo_d_T obj_e;/* '<Root>/Right motor' */
  codertarget_arduinobase_blo_d_T obj_m;/* '<Root>/Left motor' */
  real_T reqTicks;                     /* '<Root>/Chart' */
  uint8_T is_active_c1_one_meter;      /* '<Root>/Chart1' */
  uint8_T is_c1_one_meter;             /* '<Root>/Chart1' */
  uint8_T is_active_c3_one_meter;      /* '<Root>/Chart' */
  uint8_T is_c3_one_meter;             /* '<Root>/Chart' */
} DW_one_meter_T;

/* Parameters (default storage) */
struct P_one_meter_T_ {
  real_T Towlwr_wheelR;                /* Mask Parameter: Towlwr_wheelR
                                        * Referenced by: '<S3>/vtow'
                                        */
  real_T Leftencoder_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Left encoder'
                                        */
  real_T DriveDist_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/DriveDist'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T changeparameters_Gain[4];
                                /* Expression: [1 -axleLength/2; 1 axleLength/2]
                                 * Referenced by: '<S3>/change parameters'
                                 */
};

/* Real-time Model Data Structure */
struct tag_RTM_one_meter_T {
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
extern P_one_meter_T one_meter_P;

/* Block signals (default storage) */
extern B_one_meter_T one_meter_B;

/* Block states (default storage) */
extern DW_one_meter_T one_meter_DW;

/* Model entry point functions */
extern void one_meter_initialize(void);
extern void one_meter_step(void);
extern void one_meter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_one_meter_T *const one_meter_M;
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
 * '<Root>' : 'one_meter'
 * '<S1>'   : 'one_meter/Chart'
 * '<S2>'   : 'one_meter/Chart1'
 * '<S3>'   : 'one_meter/To wlwr'
 */
#endif                                 /* RTW_HEADER_one_meter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
