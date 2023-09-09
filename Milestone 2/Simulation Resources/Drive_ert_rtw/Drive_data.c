/*
 * Drive_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Drive".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Sep  9 15:32:05 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Drive.h"

/* Block parameters (default storage) */
P_Drive_T Drive_P = {
  /* Variable: InputPWM
   * Referenced by:
   *   '<Root>/Left Motor LUT'
   *   '<Root>/Right Motor LUT'
   */
  { -127.0, -126.0, -125.0, -124.0, -123.0, -122.0, -121.0, -120.0, -119.0,
    -118.0, -117.0, -116.0, -115.0, -114.0, -113.0, -112.0, -111.0, -110.0,
    -109.0, -108.0, -107.0, -106.0, -105.0, -104.0, -103.0, -102.0, -101.0,
    -100.0, -99.0, -98.0, -97.0, -96.0, -95.0, -94.0, -93.0, -92.0, -91.0, -90.0,
    -89.0, -88.0, -87.0, -86.0, -85.0, -84.0, -83.0, -82.0, -81.0, -80.0, -79.0,
    -78.0, -77.0, -76.0, -75.0, -74.0, -73.0, -72.0, -71.0, -70.0, -69.0, -68.0,
    -67.0, -66.0, -65.0, -64.0, -63.0, -62.0, -61.0, -60.0, -59.0, -58.0, -57.0,
    -56.0, -55.0, -54.0, -53.0, -52.0, -51.0, -50.0, -49.0, -48.0, -47.0, -46.0,
    -45.0, -44.0, -43.0, -42.0, 0.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0,
    49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0,
    62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0,
    75.0, 76.0, 77.0, 78.0, 79.0, 80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0,
    88.0, 89.0, 90.0, 91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0,
    100.0, 101.0, 102.0, 103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0,
    111.0, 112.0, 113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0,
    122.0, 123.0, 124.0, 125.0, 126.0, 127.0 },

  /* Variable: WheelSpeed
   * Referenced by:
   *   '<Root>/Left Motor LUT'
   *   '<Root>/Right Motor LUT'
   */
  { -12.5105278523077, -12.3751973907692, -12.2398669292308, -12.1045364676923,
    -11.9692060061538, -11.8338755446154, -11.6985450830769, -11.5632146215385,
    -11.42788416, -11.2925536984615, -11.1572232369231, -11.0218927753846,
    -10.8865623138461, -10.7512318523077, -10.6159013907692, -10.4805709292308,
    -10.3452404676923, -10.2099100061538, -10.0745795446154, -9.93924908307692,
    -9.80391862153846, -9.66858816, -9.53325769846154, -9.39792723692308,
    -9.26259677538462, -9.12726631384615, -8.99193585230769, -8.85660539076923,
    -8.72127492923077, -8.58594446769231, -8.45061400615385, -8.31528354461539,
    -8.17995308307692, -8.04462262153846, -7.90929216, -7.77396169846154,
    -7.63863123692308, -7.50330077538462, -7.36797031384615, -7.23263985230769,
    -7.09730939076923, -6.96197892923077, -6.82664846769231, -6.69131800615385,
    -6.55598754461539, -6.42065708307692, -6.28532662153846, -6.14999616,
    -6.01466569846154, -5.87933523692308, -5.74400477538462, -5.60867431384616,
    -5.47334385230769, -5.33801339076923, -5.20268292923077, -5.06735246769231,
    -4.93202200615385, -4.79669154461538, -4.66136108307692, -4.52603062153846,
    -4.39070016, -4.303992, -4.178328, -4.021248, -3.8327519999999997,
    -3.6442559999999995, -3.518592, -3.4557599999999997, -3.3300959999999997,
    -3.204432, -3.015936, -2.890272, -2.7646079999999995, -2.576112, -2.51328,
    -2.3562, -2.1677039999999996, -2.1362879999999995, -1.9163759999999999,
    -1.790712, -1.633632, -1.5708, -1.445136, -1.3508879999999999,
    -1.1623919999999999, -1.005312, 0.0, 1.005312, 1.1623919999999999,
    1.3508879999999999, 1.445136, 1.5708, 1.633632, 1.790712, 1.9163759999999999,
    2.1362879999999995, 2.1677039999999996, 2.3562, 2.51328, 2.576112,
    2.7646079999999995, 2.890272, 3.015936, 3.204432, 3.3300959999999997,
    3.4557599999999997, 3.518592, 3.6442559999999995, 3.8327519999999997,
    4.021248, 4.178328, 4.303992, 4.39070016, 4.52603062153846, 4.66136108307692,
    4.79669154461538, 4.93202200615384, 5.06735246769231, 5.20268292923077,
    5.33801339076923, 5.47334385230769, 5.60867431384615, 5.74400477538461,
    5.87933523692307, 6.01466569846154, 6.14999616, 6.28532662153846,
    6.42065708307692, 6.55598754461538, 6.69131800615384, 6.8266484676923,
    6.96197892923077, 7.09730939076923, 7.23263985230769, 7.36797031384615,
    7.50330077538461, 7.63863123692307, 7.77396169846154, 7.90929216,
    8.04462262153846, 8.17995308307692, 8.31528354461538, 8.45061400615384,
    8.5859444676923, 8.72127492923077, 8.85660539076923, 8.99193585230769,
    9.12726631384615, 9.26259677538461, 9.39792723692307, 9.53325769846153,
    9.66858816, 9.80391862153846, 9.93924908307692, 10.0745795446154,
    10.2099100061538, 10.3452404676923, 10.4805709292308, 10.6159013907692,
    10.7512318523077, 10.8865623138462, 11.0218927753847, 11.1572232369231,
    11.2925536984616, 11.42788416, 11.5632146215385, 11.698545083077,
    11.8338755446154, 11.9692060061539, 12.1045364676923, 12.2398669292308,
    12.3751973907693, 12.5105278523077 },

  /* Variable: axleLength
   * Referenced by: '<S5>/Wheel Spacing'
   */
  0.136,

  /* Variable: lineLength
   * Referenced by: '<S5>/Constant'
   */
  0.066666666666666666,

  /* Variable: ticksPerRot
   * Referenced by:
   *   '<Root>/Gain'
   *   '<Root>/Gain1'
   *   '<S2>/Gain5'
   *   '<S2>/Gain6'
   */
  20.0,

  /* Variable: wheelR
   * Referenced by:
   *   '<Root>/Gain'
   *   '<Root>/Gain1'
   *   '<S5>/Wheel Radius'
   */
  0.031,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S38>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S41>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by:
   *   '<S48>/Saturation'
   *   '<S34>/DeadZone'
   */
  -0.67,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S46>/Proportional Gain'
   */
  5.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by:
   *   '<S48>/Saturation'
   *   '<S34>/DeadZone'
   */
  0.67,

  /* Mask Parameter: LeftMotor_sensorType
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Mask Parameter: RightMotor_sensorType
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Mask Parameter: RobotSimulator_startTheta
   * Referenced by: '<S5>/Discrete-Time Integrator2'
   */
  90.0,

  /* Mask Parameter: RobotSimulator_startX
   * Referenced by: '<S5>/Discrete-Time Integrator'
   */
  0.5,

  /* Mask Parameter: RobotSimulator_startY
   * Referenced by: '<S5>/Discrete-Time Integrator1'
   */
  0.1,

  /* Mask Parameter: Towlwr_wheelR
   * Referenced by: '<S6>/vtow'
   */
  0.05,

  /* Expression: 180/pi
   * Referenced by: '<S59>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S63>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S32>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/DriveDist'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator1'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Gain2'
   */
  0.5,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S41>/Integrator'
   */
  0.01,

  /* Expression: [1 -axleLength/2; 1 axleLength/2]
   * Referenced by: '<S6>/change parameters'
   */
  { 1.0, 1.0, -0.05, 0.05 },

  /* Expression: 0
   * Referenced by: '<S32>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
   * Referenced by: '<S5>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainv_f
   * Referenced by: '<S5>/Discrete-Time Integrator1'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<S5>/Discrete-Time Integrator2'
   */
  0.01,

  /* Expression: 2*pi
   * Referenced by: '<S5>/Circle'
   */
  6.2831853071795862,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_nq
   * Referenced by: '<S3>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S3>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: Internal_A
   * Referenced by: '<S58>/Internal'
   */
  { 0.98080770808893936, -0.0028909610471093169, 0.0017089158639059857,
    0.0016333883819315276, 0.97809563881626427, -0.090636917153136778,
    0.033546615335257664, -0.046099327413318673, -0.71802525387941019 },

  /* Computed Parameter: Internal_B
   * Referenced by: '<S58>/Internal'
   */
  { 8.8292921540154625E-5, -0.011573230386956162, -0.20490427974686826 },

  /* Computed Parameter: Internal_C
   * Referenced by: '<S58>/Internal'
   */
  { -15.148808791498743, -1.7306547848144382, -0.050339133175597683 },

  /* Expression: 1
   * Referenced by: '<S3>/Switch'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: Internal_A_h
   * Referenced by: '<S62>/Internal'
   */
  { 0.98080770808893936, -0.0028909610471093169, 0.0017089158639059857,
    0.0016333883819315276, 0.97809563881626427, -0.090636917153136778,
    0.033546615335257664, -0.046099327413318673, -0.71802525387941019 },

  /* Computed Parameter: Internal_B_p
   * Referenced by: '<S62>/Internal'
   */
  { 8.8292921540154625E-5, -0.011573230386956162, -0.20490427974686826 },

  /* Computed Parameter: Internal_C_i
   * Referenced by: '<S62>/Internal'
   */
  { -15.148808791498743, -1.7306547848144382, -0.050339133175597683 },

  /* Expression: 1
   * Referenced by: '<S4>/Switch'
   */
  1.0,

  /* Expression: 1/2
   * Referenced by: '<S5>/Gain1'
   */
  0.5,

  /* Expression: (180/pi)
   * Referenced by: '<S2>/Gain3'
   */
  57.295779513082323,

  /* Expression: (180/pi)
   * Referenced by: '<S2>/Gain2'
   */
  57.295779513082323,

  /* Computed Parameter: SoftRealTime_P1_Size
   * Referenced by: '<S5>/Soft Real Time'
   */
  { 1.0, 1.0 },

  /* Expression: x
   * Referenced by: '<S5>/Soft Real Time'
   */
  1.0,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S32>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S32>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S32>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S32>/Constant4'
   */
  -1
};
