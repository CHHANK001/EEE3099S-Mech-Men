/*
 * Line_following.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Line_following".
 *
 * Model version              : 5.20
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Oct  5 15:04:30 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Line_following.h"
#include "rtwtypes.h"
#include <string.h>
#include "Line_following_types.h"
#include <math.h>
#include "Line_following_private.h"

/* Named constants for Chart: '<Root>/Line Folwing' */
#define Line_followi_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Line_followin_IN_ObjectDetected ((uint8_T)8U)
#define Line_following_IN_CorrectLeft  ((uint8_T)1U)
#define Line_following_IN_CorrectLeft1 ((uint8_T)2U)
#define Line_following_IN_CorrectRight ((uint8_T)3U)
#define Line_following_IN_CorrectRight1 ((uint8_T)4U)
#define Line_following_IN_Drive        ((uint8_T)5U)
#define Line_following_IN_End          ((uint8_T)6U)
#define Line_following_IN_EndOfLine    ((uint8_T)7U)
#define Line_following_IN_Random       ((uint8_T)9U)
#define Line_following_IN_TurnAround   ((uint8_T)10U)
#define Line_following_IN_TurnAround1  ((uint8_T)11U)
#define Line_following_IN_TurnLeft     ((uint8_T)12U)
#define Line_following_IN_TurnRight    ((uint8_T)13U)
#define Line_following_IN_WeOUT        ((uint8_T)14U)
#define Line_following_IN_checkEnd     ((uint8_T)15U)
#define Line_following_IN_notEnd       ((uint8_T)16U)
#define Line_following_IN_update       ((uint8_T)17U)

/* Block signals (default storage) */
B_Line_following_T Line_following_B;

/* Block states (default storage) */
DW_Line_following_T Line_following_DW;

/* Real-time model */
static RT_MODEL_Line_following_T Line_following_M_;
RT_MODEL_Line_following_T *const Line_following_M = &Line_following_M_;

/* Forward declaration for local functions */
static void Line_following_Drive(void);
static void Line_following_checkEnd(void);
static real_T Line_following_rand(void);
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
void Line_following_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Line_following_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Line_following_M, 2));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2 */
  Line_following_M->Timing.RateInteraction.TID0_1 =
    (Line_following_M->Timing.TaskCounters.TID[1] == 0);
  Line_following_M->Timing.RateInteraction.TID0_2 =
    (Line_following_M->Timing.TaskCounters.TID[2] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Line_following_M->Timing.TaskCounters.TID[1])++;
  if ((Line_following_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Line_following_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Line_following_M->Timing.TaskCounters.TID[2])++;
  if ((Line_following_M->Timing.TaskCounters.TID[2]) > 299) {/* Sample time: [3.0s, 0.0s] */
    Line_following_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Function for Chart: '<Root>/Line Folwing' */
static void Line_following_Drive(void)
{
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_1;
  boolean_T tmp_2;
  Line_following_B.v = 0.12;
  Line_following_B.w = 0.0;
  tmp = !Line_following_B.TmpRTBAtLineFolwingInport1;
  if (Line_following_B.TmpRTBAtLineFolwingInport2 && tmp &&
      Line_following_B.TmpRTBAtLineFolwingInport4 &&
      Line_following_B.TmpRTBAtLineFolwingInport3) {
    Line_following_DW.is_c1_Line_following = Line_following_IN_CorrectRight;
    Line_following_B.w = -3.0;
  } else {
    tmp_0 = !Line_following_B.TmpRTBAtLineFolwingInport2;
    tmp_1 = !Line_following_B.TmpRTBAtLineFolwingInport3;
    tmp_2 = !Line_following_B.TmpRTBAtLineFolwingInport4;
    if (tmp_2 && tmp_0 && tmp && tmp_1) {
      Line_following_DW.is_c1_Line_following = Line_following_IN_checkEnd;
      Line_following_DW.temporalCounter_i1 = 0U;
    } else {
      tmp = ((Line_following_DW.temporalCounter_i1 >= 50U) && tmp_0 && tmp);
      if (tmp && tmp_1 && Line_following_B.TmpRTBAtLineFolwingInport4) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_TurnRight;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = -3.0;
      } else if (tmp_0 && Line_following_B.TmpRTBAtLineFolwingInport1 &&
                 Line_following_B.TmpRTBAtLineFolwingInport4 &&
                 Line_following_B.TmpRTBAtLineFolwingInport3) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_CorrectLeft;
        Line_following_B.w = 3.0;
      } else if (Line_following_B.UltrasonicSensor != 0.0) {
        Line_following_DW.is_c1_Line_following = Line_followin_IN_ObjectDetected;
      } else if (tmp && tmp_2) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_TurnLeft;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = 3.0;
      } else if (Line_following_B.TmpRTBAtLineFolwingInport4 &&
                 Line_following_B.TmpRTBAtLineFolwingInport2 &&
                 Line_following_B.TmpRTBAtLineFolwingInport1 &&
                 Line_following_B.TmpRTBAtLineFolwingInport3) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_EndOfLine;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.v = 0.0;
      }
    }
  }
}

