#ifndef RTW_HEADER_Simulation3Draft_h_
#define RTW_HEADER_Simulation3Draft_h_
#ifndef Simulation3Draft_COMMON_INCLUDES_
#define Simulation3Draft_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "slexec_parallel.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Simulation3Draft_types.h"
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Simulation3Draft
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (32) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { int32_T ok2jbhyf1e ; uint32_T h11ovhfoxn ; uint8_T
c2dlt0ce3l ; boolean_T hecpg1s5r3 ; } dznuqijoym ; typedef struct { uint32_T
hz3a5pczoy ; } kq5rtenbu3r ; typedef struct { real_T bm4eudfrr4 [ 201 ] ;
real32_T jz240yzam0 [ 201 ] ; } gz4qqldign ; typedef struct { int32_T
e3evixvwmi ; uint8_T klt5acnwos ; boolean_T pohhf0zdrr ; kq5rtenbu3r
hsodnwhfav [ 201 ] ; } kq5rtenbu3 ; typedef struct { real_T ktg4baxiij ;
real_T cbrh4plvr3 ; real_T athhvkdmdz ; real_T pcgdgayggx ; real_T g0jjedl3h4
; real_T fiztfjj1x3 ; real_T d0xjp4ie5e ; real_T j23fnzwcfw ; real_T
kg0pryf3mc [ 4 ] ; real_T b3jbm402ar ; real_T ojoimenkbs ; real_T hohqowutc2
; real_T plm3guhvpt ; real_T i3sd1i01sd ; real_T om1zkmalu1 ; real_T
cu0343r3i2 ; real_T lg1haipmqu ; real_T evsbnfyjxg ; real_T ooajfnplre ;
real_T kqcugdbf5g ; real_T hnkwggkzou ; real_T lupfetmmtb ; real_T acattgqayi
[ 9 ] ; real_T n4nupykk20 ; real_T jnpqvfwuw0 ; real32_T iitlyzvbjb [ 4 ] ;
gz4qqldign hsodnwhfav [ 1 ] ; } B ; typedef struct { real_T i2qyvx2esr ;
real_T efs3a3hh2e ; real_T ludo5r20l3 ; real_T m4gnknfopa ; real_T b2hfiqnrei
[ 3 ] ; real_T ghbxb2zrik ; real_T i3g2v5ygab [ 3 ] ; real_T gwgdijo4lu ;
real_T dpj2cs1yxt ; real_T mcaxcsndtw ; real_T lgzytb1guk ; real_T glmlggcvnu
; struct { void * LoggedData ; } gx0eezp4oh ; struct { void * LoggedData ; }
ly1uzbh4ws ; struct { void * LoggedData ; } pocqi4rzhx ; int32_T dtffab24fv ;
int32_T g4mgdk51u1 ; int32_T cziarvqn3t ; int32_T bs4xv2f2dq ; uint32_T
cv32usfudo ; uint8_T oc2vv2qobo ; uint8_T p2ujolujvr ; uint8_T fredjixzlu ;
uint8_T p3xvndme1v ; boolean_T o3vvrfpxkk ; boolean_T mbgesywozm ; kq5rtenbu3
hsodnwhfav [ 1 ] ; dznuqijoym plige5liff [ 4 ] ; } DW ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct new1fns3yk_ { real_T
Gain1_Gain ; real_T Bias_Bias ; real_T Gain_Gain ; real_T Bias1_Bias ; real_T
Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T
Saturation3_UpperSat ; real_T Saturation3_LowerSat ; real_T Constant_Value ;
real32_T DirectLookupTablenD_table [ 791911 ] ; uint8_T
DirectLookupTablenD_DiagnosticForOutOfRangeInput ; } ; struct cr03gegb0wu_ {
real_T Gain1_Gain ; real_T Bias_Bias ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T Gain_Gain ; real_T Bias1_Bias ; real_T
Saturation1_UpperSat ; real_T Saturation1_LowerSat ; real_T Constant_Value ;
real_T Constant1_Value ; real32_T DirectLookupTablenD_table [ 791911 ] ;
uint8_T DirectLookupTablenD_DiagnosticForOutOfRangeInput ; } ; struct
cr03gegb0w_ { real_T Constant_Value [ 201 ] ; cr03gegb0wu hsodnwhfav ; } ;
struct P_ { real_T InputPWM [ 173 ] ; real_T WheelSpeed [ 173 ] ; real_T
axleLength ; real_T lineLength ; real_T ticksPerRot ; real_T wheelR ; real_T
PIDController_I ; real_T PIDController_I_i45pwgvuma ; real_T
PIDController_InitialConditionForIntegrator ; real_T
PIDController_InitialConditionForIntegrator_epasr05elh ; real_T
PIDController_LowerSaturationLimit ; real_T
PIDController_LowerSaturationLimit_np30azhqa2 ; real_T PIDController_P ;
real_T PIDController_P_kws2tbogph ; real_T PIDController_UpperSaturationLimit
; real_T PIDController_UpperSaturationLimit_lonuxufgp5 ; real_T
LineSensor_envVal ; real_T LineSensor_lineVal ; real_T LeftMotor_sensorType ;
real_T RightMotor_sensorType ; real_T RobotSimulator_startTheta ; real_T
RobotSimulator_startX ; real_T RobotSimulator_startY ; real_T Towlwr_wheelR ;
real_T Gain_Gain ; real_T Gain_Gain_o4hmcpr5ca ; real_T Constant1_Value ;
real_T Constant1_Value_puhyejpghs ; real_T DiscreteTimeIntegrator_gainval ;
real_T DiscreteTimeIntegrator1_gainval ; real_T
DiscreteTimeIntegrator2_gainval ; real_T
DiscreteTimeIntegrator_gainval_afikqgzpe0 ; real_T DiscreteTimeIntegrator_IC
; real_T Internal_A [ 9 ] ; real_T Internal_B [ 3 ] ; real_T Internal_C [ 3 ]
; real_T Switch_Threshold ; real_T DiscreteTimeIntegrator_gainval_ptlrlhszmg
; real_T DiscreteTimeIntegrator_IC_e3x2ks5ohu ; real_T Internal_A_avp5ztxxzl
[ 9 ] ; real_T Internal_B_ebkdikdi50 [ 3 ] ; real_T Internal_C_hiyczu5j42 [ 3
] ; real_T Switch_Threshold_bmwdvzwwf2 ; real_T SoftRealTime_P1_Size [ 2 ] ;
real_T SoftRealTime_P1 ; real_T changeparameters_Gain [ 4 ] ; real_T
DiscreteTimeIntegrator_gainval_lzyl4k4zxv ; real_T
DiscreteTimeIntegrator_IC_f5z3vyriqm ; real_T
DiscreteTimeIntegrator1_gainval_fz4ugw3les ; real_T
DiscreteTimeIntegrator1_IC ; real_T Gain2_Gain ; real_T Integrator_gainval ;
real_T Gain2_Gain_cq42p4ubq2 ; real_T Gain3_Gain ; real_T
Gain3_Gain_moxmp2rie1 ; real_T Integrator_gainval_di3rudnbjq ; real_T
Circle_Value ; real_T Gain1_Gain ; real_T Constant_Value [ 4 ] ; real_T
Constant1_Value_l3t40ea4hs [ 4 ] ; real_T Constant_Value_djcmpvlzjp ; real_T
Constant1_Value_k2rcs4rpgg ; real_T Clamping_zero_Value ; real_T
DriveDist_Value ; real_T DriveRot_Value ; real_T
Clamping_zero_Value_ojxi3o54um ; real32_T Switch_Threshold_j3y0cmi1bi ;
int8_T Constant_Value_aizakqrn1k ; int8_T Constant2_Value ; int8_T
Constant3_Value ; int8_T Constant4_Value ; int8_T Constant_Value_bkskdfhvuo ;
int8_T Constant2_Value_ntd5a3hqim ; int8_T Constant3_Value_ekyrhetqpn ;
int8_T Constant4_Value_o1rmvqswsf ; cr03gegb0w hsodnwhfav ; new1fns3yk
plige5liff ; } ; extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B
rtB ; extern DW rtDW ; extern P rtP ; extern mxArray *
mr_Simulation3Draft_GetDWork ( ) ; extern void mr_Simulation3Draft_SetDWork (
const mxArray * ssDW ) ; extern mxArray *
mr_Simulation3Draft_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Simulation3Draft_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
