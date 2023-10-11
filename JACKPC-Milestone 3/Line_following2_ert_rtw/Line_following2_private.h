/*
 * Line_following2_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Line_following2".
 *
 * Model version              : 5.23
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Oct  6 15:35:16 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Line_following2_private_h_
#define RTW_HEADER_Line_following2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Line_following2_types.h"
#include "Line_following2.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern uint32_T plook_u32d_binckan(real_T u, const real_T bp[], uint32_T
  maxIndex);
extern uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);

#endif                               /* RTW_HEADER_Line_following2_private_h_ */