/* Function for Chart: '<Root>/Line Folwing' */
static void Line_following_checkEnd(void)
{
  boolean_T tmp;
  Line_following_B.v = 0.12;
  if ((Line_following_DW.temporalCounter_i1 >= 50U) &&
      Line_following_B.TmpRTBAtLineFolwingInport4 &&
      Line_following_B.TmpRTBAtLineFolwingInport2 &&
      Line_following_B.TmpRTBAtLineFolwingInport1 &&
      Line_following_B.TmpRTBAtLineFolwingInport3) {
    Line_following_DW.is_c1_Line_following = Line_following_IN_notEnd;
    Line_following_DW.temporalCounter_i1 = 0U;
    Line_following_B.v = -0.12;
  } else {
    tmp = ((Line_following_DW.temporalCounter_i1 >= 50U) &&
           (!Line_following_B.TmpRTBAtLineFolwingInport4) &&
           (!Line_following_B.TmpRTBAtLineFolwingInport2) &&
           (!Line_following_B.TmpRTBAtLineFolwingInport1) &&
           (!Line_following_B.TmpRTBAtLineFolwingInport3));
    if (tmp && (Line_following_DW.i == 0.0)) {
      Line_following_DW.is_c1_Line_following = Line_following_IN_End;
      Line_following_DW.temporalCounter_i1 = 0U;
      Line_following_B.v = 0.0;
      Line_following_B.w = 0.0;
      Line_following_DW.i = 1.0;
    } else if (tmp && (Line_following_DW.i == 1.0)) {
      Line_following_DW.is_c1_Line_following = Line_following_IN_TurnAround;
      Line_following_DW.temporalCounter_i1 = 0U;
      Line_following_B.v = 0.0;
      Line_following_B.w = 3.0;
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

static real_T Line_following_rand(void)
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
  if (Line_following_DW.method == 4U) {
    k = (int32_T)(Line_following_DW.state / 127773U);
    mti = (Line_following_DW.state - (uint32_T)k * 127773U) * 16807U;
    y = 2836U * (uint32_T)k;
    if (mti < y) {
      Line_following_DW.state = ~(y - mti) & 2147483647U;
    } else {
      Line_following_DW.state = mti - y;
    }

    r = (real_T)Line_following_DW.state * 4.6566128752457969E-10;
  } else if (Line_following_DW.method == 5U) {
    mti = 69069U * Line_following_DW.state_f[0] + 1234567U;
    y = Line_following_DW.state_f[1] << 13 ^ Line_following_DW.state_f[1];
    y ^= y >> 17;
    y ^= y << 5;
    Line_following_DW.state_f[0] = mti;
    Line_following_DW.state_f[1] = y;
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
        mti = Line_following_DW.state_p[624] + 1U;
        if (Line_following_DW.state_p[624] + 1U >= 625U) {
          for (b_kk = 0; b_kk < 227; b_kk++) {
            y = (Line_following_DW.state_p[b_kk + 1] & 2147483647U) |
              (Line_following_DW.state_p[b_kk] & 2147483648U);
            if ((y & 1U) == 0U) {
              mti = y >> 1U;
            } else {
              mti = y >> 1U ^ 2567483615U;
            }

            Line_following_DW.state_p[b_kk] = Line_following_DW.state_p[b_kk +
              397] ^ mti;
          }

          for (b_kk = 0; b_kk < 396; b_kk++) {
            y = (Line_following_DW.state_p[b_kk + 227] & 2147483648U) |
              (Line_following_DW.state_p[b_kk + 228] & 2147483647U);
            if ((y & 1U) == 0U) {
              mti = y >> 1U;
            } else {
              mti = y >> 1U ^ 2567483615U;
            }

            Line_following_DW.state_p[b_kk + 227] =
              Line_following_DW.state_p[b_kk] ^ mti;
          }

          y = (Line_following_DW.state_p[623] & 2147483648U) |
            (Line_following_DW.state_p[0] & 2147483647U);
          if ((y & 1U) == 0U) {
            mti = y >> 1U;
          } else {
            mti = y >> 1U ^ 2567483615U;
          }

          Line_following_DW.state_p[623] = Line_following_DW.state_p[396] ^ mti;
          mti = 1U;
        }

        y = Line_following_DW.state_p[(int32_T)mti - 1];
        Line_following_DW.state_p[624] = mti;
        y ^= y >> 11U;
        y ^= y << 7U & 2636928640U;
        y ^= y << 15U & 4022730752U;
        b_u[k] = y >> 18U ^ y;
      }

      r = ((real_T)(b_u[0] >> 5U) * 6.7108864E+7 + (real_T)(b_u[1] >> 6U)) *
        1.1102230246251565E-16;
      if (r == 0.0) {
        if ((Line_following_DW.state_p[624] >= 1U) &&
            (Line_following_DW.state_p[624] < 625U)) {
          b_isvalid = true;
        } else {
          b_isvalid = false;
        }

        if (b_isvalid) {
          b_isvalid = false;
          k = 0;
          exitg2 = false;
          while ((!exitg2) && (k + 1 < 625)) {
            if (Line_following_DW.state_p[k] == 0U) {
              k++;
            } else {
              b_isvalid = true;
              exitg2 = true;
            }
          }
        }

        if (!b_isvalid) {
          mti = 5489U;
          Line_following_DW.state_p[0] = 5489U;
          for (k = 0; k < 623; k++) {
            mti = ((mti >> 30U ^ mti) * 1812433253U + (uint32_T)k) + 1U;
            Line_following_DW.state_p[k + 1] = mti;
          }

          Line_following_DW.state_p[624] = 624U;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return r;
}

/* Model step function for TID0 */
void Line_following_step0(void)        /* Sample time: [0.01s, 0.0s] */
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_vtow_idx_0;
  real_T rtb_vtow_idx_1;
  real_T u0;
  uint32_T duration;
  uint8_T tmp;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<Root>/Line Folwing' */
  if (Line_following_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport1 =
      Line_following_DW.TmpRTBAtLineFolwingInport1_Buff;

    /* RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport2 =
      Line_following_DW.TmpRTBAtLineFolwingInport2_Buff;

    /* RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport3 =
      Line_following_DW.TmpRTBAtLineFolwingInport3_Buff;

    /* RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport4 =
      Line_following_DW.TmpRTBAtLineFolwingInport4_Buff;
  }

  /* End of RateTransition generated from: '<Root>/Line Folwing' */

  /* RateTransition generated from: '<Root>/Line Folwing' */
  if (Line_following_M->Timing.RateInteraction.TID0_2) {
    /* RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport6 =
      Line_following_DW.TmpRTBAtLineFolwingInport6_Buff;
  }

  /* End of RateTransition generated from: '<Root>/Line Folwing' */

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (Line_following_DW.obj_bs.TunablePropsChanged) {
    Line_following_DW.obj_bs.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 13, 12, 10);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  Line_following_B.UltrasonicSensor = (real_T)duration * 0.000343 / 2.0;

  /* Chart: '<Root>/Line Folwing' */
  if (Line_following_DW.temporalCounter_i1 < 511U) {
    Line_following_DW.temporalCounter_i1++;
  }

  if (Line_following_DW.is_active_c1_Line_following == 0U) {
    Line_following_DW.is_active_c1_Line_following = 1U;
    Line_following_DW.is_c1_Line_following = Line_following_IN_Drive;
    Line_following_DW.temporalCounter_i1 = 0U;
    Line_following_B.v = 0.12;
    Line_following_B.w = 0.0;
  } else {
    switch (Line_following_DW.is_c1_Line_following) {
     case Line_following_IN_CorrectLeft:
      Line_following_B.v = 0.12;
      Line_following_B.w = 3.0;
      if ((!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_Drive;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = 0.0;
      }
      break;

     case Line_following_IN_CorrectLeft1:
      Line_following_B.w = 3.0;
      if ((!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_followin_IN_ObjectDetected;
        Line_following_B.v = 0.12;
      }
      break;

     case Line_following_IN_CorrectRight:
      Line_following_B.v = 0.12;
      Line_following_B.w = -3.0;
      if ((!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_Drive;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = 0.0;
      }
      break;

     case Line_following_IN_CorrectRight1:
      Line_following_B.w = -3.0;
      if ((!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_followin_IN_ObjectDetected;
        Line_following_B.v = 0.12;
      }
      break;

     case Line_following_IN_Drive:
      Line_following_Drive();
      break;

     case Line_following_IN_End:
      Line_following_B.v = 0.0;
      Line_following_B.w = 0.0;
      if (Line_following_DW.temporalCounter_i1 >= 300U) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_TurnAround;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = 3.0;
      }
      break;

     case Line_following_IN_EndOfLine:
      Line_following_B.v = 0.0;
      if ((Line_following_B.UltrasonicSensor < Line_following_DW.data1) &&
          (Line_following_B.UltrasonicSensor != 0.0) && (Line_following_DW.i ==
           0.0)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_update;
        Line_following_DW.data1 = Line_following_B.UltrasonicSensor;
      } else if (Line_following_DW.temporalCounter_i1 >= 100U) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_TurnAround1;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = 3.0;
      } else if ((Line_following_DW.i == 1.0) &&
                 (Line_following_B.UltrasonicSensor == Line_following_DW.data1))
      {
        Line_following_DW.is_c1_Line_following = Line_following_IN_WeOUT;
        Line_following_B.w = 0.0;
      }
      break;

     case Line_followin_IN_ObjectDetected:
      Line_following_B.v = 0.12;
      if ((!Line_following_B.TmpRTBAtLineFolwingInport4) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport3)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_EndOfLine;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.v = 0.0;
      } else if (Line_following_B.TmpRTBAtLineFolwingInport2 &&
                 (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_CorrectRight1;
        Line_following_B.w = -3.0;
      } else if ((!Line_following_B.TmpRTBAtLineFolwingInport2) &&
                 Line_following_B.TmpRTBAtLineFolwingInport1) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_CorrectLeft1;
        Line_following_B.w = 3.0;
      }
      break;

     case Line_following_IN_Random:
      if (!Line_following_B.TmpRTBAtLineFolwingInport6) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_TurnRight;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.v = 0.12;
        Line_following_B.w = -3.0;
      } else {
        Line_following_DW.is_c1_Line_following = Line_following_IN_TurnLeft;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.v = 0.12;
        Line_following_B.w = 3.0;
      }
      break;

     case Line_following_IN_TurnAround:
      Line_following_B.v = 0.0;
      Line_following_B.w = 3.0;
      if ((Line_following_DW.temporalCounter_i1 >= 200U) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_Drive;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.v = 0.12;
        Line_following_B.w = 0.0;
      }
      break;

     case Line_following_IN_TurnAround1:
      Line_following_B.w = 3.0;
      if ((Line_following_DW.temporalCounter_i1 >= 100U) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_Drive;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.v = 0.12;
        Line_following_B.w = 0.0;
      }
      break;

     case Line_following_IN_TurnLeft:
      Line_following_B.v = 0.12;
      Line_following_B.w = 3.0;
      if ((!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1) &&
          (Line_following_DW.temporalCounter_i1 >= 50U)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_Drive;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = 0.0;
      }
      break;

     case Line_following_IN_TurnRight:
      Line_following_B.v = 0.12;
      Line_following_B.w = -3.0;
      if ((Line_following_DW.temporalCounter_i1 >= 50U) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport2) &&
          (!Line_following_B.TmpRTBAtLineFolwingInport1)) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_Drive;
        Line_following_DW.temporalCounter_i1 = 0U;
        Line_following_B.w = 0.0;
      }
      break;

     case Line_following_IN_WeOUT:
      Line_following_B.v = 0.0;
      Line_following_B.w = 0.0;
      break;

     case Line_following_IN_checkEnd:
      Line_following_checkEnd();
      break;

     case Line_following_IN_notEnd:
      Line_following_B.v = -0.12;
      if (Line_following_DW.temporalCounter_i1 >= 50U) {
        Line_following_DW.is_c1_Line_following = Line_following_IN_Random;
      }
      break;

     default:
      /* case IN_update: */
      Line_following_DW.is_c1_Line_following = Line_following_IN_EndOfLine;
      Line_following_DW.temporalCounter_i1 = 0U;
      Line_following_B.v = 0.0;
      break;
    }
  }

  /* End of Chart: '<Root>/Line Folwing' */

  /* Gain: '<S2>/vtow' incorporates:
   *  Gain: '<S2>/change parameters'
   *  SignalConversion generated from: '<S2>/change parameters'
   */
  u0 = 1.0 / Line_following_P.Towlwr_wheelR;
  rtb_vtow_idx_0 = (Line_following_P.changeparameters_Gain[0] *
                    Line_following_B.v + Line_following_P.changeparameters_Gain
                    [2] * Line_following_B.w) * u0;
  rtb_vtow_idx_1 = (Line_following_P.changeparameters_Gain[1] *
                    Line_following_B.v + Line_following_P.changeparameters_Gain
                    [3] * Line_following_B.w) * u0;

  /* MATLABSystem: '<Root>/Left PWM' */
  obj = &Line_following_DW.obj_f;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);

  /* Lookup_n-D: '<Root>/Left Motor LUT' incorporates:
   *  Abs: '<Root>/Abs1'
   */
  u0 = Line_following_P.InputPWM[plook_u32d_binckan(fabs(rtb_vtow_idx_0),
    Line_following_P.WheelSpeed, 172U)];

  /* MATLABSystem: '<Root>/Left PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(Line_following_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  if (rtb_vtow_idx_0 > Line_following_P.Switch_Threshold) {
    rtb_vtow_idx_0 = Line_following_P.Constant2_Value;
  } else {
    rtb_vtow_idx_0 = Line_following_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<Root>/Left motor back' */
  u0 = rt_roundd_snf(rtb_vtow_idx_0);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(5, tmp);

  /* End of MATLABSystem: '<Root>/Left motor back' */

  /* MATLABSystem: '<Root>/Left motor forward' incorporates:
   *  Logic: '<Root>/NOT'
   */
  writeDigitalPin(4, (uint8_T)!(rtb_vtow_idx_0 != 0.0));

  /* MATLABSystem: '<Root>/Right PWM' */
  obj = &Line_following_DW.obj_p;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);

  /* Lookup_n-D: '<Root>/Left Motor LUT1' incorporates:
   *  Abs: '<Root>/Abs'
   */
  u0 = Line_following_P.InputPWM[plook_u32d_binckan(fabs(rtb_vtow_idx_1),
    Line_following_P.WheelSpeed, 172U)];

  /* MATLABSystem: '<Root>/Right PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(Line_following_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  if (rtb_vtow_idx_1 > Line_following_P.Switch1_Threshold) {
    rtb_vtow_idx_1 = Line_following_P.Constant4_Value;
  } else {
    rtb_vtow_idx_1 = Line_following_P.Constant5_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLABSystem: '<Root>/Right motor back' */
  u0 = rt_roundd_snf(rtb_vtow_idx_1);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<Root>/Right motor back' */

  /* MATLABSystem: '<Root>/Right motor forward' incorporates:
   *  Logic: '<Root>/NOT1'
   */
  writeDigitalPin(6, (uint8_T)!(rtb_vtow_idx_1 != 0.0));
}

/* Model step function for TID1 */
void Line_following_step1(void)        /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_sense3;

  /* MATLABSystem: '<Root>/sense3' */
  if (Line_following_DW.obj_h.SampleTime != Line_following_P.sense3_SampleTime)
  {
    Line_following_DW.obj_h.SampleTime = Line_following_P.sense3_SampleTime;
  }

  rtb_sense3 = readDigitalPin(9);

  /* End of MATLABSystem: '<Root>/sense3' */

  /* RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport1_Buff = rtb_sense3;

  /* MATLABSystem: '<Root>/sense2' */
  if (Line_following_DW.obj_b.SampleTime != Line_following_P.sense2_SampleTime)
  {
    Line_following_DW.obj_b.SampleTime = Line_following_P.sense2_SampleTime;
  }

  rtb_sense3 = readDigitalPin(10);

  /* End of MATLABSystem: '<Root>/sense2' */

  /* RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport2_Buff = rtb_sense3;

  /* MATLABSystem: '<Root>/sense4' */
  if (Line_following_DW.obj.SampleTime != Line_following_P.sense4_SampleTime) {
    Line_following_DW.obj.SampleTime = Line_following_P.sense4_SampleTime;
  }

  rtb_sense3 = readDigitalPin(8);

  /* End of MATLABSystem: '<Root>/sense4' */

  /* RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport3_Buff = rtb_sense3;

  /* MATLABSystem: '<Root>/sense1' */
  if (Line_following_DW.obj_m.SampleTime != Line_following_P.sense1_SampleTime)
  {
    Line_following_DW.obj_m.SampleTime = Line_following_P.sense1_SampleTime;
  }

  rtb_sense3 = readDigitalPin(11);

  /* End of MATLABSystem: '<Root>/sense1' */

  /* RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport4_Buff = rtb_sense3;
}

/* Model step function for TID2 */
void Line_following_step2(void)        /* Sample time: [3.0s, 0.0s] */
{
  real_T b;
  boolean_T rtb_RandomIntegerGenerator;

  /* MATLABSystem: '<Root>/Random Integer Generator' */
  b = Line_following_rand();
  rtb_RandomIntegerGenerator = (floor(b * 2.0) != 0.0);

  /* RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport6_Buff = rtb_RandomIntegerGenerator;
}

/* Model initialize function */
void Line_following_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Line_following_M, 0,
                sizeof(RT_MODEL_Line_following_T));

  /* block I/O */
  (void) memset(((void *) &Line_following_B), 0,
                sizeof(B_Line_following_T));

  /* states (dwork) */
  (void) memset((void *)&Line_following_DW, 0,
                sizeof(DW_Line_following_T));

  {
    codertarget_arduinobase_inter_T *obj;
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

    /* Start for RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport1 =
      Line_following_P.TmpRTBAtLineFolwingInport1_Init;

    /* Start for RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport2 =
      Line_following_P.TmpRTBAtLineFolwingInport2_Init;

    /* Start for RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport3 =
      Line_following_P.TmpRTBAtLineFolwingInport3_Init;

    /* Start for RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport4 =
      Line_following_P.TmpRTBAtLineFolwingInport4_Init;

    /* Start for RateTransition generated from: '<Root>/Line Folwing' */
    Line_following_B.TmpRTBAtLineFolwingInport6 =
      Line_following_P.TmpRTBAtLineFolwingInport6_Init;

    /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
    Line_following_DW.objisempty_d = true;
    Line_following_DW.obj_bs.isInitialized = 1;
    MW_UltrasonicSetup(13, 12);
    Line_following_DW.obj_bs.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<Root>/Left PWM' */
    Line_following_DW.obj_f.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_j = true;
    obj = &Line_following_DW.obj_f;
    Line_following_DW.obj_f.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(16U, 0.0, 0.0);
    Line_following_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor back' */
    Line_following_DW.obj_m4.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_hc = true;
    Line_following_DW.obj_m4.isInitialized = 1;
    digitalIOSetup(5, 1);
    Line_following_DW.obj_m4.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left motor forward' */
    Line_following_DW.obj_k.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_e = true;
    Line_following_DW.obj_k.isInitialized = 1;
    digitalIOSetup(4, 1);
    Line_following_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right PWM' */
    Line_following_DW.obj_p.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_mf = true;
    obj = &Line_following_DW.obj_p;
    Line_following_DW.obj_p.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(17U, 0.0, 0.0);
    Line_following_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor back' */
    Line_following_DW.obj_d.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_l = true;
    Line_following_DW.obj_d.isInitialized = 1;
    digitalIOSetup(7, 1);
    Line_following_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Right motor forward' */
    Line_following_DW.obj_hn.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_n = true;
    Line_following_DW.obj_hn.isInitialized = 1;
    digitalIOSetup(6, 1);
    Line_following_DW.obj_hn.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/sense3' */
    Line_following_DW.obj_h.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_f = true;
    Line_following_DW.obj_h.SampleTime = Line_following_P.sense3_SampleTime;
    Line_following_DW.obj_h.isInitialized = 1;
    digitalIOSetup(9, 0);
    Line_following_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/sense2' */
    Line_following_DW.obj_b.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_m = true;
    Line_following_DW.obj_b.SampleTime = Line_following_P.sense2_SampleTime;
    Line_following_DW.obj_b.isInitialized = 1;
    digitalIOSetup(10, 0);
    Line_following_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/sense4' */
    Line_following_DW.obj.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty = true;
    Line_following_DW.obj.SampleTime = Line_following_P.sense4_SampleTime;
    Line_following_DW.obj.isInitialized = 1;
    digitalIOSetup(8, 0);
    Line_following_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/sense1' */
    Line_following_DW.obj_m.matlabCodegenIsDeleted = false;
    Line_following_DW.objisempty_h = true;
    Line_following_DW.obj_m.SampleTime = Line_following_P.sense1_SampleTime;
    Line_following_DW.obj_m.isInitialized = 1;
    digitalIOSetup(11, 0);
    Line_following_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Random Integer Generator' */
    Line_following_DW.method = 7U;
    Line_following_DW.state_not_empty_d = true;
    Line_following_DW.state = 1144108930U;
    Line_following_DW.state_not_empty = true;
    Line_following_DW.state_f[0] = 362436069U;
    Line_following_DW.state_f[1] = 521288629U;
    Line_following_DW.method_not_empty = true;
    memcpy(&Line_following_DW.state_p[0], &tmp[0], 625U * sizeof(uint32_T));
    Line_following_DW.state_not_empty_f = true;
    Line_following_DW.objisempty_b = true;
    Line_following_DW.obj_ba.isInitialized = 1;
  }

  /* InitializeConditions for RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport1_Buff =
    Line_following_P.TmpRTBAtLineFolwingInport1_Init;

  /* InitializeConditions for RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport2_Buff =
    Line_following_P.TmpRTBAtLineFolwingInport2_Init;

  /* InitializeConditions for RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport3_Buff =
    Line_following_P.TmpRTBAtLineFolwingInport3_Init;

  /* InitializeConditions for RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport4_Buff =
    Line_following_P.TmpRTBAtLineFolwingInport4_Init;

  /* InitializeConditions for RateTransition generated from: '<Root>/Line Folwing' */
  Line_following_DW.TmpRTBAtLineFolwingInport6_Buff =
    Line_following_P.TmpRTBAtLineFolwingInport6_Init;

  /* SystemInitialize for Chart: '<Root>/Line Folwing' */
  Line_following_DW.temporalCounter_i1 = 0U;
  Line_following_DW.is_active_c1_Line_following = 0U;
  Line_following_DW.is_c1_Line_following = Line_followi_IN_NO_ACTIVE_CHILD;
  Line_following_DW.i = 0.0;
  Line_following_DW.data1 = 100.0;
  Line_following_B.v = 0.0;
  Line_following_B.w = 0.0;
}

