/*
 * Simulation4Draft.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulation4Draft".
 *
 * Model version              : 5.10
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Sep  9 13:48:00 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Simulation4Draft.h"
#include "rtwtypes.h"
#include <string.h>
#include "Simulation4Draft_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>

/* Named constants for Chart: '<Root>/Line Following' */
#define Simulation4D_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Simulation4Dr_IN_ObjectDetected ((uint8_T)8U)
#define Simulation4Dra_IN_CorrectRight1 ((uint8_T)4U)
#define Simulation4Draf_IN_CorrectLeft1 ((uint8_T)2U)
#define Simulation4Draf_IN_CorrectRight ((uint8_T)3U)
#define Simulation4Draft_IN_CorrectLeft ((uint8_T)1U)
#define Simulation4Draft_IN_Drive      ((uint8_T)5U)
#define Simulation4Draft_IN_End        ((uint8_T)6U)
#define Simulation4Draft_IN_EndOfLine  ((uint8_T)7U)
#define Simulation4Draft_IN_Random     ((uint8_T)9U)
#define Simulation4Draft_IN_TurnAround1 ((uint8_T)10U)
#define Simulation4Draft_IN_TurnLeft   ((uint8_T)11U)
#define Simulation4Draft_IN_TurnRight  ((uint8_T)12U)
#define Simulation4Draft_IN_checkEnd   ((uint8_T)13U)
#define Simulation4Draft_IN_notEnd     ((uint8_T)14U)

/* Block signals (default storage) */
B_Simulation4Draft_T Simulation4Draft_B;

/* Block states (default storage) */
DW_Simulation4Draft_T Simulation4Draft_DW;

/* Real-time model */
static RT_MODEL_Simulation4Draft_T Simulation4Draft_M_;
RT_MODEL_Simulation4Draft_T *const Simulation4Draft_M = &Simulation4Draft_M_;

