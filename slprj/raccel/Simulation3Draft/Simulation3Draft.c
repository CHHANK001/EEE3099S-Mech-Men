#include "Simulation3Draft.h"
#include "rtwtypes.h"
#include "Simulation3Draft_private.h"
#include <string.h>
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "Simulation3Draft_capi.h"
#include "Simulation3Draft_dt.h"
#include "sfcn_loader_c_api.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.9 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define mivu3qnvf4 (-1)
#define a3qpugknvb (-1)
#define asvf3dhiaz (6U)
#define b3qwlp0ld1 (4U)
#define bid1o4node (8U)
#define enixwnssg5 ((uint8_T)0U)
#define fu0x2nnkp2 (7U)
#define k0ig43i0zc (1U)
#define mbtnfgkvfw (5U)
#define nbkwgunte3 (2U)
#define olbpopzv0e (3U)
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; uint32_T plook_u32d_binckan ( real_T u , const real_T bp [ ] ,
uint32_T maxIndex ) { uint32_T bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex = 0U
; } else if ( u < bp [ maxIndex ] ) { bpIndex = binsearch_u32d ( u , bp ,
maxIndex >> 1U , maxIndex ) ; if ( ( bpIndex < maxIndex ) && ( bp [ bpIndex +
1U ] - u <= u - bp [ bpIndex ] ) ) { bpIndex ++ ; } } else { bpIndex =
maxIndex ; } return bpIndex ; } uint32_T binsearch_u32d ( real_T u , const
real_T bp [ ] , uint32_T startIndex , uint32_T maxIndex ) { uint32_T bpIdx ;
uint32_T bpIndex ; uint32_T iRght ; bpIdx = startIndex ; bpIndex = 0U ; iRght
= maxIndex ; while ( iRght - bpIndex > 1U ) { if ( u < bp [ bpIdx ] ) { iRght
= bpIdx ; } else { bpIndex = bpIdx ; } bpIdx = ( iRght + bpIndex ) >> 1U ; }
return bpIndex ; } void k5sqpz3mnl ( void ) { int32_T ms3ldw4g12 ; for (
ms3ldw4g12 = 0 ; ms3ldw4g12 < 4 ; ms3ldw4g12 ++ ) { rtDW . plige5liff [
ms3ldw4g12 ] . ok2jbhyf1e = mivu3qnvf4 ; rtDW . plige5liff [ ms3ldw4g12 ] .
c2dlt0ce3l = 0U ; } } void cfnt3wn3iq ( void ) { int32_T ms3ldw4g12 ; for (
ms3ldw4g12 = 0 ; ms3ldw4g12 < 4 ; ms3ldw4g12 ++ ) { rtDW . plige5liff [
ms3ldw4g12 ] . h11ovhfoxn = 0U ; } } void lznujbde5u ( int32_T ms3ldw4g12 ) {
real_T cka1l0fd0c ; real_T ifldb15xul ; real32_T oomvy3frlm ; cka1l0fd0c =
rtP . Constant_Value [ ms3ldw4g12 ] ; ifldb15xul = rtP .
Constant1_Value_l3t40ea4hs [ ms3ldw4g12 ] ; { real_T tmp_p [ 9 ] ; real_T
transPt [ 3 ] ; real_T adx4iqiokd ; real_T laahffj5gd ; real_T tmp ; int32_T
i ; SimStruct * S ; void * diag ; rtDW . plige5liff [ ms3ldw4g12 ] .
ok2jbhyf1e = mivu3qnvf4 ; tmp_p [ 0 ] = muDoubleScalarCos ( rtB . athhvkdmdz
) ; tmp_p [ 3 ] = - muDoubleScalarSin ( rtB . athhvkdmdz ) ; tmp_p [ 6 ] =
0.0 ; tmp_p [ 1 ] = muDoubleScalarSin ( rtB . athhvkdmdz ) ; tmp_p [ 4 ] =
muDoubleScalarCos ( rtB . athhvkdmdz ) ; tmp_p [ 7 ] = 0.0 ; tmp_p [ 2 ] =
0.0 ; tmp_p [ 5 ] = 0.0 ; tmp_p [ 8 ] = 1.0 ; for ( i = 0 ; i < 3 ; i ++ ) {
transPt [ i ] = tmp_p [ i + 3 ] * ifldb15xul + tmp_p [ i ] * cka1l0fd0c ; }
adx4iqiokd = muDoubleScalarRound ( rtP . plige5liff . Constant_Value - ( rtB
. cbrh4plvr3 + transPt [ 1 ] ) * rtP . plige5liff . Gain1_Gain ) + rtP .
plige5liff . Bias_Bias ; if ( adx4iqiokd > rtP . plige5liff .
Saturation2_UpperSat ) { adx4iqiokd = rtP . plige5liff . Saturation2_UpperSat
; } else if ( adx4iqiokd < rtP . plige5liff . Saturation2_LowerSat ) {
adx4iqiokd = rtP . plige5liff . Saturation2_LowerSat ; } laahffj5gd =
muDoubleScalarRound ( ( rtB . ktg4baxiij + transPt [ 0 ] ) * rtP . plige5liff
. Gain_Gain ) + rtP . plige5liff . Bias1_Bias ; if ( laahffj5gd > rtP .
plige5liff . Saturation3_UpperSat ) { laahffj5gd = rtP . plige5liff .
Saturation3_UpperSat ; } else if ( laahffj5gd < rtP . plige5liff .
Saturation3_LowerSat ) { laahffj5gd = rtP . plige5liff . Saturation3_LowerSat
; } tmp = muDoubleScalarFloor ( adx4iqiokd ) ; if ( ( rtP . plige5liff .
DirectLookupTablenD_DiagnosticForOutOfRangeInput != 0 ) && ( ( ! ( tmp >= 0.0
) ) || ( ! ( tmp <= 1258.0 ) ) ) ) { if ( rtP . plige5liff .
DirectLookupTablenD_DiagnosticForOutOfRangeInput == 1 ) { if ( rtDW .
plige5liff [ ms3ldw4g12 ] . h11ovhfoxn == 0U ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeWarnMsg" , 1 , 5 ,
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW . plige5liff [
ms3ldw4g12 ] . h11ovhfoxn != 0U ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockNumOfIndexOutOfRangeWarnMsg" , 2 , 5 ,
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
, 1 , rtDW . plige5liff [ ms3ldw4g12 ] . h11ovhfoxn ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW . plige5liff [
ms3ldw4g12 ] . h11ovhfoxn < MAX_uint32_T ) { rtDW . plige5liff [ ms3ldw4g12 ]
. h11ovhfoxn ++ ; } } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeErrorMsg" , 1 , 5 ,
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
) ; rt_ssSet_slErrMsg ( S , diag ) ; } } tmp = muDoubleScalarFloor (
laahffj5gd ) ; if ( ( rtP . plige5liff .
DirectLookupTablenD_DiagnosticForOutOfRangeInput != 0 ) && ( ( ! ( tmp >= 0.0
) ) || ( ! ( tmp <= 628.0 ) ) ) ) { if ( rtP . plige5liff .
DirectLookupTablenD_DiagnosticForOutOfRangeInput == 1 ) { if ( rtDW .
plige5liff [ ms3ldw4g12 ] . h11ovhfoxn == 0U ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeWarnMsg" , 1 , 5 ,
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW . plige5liff [
ms3ldw4g12 ] . h11ovhfoxn != 0U ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockNumOfIndexOutOfRangeWarnMsg" , 2 , 5 ,
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
, 1 , rtDW . plige5liff [ ms3ldw4g12 ] . h11ovhfoxn ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW . plige5liff [
ms3ldw4g12 ] . h11ovhfoxn < MAX_uint32_T ) { rtDW . plige5liff [ ms3ldw4g12 ]
. h11ovhfoxn ++ ; } } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeErrorMsg" , 1 , 5 ,
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
) ; rt_ssSet_slErrMsg ( S , diag ) ; } } if ( muDoubleScalarIsNaN (
laahffj5gd ) ) { laahffj5gd = 0.0 ; } if ( muDoubleScalarIsNaN ( adx4iqiokd )
) { adx4iqiokd = 0.0 ; } if ( laahffj5gd > 628.0 ) { laahffj5gd = 628.0 ; }
else if ( laahffj5gd < 0.0 ) { laahffj5gd = 0.0 ; } if ( adx4iqiokd > 1258.0
) { adx4iqiokd = 1258.0 ; } else if ( adx4iqiokd < 0.0 ) { adx4iqiokd = 0.0 ;
} oomvy3frlm = rtP . plige5liff . DirectLookupTablenD_table [ ( int32_T )
laahffj5gd * 1259 + ( int32_T ) adx4iqiokd ] ; } rtB . iitlyzvbjb [
ms3ldw4g12 ] = oomvy3frlm ; } void biy4dsk3hr ( void ) { int32_T erbe2iepeg ;
for ( erbe2iepeg = 0 ; erbe2iepeg < 201 ; erbe2iepeg ++ ) { rtDW . hsodnwhfav
[ rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] . hz3a5pczoy = 0U ; } }
void o5s2faxrbo ( int32_T erbe2iepeg ) { real_T b2tyk3s5bt [ 3 ] ; real32_T
mc1jd4ertv ; b2tyk3s5bt [ 0 ] = rtB . hsodnwhfav [ rtDW . dtffab24fv ] .
bm4eudfrr4 [ erbe2iepeg ] ; { real_T m3d4gr1ril [ 3 ] ; real_T fdqk4wcm0i ;
real_T my2yrjkuy5 ; real_T tmp ; int32_T i ; SimStruct * S ; void * diag ;
b2tyk3s5bt [ 1 ] = rtB . hnkwggkzou ; b2tyk3s5bt [ 2 ] = rtP . hsodnwhfav .
hsodnwhfav . Constant_Value ; my2yrjkuy5 = b2tyk3s5bt [ 1 ] ; fdqk4wcm0i =
b2tyk3s5bt [ 0 ] ; tmp = b2tyk3s5bt [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) {
m3d4gr1ril [ i ] = ( rtB . acattgqayi [ i + 3 ] * my2yrjkuy5 + rtB .
acattgqayi [ i ] * fdqk4wcm0i ) + rtB . acattgqayi [ i + 6 ] * tmp ; }
my2yrjkuy5 = muDoubleScalarRound ( rtP . hsodnwhfav . hsodnwhfav .
Constant1_Value - ( m3d4gr1ril [ 1 ] + rtB . cbrh4plvr3 ) * rtP . hsodnwhfav
. hsodnwhfav . Gain1_Gain ) + rtP . hsodnwhfav . hsodnwhfav . Bias_Bias ; if
( my2yrjkuy5 > rtP . hsodnwhfav . hsodnwhfav . Saturation_UpperSat ) {
my2yrjkuy5 = rtP . hsodnwhfav . hsodnwhfav . Saturation_UpperSat ; } else if
( my2yrjkuy5 < rtP . hsodnwhfav . hsodnwhfav . Saturation_LowerSat ) {
my2yrjkuy5 = rtP . hsodnwhfav . hsodnwhfav . Saturation_LowerSat ; }
fdqk4wcm0i = muDoubleScalarRound ( ( m3d4gr1ril [ 0 ] + rtB . ktg4baxiij ) *
rtP . hsodnwhfav . hsodnwhfav . Gain_Gain ) + rtP . hsodnwhfav . hsodnwhfav .
Bias1_Bias ; if ( fdqk4wcm0i > rtP . hsodnwhfav . hsodnwhfav .
Saturation1_UpperSat ) { fdqk4wcm0i = rtP . hsodnwhfav . hsodnwhfav .
Saturation1_UpperSat ; } else if ( fdqk4wcm0i < rtP . hsodnwhfav . hsodnwhfav
. Saturation1_LowerSat ) { fdqk4wcm0i = rtP . hsodnwhfav . hsodnwhfav .
Saturation1_LowerSat ; } tmp = muDoubleScalarFloor ( my2yrjkuy5 ) ; if ( (
rtP . hsodnwhfav . hsodnwhfav .
DirectLookupTablenD_DiagnosticForOutOfRangeInput != 0 ) && ( ( ! ( tmp >= 0.0
) ) || ( ! ( tmp <= 1258.0 ) ) ) ) { if ( rtP . hsodnwhfav . hsodnwhfav .
DirectLookupTablenD_DiagnosticForOutOfRangeInput == 1 ) { if ( rtDW .
hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] . hz3a5pczoy ==
0U ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeWarnMsg" , 1 , 5 ,
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW . hsodnwhfav [
rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] . hz3a5pczoy != 0U ) { S =
rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockNumOfIndexOutOfRangeWarnMsg" , 2 , 5 ,
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
, 1 , rtDW . hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] .
hz3a5pczoy ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW .
hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] . hz3a5pczoy <
MAX_uint32_T ) { rtDW . hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [
erbe2iepeg ] . hz3a5pczoy ++ ; } } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeErrorMsg" , 1 , 5 ,
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
) ; rt_ssSet_slErrMsg ( S , diag ) ; } } tmp = muDoubleScalarFloor (
fdqk4wcm0i ) ; if ( ( rtP . hsodnwhfav . hsodnwhfav .
DirectLookupTablenD_DiagnosticForOutOfRangeInput != 0 ) && ( ( ! ( tmp >= 0.0
) ) || ( ! ( tmp <= 628.0 ) ) ) ) { if ( rtP . hsodnwhfav . hsodnwhfav .
DirectLookupTablenD_DiagnosticForOutOfRangeInput == 1 ) { if ( rtDW .
hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] . hz3a5pczoy ==
0U ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeWarnMsg" , 1 , 5 ,
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW . hsodnwhfav [
rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] . hz3a5pczoy != 0U ) { S =
rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockNumOfIndexOutOfRangeWarnMsg" , 2 , 5 ,
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
, 1 , rtDW . hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] .
hz3a5pczoy ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( rtDW .
hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [ erbe2iepeg ] . hz3a5pczoy <
MAX_uint32_T ) { rtDW . hsodnwhfav [ rtDW . dtffab24fv ] . hsodnwhfav [
erbe2iepeg ] . hz3a5pczoy ++ ; } } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeErrorMsg" , 1 , 5 ,
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
) ; rt_ssSet_slErrMsg ( S , diag ) ; } } if ( muDoubleScalarIsNaN (
fdqk4wcm0i ) ) { fdqk4wcm0i = 0.0 ; } if ( muDoubleScalarIsNaN ( my2yrjkuy5 )
) { my2yrjkuy5 = 0.0 ; } if ( fdqk4wcm0i > 628.0 ) { fdqk4wcm0i = 628.0 ; }
else if ( fdqk4wcm0i < 0.0 ) { fdqk4wcm0i = 0.0 ; } if ( my2yrjkuy5 > 1258.0
) { my2yrjkuy5 = 1258.0 ; } else if ( my2yrjkuy5 < 0.0 ) { my2yrjkuy5 = 0.0 ;
} mc1jd4ertv = rtP . hsodnwhfav . hsodnwhfav . DirectLookupTablenD_table [ (
int32_T ) fdqk4wcm0i * 1259 + ( int32_T ) my2yrjkuy5 ] ; } rtB . hsodnwhfav [
rtDW . dtffab24fv ] . jz240yzam0 [ erbe2iepeg ] = mc1jd4ertv ; } void
MdlInitialize ( void ) { rtDW . i2qyvx2esr = rtP . RobotSimulator_startX ;
rtDW . efs3a3hh2e = rtP . RobotSimulator_startY ; rtDW . ludo5r20l3 = rtP .
RobotSimulator_startTheta * 0.017453292519943295 ; rtDW . m4gnknfopa = rtP .
DiscreteTimeIntegrator_IC ; rtDW . b2hfiqnrei [ 0 ] = 0.0 ; rtDW . b2hfiqnrei
[ 1 ] = 0.0 ; rtDW . b2hfiqnrei [ 2 ] = 0.0 ; rtDW . ghbxb2zrik = rtP .
DiscreteTimeIntegrator_IC_e3x2ks5ohu ; rtDW . i3g2v5ygab [ 0 ] = 0.0 ; rtDW .
i3g2v5ygab [ 1 ] = 0.0 ; rtDW . i3g2v5ygab [ 2 ] = 0.0 ; rtDW . gwgdijo4lu =
rtP . DiscreteTimeIntegrator_IC_f5z3vyriqm ; rtDW . dpj2cs1yxt = rtP .
DiscreteTimeIntegrator1_IC ; rtDW . mcaxcsndtw = rtP .
PIDController_InitialConditionForIntegrator ; rtDW . lgzytb1guk = rtP .
PIDController_InitialConditionForIntegrator_epasr05elh ; rtDW . cziarvqn3t =
a3qpugknvb ; rtDW . p2ujolujvr = 0U ; k5sqpz3mnl ( ) ; rtDW . g4mgdk51u1 =
a3qpugknvb ; rtDW . oc2vv2qobo = 0U ; rtDW . dtffab24fv = 0 ; while ( rtDW .
dtffab24fv < 1 ) { rtDW . hsodnwhfav [ rtDW . dtffab24fv ] . e3evixvwmi =
a3qpugknvb ; rtDW . hsodnwhfav [ rtDW . dtffab24fv ] . klt5acnwos = 0U ; rtDW
. dtffab24fv ++ ; } rtDW . bs4xv2f2dq = a3qpugknvb ; rtDW . p3xvndme1v = 0U ;
rtDW . fredjixzlu = 0U ; rtDW . cv32usfudo = enixwnssg5 ; rtB . n4nupykk20 =
0.0 ; rtB . jnpqvfwuw0 = 0.0 ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} cfnt3wn3iq ( ) ; rtDW . dtffab24fv = 0 ; while ( rtDW . dtffab24fv < 1 ) {
memset ( & rtB . hsodnwhfav [ rtDW . dtffab24fv ] . bm4eudfrr4 [ 0 ] , 0 ,
201U * sizeof ( real_T ) ) ; biy4dsk3hr ( ) ; rtDW . dtffab24fv ++ ; } {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; { static const char *
blockSIDForSFcnLoader = "Simulation3Draft:4:401" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = ssGetmdlStart ( rts ) ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T deu1hqt5kj ; real_T jzt0gcydni ; real_T
lffxqlfwyl ; real_T mobryh41lr ; int32_T b_ii ; int32_T i ; int32_T
ii_size_idx_0 ; int8_T tmp ; int8_T tmp_p ; uint8_T ii_data_idx_0 ; boolean_T
exitg1 ; rtB . ktg4baxiij = rtDW . i2qyvx2esr ; rtB . cbrh4plvr3 = rtDW .
efs3a3hh2e ; rtB . athhvkdmdz = muDoubleScalarMod ( rtDW . ludo5r20l3 , rtP .
Circle_Value ) ; rtDW . cziarvqn3t = a3qpugknvb ; { rtB . pcgdgayggx = ( rtP
. Internal_C [ 0 ] ) * rtDW . b2hfiqnrei [ 0 ] + ( rtP . Internal_C [ 1 ] ) *
rtDW . b2hfiqnrei [ 1 ] + ( rtP . Internal_C [ 2 ] ) * rtDW . b2hfiqnrei [ 2
] ; } if ( rtP . LeftMotor_sensorType > rtP . Switch_Threshold ) { jzt0gcydni
= rtP . Gain_Gain * rtDW . m4gnknfopa ; } else { jzt0gcydni = rtB .
pcgdgayggx ; } { rtB . g0jjedl3h4 = ( rtP . Internal_C_hiyczu5j42 [ 0 ] ) *
rtDW . i3g2v5ygab [ 0 ] + ( rtP . Internal_C_hiyczu5j42 [ 1 ] ) * rtDW .
i3g2v5ygab [ 1 ] + ( rtP . Internal_C_hiyczu5j42 [ 2 ] ) * rtDW . i3g2v5ygab
[ 2 ] ; } if ( rtP . RightMotor_sensorType > rtP .
Switch_Threshold_bmwdvzwwf2 ) { deu1hqt5kj = rtP . Gain_Gain_o4hmcpr5ca *
rtDW . ghbxb2zrik ; } else { deu1hqt5kj = rtB . g0jjedl3h4 ; } rtB .
fiztfjj1x3 = ( deu1hqt5kj - jzt0gcydni ) * rtB . ooajfnplre ; mobryh41lr = (
jzt0gcydni + deu1hqt5kj ) * rtB . kqcugdbf5g ; rtB . d0xjp4ie5e = mobryh41lr
* muDoubleScalarCos ( rtDW . ludo5r20l3 ) ; rtB . j23fnzwcfw = mobryh41lr *
muDoubleScalarSin ( rtDW . ludo5r20l3 ) ; { SimStruct * rts = ssGetSFunction
( rtS , 0 ) ; { static const char * blockSIDForSFcnLoader =
"Simulation3Draft:4:401" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * , int ) =
rts -> modelMethods . sFcn . mdlOutputs . level2 ;
sfcnLoader_separateComplexHandler_withTID ( rts , sfcnMethodPtr , ( 0 <= 1 )
&& gbl_raccel_tid01eq ? 0 : 0 ) ; } } parallel_for ( 4 , lznujbde5u , 1 ,
"lznujbde5u" ) ; if ( rtB . iitlyzvbjb [ 0 ] > rtP .
Switch_Threshold_j3y0cmi1bi ) { rtB . kg0pryf3mc [ 0 ] = rtP .
LineSensor_envVal ; } else { rtB . kg0pryf3mc [ 0 ] = rtP .
LineSensor_lineVal ; } if ( rtB . iitlyzvbjb [ 1 ] > rtP .
Switch_Threshold_j3y0cmi1bi ) { rtB . kg0pryf3mc [ 1 ] = rtP .
LineSensor_envVal ; } else { rtB . kg0pryf3mc [ 1 ] = rtP .
LineSensor_lineVal ; } if ( rtB . iitlyzvbjb [ 2 ] > rtP .
Switch_Threshold_j3y0cmi1bi ) { rtB . kg0pryf3mc [ 2 ] = rtP .
LineSensor_envVal ; } else { rtB . kg0pryf3mc [ 2 ] = rtP .
LineSensor_lineVal ; } if ( rtB . iitlyzvbjb [ 3 ] > rtP .
Switch_Threshold_j3y0cmi1bi ) { rtB . kg0pryf3mc [ 3 ] = rtP .
LineSensor_envVal ; } else { rtB . kg0pryf3mc [ 3 ] = rtP .
LineSensor_lineVal ; } rtDW . g4mgdk51u1 = a3qpugknvb ; rtB . acattgqayi [ 0
] = muDoubleScalarCos ( rtB . athhvkdmdz ) ; rtB . acattgqayi [ 3 ] = -
muDoubleScalarSin ( rtB . athhvkdmdz ) ; rtB . acattgqayi [ 6 ] = 0.0 ; rtB .
acattgqayi [ 1 ] = muDoubleScalarSin ( rtB . athhvkdmdz ) ; rtB . acattgqayi
[ 4 ] = muDoubleScalarCos ( rtB . athhvkdmdz ) ; rtB . acattgqayi [ 7 ] = 0.0
; rtB . acattgqayi [ 2 ] = 0.0 ; rtB . acattgqayi [ 5 ] = 0.0 ; rtB .
acattgqayi [ 8 ] = 1.0 ; rtDW . dtffab24fv = 0 ; while ( rtDW . dtffab24fv <
1 ) { rtB . hnkwggkzou = rtP . Constant1_Value_k2rcs4rpgg ; for ( i = 0 ; i <
201 ; i ++ ) { rtB . hsodnwhfav [ rtDW . dtffab24fv ] . bm4eudfrr4 [ i ] =
rtP . hsodnwhfav . Constant_Value [ i ] + rtP . Constant_Value_djcmpvlzjp ; }
parallel_for ( 201 , o5s2faxrbo , 1 , "o5s2faxrbo" ) ; rtDW . hsodnwhfav [
rtDW . dtffab24fv ] . e3evixvwmi = a3qpugknvb ; i = 0 ; ii_size_idx_0 = 1 ;
b_ii = 0 ; exitg1 = false ; while ( ( ! exitg1 ) && ( b_ii < 201 ) ) { if ( !
( rtB . hsodnwhfav [ rtDW . dtffab24fv ] . jz240yzam0 [ b_ii ] != 0.0F ) ) {
i = 1 ; ii_data_idx_0 = ( uint8_T ) ( b_ii + 1 ) ; exitg1 = true ; } else {
b_ii ++ ; } } if ( i == 0 ) { ii_size_idx_0 = 0 ; } rtB . lupfetmmtb = 0.0 ;
if ( ii_size_idx_0 != 0 ) { rtB . lupfetmmtb = rtP . hsodnwhfav .
Constant_Value [ ii_data_idx_0 - 1 ] ; } rtDW . dtffab24fv ++ ; } if ( rtDW .
p3xvndme1v < 127U ) { rtDW . p3xvndme1v ++ ; } rtDW . bs4xv2f2dq = a3qpugknvb
; if ( rtDW . fredjixzlu == 0U ) { rtDW . fredjixzlu = 1U ; rtDW . cv32usfudo
= k0ig43i0zc ; rtB . n4nupykk20 = 0.2 ; rtB . jnpqvfwuw0 = 0.0 ; } else {
switch ( rtDW . cv32usfudo ) { case k0ig43i0zc : rtB . n4nupykk20 = 0.2 ; rtB
. jnpqvfwuw0 = 0.0 ; if ( ( rtB . kg0pryf3mc [ 1 ] == 0.0 ) && ( rtB .
kg0pryf3mc [ 2 ] == 0.0 ) ) { rtDW . cv32usfudo = nbkwgunte3 ; rtB .
n4nupykk20 = 0.2 ; rtB . jnpqvfwuw0 = 0.0 ; } break ; case nbkwgunte3 : rtB .
n4nupykk20 = 0.2 ; rtB . jnpqvfwuw0 = 0.0 ; if ( rtB . kg0pryf3mc [ 1 ] ==
1.0 ) { rtDW . cv32usfudo = b3qwlp0ld1 ; rtB . n4nupykk20 = 0.1 ; rtB .
jnpqvfwuw0 = - 1.0 ; } else if ( rtB . kg0pryf3mc [ 2 ] == 1.0 ) { rtDW .
cv32usfudo = olbpopzv0e ; rtB . n4nupykk20 = 0.1 ; rtB . jnpqvfwuw0 = 1.0 ; }
else if ( ( rtB . kg0pryf3mc [ 3 ] == 0.0 ) && ( rtB . kg0pryf3mc [ 0 ] ==
1.0 ) ) { rtDW . cv32usfudo = mbtnfgkvfw ; rtDW . p3xvndme1v = 0U ; rtB .
n4nupykk20 = 0.05 ; rtB . jnpqvfwuw0 = - 1.0 ; } else if ( ( rtB . kg0pryf3mc
[ 0 ] == 0.0 ) && ( rtB . kg0pryf3mc [ 3 ] == 0.0 ) ) { rtDW . cv32usfudo =
asvf3dhiaz ; rtDW . p3xvndme1v = 0U ; rtB . n4nupykk20 = 0.05 ; rtB .
jnpqvfwuw0 = 0.0 ; } break ; case olbpopzv0e : rtB . n4nupykk20 = 0.1 ; rtB .
jnpqvfwuw0 = 1.0 ; if ( rtB . kg0pryf3mc [ 2 ] == 0.0 ) { rtDW . cv32usfudo =
nbkwgunte3 ; rtB . n4nupykk20 = 0.2 ; rtB . jnpqvfwuw0 = 0.0 ; } break ; case
b3qwlp0ld1 : rtB . n4nupykk20 = 0.1 ; rtB . jnpqvfwuw0 = - 1.0 ; if ( rtB .
kg0pryf3mc [ 1 ] == 0.0 ) { rtDW . cv32usfudo = nbkwgunte3 ; rtB . n4nupykk20
= 0.2 ; rtB . jnpqvfwuw0 = 0.0 ; } break ; case mbtnfgkvfw : rtB . n4nupykk20
= 0.05 ; rtB . jnpqvfwuw0 = - 1.0 ; if ( ( rtDW . p3xvndme1v >= 100U ) && (
rtB . kg0pryf3mc [ 1 ] == 0.0 ) && ( rtB . kg0pryf3mc [ 2 ] == 0.0 ) ) { rtDW
. cv32usfudo = nbkwgunte3 ; rtB . n4nupykk20 = 0.2 ; rtB . jnpqvfwuw0 = 0.0 ;
} break ; case asvf3dhiaz : rtB . n4nupykk20 = 0.05 ; rtB . jnpqvfwuw0 = 0.0
; if ( rtDW . p3xvndme1v >= 50U ) { rtDW . cv32usfudo = fu0x2nnkp2 ; rtDW .
p3xvndme1v = 0U ; rtB . n4nupykk20 = 0.0 ; } break ; case fu0x2nnkp2 : rtB .
n4nupykk20 = 0.0 ; if ( rtDW . p3xvndme1v >= 100U ) { rtDW . cv32usfudo =
bid1o4node ; rtDW . p3xvndme1v = 0U ; rtB . jnpqvfwuw0 = 1.0 ; } break ;
default : rtB . jnpqvfwuw0 = 1.0 ; if ( ( rtDW . p3xvndme1v >= 100U ) && (
rtB . kg0pryf3mc [ 1 ] == 0.0 ) && ( rtB . kg0pryf3mc [ 2 ] == 0.0 ) ) { rtDW
. cv32usfudo = nbkwgunte3 ; rtB . n4nupykk20 = 0.2 ; rtB . jnpqvfwuw0 = 0.0 ;
} break ; } } mobryh41lr = 1.0 / rtP . Towlwr_wheelR ; rtB . b3jbm402ar = rtP
. InputPWM [ plook_u32d_binckan ( ( rtP . changeparameters_Gain [ 0 ] * rtB .
n4nupykk20 + rtP . changeparameters_Gain [ 2 ] * rtB . jnpqvfwuw0 ) *
mobryh41lr , rtP . WheelSpeed , 172U ) ] ; rtB . ojoimenkbs = rtP . InputPWM
[ plook_u32d_binckan ( ( rtP . changeparameters_Gain [ 1 ] * rtB . n4nupykk20
+ rtP . changeparameters_Gain [ 3 ] * rtB . jnpqvfwuw0 ) * mobryh41lr , rtP .
WheelSpeed , 172U ) ] ; rtB . hohqowutc2 = 6.2831853071795862 * rtP . wheelR
/ rtP . ticksPerRot * muDoubleScalarCeil ( rtP . ticksPerRot / 360.0 * rtDW .
gwgdijo4lu ) ; rtB . plm3guhvpt = 6.2831853071795862 * rtP . wheelR / rtP .
ticksPerRot * muDoubleScalarCeil ( rtP . ticksPerRot / 360.0 * rtDW .
dpj2cs1yxt ) ; rtB . i3sd1i01sd = rtB . hohqowutc2 - rtB . plm3guhvpt ;
mobryh41lr = rtP . DriveDist_Value - ( rtB . hohqowutc2 + rtB . plm3guhvpt )
* rtP . Gain2_Gain ; lffxqlfwyl = rtP . PIDController_P * mobryh41lr + rtDW .
mcaxcsndtw ; if ( lffxqlfwyl > rtP . PIDController_UpperSaturationLimit ) {
lffxqlfwyl -= rtP . PIDController_UpperSaturationLimit ; } else if (
lffxqlfwyl >= rtP . PIDController_LowerSaturationLimit ) { lffxqlfwyl = 0.0 ;
} else { lffxqlfwyl -= rtP . PIDController_LowerSaturationLimit ; }
mobryh41lr *= rtP . PIDController_I ; if ( lffxqlfwyl > rtP .
Clamping_zero_Value ) { tmp = rtP . Constant_Value_aizakqrn1k ; } else { tmp
= rtP . Constant2_Value ; } if ( mobryh41lr > rtP . Clamping_zero_Value ) {
tmp_p = rtP . Constant3_Value ; } else { tmp_p = rtP . Constant4_Value ; } if
( ( rtP . Clamping_zero_Value != lffxqlfwyl ) && ( tmp == tmp_p ) ) { rtB .
om1zkmalu1 = rtP . Constant1_Value ; } else { rtB . om1zkmalu1 = mobryh41lr ;
} rtB . cu0343r3i2 = rtP . Gain2_Gain_cq42p4ubq2 * jzt0gcydni ; rtB .
lg1haipmqu = rtP . Gain3_Gain * deu1hqt5kj ; jzt0gcydni = rtP .
DriveRot_Value - rtP . Gain3_Gain_moxmp2rie1 * rtB . i3sd1i01sd ; deu1hqt5kj
= rtP . PIDController_P_kws2tbogph * jzt0gcydni + rtDW . lgzytb1guk ; if (
deu1hqt5kj > rtP . PIDController_UpperSaturationLimit_lonuxufgp5 ) {
deu1hqt5kj -= rtP . PIDController_UpperSaturationLimit_lonuxufgp5 ; } else if
( deu1hqt5kj >= rtP . PIDController_LowerSaturationLimit_np30azhqa2 ) {
deu1hqt5kj = 0.0 ; } else { deu1hqt5kj -= rtP .
PIDController_LowerSaturationLimit_np30azhqa2 ; } jzt0gcydni *= rtP .
PIDController_I_i45pwgvuma ; if ( deu1hqt5kj > rtP .
Clamping_zero_Value_ojxi3o54um ) { tmp = rtP . Constant_Value_bkskdfhvuo ; }
else { tmp = rtP . Constant2_Value_ntd5a3hqim ; } if ( jzt0gcydni > rtP .
Clamping_zero_Value_ojxi3o54um ) { tmp_p = rtP . Constant3_Value_ekyrhetqpn ;
} else { tmp_p = rtP . Constant4_Value_o1rmvqswsf ; } if ( ( rtP .
Clamping_zero_Value_ojxi3o54um != deu1hqt5kj ) && ( tmp == tmp_p ) ) { rtB .
evsbnfyjxg = rtP . Constant1_Value_puhyejpghs ; } else { rtB . evsbnfyjxg =
jzt0gcydni ; } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid )
{ rtB . ooajfnplre = rtP . wheelR / rtP . axleLength ; rtB . kqcugdbf5g = rtP
. Gain1_Gain * rtP . wheelR ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { rtDW . i2qyvx2esr += rtP . DiscreteTimeIntegrator_gainval * rtB
. d0xjp4ie5e ; rtDW . efs3a3hh2e += rtP . DiscreteTimeIntegrator1_gainval *
rtB . j23fnzwcfw ; rtDW . ludo5r20l3 += rtP . DiscreteTimeIntegrator2_gainval
* rtB . fiztfjj1x3 ; rtDW . m4gnknfopa += rtP .
DiscreteTimeIntegrator_gainval_afikqgzpe0 * rtB . pcgdgayggx ; { real_T xnew
[ 3 ] ; xnew [ 0 ] = ( rtP . Internal_A [ 0 ] ) * rtDW . b2hfiqnrei [ 0 ] + (
rtP . Internal_A [ 1 ] ) * rtDW . b2hfiqnrei [ 1 ] + ( rtP . Internal_A [ 2 ]
) * rtDW . b2hfiqnrei [ 2 ] ; xnew [ 0 ] += ( rtP . Internal_B [ 0 ] ) * rtB
. b3jbm402ar ; xnew [ 1 ] = ( rtP . Internal_A [ 3 ] ) * rtDW . b2hfiqnrei [
0 ] + ( rtP . Internal_A [ 4 ] ) * rtDW . b2hfiqnrei [ 1 ] + ( rtP .
Internal_A [ 5 ] ) * rtDW . b2hfiqnrei [ 2 ] ; xnew [ 1 ] += ( rtP .
Internal_B [ 1 ] ) * rtB . b3jbm402ar ; xnew [ 2 ] = ( rtP . Internal_A [ 6 ]
) * rtDW . b2hfiqnrei [ 0 ] + ( rtP . Internal_A [ 7 ] ) * rtDW . b2hfiqnrei
[ 1 ] + ( rtP . Internal_A [ 8 ] ) * rtDW . b2hfiqnrei [ 2 ] ; xnew [ 2 ] +=
( rtP . Internal_B [ 2 ] ) * rtB . b3jbm402ar ; ( void ) memcpy ( & rtDW .
b2hfiqnrei [ 0 ] , xnew , sizeof ( real_T ) * 3 ) ; } rtDW . ghbxb2zrik +=
rtP . DiscreteTimeIntegrator_gainval_ptlrlhszmg * rtB . g0jjedl3h4 ; { real_T
xnew [ 3 ] ; xnew [ 0 ] = ( rtP . Internal_A_avp5ztxxzl [ 0 ] ) * rtDW .
i3g2v5ygab [ 0 ] + ( rtP . Internal_A_avp5ztxxzl [ 1 ] ) * rtDW . i3g2v5ygab
[ 1 ] + ( rtP . Internal_A_avp5ztxxzl [ 2 ] ) * rtDW . i3g2v5ygab [ 2 ] ;
xnew [ 0 ] += ( rtP . Internal_B_ebkdikdi50 [ 0 ] ) * rtB . ojoimenkbs ; xnew
[ 1 ] = ( rtP . Internal_A_avp5ztxxzl [ 3 ] ) * rtDW . i3g2v5ygab [ 0 ] + (
rtP . Internal_A_avp5ztxxzl [ 4 ] ) * rtDW . i3g2v5ygab [ 1 ] + ( rtP .
Internal_A_avp5ztxxzl [ 5 ] ) * rtDW . i3g2v5ygab [ 2 ] ; xnew [ 1 ] += ( rtP
. Internal_B_ebkdikdi50 [ 1 ] ) * rtB . ojoimenkbs ; xnew [ 2 ] = ( rtP .
Internal_A_avp5ztxxzl [ 6 ] ) * rtDW . i3g2v5ygab [ 0 ] + ( rtP .
Internal_A_avp5ztxxzl [ 7 ] ) * rtDW . i3g2v5ygab [ 1 ] + ( rtP .
Internal_A_avp5ztxxzl [ 8 ] ) * rtDW . i3g2v5ygab [ 2 ] ; xnew [ 2 ] += ( rtP
. Internal_B_ebkdikdi50 [ 2 ] ) * rtB . ojoimenkbs ; ( void ) memcpy ( & rtDW
. i3g2v5ygab [ 0 ] , xnew , sizeof ( real_T ) * 3 ) ; } rtDW . gwgdijo4lu +=
rtP . DiscreteTimeIntegrator_gainval_lzyl4k4zxv * rtB . cu0343r3i2 ; rtDW .
dpj2cs1yxt += rtP . DiscreteTimeIntegrator1_gainval_fz4ugw3les * rtB .
lg1haipmqu ; rtDW . mcaxcsndtw += rtP . Integrator_gainval * rtB . om1zkmalu1
; rtDW . lgzytb1guk += rtP . Integrator_gainval_di3rudnbjq * rtB . evsbnfyjxg
; UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; { static const char * blockSIDForSFcnLoader =
"Simulation3Draft:4:401" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts ->
modelMethods . sFcn . mdlTerminate ; sfcnLoader_separateComplexHandler ( rts
, sfcnMethodPtr ) ; } } } static void mr_Simulation3Draft_cacheDataAsMxArray
( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) ; static void mr_Simulation3Draft_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) {
mxArray * newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_Simulation3Draft_restoreDataFromMxArray (
void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) ; static void mr_Simulation3Draft_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) {
memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_Simulation3Draft_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_Simulation3Draft_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_Simulation3Draft_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_Simulation3Draft_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_Simulation3Draft_restoreDataFromMxArrayWithOffset
( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_Simulation3Draft_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void mr_Simulation3Draft_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
{ mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_Simulation3Draft_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_Simulation3Draft_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_Simulation3Draft_GetDWork ( ) {
static const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" ,
"NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; mr_Simulation3Draft_cacheDataAsMxArray ( ssDW , 0 , 0 , (
const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char_T *
rtdwDataFieldNames [ 31 ] = { "rtDW.i2qyvx2esr" , "rtDW.efs3a3hh2e" ,
"rtDW.ludo5r20l3" , "rtDW.m4gnknfopa" , "rtDW.b2hfiqnrei" , "rtDW.ghbxb2zrik"
, "rtDW.i3g2v5ygab" , "rtDW.gwgdijo4lu" , "rtDW.dpj2cs1yxt" ,
"rtDW.mcaxcsndtw" , "rtDW.lgzytb1guk" , "rtDW.glmlggcvnu" , "rtDW.dtffab24fv"
, "rtDW.g4mgdk51u1" , "rtDW.cziarvqn3t" , "rtDW.bs4xv2f2dq" ,
"rtDW.cv32usfudo" , "rtDW.oc2vv2qobo" , "rtDW.p2ujolujvr" , "rtDW.fredjixzlu"
, "rtDW.p3xvndme1v" , "rtDW.o3vvrfpxkk" , "rtDW.mbgesywozm" ,
"rtDW.hsodnwhfav[0].e3evixvwmi" , "rtDW.hsodnwhfav[0].klt5acnwos" ,
"rtDW.hsodnwhfav[0].pohhf0zdrr" ,
"rtDW.hsodnwhfav[0].hsodnwhfav[0].hz3a5pczoy" ,
"rtDW.plige5liff[0].ok2jbhyf1e" , "rtDW.plige5liff[0].h11ovhfoxn" ,
"rtDW.plige5liff[0].c2dlt0ce3l" , "rtDW.plige5liff[0].hecpg1s5r3" , } ;
mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 31 , rtdwDataFieldNames )
; int k0 ; int k1 ; mxSetFieldByNumber ( rtdwData , 0 , 23 ,
mxCreateUninitNumericMatrix ( 1 , 1 * sizeof ( rtDW . hsodnwhfav [ 0 ] .
e3evixvwmi ) , mxUINT8_CLASS , mxREAL ) ) ; mxSetFieldByNumber ( rtdwData , 0
, 24 , mxCreateUninitNumericMatrix ( 1 , 1 * sizeof ( rtDW . hsodnwhfav [ 0 ]
. klt5acnwos ) , mxUINT8_CLASS , mxREAL ) ) ; mxSetFieldByNumber ( rtdwData ,
0 , 25 , mxCreateUninitNumericMatrix ( 1 , 1 * sizeof ( rtDW . hsodnwhfav [ 0
] . pohhf0zdrr ) , mxUINT8_CLASS , mxREAL ) ) ; mxSetFieldByNumber ( rtdwData
, 0 , 26 , mxCreateUninitNumericMatrix ( 1 , 201 * sizeof ( rtDW . hsodnwhfav
[ 0 ] . hsodnwhfav [ 0 ] . hz3a5pczoy ) , mxUINT8_CLASS , mxREAL ) ) ;
mxSetFieldByNumber ( rtdwData , 0 , 27 , mxCreateUninitNumericMatrix ( 1 , 4
* sizeof ( rtDW . plige5liff [ 0 ] . ok2jbhyf1e ) , mxUINT8_CLASS , mxREAL )
) ; mxSetFieldByNumber ( rtdwData , 0 , 28 , mxCreateUninitNumericMatrix ( 1
, 4 * sizeof ( rtDW . plige5liff [ 0 ] . h11ovhfoxn ) , mxUINT8_CLASS ,
mxREAL ) ) ; mxSetFieldByNumber ( rtdwData , 0 , 29 ,
mxCreateUninitNumericMatrix ( 1 , 4 * sizeof ( rtDW . plige5liff [ 0 ] .
c2dlt0ce3l ) , mxUINT8_CLASS , mxREAL ) ) ; mxSetFieldByNumber ( rtdwData , 0
, 30 , mxCreateUninitNumericMatrix ( 1 , 4 * sizeof ( rtDW . plige5liff [ 0 ]
. hecpg1s5r3 ) , mxUINT8_CLASS , mxREAL ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * )
& ( rtDW . i2qyvx2esr ) , sizeof ( rtDW . i2qyvx2esr ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * )
& ( rtDW . efs3a3hh2e ) , sizeof ( rtDW . efs3a3hh2e ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * )
& ( rtDW . ludo5r20l3 ) , sizeof ( rtDW . ludo5r20l3 ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * )
& ( rtDW . m4gnknfopa ) , sizeof ( rtDW . m4gnknfopa ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * )
& ( rtDW . b2hfiqnrei ) , sizeof ( rtDW . b2hfiqnrei ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * )
& ( rtDW . ghbxb2zrik ) , sizeof ( rtDW . ghbxb2zrik ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * )
& ( rtDW . i3g2v5ygab ) , sizeof ( rtDW . i3g2v5ygab ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * )
& ( rtDW . gwgdijo4lu ) , sizeof ( rtDW . gwgdijo4lu ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * )
& ( rtDW . dpj2cs1yxt ) , sizeof ( rtDW . dpj2cs1yxt ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * )
& ( rtDW . mcaxcsndtw ) , sizeof ( rtDW . mcaxcsndtw ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * )
& ( rtDW . lgzytb1guk ) , sizeof ( rtDW . lgzytb1guk ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * )
& ( rtDW . glmlggcvnu ) , sizeof ( rtDW . glmlggcvnu ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * )
& ( rtDW . dtffab24fv ) , sizeof ( rtDW . dtffab24fv ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * )
& ( rtDW . g4mgdk51u1 ) , sizeof ( rtDW . g4mgdk51u1 ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * )
& ( rtDW . cziarvqn3t ) , sizeof ( rtDW . cziarvqn3t ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * )
& ( rtDW . bs4xv2f2dq ) , sizeof ( rtDW . bs4xv2f2dq ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * )
& ( rtDW . cv32usfudo ) , sizeof ( rtDW . cv32usfudo ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * )
& ( rtDW . oc2vv2qobo ) , sizeof ( rtDW . oc2vv2qobo ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * )
& ( rtDW . p2ujolujvr ) , sizeof ( rtDW . p2ujolujvr ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * )
& ( rtDW . fredjixzlu ) , sizeof ( rtDW . fredjixzlu ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * )
& ( rtDW . p3xvndme1v ) , sizeof ( rtDW . p3xvndme1v ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * )
& ( rtDW . o3vvrfpxkk ) , sizeof ( rtDW . o3vvrfpxkk ) ) ;
mr_Simulation3Draft_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * )
& ( rtDW . mbgesywozm ) , sizeof ( rtDW . mbgesywozm ) ) ; for ( k0 = 0 ; k0
< 1 ; ++ k0 ) { const mwIndex offset0 = k0 ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 23 ,
offset0 , & ( rtDW . hsodnwhfav [ k0 ] . e3evixvwmi ) , sizeof ( rtDW .
hsodnwhfav [ 0 ] . e3evixvwmi ) ) ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 24 ,
offset0 , & ( rtDW . hsodnwhfav [ k0 ] . klt5acnwos ) , sizeof ( rtDW .
hsodnwhfav [ 0 ] . klt5acnwos ) ) ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 25 ,
offset0 , & ( rtDW . hsodnwhfav [ k0 ] . pohhf0zdrr ) , sizeof ( rtDW .
hsodnwhfav [ 0 ] . pohhf0zdrr ) ) ; for ( k1 = 0 ; k1 < 201 ; ++ k1 ) { const
mwIndex offset1 = k0 * 201 + k1 ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 26 ,
offset1 , & ( rtDW . hsodnwhfav [ k0 ] . hsodnwhfav [ k1 ] . hz3a5pczoy ) ,
sizeof ( rtDW . hsodnwhfav [ 0 ] . hsodnwhfav [ 0 ] . hz3a5pczoy ) ) ; } }
for ( k0 = 0 ; k0 < 4 ; ++ k0 ) { const mwIndex offset0 = k0 ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 27 ,
offset0 , & ( rtDW . plige5liff [ k0 ] . ok2jbhyf1e ) , sizeof ( rtDW .
plige5liff [ 0 ] . ok2jbhyf1e ) ) ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 28 ,
offset0 , & ( rtDW . plige5liff [ k0 ] . h11ovhfoxn ) , sizeof ( rtDW .
plige5liff [ 0 ] . h11ovhfoxn ) ) ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 29 ,
offset0 , & ( rtDW . plige5liff [ k0 ] . c2dlt0ce3l ) , sizeof ( rtDW .
plige5liff [ 0 ] . c2dlt0ce3l ) ) ;
mr_Simulation3Draft_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 30 ,
offset0 , & ( rtDW . plige5liff [ k0 ] . hecpg1s5r3 ) , sizeof ( rtDW .
plige5liff [ 0 ] . hecpg1s5r3 ) ) ; } mxSetFieldByNumber ( ssDW , 0 , 1 ,
rtdwData ) ; } return ssDW ; } void mr_Simulation3Draft_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_Simulation3Draft_restoreDataFromMxArray
( ( void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ; int k0 ; int k1 ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . i2qyvx2esr
) , rtdwData , 0 , 0 , sizeof ( rtDW . i2qyvx2esr ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . efs3a3hh2e
) , rtdwData , 0 , 1 , sizeof ( rtDW . efs3a3hh2e ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . ludo5r20l3
) , rtdwData , 0 , 2 , sizeof ( rtDW . ludo5r20l3 ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . m4gnknfopa
) , rtdwData , 0 , 3 , sizeof ( rtDW . m4gnknfopa ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . b2hfiqnrei
) , rtdwData , 0 , 4 , sizeof ( rtDW . b2hfiqnrei ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . ghbxb2zrik
) , rtdwData , 0 , 5 , sizeof ( rtDW . ghbxb2zrik ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . i3g2v5ygab
) , rtdwData , 0 , 6 , sizeof ( rtDW . i3g2v5ygab ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . gwgdijo4lu
) , rtdwData , 0 , 7 , sizeof ( rtDW . gwgdijo4lu ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . dpj2cs1yxt
) , rtdwData , 0 , 8 , sizeof ( rtDW . dpj2cs1yxt ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . mcaxcsndtw
) , rtdwData , 0 , 9 , sizeof ( rtDW . mcaxcsndtw ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . lgzytb1guk
) , rtdwData , 0 , 10 , sizeof ( rtDW . lgzytb1guk ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . glmlggcvnu
) , rtdwData , 0 , 11 , sizeof ( rtDW . glmlggcvnu ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . dtffab24fv
) , rtdwData , 0 , 12 , sizeof ( rtDW . dtffab24fv ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . g4mgdk51u1
) , rtdwData , 0 , 13 , sizeof ( rtDW . g4mgdk51u1 ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . cziarvqn3t
) , rtdwData , 0 , 14 , sizeof ( rtDW . cziarvqn3t ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . bs4xv2f2dq
) , rtdwData , 0 , 15 , sizeof ( rtDW . bs4xv2f2dq ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . cv32usfudo
) , rtdwData , 0 , 16 , sizeof ( rtDW . cv32usfudo ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . oc2vv2qobo
) , rtdwData , 0 , 17 , sizeof ( rtDW . oc2vv2qobo ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . p2ujolujvr
) , rtdwData , 0 , 18 , sizeof ( rtDW . p2ujolujvr ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . fredjixzlu
) , rtdwData , 0 , 19 , sizeof ( rtDW . fredjixzlu ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . p3xvndme1v
) , rtdwData , 0 , 20 , sizeof ( rtDW . p3xvndme1v ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . o3vvrfpxkk
) , rtdwData , 0 , 21 , sizeof ( rtDW . o3vvrfpxkk ) ) ;
mr_Simulation3Draft_restoreDataFromMxArray ( ( void * ) & ( rtDW . mbgesywozm
) , rtdwData , 0 , 22 , sizeof ( rtDW . mbgesywozm ) ) ; for ( k0 = 0 ; k0 <
1 ; ++ k0 ) { const mwIndex offset0 = k0 ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . hsodnwhfav
[ k0 ] . e3evixvwmi ) , rtdwData , 0 , 23 , offset0 , sizeof ( rtDW .
hsodnwhfav [ 0 ] . e3evixvwmi ) ) ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . hsodnwhfav
[ k0 ] . klt5acnwos ) , rtdwData , 0 , 24 , offset0 , sizeof ( rtDW .
hsodnwhfav [ 0 ] . klt5acnwos ) ) ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . hsodnwhfav
[ k0 ] . pohhf0zdrr ) , rtdwData , 0 , 25 , offset0 , sizeof ( rtDW .
hsodnwhfav [ 0 ] . pohhf0zdrr ) ) ; for ( k1 = 0 ; k1 < 201 ; ++ k1 ) { const
mwIndex offset1 = k0 * 201 + k1 ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . hsodnwhfav
[ k0 ] . hsodnwhfav [ k1 ] . hz3a5pczoy ) , rtdwData , 0 , 26 , offset1 ,
sizeof ( rtDW . hsodnwhfav [ 0 ] . hsodnwhfav [ 0 ] . hz3a5pczoy ) ) ; } }
for ( k0 = 0 ; k0 < 4 ; ++ k0 ) { const mwIndex offset0 = k0 ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . plige5liff
[ k0 ] . ok2jbhyf1e ) , rtdwData , 0 , 27 , offset0 , sizeof ( rtDW .
plige5liff [ 0 ] . ok2jbhyf1e ) ) ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . plige5liff
[ k0 ] . h11ovhfoxn ) , rtdwData , 0 , 28 , offset0 , sizeof ( rtDW .
plige5liff [ 0 ] . h11ovhfoxn ) ) ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . plige5liff
[ k0 ] . c2dlt0ce3l ) , rtdwData , 0 , 29 , offset0 , sizeof ( rtDW .
plige5liff [ 0 ] . c2dlt0ce3l ) ) ;
mr_Simulation3Draft_restoreDataFromMxArrayWithOffset ( & ( rtDW . plige5liff
[ k0 ] . hecpg1s5r3 ) , rtdwData , 0 , 30 , offset0 , sizeof ( rtDW .
plige5liff [ 0 ] . hecpg1s5r3 ) ) ; } } } mxArray *
mr_Simulation3Draft_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 3 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 3 ] = { "Scope" , "Scope" , "Scope" , } ; static const
char_T * blockPath [ 3 ] = { "Simulation3Draft/Differential" ,
"Simulation3Draft/LMotorDist" , "Simulation3Draft/RMotorDist" , } ; static
const int reason [ 3 ] = { 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ]
< 3 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript (
data , 2 , subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [
subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2
, subs ) ; mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0
] ] ) ) ; subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs
[ 0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ;
ssSetNumBlocks ( rtS , 170 ) ; ssSetNumBlockIO ( rtS , 32 ) ;
ssSetNumBlockParams ( rtS , 1584497 ) ; } void MdlInitializeSampleTimes (
void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.01
) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3909823708U ) ;
ssSetChecksumVal ( rtS , 1 , 1113749105U ) ; ssSetChecksumVal ( rtS , 2 ,
912998277U ) ; ssSetChecksumVal ( rtS , 3 , 2265357886U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 23 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } Simulation3Draft_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Simulation3Draft" ) ; ssSetPath ( rtS , "Simulation3Draft" ) ; ssSetTStart (
rtS , 0.0 ) ; ssSetTFinal ( rtS , 30.0 ) ; ssSetStepSize ( rtS , 0.01 ) ;
ssSetFixedStepSize ( rtS , 0.01 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 3 , 1 , 3 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
} ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 3 , 1 , 3 ,
1 , 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"Simulation3Draft/Robot Simulator/Discrete-Time\nIntegrator" ,
"Simulation3Draft/Robot Simulator/Discrete-Time\nIntegrator1" ,
"Simulation3Draft/Robot Simulator/Discrete-Time\nIntegrator2" ,
"Simulation3Draft/LeftMotor/Discrete-Time\nIntegrator" ,
"Simulation3Draft/LeftMotor/Motor/Internal" ,
"Simulation3Draft/RightMotor/Discrete-Time\nIntegrator" ,
"Simulation3Draft/RightMotor/Motor/Internal" ,
"Simulation3Draft/Encoder/Discrete-Time\nIntegrator" ,
"Simulation3Draft/Encoder/Discrete-Time\nIntegrator1" ,
"Simulation3Draft/DistanceControl/PID Controller/Integrator/Discrete/Integrator"
, "Simulation3Draft/RotControl/PID Controller/Integrator/Discrete/Integrator"
} ; static const char_T * rt_LoggedStateNames [ ] = { "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 ,
6 , 7 , 8 , 9 , 10 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
11 , rt_LoggedStateWidths , rt_LoggedStateNumDimensions ,
rt_LoggedStateDimensions , rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) ,
rt_LoggedStateDataTypeIds , rt_LoggedStateComplexSignals , ( NULL ) ,
rt_LoggingStatePreprocessingFcnPtrs , { rt_LoggedStateLabels } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 11 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtDW . i2qyvx2esr ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . efs3a3hh2e ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtDW . ludo5r20l3 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtDW . m4gnknfopa ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) rtDW . b2hfiqnrei ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtDW . ghbxb2zrik ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) rtDW . i3g2v5ygab ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtDW . gwgdijo4lu ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . dpj2cs1yxt ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtDW . mcaxcsndtw ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . lgzytb1guk ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetNumNonContDerivSigInfos ( rtS , 0 ) ;
ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS , &
slvrInfo ) ; ssSetSolverName ( rtS , "FixedStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
3909823708U ) ; ssSetChecksumVal ( rtS , 1 , 1113749105U ) ; ssSetChecksumVal
( rtS , 2 , 912998277U ) ; ssSetChecksumVal ( rtS , 3 , 2265357886U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 15 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = &
rtAlwaysEnabled ; systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = &
rtAlwaysEnabled ; systemRan [ 14 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Simulation3Draft_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_Simulation3Draft_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_Simulation3Draft_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } ssSetNumSFunctions ( rtS , 1 ) ; { static SimStruct
childSFunctions [ 1 ] ; static SimStruct * childSFunctionPtrs [ 1 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction (
rtS , 0 , & childSFunctions [ 0 ] ) ; { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ;
static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 ,
sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 ,
sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; }
ssSetModelName ( rts , "sfun_time" ) ; ssSetPath ( rts ,
"Simulation3Draft/Robot Simulator/Soft Real Time" ) ; if ( ssGetRTModel ( rtS
) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 1 ] ; ssSetSFcnParamsCount ( rts , 1 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
SoftRealTime_P1_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW .
glmlggcvnu ) ; { static struct _ssDWorkRecord dWorkRecord [ 1 ] ; static
struct _ssDWorkAuxRecord dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts ,
dWorkRecord ) ; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ;
ssSetNumDWorkAsInt ( rts , 1 ) ; ssSetDWorkWidthAsInt ( rts , 0 , 1 ) ;
ssSetDWorkDataType ( rts , 0 , SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts ,
0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW . glmlggcvnu ) ; } {
raccelLoadSFcnMexFile ( "sfun_time" , "Simulation3Draft:4:401" , rts , 0 ) ;
if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } } sfcnInitializeSampleTimes
( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 0.0
) ; sfcnTsMap [ 0 ] = 0 ; ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; } } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
