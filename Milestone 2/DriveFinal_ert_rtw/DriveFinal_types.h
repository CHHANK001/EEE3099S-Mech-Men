/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DriveFinal_types.h
 *
 * Code generated for Simulink model 'DriveFinal'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Oct  3 15:23:27 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DriveFinal_types_h_
#define RTW_HEADER_DriveFinal_types_h_
#include "rtwtypes.h"
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

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_mPMPiw8t0JZKYO8orfnwRG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

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

#ifndef typedef_codertarget_arduinobase_blo_g_T
#define typedef_codertarget_arduinobase_blo_g_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG codertarget_arduinobase_blo_g_T;

#endif                             /* typedef_codertarget_arduinobase_blo_g_T */

/* Parameters (default storage) */
typedef struct P_DriveFinal_T_ P_DriveFinal_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_DriveFinal_T RT_MODEL_DriveFinal_T;

#endif                                 /* RTW_HEADER_DriveFinal_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
