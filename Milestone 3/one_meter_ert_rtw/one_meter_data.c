/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: one_meter_data.c
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

#include "one_meter.h"

/* Block parameters (default storage) */
P_one_meter_T one_meter_P = {
  /* Mask Parameter: Towlwr_wheelR
   * Referenced by: '<S3>/vtow'
   */
  0.05,

  /* Expression: 0.1
   * Referenced by: '<Root>/Left encoder'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<Root>/DriveDist'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: [1 -axleLength/2; 1 axleLength/2]
   * Referenced by: '<S3>/change parameters'
   */
  { 1.0, 1.0, -0.05, 0.05 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
