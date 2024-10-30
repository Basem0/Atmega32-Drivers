/*
 * STD_TYPES.h
 *
 * Created: 10/23/2024 2:52:31 PM
 *  Author: ahmed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// ************************* INT TYPES ***************************
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned long      uint32;
typedef unsigned long long uint64;

typedef signed char        sint8;
typedef signed short       sint16;
typedef signed long        sint32;
typedef signed long long   sint64;

typedef volatile unsigned char              vuint8;
typedef volatile unsigned short             vuint16;
typedef volatile unsigned int               vuint32;
typedef volatile unsigned long long int     vuint64;

typedef volatile signed char                vsint8;
typedef volatile signed short               vsint16;
typedef volatile signed int                 vsint32;
typedef volatile signed long long int       vsint64;
// ***************************************************************

// ************************* FLOAT TYPES *************************
typedef float      f32;
typedef double     f64;
// ***************************************************************

// ************************** STD TYPES **************************
// Return Type Of Function
typedef enum
{
	E_NOK = 0,
	E_OK,
	E_NULL_PTR	
}STD_RET;

// Voltage Return Type
typedef enum
{
	STD_LOW = 0,
	STD_HIGH,
}STD_STATE;

#define ZERO_INIT 0
#define NULL ((void *)0)
// ***************************************************************






#endif /* STD_TYPES_H_ */