/* Model terminate function */
void Line_following_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Left PWM' */
  obj = &Line_following_DW.obj_f;
  if (!Line_following_DW.obj_f.matlabCodegenIsDeleted) {
    Line_following_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Line_following_DW.obj_f.isInitialized == 1) &&
        Line_following_DW.obj_f.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_SetDutyCycle(Line_following_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_Close(Line_following_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left PWM' */

  /* Terminate for MATLABSystem: '<Root>/Left motor back' */
  if (!Line_following_DW.obj_m4.matlabCodegenIsDeleted) {
    Line_following_DW.obj_m4.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor back' */

  /* Terminate for MATLABSystem: '<Root>/Left motor forward' */
  if (!Line_following_DW.obj_k.matlabCodegenIsDeleted) {
    Line_following_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left motor forward' */

  /* Terminate for MATLABSystem: '<Root>/Right PWM' */
  obj = &Line_following_DW.obj_p;
  if (!Line_following_DW.obj_p.matlabCodegenIsDeleted) {
    Line_following_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Line_following_DW.obj_p.isInitialized == 1) &&
        Line_following_DW.obj_p.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_SetDutyCycle(Line_following_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(17U);
      MW_PWM_Close(Line_following_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right PWM' */

  /* Terminate for MATLABSystem: '<Root>/Right motor back' */
  if (!Line_following_DW.obj_d.matlabCodegenIsDeleted) {
    Line_following_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor back' */

  /* Terminate for MATLABSystem: '<Root>/Right motor forward' */
  if (!Line_following_DW.obj_hn.matlabCodegenIsDeleted) {
    Line_following_DW.obj_hn.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right motor forward' */

  /* Terminate for MATLABSystem: '<Root>/sense3' */
  if (!Line_following_DW.obj_h.matlabCodegenIsDeleted) {
    Line_following_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/sense3' */

  /* Terminate for MATLABSystem: '<Root>/sense2' */
  if (!Line_following_DW.obj_b.matlabCodegenIsDeleted) {
    Line_following_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/sense2' */

  /* Terminate for MATLABSystem: '<Root>/sense4' */
  if (!Line_following_DW.obj.matlabCodegenIsDeleted) {
    Line_following_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/sense4' */

  /* Terminate for MATLABSystem: '<Root>/sense1' */
  if (!Line_following_DW.obj_m.matlabCodegenIsDeleted) {
    Line_following_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/sense1' */
}
