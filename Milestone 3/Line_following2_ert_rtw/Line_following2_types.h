/*
 * Line_following2_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Line_following2".
 *
 * Model version              : 5.21
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Oct  5 15:36:20 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Line_following2_types_h_
#define RTW_HEADER_Line_following2_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<Root>/Right PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_g_matlabshared_ioclient_perip_T
#define typedef_g_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN g_matlabshared_ioclient_perip_T;

#endif                             /* typedef_g_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_qrLkTWTW64zZK0sqwALTyG
#define struct_tag_qrLkTWTW64zZK0sqwALTyG

struct tag_qrLkTWTW64zZK0sqwALTyG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_qrLkTWTW64zZK0sqwALTyG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_hWgtZAPqSjs1EyhETh9jYH
#define struct_tag_hWgtZAPqSjs1EyhETh9jYH

struct tag_hWgtZAPqSjs1EyhETh9jYH
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_hWgtZAPqSjs1EyhETh9jYH */

#ifndef typedef_comm_internal_RandomIntegerGe_T
#define typedef_comm_internal_RandomIntegerGe_T

typedef struct tag_hWgtZAPqSjs1EyhETh9jYH comm_internal_RandomIntegerGe_T;

#endif                             /* typedef_comm_internal_RandomIntegerGe_T */

#ifndef struct_tag_jShWpKUOycwBMhFyiKcKhC
#define struct_tag_jShWpKUOycwBMhFyiKcKhC

struct tag_jShWpKUOycwBMhFyiKcKhC
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
};

#endif                                 /* struct_tag_jShWpKUOycwBMhFyiKcKhC */

#ifndef typedef_codertarget_arduinobase_int_b_T
#define typedef_codertarget_arduinobase_int_b_T

typedef struct tag_jShWpKUOycwBMhFyiKcKhC codertarget_arduinobase_int_b_T;

#endif                             /* typedef_codertarget_arduinobase_int_b_T */

#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_d_arduinodriver_ArduinoDigita_T
#define typedef_d_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C d_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_d_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_mPMPiw8t0JZKYO8orfnwRG
#define struct_tag_mPMPiw8t0JZKYO8orfnwRG

struct tag_mPMPiw8t0JZKYO8orfnwRG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_mPMPiw8t0JZKYO8orfnwRG */

#ifndef typedef_codertarget_arduinobase_blo_b_T
#define typedef_codertarget_arduinobase_blo_b_T

typedef struct tag_mPMPiw8t0JZKYO8orfnwRG codertarget_arduinobase_blo_b_T;

#endif                             /* typedef_codertarget_arduinobase_blo_b_T */

/* Parameters (default storage) */
typedef struct P_Line_following2_T_ P_Line_following2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Line_following2_T RT_MODEL_Line_following2_T;

#endif                                 /* RTW_HEADER_Line_following2_types_h_ */
