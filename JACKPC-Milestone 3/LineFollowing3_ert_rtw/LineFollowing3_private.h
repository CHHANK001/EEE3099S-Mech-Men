/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LineFollowing3_private.h
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

#ifndef RTW_HEADER_LineFollowing3_private_h_
#define RTW_HEADER_LineFollowing3_private_h_
#include "rtwtypes.h"
#include "LineFollowing3_types.h"
#include "LineFollowing3.h"

extern real_T rt_roundd_snf(real_T u);
extern uint32_T plook_u32d_binckan(real_T u, const real_T bp[], uint32_T
  maxIndex);
extern uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);

#endif                                /* RTW_HEADER_LineFollowing3_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