/* Forward declaration for local functions */
static void Simulation4Draft_Drive(void);
static real_T Simulation4Draft_rand(void);
static void rate_monotonic_scheduler(void);
uint32_T plook_u32d_binckan(real_T u, const real_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Simulation4Draft_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Simulation4Draft_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Simulation4Draft_M->Timing.TaskCounters.TID[2])++;
  if ((Simulation4Draft_M->Timing.TaskCounters.TID[2]) > 299) {/* Sample time: [3.0s, 0.0s] */
    Simulation4Draft_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Function for Chart: '<Root>/Line Following' */
static void Simulation4Draft_Drive(void)
{
  boolean_T tmp;
  Simulation4Draft_B.v = 0.05;
  Simulation4Draft_B.w = 0.0;
  if ((Simulation4Draft_B.Switch[0] == 0.0) && (Simulation4Draft_B.Switch[1] ==
       0.0) && (Simulation4Draft_B.Switch[2] == 0.0) &&
      (Simulation4Draft_B.Switch[3] == 0.0)) {
    Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_checkEnd;
    Simulation4Draft_DW.temporalCounter_i1 = 0U;
  } else if ((Simulation4Draft_B.Switch[1] == 1.0) &&
             (Simulation4Draft_B.Switch[2] == 0.0) &&
             (Simulation4Draft_B.Switch[0] == 1.0) &&
             (Simulation4Draft_B.Switch[3] == 1.0)) {
    Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draf_IN_CorrectRight;
    Simulation4Draft_B.v = 0.01;
    Simulation4Draft_B.w = -0.8;
  } else {
    tmp = ((Simulation4Draft_DW.temporalCounter_i1 >= 50U) &&
           (Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
            == 0.0));
    if (tmp && (Simulation4Draft_B.Switch[3] == 0.0) &&
        (Simulation4Draft_B.Switch[0] == 1.0)) {
      Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_TurnRight;
      Simulation4Draft_DW.temporalCounter_i1 = 0U;
      Simulation4Draft_B.v = 0.01;
      Simulation4Draft_B.w = -0.4;
    } else if ((Simulation4Draft_B.Switch[1] == 0.0) &&
               (Simulation4Draft_B.Switch[2] == 1.0) &&
               (Simulation4Draft_B.Switch[0] == 1.0) &&
               (Simulation4Draft_B.Switch[3] == 1.0)) {
      Simulation4Draft_DW.is_c1_Simulation4Draft =
        Simulation4Draft_IN_CorrectLeft;
      Simulation4Draft_B.v = 0.01;
      Simulation4Draft_B.w = 0.8;
    } else if (Simulation4Draft_B.ImpAsg_InsertedFor_DistanceArra != 0.0) {
      Simulation4Draft_DW.is_c1_Simulation4Draft =
        Simulation4Dr_IN_ObjectDetected;
      Simulation4Draft_B.v = 0.1;
    } else if (tmp && (Simulation4Draft_B.Switch[0] == 0.0)) {
      Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_TurnLeft;
      Simulation4Draft_DW.temporalCounter_i1 = 0U;
      Simulation4Draft_B.v = 0.01;
      Simulation4Draft_B.w = 0.4;
    } else if ((Simulation4Draft_B.Switch[0] == 1.0) &&
               (Simulation4Draft_B.Switch[1] == 1.0) &&
               (Simulation4Draft_B.Switch[2] == 1.0) &&
               (Simulation4Draft_B.Switch[3] == 1.0)) {
      Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_EndOfLine;
      Simulation4Draft_DW.temporalCounter_i1 = 0U;
      Simulation4Draft_B.v = 0.0;
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static real_T Simulation4Draft_rand(void)
{
  real_T r;
  int32_T b_kk;
  int32_T exitg1;
  int32_T k;
  uint32_T b_u[2];
  uint32_T mti;
  uint32_T y;
  boolean_T b_isvalid;
  boolean_T exitg2;
  if (Simulation4Draft_DW.method == 4U) {
    k = (int32_T)(Simulation4Draft_DW.state / 127773U);
    mti = (Simulation4Draft_DW.state - (uint32_T)k * 127773U) * 16807U;
    y = 2836U * (uint32_T)k;
    if (mti < y) {
      Simulation4Draft_DW.state = ~(y - mti) & 2147483647U;
    } else {
      Simulation4Draft_DW.state = mti - y;
    }

    r = (real_T)Simulation4Draft_DW.state * 4.6566128752457969E-10;
  } else if (Simulation4Draft_DW.method == 5U) {
    mti = 69069U * Simulation4Draft_DW.state_f[0] + 1234567U;
    y = Simulation4Draft_DW.state_f[1] << 13 ^ Simulation4Draft_DW.state_f[1];
    y ^= y >> 17;
    y ^= y << 5;
    Simulation4Draft_DW.state_f[0] = mti;
    Simulation4Draft_DW.state_f[1] = y;
    r = (real_T)(mti + y) * 2.328306436538696E-10;
  } else {
    /* ========================= COPYRIGHT NOTICE ============================ */
    /*  This is a uniform (0,1) pseudorandom number generator based on:        */
    /*                                                                         */
    /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
    /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
    /*                                                                         */
    /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
    /*  All rights reserved.                                                   */
    /*                                                                         */
    /*  Redistribution and use in source and binary forms, with or without     */
    /*  modification, are permitted provided that the following conditions     */
    /*  are met:                                                               */
    /*                                                                         */
    /*    1. Redistributions of source code must retain the above copyright    */
    /*       notice, this list of conditions and the following disclaimer.     */
    /*                                                                         */
    /*    2. Redistributions in binary form must reproduce the above copyright */
    /*       notice, this list of conditions and the following disclaimer      */
    /*       in the documentation and/or other materials provided with the     */
    /*       distribution.                                                     */
    /*                                                                         */
    /*    3. The names of its contributors may not be used to endorse or       */
    /*       promote products derived from this software without specific      */
    /*       prior written permission.                                         */
    /*                                                                         */
    /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
    /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
    /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
    /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
    /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
    /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
    /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
    /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
    /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
    /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
    /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
    /*                                                                         */
    /* =============================   END   ================================= */
    do {
      exitg1 = 0;
      for (k = 0; k < 2; k++) {
        mti = Simulation4Draft_DW.state_p[624] + 1U;
        if (Simulation4Draft_DW.state_p[624] + 1U >= 625U) {
          for (b_kk = 0; b_kk < 227; b_kk++) {
            y = (Simulation4Draft_DW.state_p[b_kk + 1] & 2147483647U) |
              (Simulation4Draft_DW.state_p[b_kk] & 2147483648U);
            if ((y & 1U) == 0U) {
              mti = y >> 1U;
            } else {
              mti = y >> 1U ^ 2567483615U;
            }

            Simulation4Draft_DW.state_p[b_kk] = Simulation4Draft_DW.state_p[b_kk
              + 397] ^ mti;
          }

          for (b_kk = 0; b_kk < 396; b_kk++) {
            y = (Simulation4Draft_DW.state_p[b_kk + 227] & 2147483648U) |
              (Simulation4Draft_DW.state_p[b_kk + 228] & 2147483647U);
            if ((y & 1U) == 0U) {
              mti = y >> 1U;
            } else {
              mti = y >> 1U ^ 2567483615U;
            }

            Simulation4Draft_DW.state_p[b_kk + 227] =
              Simulation4Draft_DW.state_p[b_kk] ^ mti;
          }

          y = (Simulation4Draft_DW.state_p[623] & 2147483648U) |
            (Simulation4Draft_DW.state_p[0] & 2147483647U);
          if ((y & 1U) == 0U) {
            mti = y >> 1U;
          } else {
            mti = y >> 1U ^ 2567483615U;
          }

          Simulation4Draft_DW.state_p[623] = Simulation4Draft_DW.state_p[396] ^
            mti;
          mti = 1U;
        }

        y = Simulation4Draft_DW.state_p[(int32_T)mti - 1];
        Simulation4Draft_DW.state_p[624] = mti;
        y ^= y >> 11U;
        y ^= y << 7U & 2636928640U;
        y ^= y << 15U & 4022730752U;
        b_u[k] = y >> 18U ^ y;
      }

      r = ((real_T)(b_u[0] >> 5U) * 6.7108864E+7 + (real_T)(b_u[1] >> 6U)) *
        1.1102230246251565E-16;
      if (r == 0.0) {
        if ((Simulation4Draft_DW.state_p[624] >= 1U) &&
            (Simulation4Draft_DW.state_p[624] < 625U)) {
          b_isvalid = true;
        } else {
          b_isvalid = false;
        }

        if (b_isvalid) {
          b_isvalid = false;
          k = 0;
          exitg2 = false;
          while ((!exitg2) && (k + 1 < 625)) {
            if (Simulation4Draft_DW.state_p[k] == 0U) {
              k++;
            } else {
              b_isvalid = true;
              exitg2 = true;
            }
          }
        }

        if (!b_isvalid) {
          mti = 5489U;
          Simulation4Draft_DW.state_p[0] = 5489U;
          for (k = 0; k < 623; k++) {
            mti = ((mti >> 30U ^ mti) * 1812433253U + (uint32_T)k) + 1U;
            Simulation4Draft_DW.state_p[k + 1] = mti;
          }

          Simulation4Draft_DW.state_p[624] = 624U;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return r;
}

/* Model step function for TID0 */
void Simulation4Draft_step0(void)      /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Gain3;
  real_T rtb_Gain2;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_a;
  int32_T ForEach_itr_f;
  int32_T b_ii;
  int32_T i;
  int32_T ii_size_idx_0;
  int8_T ii_data_idx_0;
  boolean_T exitg1;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Math: '<S7>/Math Function' incorporates:
   *  Constant: '<S7>/Circle'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'
   */
  Simulation4Draft_B.MathFunction = rt_modd_snf
    (Simulation4Draft_DW.DiscreteTimeIntegrator2_DSTATE,
     Simulation4Draft_P.Circle_Value);

  /* Outputs for Iterator SubSystem: '<S66>/For Each Subsystem' incorporates:
   *  ForEach: '<S67>/For Each'
   */
  /* MATLAB Function: '<S126>/Calculate Rotation Matrix' incorporates:
   *  MATLAB Function: '<S67>/Transform Sensor Offset'
   */
  Simulation4Draft_B.Gain_b = sin(Simulation4Draft_B.MathFunction);
  Simulation4Draft_B.rtb_rotMat_tmp_tmp = cos(Simulation4Draft_B.MathFunction);

  /* End of Outputs for SubSystem: '<S66>/For Each Subsystem' */
  Simulation4Draft_B.rotMat[0] = Simulation4Draft_B.rtb_rotMat_tmp_tmp;
  Simulation4Draft_B.rotMat[3] = -Simulation4Draft_B.Gain_b;
  Simulation4Draft_B.rotMat[6] = 0.0;
  Simulation4Draft_B.rotMat[1] = Simulation4Draft_B.Gain_b;
  Simulation4Draft_B.rotMat[4] = Simulation4Draft_B.rtb_rotMat_tmp_tmp;
  Simulation4Draft_B.rotMat[7] = 0.0;
  Simulation4Draft_B.rotMat[2] = 0.0;
  Simulation4Draft_B.rotMat[5] = 0.0;
  Simulation4Draft_B.rotMat[8] = 1.0;

  /* Outputs for Iterator SubSystem: '<S66>/For Each Subsystem' incorporates:
   *  ForEach: '<S67>/For Each'
   */
  for (ForEach_itr_f = 0; ForEach_itr_f < 4; ForEach_itr_f++) {
    /* MATLAB Function: '<S67>/Transform Sensor Offset' incorporates:
     *  Constant: '<S5>/Constant'
     *  Constant: '<S5>/Constant1'
     *  ForEachSliceSelector generated from: '<S67>/offSetX'
     */
    Simulation4Draft_B.dv[0] = Simulation4Draft_B.rtb_rotMat_tmp_tmp;
    Simulation4Draft_B.dv[3] = -Simulation4Draft_B.Gain_b;
    Simulation4Draft_B.dv[6] = 0.0;
    Simulation4Draft_B.dv[1] = Simulation4Draft_B.Gain_b;
    Simulation4Draft_B.dv[4] = Simulation4Draft_B.rtb_rotMat_tmp_tmp;
    Simulation4Draft_B.dv[7] = 0.0;
    Simulation4Draft_B.dv[2] = 0.0;
    Simulation4Draft_B.dv[5] = 0.0;
    Simulation4Draft_B.dv[8] = 1.0;
    Simulation4Draft_B.MathFunction =
      Simulation4Draft_P.Constant_Value[ForEach_itr_f];
    Simulation4Draft_B.DiscreteTimeIntegrator_d =
      Simulation4Draft_P.Constant1_Value[ForEach_itr_f];
    for (i = 0; i < 3; i++) {
      Simulation4Draft_B.MathFunction_g[i] = Simulation4Draft_B.dv[i + 3] *
        Simulation4Draft_B.DiscreteTimeIntegrator_d + Simulation4Draft_B.dv[i] *
        Simulation4Draft_B.MathFunction;
    }

    /* Outputs for Atomic SubSystem: '<S67>/Look up Line Value' */
    /* Sum: '<S68>/Sum' incorporates:
     *  Constant: '<S68>/Constant'
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
     *  Gain: '<S68>/Gain1'
     *  MATLAB Function: '<S67>/Transform Sensor Offset'
     */
    Simulation4Draft_B.MathFunction =
      Simulation4Draft_P.CoreSubsys.Constant_Value -
      (Simulation4Draft_DW.DiscreteTimeIntegrator1_DSTATE +
       Simulation4Draft_B.MathFunction_g[1]) *
      Simulation4Draft_P.CoreSubsys.Gain1_Gain;

    /* Gain: '<S68>/Gain' incorporates:
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
     *  MATLAB Function: '<S67>/Transform Sensor Offset'
     */
    Simulation4Draft_B.DiscreteTimeIntegrator_d =
      (Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE +
       Simulation4Draft_B.MathFunction_g[0]) *
      Simulation4Draft_P.CoreSubsys.Gain_Gain;

    /* LookupNDDirect: '<S68>/Direct Lookup Table (n-D)' incorporates:
     *  Bias: '<S68>/Bias'
     *  Bias: '<S68>/Bias1'
     *  Rounding: '<S68>/Rounding Function'
     *  Rounding: '<S68>/Rounding Function1'
     *  Saturate: '<S68>/Saturation2'
     *  Saturate: '<S68>/Saturation3'
     *
     * About '<S68>/Direct Lookup Table (n-D)':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Simulation4Draft_B.DiscreteTimeIntegrator_d = rt_roundd_snf
      (Simulation4Draft_B.DiscreteTimeIntegrator_d) +
      Simulation4Draft_P.CoreSubsys.Bias1_Bias;
    if (Simulation4Draft_B.DiscreteTimeIntegrator_d >
        Simulation4Draft_P.CoreSubsys.Saturation3_UpperSat) {
      Simulation4Draft_B.DiscreteTimeIntegrator_d =
        Simulation4Draft_P.CoreSubsys.Saturation3_UpperSat;
    } else if (Simulation4Draft_B.DiscreteTimeIntegrator_d <
               Simulation4Draft_P.CoreSubsys.Saturation3_LowerSat) {
      Simulation4Draft_B.DiscreteTimeIntegrator_d =
        Simulation4Draft_P.CoreSubsys.Saturation3_LowerSat;
    }

    Simulation4Draft_B.MathFunction = rt_roundd_snf
      (Simulation4Draft_B.MathFunction) +
      Simulation4Draft_P.CoreSubsys.Bias_Bias;
    if (Simulation4Draft_B.MathFunction >
        Simulation4Draft_P.CoreSubsys.Saturation2_UpperSat) {
      Simulation4Draft_B.MathFunction =
        Simulation4Draft_P.CoreSubsys.Saturation2_UpperSat;
    } else if (Simulation4Draft_B.MathFunction <
               Simulation4Draft_P.CoreSubsys.Saturation2_LowerSat) {
      Simulation4Draft_B.MathFunction =
        Simulation4Draft_P.CoreSubsys.Saturation2_LowerSat;
    }

    if (Simulation4Draft_B.DiscreteTimeIntegrator_d > 628.0) {
      Simulation4Draft_B.DiscreteTimeIntegrator_d = 628.0;
    } else if (Simulation4Draft_B.DiscreteTimeIntegrator_d < 0.0) {
      Simulation4Draft_B.DiscreteTimeIntegrator_d = 0.0;
    }

    if (Simulation4Draft_B.MathFunction > 1258.0) {
      Simulation4Draft_B.MathFunction = 1258.0;
    } else if (Simulation4Draft_B.MathFunction < 0.0) {
      Simulation4Draft_B.MathFunction = 0.0;
    }

    /* ForEachSliceAssignment generated from: '<S67>/LineArray' incorporates:
     *  LookupNDDirect: '<S68>/Direct Lookup Table (n-D)'
     *
     * About '<S68>/Direct Lookup Table (n-D)':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    Simulation4Draft_B.ImpAsg_InsertedFor_LineArra[ForEach_itr_f] =
      Simulation4Draft_P.CoreSubsys.DirectLookupTablenD_table[(int32_T)
      Simulation4Draft_B.DiscreteTimeIntegrator_d * 1259 + (int32_T)
      Simulation4Draft_B.MathFunction];

    /* End of Outputs for SubSystem: '<S67>/Look up Line Value' */
  }

  /* End of Outputs for SubSystem: '<S66>/For Each Subsystem' */

  /* Switch: '<S5>/Switch' */
  if (Simulation4Draft_B.ImpAsg_InsertedFor_LineArra[0] >
      Simulation4Draft_P.Switch_Threshold_j) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Environment'
     */
    Simulation4Draft_B.Switch[0] = Simulation4Draft_P.LineSensor_envVal;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Line'
     */
    Simulation4Draft_B.Switch[0] = Simulation4Draft_P.LineSensor_lineVal;
  }

  if (Simulation4Draft_B.ImpAsg_InsertedFor_LineArra[1] >
      Simulation4Draft_P.Switch_Threshold_j) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Environment'
     */
    Simulation4Draft_B.Switch[1] = Simulation4Draft_P.LineSensor_envVal;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Line'
     */
    Simulation4Draft_B.Switch[1] = Simulation4Draft_P.LineSensor_lineVal;
  }

  if (Simulation4Draft_B.ImpAsg_InsertedFor_LineArra[2] >
      Simulation4Draft_P.Switch_Threshold_j) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Environment'
     */
    Simulation4Draft_B.Switch[2] = Simulation4Draft_P.LineSensor_envVal;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Line'
     */
    Simulation4Draft_B.Switch[2] = Simulation4Draft_P.LineSensor_lineVal;
  }

  if (Simulation4Draft_B.ImpAsg_InsertedFor_LineArra[3] >
      Simulation4Draft_P.Switch_Threshold_j) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Environment'
     */
    Simulation4Draft_B.Switch[3] = Simulation4Draft_P.LineSensor_envVal;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Scale to Line'
     */
    Simulation4Draft_B.Switch[3] = Simulation4Draft_P.LineSensor_lineVal;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Outputs for Iterator SubSystem: '<S126>/Subsystem' incorporates:
   *  ForEach: '<S128>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 1; ForEach_itr++) {
    /* Sum: '<S128>/Sum1' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S128>/Constant'
     */
    for (i = 0; i < 31; i++) {
      Simulation4Draft_B.Sum1[i] =
        Simulation4Draft_P.CoreSubsys_c.Constant_Value[i] +
        Simulation4Draft_P.Constant_Value_d;
    }

    /* End of Sum: '<S128>/Sum1' */

    /* Outputs for Iterator SubSystem: '<S128>/Look up Sensor Value' incorporates:
     *  ForEach: '<S129>/For Each'
     */
    for (ForEach_itr_a = 0; ForEach_itr_a < 31; ForEach_itr_a++) {
      /* ForEachSliceSelector generated from: '<S129>/SensorLineX' */
      Simulation4Draft_B.Gain_b = Simulation4Draft_B.Sum1[ForEach_itr_a];

      /* Product: '<S129>/Matrix Multiply' */
      for (i = 0; i < 3; i++) {
        /* Math: '<S129>/Math Function' incorporates:
         *  Concatenate: '<S129>/Vector Concatenate'
         *  Constant: '<S10>/Constant1'
         *  Constant: '<S129>/Constant'
         */
        Simulation4Draft_B.MathFunction_g[i] = (Simulation4Draft_B.rotMat[i + 3]
          * Simulation4Draft_P.Constant1_Value_k + Simulation4Draft_B.rotMat[i] *
          Simulation4Draft_B.Gain_b) + Simulation4Draft_B.rotMat[i + 6] *
          Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Constant_Value;
      }

      /* End of Product: '<S129>/Matrix Multiply' */

      /* Sum: '<S129>/Sum3' incorporates:
       *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
       */
      Simulation4Draft_B.MathFunction = Simulation4Draft_B.MathFunction_g[1] +
        Simulation4Draft_DW.DiscreteTimeIntegrator1_DSTATE;

      /* Sum: '<S129>/Sum2' incorporates:
       *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
       */
      Simulation4Draft_B.DiscreteTimeIntegrator_d =
        Simulation4Draft_B.MathFunction_g[0] +
        Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE;

      /* LookupNDDirect: '<S131>/Direct Lookup Table (n-D)' incorporates:
       *  Bias: '<S131>/Bias'
       *  Bias: '<S131>/Bias1'
       *  Constant: '<S131>/Constant1'
       *  Gain: '<S131>/Gain'
       *  Gain: '<S131>/Gain1'
       *  Rounding: '<S131>/Rounding Function'
       *  Rounding: '<S131>/Rounding Function1'
       *  Saturate: '<S131>/Saturation'
       *  Saturate: '<S131>/Saturation1'
       *  Sum: '<S131>/Sum'
       *
       * About '<S131>/Direct Lookup Table (n-D)':
       *  2-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      Simulation4Draft_B.DiscreteTimeIntegrator_d = rt_roundd_snf
        (Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Gain_Gain *
         Simulation4Draft_B.DiscreteTimeIntegrator_d) +
        Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Bias1_Bias;
      if (Simulation4Draft_B.DiscreteTimeIntegrator_d >
          Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation1_UpperSat) {
        Simulation4Draft_B.DiscreteTimeIntegrator_d =
          Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation1_UpperSat;
      } else if (Simulation4Draft_B.DiscreteTimeIntegrator_d <
                 Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation1_LowerSat)
      {
        Simulation4Draft_B.DiscreteTimeIntegrator_d =
          Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation1_LowerSat;
      }

      Simulation4Draft_B.MathFunction = rt_roundd_snf
        (Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Constant1_Value -
         Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Gain1_Gain *
         Simulation4Draft_B.MathFunction) +
        Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Bias_Bias;
      if (Simulation4Draft_B.MathFunction >
          Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation_UpperSat) {
        Simulation4Draft_B.MathFunction =
          Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation_UpperSat;
      } else if (Simulation4Draft_B.MathFunction <
                 Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation_LowerSat)
      {
        Simulation4Draft_B.MathFunction =
          Simulation4Draft_P.CoreSubsys_c.CoreSubsys.Saturation_LowerSat;
      }

      if (Simulation4Draft_B.DiscreteTimeIntegrator_d > 628.0) {
        Simulation4Draft_B.DiscreteTimeIntegrator_d = 628.0;
      } else if (Simulation4Draft_B.DiscreteTimeIntegrator_d < 0.0) {
        Simulation4Draft_B.DiscreteTimeIntegrator_d = 0.0;
      }

      if (Simulation4Draft_B.MathFunction > 1258.0) {
        Simulation4Draft_B.MathFunction = 1258.0;
      } else if (Simulation4Draft_B.MathFunction < 0.0) {
        Simulation4Draft_B.MathFunction = 0.0;
      }

      /* ForEachSliceAssignment generated from: '<S129>/SensorVal' incorporates:
       *  LookupNDDirect: '<S131>/Direct Lookup Table (n-D)'
       *
       * About '<S131>/Direct Lookup Table (n-D)':
       *  2-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      Simulation4Draft_B.ImpAsg_InsertedFor_SensorVa[ForEach_itr_a] =
        Simulation4Draft_P.CoreSubsys_c.CoreSubsys.DirectLookupTablenD_table
        [(int32_T)Simulation4Draft_B.DiscreteTimeIntegrator_d * 1259 + (int32_T)
        Simulation4Draft_B.MathFunction];
    }

    /* End of Outputs for SubSystem: '<S128>/Look up Sensor Value' */

    /* MATLAB Function: '<S128>/Nearest Object' */
    i = 0;
    ii_size_idx_0 = 1;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 31)) {
      if (!(Simulation4Draft_B.ImpAsg_InsertedFor_SensorVa[b_ii] != 0.0F)) {
        i = 1;
        ii_data_idx_0 = (int8_T)(b_ii + 1);
        exitg1 = true;
      } else {
        b_ii++;
      }
    }

    if (i == 0) {
      ii_size_idx_0 = 0;
    }

    /* ForEachSliceAssignment generated from: '<S128>/DistanceArray' incorporates:
     *  MATLAB Function: '<S128>/Nearest Object'
     */
    Simulation4Draft_B.ImpAsg_InsertedFor_DistanceArra = 0.0;

    /* MATLAB Function: '<S128>/Nearest Object' */
    if (ii_size_idx_0 != 0) {
      /* ForEachSliceAssignment generated from: '<S128>/DistanceArray' incorporates:
       *  Constant: '<S128>/Constant'
       */
      Simulation4Draft_B.ImpAsg_InsertedFor_DistanceArra =
        Simulation4Draft_P.CoreSubsys_c.Constant_Value[ii_data_idx_0 - 1];
    }
  }

  /* End of Outputs for SubSystem: '<S126>/Subsystem' */

  /* Chart: '<Root>/Line Following' */
  if (Simulation4Draft_DW.temporalCounter_i1 < 127U) {
    Simulation4Draft_DW.temporalCounter_i1++;
  }

  if (Simulation4Draft_DW.is_active_c1_Simulation4Draft == 0U) {
    Simulation4Draft_DW.is_active_c1_Simulation4Draft = 1U;
    Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_Drive;
    Simulation4Draft_DW.temporalCounter_i1 = 0U;
    Simulation4Draft_B.v = 0.05;
    Simulation4Draft_B.w = 0.0;
  } else {
    switch (Simulation4Draft_DW.is_c1_Simulation4Draft) {
     case Simulation4Draft_IN_CorrectLeft:
      Simulation4Draft_B.v = 0.01;
      Simulation4Draft_B.w = 0.8;
      if ((Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
           == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_Drive;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.05;
        Simulation4Draft_B.w = 0.0;
      }
      break;

     case Simulation4Draf_IN_CorrectLeft1:
      Simulation4Draft_B.w = 0.5;
      if ((Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
           == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Dr_IN_ObjectDetected;
        Simulation4Draft_B.v = 0.1;
      }
      break;

     case Simulation4Draf_IN_CorrectRight:
      Simulation4Draft_B.v = 0.01;
      Simulation4Draft_B.w = -0.8;
      if ((Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
           == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_Drive;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.05;
        Simulation4Draft_B.w = 0.0;
      }
      break;

     case Simulation4Dra_IN_CorrectRight1:
      Simulation4Draft_B.w = -0.5;
      if ((Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
           == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Dr_IN_ObjectDetected;
        Simulation4Draft_B.v = 0.1;
      }
      break;

     case Simulation4Draft_IN_Drive:
      Simulation4Draft_Drive();
      break;

     case Simulation4Draft_IN_End:
      Simulation4Draft_B.v = 0.0;
      Simulation4Draft_B.w = 0.0;
      break;

     case Simulation4Draft_IN_EndOfLine:
      Simulation4Draft_B.v = 0.0;
      if (Simulation4Draft_DW.temporalCounter_i1 >= 100U) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Draft_IN_TurnAround1;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.data =
          Simulation4Draft_B.ImpAsg_InsertedFor_DistanceArra;
        Simulation4Draft_B.w = 0.6;
      }
      break;

     case Simulation4Dr_IN_ObjectDetected:
      Simulation4Draft_B.v = 0.1;
      if ((Simulation4Draft_B.Switch[0] == 0.0) && (Simulation4Draft_B.Switch[3]
           == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Draft_IN_EndOfLine;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.0;
      } else if ((Simulation4Draft_B.Switch[1] == 1.0) &&
                 (Simulation4Draft_B.Switch[2] == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Dra_IN_CorrectRight1;
        Simulation4Draft_B.w = -0.5;
      } else if ((Simulation4Draft_B.Switch[1] == 0.0) &&
                 (Simulation4Draft_B.Switch[2] == 1.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Draf_IN_CorrectLeft1;
        Simulation4Draft_B.w = 0.5;
      }
      break;

     case Simulation4Draft_IN_Random:
      if (Simulation4Draft_DW.dir == 0.0) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Draft_IN_TurnRight;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.01;
        Simulation4Draft_B.w = -0.4;
      } else if (Simulation4Draft_DW.dir == 1.0) {
        Simulation4Draft_DW.is_c1_Simulation4Draft =
          Simulation4Draft_IN_TurnLeft;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.01;
        Simulation4Draft_B.w = 0.4;
      }
      break;

     case Simulation4Draft_IN_TurnAround1:
      Simulation4Draft_B.w = 0.6;
      if ((Simulation4Draft_DW.temporalCounter_i1 >= 100U) &&
          (Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
           == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_Drive;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.05;
        Simulation4Draft_B.w = 0.0;
      }
      break;

     case Simulation4Draft_IN_TurnLeft:
      Simulation4Draft_B.v = 0.01;
      Simulation4Draft_B.w = 0.4;
      if ((Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
           == 0.0) && (Simulation4Draft_DW.temporalCounter_i1 >= 50U)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_Drive;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.05;
        Simulation4Draft_B.w = 0.0;
      }
      break;

     case Simulation4Draft_IN_TurnRight:
      Simulation4Draft_B.v = 0.01;
      Simulation4Draft_B.w = -0.4;
      if ((Simulation4Draft_DW.temporalCounter_i1 >= 50U) &&
          (Simulation4Draft_B.Switch[1] == 0.0) && (Simulation4Draft_B.Switch[2]
           == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_Drive;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = 0.05;
        Simulation4Draft_B.w = 0.0;
      }
      break;

     case Simulation4Draft_IN_checkEnd:
      Simulation4Draft_B.v = 0.05;
      if ((Simulation4Draft_DW.temporalCounter_i1 >= 50U) &&
          (Simulation4Draft_B.Switch[0] == 1.0) && (Simulation4Draft_B.Switch[1]
           == 1.0) && (Simulation4Draft_B.Switch[2] == 1.0) &&
          (Simulation4Draft_B.Switch[3] == 1.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_notEnd;
        Simulation4Draft_DW.temporalCounter_i1 = 0U;
        Simulation4Draft_B.v = -0.05;
      } else if ((Simulation4Draft_DW.temporalCounter_i1 >= 50U) &&
                 (Simulation4Draft_B.Switch[0] == 0.0) &&
                 (Simulation4Draft_B.Switch[1] == 0.0) &&
                 (Simulation4Draft_B.Switch[2] == 0.0) &&
                 (Simulation4Draft_B.Switch[3] == 0.0)) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_End;
        Simulation4Draft_B.v = 0.0;
        Simulation4Draft_B.w = 0.0;
      }
      break;

     default:
      /* case IN_notEnd: */
      Simulation4Draft_B.v = -0.05;
      if (Simulation4Draft_DW.temporalCounter_i1 >= 50U) {
        Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4Draft_IN_Random;
        Simulation4Draft_DW.dir = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Line Following' */

  /* Gain: '<S9>/vtow' */
  Simulation4Draft_B.Gain_b = 1.0 / Simulation4Draft_P.Towlwr_wheelR;

  /* Lookup_n-D: '<Root>/Left Motor LUT' incorporates:
   *  Gain: '<S9>/change parameters'
   *  Gain: '<S9>/vtow'
   *  SignalConversion generated from: '<S9>/change parameters'
   */
  Simulation4Draft_B.LeftPWM = Simulation4Draft_P.InputPWM[plook_u32d_binckan
    ((Simulation4Draft_P.changeparameters_Gain[0] * Simulation4Draft_B.v +
      Simulation4Draft_P.changeparameters_Gain[2] * Simulation4Draft_B.w) *
     Simulation4Draft_B.Gain_b, Simulation4Draft_P.WheelSpeed, 172U)];

  /* Lookup_n-D: '<Root>/Right Motor LUT' incorporates:
   *  Gain: '<S9>/change parameters'
   *  Gain: '<S9>/vtow'
   *  SignalConversion generated from: '<S9>/change parameters'
   */
  Simulation4Draft_B.RightPWM = Simulation4Draft_P.InputPWM[plook_u32d_binckan
    ((Simulation4Draft_P.changeparameters_Gain[1] * Simulation4Draft_B.v +
      Simulation4Draft_P.changeparameters_Gain[3] * Simulation4Draft_B.w) *
     Simulation4Draft_B.Gain_b, Simulation4Draft_P.WheelSpeed, 172U)];

  /* DiscreteStateSpace: '<S62>/Internal' */
  {
    Simulation4Draft_B.Internal = (Simulation4Draft_P.Internal_C[0])*
      Simulation4Draft_DW.Internal_DSTATE[0]
      + (Simulation4Draft_P.Internal_C[1])*Simulation4Draft_DW.Internal_DSTATE[1]
      + (Simulation4Draft_P.Internal_C[2])*Simulation4Draft_DW.Internal_DSTATE[2];
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Gain: '<S63>/Gain'
   */
  if (Simulation4Draft_P.LeftMotor_sensorType >
      Simulation4Draft_P.Switch_Threshold) {
    Simulation4Draft_B.MathFunction = Simulation4Draft_P.Gain_Gain *
      Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_d;
  } else {
    Simulation4Draft_B.MathFunction = Simulation4Draft_B.Internal;
  }

  /* End of Switch: '<S3>/Switch' */

  /* DiscreteStateSpace: '<S70>/Internal' */
  {
    Simulation4Draft_B.Internal_b = (Simulation4Draft_P.Internal_C_h[0])*
      Simulation4Draft_DW.Internal_DSTATE_n[0]
      + (Simulation4Draft_P.Internal_C_h[1])*
      Simulation4Draft_DW.Internal_DSTATE_n[1]
      + (Simulation4Draft_P.Internal_C_h[2])*
      Simulation4Draft_DW.Internal_DSTATE_n[2];
  }

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Gain: '<S71>/Gain'
   */
  if (Simulation4Draft_P.RightMotor_sensorType >
      Simulation4Draft_P.Switch_Threshold_b) {
    Simulation4Draft_B.Gain_b = Simulation4Draft_P.Gain_Gain_o *
      Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_j;
  } else {
    Simulation4Draft_B.Gain_b = Simulation4Draft_B.Internal_b;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Wheel Radius'
   *  Gain: '<S7>/Gain1'
   *  Sum: '<S7>/Common Mode'
   */
  Simulation4Draft_B.DiscreteTimeIntegrator_d = (Simulation4Draft_B.MathFunction
    + Simulation4Draft_B.Gain_b) * (Simulation4Draft_P.Gain1_Gain *
    Simulation4Draft_P.wheelR);

  /* Product: '<S7>/Product2' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'
   *  Trigonometry: '<S7>/Comp_x'
   */
  Simulation4Draft_B.Product2 = Simulation4Draft_B.DiscreteTimeIntegrator_d *
    cos(Simulation4Draft_DW.DiscreteTimeIntegrator2_DSTATE);

  /* Product: '<S7>/Product3' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator2'
   *  Trigonometry: '<S7>/Comp_y'
   */
  Simulation4Draft_B.Product3 = Simulation4Draft_B.DiscreteTimeIntegrator_d *
    sin(Simulation4Draft_DW.DiscreteTimeIntegrator2_DSTATE);

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S7>/Wheel Radius'
   *  Constant: '<S7>/Wheel Spacing'
   *  Product: '<S7>/Divide'
   *  Sum: '<S7>/Differential'
   */
  Simulation4Draft_B.Product1 = Simulation4Draft_P.wheelR /
    Simulation4Draft_P.axleLength * (Simulation4Draft_B.Gain_b -
    Simulation4Draft_B.MathFunction);

  /* Gain: '<S2>/Gain3' */
  rtb_Gain3 = Simulation4Draft_P.Gain3_Gain * Simulation4Draft_B.Gain_b;

  /* Gain: '<S2>/Gain2' */
  rtb_Gain2 = Simulation4Draft_P.Gain2_Gain * Simulation4Draft_B.MathFunction;

  /* Gain: '<Root>/Gain' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<S2>/Gain5'
   *  Rounding: '<S2>/Rounding Function'
   */
  Simulation4Draft_B.MathFunction = 6.2831853071795862 *
    Simulation4Draft_P.wheelR / Simulation4Draft_P.ticksPerRot;
  Simulation4Draft_B.Gain_b = ceil(Simulation4Draft_P.ticksPerRot / 360.0 *
    Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_n) *
    Simulation4Draft_B.MathFunction;

  /* Gain: '<Root>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   *  Gain: '<S2>/Gain6'
   *  Rounding: '<S2>/Rounding Function1'
   */
  Simulation4Draft_B.DiscreteTimeIntegrator_d = ceil
    (Simulation4Draft_P.ticksPerRot / 360.0 *
     Simulation4Draft_DW.DiscreteTimeIntegrator1_DSTAT_d) *
    Simulation4Draft_B.MathFunction;

  /* Sum: '<Root>/Subtract' */
  Simulation4Draft_B.MathFunction = Simulation4Draft_B.Gain_b -
    Simulation4Draft_B.DiscreteTimeIntegrator_d;

  /* S-Function (sfun_time): '<S7>/Soft Real Time' */

  /* Level2 S-Function Block: '<S7>/Soft Real Time' (sfun_time) */
  {
    SimStruct *rts = Simulation4Draft_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator2' */
  Simulation4Draft_DW.DiscreteTimeIntegrator2_DSTATE +=
    Simulation4Draft_P.DiscreteTimeIntegrator2_gainval *
    Simulation4Draft_B.Product1;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE +=
    Simulation4Draft_P.DiscreteTimeIntegrator_gainval *
    Simulation4Draft_B.Product2;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */
  Simulation4Draft_DW.DiscreteTimeIntegrator1_DSTATE +=
    Simulation4Draft_P.DiscreteTimeIntegrator1_gainval *
    Simulation4Draft_B.Product3;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_d +=
    Simulation4Draft_P.DiscreteTimeIntegrator_gainva_a *
    Simulation4Draft_B.Internal;

  /* Update for DiscreteStateSpace: '<S62>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (Simulation4Draft_P.Internal_A[0])*
      Simulation4Draft_DW.Internal_DSTATE[0]
      + (Simulation4Draft_P.Internal_A[1])*Simulation4Draft_DW.Internal_DSTATE[1]
      + (Simulation4Draft_P.Internal_A[2])*Simulation4Draft_DW.Internal_DSTATE[2];
    xnew[0] += (Simulation4Draft_P.Internal_B[0])*Simulation4Draft_B.LeftPWM;
    xnew[1] = (Simulation4Draft_P.Internal_A[3])*
      Simulation4Draft_DW.Internal_DSTATE[0]
      + (Simulation4Draft_P.Internal_A[4])*Simulation4Draft_DW.Internal_DSTATE[1]
      + (Simulation4Draft_P.Internal_A[5])*Simulation4Draft_DW.Internal_DSTATE[2];
    xnew[1] += (Simulation4Draft_P.Internal_B[1])*Simulation4Draft_B.LeftPWM;
    xnew[2] = (Simulation4Draft_P.Internal_A[6])*
      Simulation4Draft_DW.Internal_DSTATE[0]
      + (Simulation4Draft_P.Internal_A[7])*Simulation4Draft_DW.Internal_DSTATE[1]
      + (Simulation4Draft_P.Internal_A[8])*Simulation4Draft_DW.Internal_DSTATE[2];
    xnew[2] += (Simulation4Draft_P.Internal_B[2])*Simulation4Draft_B.LeftPWM;
    (void) memcpy(&Simulation4Draft_DW.Internal_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_j +=
    Simulation4Draft_P.DiscreteTimeIntegrator_gainva_p *
    Simulation4Draft_B.Internal_b;

  /* Update for DiscreteStateSpace: '<S70>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (Simulation4Draft_P.Internal_A_a[0])*
      Simulation4Draft_DW.Internal_DSTATE_n[0]
      + (Simulation4Draft_P.Internal_A_a[1])*
      Simulation4Draft_DW.Internal_DSTATE_n[1]
      + (Simulation4Draft_P.Internal_A_a[2])*
      Simulation4Draft_DW.Internal_DSTATE_n[2];
    xnew[0] += (Simulation4Draft_P.Internal_B_e[0])*Simulation4Draft_B.RightPWM;
    xnew[1] = (Simulation4Draft_P.Internal_A_a[3])*
      Simulation4Draft_DW.Internal_DSTATE_n[0]
      + (Simulation4Draft_P.Internal_A_a[4])*
      Simulation4Draft_DW.Internal_DSTATE_n[1]
      + (Simulation4Draft_P.Internal_A_a[5])*
      Simulation4Draft_DW.Internal_DSTATE_n[2];
    xnew[1] += (Simulation4Draft_P.Internal_B_e[1])*Simulation4Draft_B.RightPWM;
    xnew[2] = (Simulation4Draft_P.Internal_A_a[6])*
      Simulation4Draft_DW.Internal_DSTATE_n[0]
      + (Simulation4Draft_P.Internal_A_a[7])*
      Simulation4Draft_DW.Internal_DSTATE_n[1]
      + (Simulation4Draft_P.Internal_A_a[8])*
      Simulation4Draft_DW.Internal_DSTATE_n[2];
    xnew[2] += (Simulation4Draft_P.Internal_B_e[2])*Simulation4Draft_B.RightPWM;
    (void) memcpy(&Simulation4Draft_DW.Internal_DSTATE_n[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_n +=
    Simulation4Draft_P.DiscreteTimeIntegrator_gainva_l * rtb_Gain2;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Simulation4Draft_DW.DiscreteTimeIntegrator1_DSTAT_d +=
    Simulation4Draft_P.DiscreteTimeIntegrator1_gainv_f * rtb_Gain3;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Simulation4Draft_M->Timing.clockTick0)) {
    ++Simulation4Draft_M->Timing.clockTickH0;
  }

  Simulation4Draft_M->Timing.t[0] = Simulation4Draft_M->Timing.clockTick0 *
    Simulation4Draft_M->Timing.stepSize0 +
    Simulation4Draft_M->Timing.clockTickH0 *
    Simulation4Draft_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  Simulation4Draft_M->Timing.clockTick1++;
  if (!Simulation4Draft_M->Timing.clockTick1) {
    Simulation4Draft_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void Simulation4Draft_step2(void)      /* Sample time: [3.0s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Random Integer Generator' */
  Simulation4Draft_rand();
}

/* Model initialize function */
void Simulation4Draft_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Simulation4Draft_M, 0,
                sizeof(RT_MODEL_Simulation4Draft_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Simulation4Draft_M->solverInfo,
                          &Simulation4Draft_M->Timing.simTimeStep);
    rtsiSetTPtr(&Simulation4Draft_M->solverInfo, &rtmGetTPtr(Simulation4Draft_M));
    rtsiSetStepSizePtr(&Simulation4Draft_M->solverInfo,
                       &Simulation4Draft_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Simulation4Draft_M->solverInfo, (&rtmGetErrorStatus
      (Simulation4Draft_M)));
    rtsiSetRTModelPtr(&Simulation4Draft_M->solverInfo, Simulation4Draft_M);
  }

  rtsiSetSimTimeStep(&Simulation4Draft_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Simulation4Draft_M->solverInfo,"FixedStepDiscrete");
  Simulation4Draft_M->solverInfoPtr = (&Simulation4Draft_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Simulation4Draft_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Simulation4Draft_M points to
       static memory which is guaranteed to be non-NULL" */
    Simulation4Draft_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Simulation4Draft_M->Timing.sampleTimes =
      (&Simulation4Draft_M->Timing.sampleTimesArray[0]);
    Simulation4Draft_M->Timing.offsetTimes =
      (&Simulation4Draft_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Simulation4Draft_M->Timing.sampleTimes[0] = (0.0);
    Simulation4Draft_M->Timing.sampleTimes[1] = (0.01);
    Simulation4Draft_M->Timing.sampleTimes[2] = (3.0);

    /* task offsets */
    Simulation4Draft_M->Timing.offsetTimes[0] = (0.0);
    Simulation4Draft_M->Timing.offsetTimes[1] = (0.0);
    Simulation4Draft_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Simulation4Draft_M, &Simulation4Draft_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Simulation4Draft_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Simulation4Draft_M->Timing.perTaskSampleHitsArray;
    Simulation4Draft_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Simulation4Draft_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Simulation4Draft_M, -1);
  Simulation4Draft_M->Timing.stepSize0 = 0.01;
  Simulation4Draft_M->solverInfoPtr = (&Simulation4Draft_M->solverInfo);
  Simulation4Draft_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Simulation4Draft_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Simulation4Draft_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &Simulation4Draft_B), 0,
                sizeof(B_Simulation4Draft_T));

  /* states (dwork) */
  (void) memset((void *)&Simulation4Draft_DW, 0,
                sizeof(DW_Simulation4Draft_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Simulation4Draft_M->NonInlinedSFcns.sfcnInfo;
    Simulation4Draft_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Simulation4Draft_M)));
    Simulation4Draft_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Simulation4Draft_M->Sizes.numSampTimes);
    Simulation4Draft_M->NonInlinedSFcns.taskTimePtrs[0] = (&rtmGetTPtr
      (Simulation4Draft_M)[0]);
    Simulation4Draft_M->NonInlinedSFcns.taskTimePtrs[1] = (&rtmGetTPtr
      (Simulation4Draft_M)[1]);
    Simulation4Draft_M->NonInlinedSFcns.taskTimePtrs[2] = (&rtmGetTPtr
      (Simulation4Draft_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,Simulation4Draft_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Simulation4Draft_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Simulation4Draft_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Simulation4Draft_M));
    rtssSetStepSizePtr(sfcnInfo, &Simulation4Draft_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Simulation4Draft_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Simulation4Draft_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Simulation4Draft_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Simulation4Draft_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Simulation4Draft_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Simulation4Draft_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Simulation4Draft_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Simulation4Draft_M->solverInfoPtr);
  }

  Simulation4Draft_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&Simulation4Draft_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    Simulation4Draft_M->childSfunctions =
      (&Simulation4Draft_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Simulation4Draft_M->childSfunctions[0] =
      (&Simulation4Draft_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: Simulation4Draft/<S7>/Soft Real Time (sfun_time) */
    {
      SimStruct *rts = Simulation4Draft_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Simulation4Draft_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Simulation4Draft_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Simulation4Draft_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Simulation4Draft_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Simulation4Draft_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Simulation4Draft_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Simulation4Draft_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Simulation4Draft_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Simulation4Draft_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Simulation4Draft_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Simulation4Draft_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "Soft Real Time");
      ssSetPath(rts, "Simulation4Draft/Robot Simulator/Soft Real Time");
      ssSetRTModel(rts,Simulation4Draft_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Simulation4Draft_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Simulation4Draft_P.SoftRealTime_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Simulation4Draft_DW.SoftRealTime_RWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Simulation4Draft_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Simulation4Draft_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Simulation4Draft_DW.SoftRealTime_RWORK);
      }

      /* registration */
      sfun_time(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }
  }

  {
    static const uint32_T tmp[625] = { 5489U, 1301868182U, 2938499221U,
      2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
      219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
      3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U,
      2982310801U, 1586906132U, 1951078751U, 1808158765U, 1733897588U,
      431328322U, 4202539044U, 530658942U, 1714810322U, 3025256284U, 3342585396U,
      1937033938U, 2640572511U, 1654299090U, 3692403553U, 4233871309U,
      3497650794U, 862629010U, 2943236032U, 2426458545U, 1603307207U,
      1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U, 761573964U,
      3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U, 3295982469U,
      1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
      699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
      1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
      3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U,
      2995682783U, 1620962684U, 3704723357U, 371613603U, 2814834333U,
      2111005706U, 624778151U, 2094172212U, 4284947003U, 1211977835U, 991917094U,
      1570449747U, 2962370480U, 1259410321U, 170182696U, 146300961U, 2836829791U,
      619452428U, 2723670296U, 1881399711U, 1161269684U, 1675188680U,
      4132175277U, 780088327U, 3409462821U, 1036518241U, 1834958505U,
      3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U, 1924681712U,
      3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
      3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
      2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
      3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
      819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
      1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
      2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U,
      2277067795U, 4131855432U, 2722057515U, 1264804546U, 3848622725U,
      2211267957U, 4100593547U, 959123777U, 2130745407U, 3194437393U, 486673947U,
      1377371204U, 17472727U, 352317554U, 3955548058U, 159652094U, 1232063192U,
      3835177280U, 49423123U, 3083993636U, 733092U, 2120519771U, 2573409834U,
      1112952433U, 3239502554U, 761045320U, 1087580692U, 2540165110U, 641058802U,
      1792435497U, 2261799288U, 1579184083U, 627146892U, 2165744623U,
      2200142389U, 2167590760U, 2381418376U, 1793358889U, 3081659520U,
      1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
      3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
      3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
      354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
      1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
      1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
      171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U,
      1708711359U, 1970023127U, 2859691344U, 2588476477U, 2748146879U,
      136111222U, 2967685492U, 909517429U, 2835297809U, 3206906216U, 3186870716U,
      341264097U, 2542035121U, 3353277068U, 548223577U, 3170936588U, 1678403446U,
      297435620U, 2337555430U, 466603495U, 1132321815U, 1208589219U, 696392160U,
      894244439U, 2562678859U, 470224582U, 3306867480U, 201364898U, 2075966438U,
      1767227936U, 2929737987U, 3674877796U, 2654196643U, 3692734598U,
      3528895099U, 2796780123U, 3048728353U, 842329300U, 191554730U, 2922459673U,
      3489020079U, 3979110629U, 1022523848U, 2202932467U, 3583655201U,
      3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U, 396426791U,
      3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
      3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
      2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
      1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U,
      903417639U, 1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U,
      2493544470U, 1008604435U, 1756003503U, 1488867287U, 1386808992U,
      732088248U, 1780630732U, 2482101014U, 976561178U, 1543448953U, 2602866064U,
      2021139923U, 1952599828U, 2360242564U, 2117959962U, 2753061860U,
      2388623612U, 4138193781U, 2962920654U, 2284970429U, 766920861U,
      3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
      3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
      686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
      4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U,
      1170874362U, 2008609376U, 3260320415U, 2211196135U, 433538229U,
      2728786374U, 2189520818U, 262554063U, 1182318347U, 3710237267U,
      1221022450U, 715966018U, 2417068910U, 2591870721U, 2870691989U,
      3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
      4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
      1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
      422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
      1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U,
      539474248U, 1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U,
      2605208763U, 1441755014U, 181878989U, 3124053868U, 1447103986U,
      3183906156U, 1728556020U, 3502241336U, 3055466967U, 1013272474U,
      818402132U, 1715099063U, 2900113506U, 397254517U, 4194863039U, 1009068739U,
      232864647U, 2540223708U, 2608288560U, 2415367765U, 478404847U, 3455100648U,
      3182600021U, 2115988978U, 434269567U, 4117179324U, 3461774077U, 887256537U,
      3545801025U, 286388911U, 3451742129U, 1981164769U, 786667016U, 3310123729U,
      3097811076U, 2224235657U, 2959658883U, 3370969234U, 2514770915U,
      3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
      4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
      1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U,
      3177020907U, 2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U,
      2114162633U, 3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U,
      171987910U, 1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U,
      1922855120U, 835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U,
      3376881639U, 2287770315U, 1658692645U, 1262815245U, 3957234326U,
      1168096164U, 2968737525U, 2655813712U, 2132313144U, 3976047964U,
      326516571U, 353088456U, 3679188938U, 3205649712U, 2654036126U, 1249024881U,
      880166166U, 691800469U, 2229503665U, 1673458056U, 4032208375U, 1851778863U,
      2563757330U, 376742205U, 1794655231U, 340247333U, 1505873033U, 396524441U,
      879666767U, 3335579166U, 3260764261U, 3335999539U, 506221798U, 4214658741U,
      975887814U, 2080536343U, 3360539560U, 571586418U, 138896374U, 4234352651U,
      2737620262U, 3928362291U, 1516365296U, 38056726U, 3599462320U, 3585007266U,
      3850961033U, 471667319U, 1536883193U, 2310166751U, 1861637689U,
      2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
      2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
      643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
      3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U,
      3979815115U, 2567840007U, 4116821529U, 213304419U, 4125718577U,
      1473064925U, 2442436592U, 1893310111U, 4195361916U, 3747569474U,
      828465101U, 2991227658U, 750582866U, 1205170309U, 1409813056U, 678418130U,
      1171531016U, 3821236156U, 354504587U, 4202874632U, 3882511497U,
      1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U, 3725758099U,
      831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U, 3358210805U,
      4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U, 190157081U,
      3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
      2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
      453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
      3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
      1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
      705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
      2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U,
      1367820199U, 2369854699U, 2844269403U, 79981964U, 624U };

    /* Start for S-Function (sfun_time): '<S7>/Soft Real Time' */
    /* Level2 S-Function Block: '<S7>/Soft Real Time' (sfun_time) */
    {
      SimStruct *rts = Simulation4Draft_M->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for MATLABSystem: '<Root>/Random Integer Generator' */
    Simulation4Draft_DW.method = 7U;
    Simulation4Draft_DW.state_not_empty_d = true;
    Simulation4Draft_DW.state = 1144108930U;
    Simulation4Draft_DW.state_not_empty = true;
    Simulation4Draft_DW.state_f[0] = 362436069U;
    Simulation4Draft_DW.state_f[1] = 521288629U;
    Simulation4Draft_DW.method_not_empty = true;
    memcpy(&Simulation4Draft_DW.state_p[0], &tmp[0], 625U * sizeof(uint32_T));
    Simulation4Draft_DW.state_not_empty_f = true;
    Simulation4Draft_DW.objisempty = true;
    Simulation4Draft_DW.obj.isInitialized = 1;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator2' */
  Simulation4Draft_DW.DiscreteTimeIntegrator2_DSTATE =
    Simulation4Draft_P.RobotSimulator_startTheta * 0.017453292519943295;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE =
    Simulation4Draft_P.RobotSimulator_startX;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */
  Simulation4Draft_DW.DiscreteTimeIntegrator1_DSTATE =
    Simulation4Draft_P.RobotSimulator_startY;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_d =
    Simulation4Draft_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteStateSpace: '<S62>/Internal' */
  Simulation4Draft_DW.Internal_DSTATE[0] = 0.0;
  Simulation4Draft_DW.Internal_DSTATE[1] = 0.0;
  Simulation4Draft_DW.Internal_DSTATE[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_j =
    Simulation4Draft_P.DiscreteTimeIntegrator_IC_e;

  /* InitializeConditions for DiscreteStateSpace: '<S70>/Internal' */
  Simulation4Draft_DW.Internal_DSTATE_n[0] = 0.0;
  Simulation4Draft_DW.Internal_DSTATE_n[1] = 0.0;
  Simulation4Draft_DW.Internal_DSTATE_n[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Simulation4Draft_DW.DiscreteTimeIntegrator_DSTATE_n =
    Simulation4Draft_P.DiscreteTimeIntegrator_IC_f;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Simulation4Draft_DW.DiscreteTimeIntegrator1_DSTAT_d =
    Simulation4Draft_P.DiscreteTimeIntegrator1_IC;

  /* SystemInitialize for Chart: '<Root>/Line Following' */
  Simulation4Draft_DW.temporalCounter_i1 = 0U;
  Simulation4Draft_DW.is_active_c1_Simulation4Draft = 0U;
  Simulation4Draft_DW.is_c1_Simulation4Draft = Simulation4D_IN_NO_ACTIVE_CHILD;
  Simulation4Draft_DW.dir = 0.0;
  Simulation4Draft_B.v = 0.0;
  Simulation4Draft_B.data = 0.0;
  Simulation4Draft_B.w = 0.0;
}

/* Model terminate function */
void Simulation4Draft_terminate(void)
{
  /* Terminate for S-Function (sfun_time): '<S7>/Soft Real Time' */
  /* Level2 S-Function Block: '<S7>/Soft Real Time' (sfun_time) */
  {
    SimStruct *rts = Simulation4Draft_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}
