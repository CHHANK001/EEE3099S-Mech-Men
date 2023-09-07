#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Simulation3Draft_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "Simulation3Draft.h"
#include "Simulation3Draft_capi.h"
#include "Simulation3Draft_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 2 , TARGET_STRING (
"Simulation3Draft/Line Following" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 1 , 2 , TARGET_STRING ( "Simulation3Draft/Line Following" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"Simulation3Draft/Line Following/is_active_c1_Simulation3Draft" ) ,
TARGET_STRING ( "is_active_c1_Simulation3Draft" ) , 0 , 1 , 0 , 0 , 0 } , { 3
, 0 , TARGET_STRING (
"Simulation3Draft/Line Following/is_c1_Simulation3Draft" ) , TARGET_STRING (
"is_c1_Simulation3Draft" ) , 0 , 2 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"Simulation3Draft/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5
, 0 , TARGET_STRING ( "Simulation3Draft/Gain1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING ( "Simulation3Draft/Left Motor LUT"
) , TARGET_STRING ( "Left PWM" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 ,
TARGET_STRING ( "Simulation3Draft/Right Motor LUT" ) , TARGET_STRING (
"Right PWM" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"Simulation3Draft/Subtract" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 9 , 0 , TARGET_STRING ( "Simulation3Draft/Encoder/Gain2" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"Simulation3Draft/Encoder/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 11 , 0 , TARGET_STRING ( "Simulation3Draft/Line Sensor/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
 "Simulation3Draft/Robot Simulator/MATLAB Function/is_active_c1_mobileRoboticsTrainingLib"
) , TARGET_STRING ( "is_active_c1_mobileRoboticsTrainingLib" ) , 0 , 1 , 0 ,
0 , 0 } , { 13 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Discrete-Time Integrator" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Discrete-Time Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 16 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Math Function" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Divide" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Product1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Product2" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Product3" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"Simulation3Draft/LeftMotor/Motor/Internal" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 22 , 6 , TARGET_STRING (
"Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem" ) ,
TARGET_STRING ( "" ) , 0 , 3 , 1 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"Simulation3Draft/RightMotor/Motor/Internal" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 24 , 14 , TARGET_STRING (
"Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 9 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Calculate Rotation Matrix"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Calculate Rotation Matrix/is_active_c4_mobileRoboticsTrainingLib"
) , TARGET_STRING ( "is_active_c4_mobileRoboticsTrainingLib" ) , 0 , 1 , 0 ,
0 , 0 } , { 27 , 0 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Transform Sensor Offset/is_active_c2_mobileRoboticsTrainingLib"
) , TARGET_STRING ( "is_active_c2_mobileRoboticsTrainingLib" ) , 0 , 1 , 0 ,
0 , 0 } , { 28 , 12 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value"
) , TARGET_STRING ( "" ) , 0 , 3 , 3 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Nearest Object/is_active_c5_mobileRoboticsTrainingLib"
) , TARGET_STRING ( "is_active_c5_mobileRoboticsTrainingLib" ) , 0 , 1 , 0 ,
0 , 0 } , { 30 , 13 , TARGET_STRING (
"Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Sum1" )
, TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
 "Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
 "Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 33 , TARGET_STRING ( "Simulation3Draft/LeftMotor"
) , TARGET_STRING ( "sensorType" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"Simulation3Draft/Line Sensor" ) , TARGET_STRING ( "envVal" ) , 0 , 0 , 0 } ,
{ 35 , TARGET_STRING ( "Simulation3Draft/Line Sensor" ) , TARGET_STRING (
"lineVal" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"Simulation3Draft/RightMotor" ) , TARGET_STRING ( "sensorType" ) , 0 , 0 , 0
} , { 37 , TARGET_STRING ( "Simulation3Draft/Robot Simulator" ) ,
TARGET_STRING ( "startX" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"Simulation3Draft/Robot Simulator" ) , TARGET_STRING ( "startY" ) , 0 , 0 , 0
} , { 39 , TARGET_STRING ( "Simulation3Draft/Robot Simulator" ) ,
TARGET_STRING ( "startTheta" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"Simulation3Draft/To wlwr" ) , TARGET_STRING ( "wheelR" ) , 0 , 0 , 0 } , {
41 , TARGET_STRING ( "Simulation3Draft/DriveDist" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 42 , TARGET_STRING ( "Simulation3Draft/DriveRot" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"Simulation3Draft/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 44 ,
TARGET_STRING ( "Simulation3Draft/Gain3" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 45 , TARGET_STRING (
"Simulation3Draft/DistanceControl/PID Controller" ) , TARGET_STRING ( "P" ) ,
0 , 0 , 0 } , { 46 , TARGET_STRING (
"Simulation3Draft/DistanceControl/PID Controller" ) , TARGET_STRING ( "I" ) ,
0 , 0 , 0 } , { 47 , TARGET_STRING (
"Simulation3Draft/DistanceControl/PID Controller" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 48 , TARGET_STRING (
"Simulation3Draft/DistanceControl/PID Controller" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"Simulation3Draft/DistanceControl/PID Controller" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"Simulation3Draft/Encoder/Discrete-Time Integrator" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"Simulation3Draft/Encoder/Discrete-Time Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING (
"Simulation3Draft/Encoder/Discrete-Time Integrator1" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"Simulation3Draft/Encoder/Discrete-Time Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"Simulation3Draft/Encoder/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 55 , TARGET_STRING ( "Simulation3Draft/Encoder/Gain3" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING (
"Simulation3Draft/LeftMotor/Discrete-Time Integrator" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"Simulation3Draft/LeftMotor/Discrete-Time Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
"Simulation3Draft/LeftMotor/Switch" ) , TARGET_STRING ( "Threshold" ) , 0 , 0
, 0 } , { 59 , TARGET_STRING ( "Simulation3Draft/Line Sensor/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 60 , TARGET_STRING (
"Simulation3Draft/Line Sensor/Constant1" ) , TARGET_STRING ( "Value" ) , 0 ,
1 , 0 } , { 61 , TARGET_STRING ( "Simulation3Draft/Line Sensor/Switch" ) ,
TARGET_STRING ( "Threshold" ) , 3 , 0 , 0 } , { 62 , TARGET_STRING (
"Simulation3Draft/RightMotor/Discrete-Time Integrator" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"Simulation3Draft/RightMotor/Discrete-Time Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
"Simulation3Draft/RightMotor/Switch" ) , TARGET_STRING ( "Threshold" ) , 0 ,
0 , 0 } , { 65 , TARGET_STRING ( "Simulation3Draft/Robot Simulator/Circle" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 66 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Discrete-Time Integrator" ) , TARGET_STRING
( "gainval" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Discrete-Time Integrator1" ) ,
TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 68 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Discrete-Time Integrator2" ) ,
TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 70 , TARGET_STRING (
"Simulation3Draft/Robot Simulator/Soft Real Time" ) , TARGET_STRING ( "P1" )
, 0 , 0 , 0 } , { 71 , TARGET_STRING (
"Simulation3Draft/RotControl/PID Controller" ) , TARGET_STRING ( "P" ) , 0 ,
0 , 0 } , { 72 , TARGET_STRING ( "Simulation3Draft/RotControl/PID Controller"
) , TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
"Simulation3Draft/RotControl/PID Controller" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
"Simulation3Draft/RotControl/PID Controller" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"Simulation3Draft/RotControl/PID Controller" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"Simulation3Draft/To wlwr/change parameters" ) , TARGET_STRING ( "Gain" ) , 0
, 4 , 0 } , { 77 , TARGET_STRING (
"Simulation3Draft/Ultrasonic Sensor/Constant" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 78 , TARGET_STRING (
"Simulation3Draft/Ultrasonic Sensor/Constant1" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 79 , TARGET_STRING (
"Simulation3Draft/LeftMotor/Motor/Internal" ) , TARGET_STRING ( "A" ) , 0 , 5
, 0 } , { 80 , TARGET_STRING ( "Simulation3Draft/LeftMotor/Motor/Internal" )
, TARGET_STRING ( "B" ) , 0 , 6 , 0 } , { 81 , TARGET_STRING (
"Simulation3Draft/LeftMotor/Motor/Internal" ) , TARGET_STRING ( "C" ) , 0 , 6
, 0 } , { 82 , TARGET_STRING (
"Simulation3Draft/LeftMotor/Radians to Degrees/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 83 , TARGET_STRING (
"Simulation3Draft/RightMotor/Motor/Internal" ) , TARGET_STRING ( "A" ) , 0 ,
5 , 0 } , { 84 , TARGET_STRING ( "Simulation3Draft/RightMotor/Motor/Internal"
) , TARGET_STRING ( "B" ) , 0 , 6 , 0 } , { 85 , TARGET_STRING (
"Simulation3Draft/RightMotor/Motor/Internal" ) , TARGET_STRING ( "C" ) , 0 ,
6 , 0 } , { 86 , TARGET_STRING (
"Simulation3Draft/RightMotor/Radians to Degrees/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 88 , TARGET_STRING (
 "Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
 "Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 90 , TARGET_STRING (
 "Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
 "Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 92 , TARGET_STRING (
 "Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 93 , TARGET_STRING (
 "Simulation3Draft/DistanceControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 94 , TARGET_STRING (
"Simulation3Draft/DistanceControl/PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 96 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 97 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 98 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 100 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Saturation2"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 101 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Saturation2"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 102 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Saturation3"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 103 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Saturation3"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 104 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
) , TARGET_STRING ( "Table" ) , 3 , 8 , 0 } , { 105 , TARGET_STRING (
 "Simulation3Draft/Line Sensor/Look up Line Value/For Each Subsystem/Look up Line Value/Direct Lookup Table (n-D)"
) , TARGET_STRING ( "DiagnosticForOutOfRangeInput" ) , 1 , 0 , 0 } , { 106 ,
TARGET_STRING (
 "Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 107 , TARGET_STRING (
 "Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 108 , TARGET_STRING (
 "Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 109 , TARGET_STRING (
 "Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 110 , TARGET_STRING (
 "Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 111 , TARGET_STRING (
 "Simulation3Draft/RotControl/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 4 , 0 , 0 } , { 112 , TARGET_STRING (
"Simulation3Draft/RotControl/PID Controller/Integrator/Discrete/Integrator" )
, TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 113 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 114 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 116 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 117 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 118 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 119 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Saturation"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 120 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Saturation"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Saturation1"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 122 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Saturation1"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 123 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
) , TARGET_STRING ( "Table" ) , 3 , 8 , 0 } , { 124 , TARGET_STRING (
 "Simulation3Draft/Ultrasonic Sensor/Look up Distance Value/Subsystem/Look up Sensor Value/Lookup Obstacle Map/Direct Lookup Table (n-D)"
) , TARGET_STRING ( "DiagnosticForOutOfRangeInput" ) , 1 , 0 , 0 } , { 0 , (
NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] =
{ - 1 } ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL
) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals
rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 125 ,
TARGET_STRING ( "InputPWM" ) , 0 , 9 , 0 } , { 126 , TARGET_STRING (
"WheelSpeed" ) , 0 , 9 , 0 } , { 127 , TARGET_STRING ( "axleLength" ) , 0 , 0
, 0 } , { 128 , TARGET_STRING ( "lineLength" ) , 0 , 0 , 0 } , { 129 ,
TARGET_STRING ( "ticksPerRot" ) , 0 , 0 , 0 } , { 130 , TARGET_STRING (
"wheelR" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . n4nupykk20 , & rtB . jnpqvfwuw0 ,
& rtDW . fredjixzlu , & rtDW . cv32usfudo , & rtB . hohqowutc2 , & rtB .
plm3guhvpt , & rtB . b3jbm402ar , & rtB . ojoimenkbs , & rtB . i3sd1i01sd , &
rtB . cu0343r3i2 , & rtB . lg1haipmqu , & rtB . kg0pryf3mc [ 0 ] , & rtDW .
p2ujolujvr , & rtB . ktg4baxiij , & rtB . cbrh4plvr3 , & rtB . kqcugdbf5g , &
rtB . athhvkdmdz , & rtB . ooajfnplre , & rtB . fiztfjj1x3 , & rtB .
d0xjp4ie5e , & rtB . j23fnzwcfw , & rtB . pcgdgayggx , & rtB . iitlyzvbjb [ 0
] , & rtB . g0jjedl3h4 , & rtB . lupfetmmtb , & rtB . acattgqayi [ 0 ] , &
rtDW . oc2vv2qobo , & rtDW . plige5liff [ 3 ] . c2dlt0ce3l , & rtB .
hsodnwhfav [ 0 ] . jz240yzam0 [ 0 ] , & rtDW . hsodnwhfav [ 0 ] . klt5acnwos
, & rtB . hsodnwhfav [ 0 ] . bm4eudfrr4 [ 0 ] , & rtB . om1zkmalu1 , & rtB .
evsbnfyjxg , & rtP . LeftMotor_sensorType , & rtP . LineSensor_envVal , & rtP
. LineSensor_lineVal , & rtP . RightMotor_sensorType , & rtP .
RobotSimulator_startX , & rtP . RobotSimulator_startY , & rtP .
RobotSimulator_startTheta , & rtP . Towlwr_wheelR , & rtP . DriveDist_Value ,
& rtP . DriveRot_Value , & rtP . Gain2_Gain , & rtP . Gain3_Gain_moxmp2rie1 ,
& rtP . PIDController_P , & rtP . PIDController_I , & rtP .
PIDController_InitialConditionForIntegrator , & rtP .
PIDController_UpperSaturationLimit , & rtP .
PIDController_LowerSaturationLimit , & rtP .
DiscreteTimeIntegrator_gainval_lzyl4k4zxv , & rtP .
DiscreteTimeIntegrator_IC_f5z3vyriqm , & rtP .
DiscreteTimeIntegrator1_gainval_fz4ugw3les , & rtP .
DiscreteTimeIntegrator1_IC , & rtP . Gain2_Gain_cq42p4ubq2 , & rtP .
Gain3_Gain , & rtP . DiscreteTimeIntegrator_gainval_afikqgzpe0 , & rtP .
DiscreteTimeIntegrator_IC , & rtP . Switch_Threshold , & rtP . Constant_Value
[ 0 ] , & rtP . Constant1_Value_l3t40ea4hs [ 0 ] , & rtP .
Switch_Threshold_j3y0cmi1bi , & rtP .
DiscreteTimeIntegrator_gainval_ptlrlhszmg , & rtP .
DiscreteTimeIntegrator_IC_e3x2ks5ohu , & rtP . Switch_Threshold_bmwdvzwwf2 ,
& rtP . Circle_Value , & rtP . DiscreteTimeIntegrator_gainval , & rtP .
DiscreteTimeIntegrator1_gainval , & rtP . DiscreteTimeIntegrator2_gainval , &
rtP . Gain1_Gain , & rtP . SoftRealTime_P1 , & rtP .
PIDController_P_kws2tbogph , & rtP . PIDController_I_i45pwgvuma , & rtP .
PIDController_InitialConditionForIntegrator_epasr05elh , & rtP .
PIDController_UpperSaturationLimit_lonuxufgp5 , & rtP .
PIDController_LowerSaturationLimit_np30azhqa2 , & rtP . changeparameters_Gain
[ 0 ] , & rtP . Constant_Value_djcmpvlzjp , & rtP .
Constant1_Value_k2rcs4rpgg , & rtP . Internal_A [ 0 ] , & rtP . Internal_B [
0 ] , & rtP . Internal_C [ 0 ] , & rtP . Gain_Gain , & rtP .
Internal_A_avp5ztxxzl [ 0 ] , & rtP . Internal_B_ebkdikdi50 [ 0 ] , & rtP .
Internal_C_hiyczu5j42 [ 0 ] , & rtP . Gain_Gain_o4hmcpr5ca , & rtP .
hsodnwhfav . Constant_Value [ 0 ] , & rtP . Clamping_zero_Value , & rtP .
Constant_Value_aizakqrn1k , & rtP . Constant1_Value , & rtP . Constant2_Value
, & rtP . Constant3_Value , & rtP . Constant4_Value , & rtP .
Integrator_gainval , & rtP . plige5liff . Bias_Bias , & rtP . plige5liff .
Bias1_Bias , & rtP . plige5liff . Constant_Value , & rtP . plige5liff .
Gain_Gain , & rtP . plige5liff . Gain1_Gain , & rtP . plige5liff .
Saturation2_UpperSat , & rtP . plige5liff . Saturation2_LowerSat , & rtP .
plige5liff . Saturation3_UpperSat , & rtP . plige5liff . Saturation3_LowerSat
, & rtP . plige5liff . DirectLookupTablenD_table [ 0 ] , & rtP . plige5liff .
DirectLookupTablenD_DiagnosticForOutOfRangeInput , & rtP .
Clamping_zero_Value_ojxi3o54um , & rtP . Constant_Value_bkskdfhvuo , & rtP .
Constant1_Value_puhyejpghs , & rtP . Constant2_Value_ntd5a3hqim , & rtP .
Constant3_Value_ekyrhetqpn , & rtP . Constant4_Value_o1rmvqswsf , & rtP .
Integrator_gainval_di3rudnbjq , & rtP . hsodnwhfav . hsodnwhfav .
Constant_Value , & rtP . hsodnwhfav . hsodnwhfav . Bias_Bias , & rtP .
hsodnwhfav . hsodnwhfav . Bias1_Bias , & rtP . hsodnwhfav . hsodnwhfav .
Constant1_Value , & rtP . hsodnwhfav . hsodnwhfav . Gain_Gain , & rtP .
hsodnwhfav . hsodnwhfav . Gain1_Gain , & rtP . hsodnwhfav . hsodnwhfav .
Saturation_UpperSat , & rtP . hsodnwhfav . hsodnwhfav . Saturation_LowerSat ,
& rtP . hsodnwhfav . hsodnwhfav . Saturation1_UpperSat , & rtP . hsodnwhfav .
hsodnwhfav . Saturation1_LowerSat , & rtP . hsodnwhfav . hsodnwhfav .
DirectLookupTablenD_table [ 0 ] , & rtP . hsodnwhfav . hsodnwhfav .
DirectLookupTablenD_DiagnosticForOutOfRangeInput , & rtP . InputPWM [ 0 ] , &
rtP . WheelSpeed [ 0 ] , & rtP . axleLength , & rtP . lineLength , & rtP .
ticksPerRot , & rtP . wheelR , } ; static int32_T * rtVarDimsAddrMap [ ] = {
( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof (
uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0 } , { "float" , "real32_T" , 0
, 0 , sizeof ( real32_T ) , ( uint8_T ) SS_SINGLE , 0 , 0 , 0 } , {
"signed char" , "int8_T" , 0 , 0 , sizeof ( int8_T ) , ( uint8_T ) SS_INT8 ,
0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR , 18 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 1 , 1 , 4 , 1 , 3 , 3 , 201 , 1
, 2 , 2 , 9 , 1 , 3 , 1 , 1 , 201 , 1259 , 629 , 1 , 173 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.01 , 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 1 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 33 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 92 ,
rtModelParameters , 6 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 3909823708U , 1113749105U , 912998277U , 2265357886U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * Simulation3Draft_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Simulation3Draft_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( (
* rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Simulation3Draft_host_InitializeDataMapInfo (
Simulation3Draft_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
