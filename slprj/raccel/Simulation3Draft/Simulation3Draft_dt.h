#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , { "uint64_T" , 17 , 8 } , {
"int64_T" , 18 , 8 } , { "uint_T" , 19 , 32 } , { "char_T" , 20 , 8 } , {
"uchar_T" , 21 , 8 } , { "time_T" , 22 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( uint64_T ) , sizeof ( int64_T ) , sizeof ( uint_T ) ,
sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T ) } ; static const
char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T"
, "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"physical_connection" , "int64_T" , "uint64_T" , "uint64_T" , "int64_T" ,
"uint_T" , "char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition
rtBTransitions [ ] = { { ( char_T * ) ( & rtB . ktg4baxiij ) , 0 , 0 , 36 } ,
{ ( char_T * ) ( & rtB . iitlyzvbjb [ 0 ] ) , 1 , 0 , 4 } , { ( char_T * ) (
& rtB . hsodnwhfav [ 0 ] . bm4eudfrr4 [ 0 ] ) , 0 , 0 , 201 } , { ( char_T *
) ( & rtB . hsodnwhfav [ 0 ] . jz240yzam0 [ 0 ] ) , 1 , 0 , 201 } , { (
char_T * ) ( & rtDW . i2qyvx2esr ) , 0 , 0 , 16 } , { ( char_T * ) ( & rtDW .
gx0eezp4oh . LoggedData ) , 11 , 0 , 3 } , { ( char_T * ) ( & rtDW .
dtffab24fv ) , 6 , 0 , 4 } , { ( char_T * ) ( & rtDW . cv32usfudo ) , 7 , 0 ,
1 } , { ( char_T * ) ( & rtDW . oc2vv2qobo ) , 3 , 0 , 4 } , { ( char_T * ) (
& rtDW . o3vvrfpxkk ) , 8 , 0 , 2 } , { ( char_T * ) ( & rtDW . hsodnwhfav [
0 ] . e3evixvwmi ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . hsodnwhfav [ 0 ]
. klt5acnwos ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . hsodnwhfav [ 0 ] .
pohhf0zdrr ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . hsodnwhfav [ 0 ] .
hsodnwhfav [ 200 ] . hz3a5pczoy ) , 7 , 0 , 1 } , { ( char_T * ) ( & rtDW .
plige5liff [ 3 ] . ok2jbhyf1e ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW .
plige5liff [ 3 ] . h11ovhfoxn ) , 7 , 0 , 1 } , { ( char_T * ) ( & rtDW .
plige5liff [ 3 ] . c2dlt0ce3l ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW .
plige5liff [ 3 ] . hecpg1s5r3 ) , 8 , 0 , 1 } } ; static
DataTypeTransitionTable rtBTransTable = { 18U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . InputPWM [
0 ] ) , 0 , 0 , 444 } , { ( char_T * ) ( & rtP . Switch_Threshold_j3y0cmi1bi
) , 1 , 0 , 1 } , { ( char_T * ) ( & rtP . Constant_Value_aizakqrn1k ) , 2 ,
0 , 8 } , { ( char_T * ) ( & rtP . hsodnwhfav . Constant_Value [ 0 ] ) , 0 ,
0 , 201 } , { ( char_T * ) ( & rtP . hsodnwhfav . hsodnwhfav . Gain1_Gain ) ,
0 , 0 , 10 } , { ( char_T * ) ( & rtP . hsodnwhfav . hsodnwhfav .
DirectLookupTablenD_table [ 0 ] ) , 1 , 0 , 791911 } , { ( char_T * ) ( & rtP
. hsodnwhfav . hsodnwhfav . DirectLookupTablenD_DiagnosticForOutOfRangeInput
) , 3 , 0 , 1 } , { ( char_T * ) ( & rtP . plige5liff . Gain1_Gain ) , 0 , 0
, 9 } , { ( char_T * ) ( & rtP . plige5liff . DirectLookupTablenD_table [ 0 ]
) , 1 , 0 , 791911 } , { ( char_T * ) ( & rtP . plige5liff .
DirectLookupTablenD_DiagnosticForOutOfRangeInput ) , 3 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 10U , rtPTransitions } ;
