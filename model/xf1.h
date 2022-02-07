/*
Fujifilm X-F1 Information File
*/

#define MODEL_NAME "Fujifilm XF-1"

// Confirmed tests:
#define CAN_DO_EXECUTER
#define CAN_CUSTOM_FIRMWARE
#define PRINTIM_HACK_WORKS

#define MEM_START 0x011ea108 - 0x10000
#define TEXT_START 0x00492150 - 0x10000
#define COPY_LENGTH 0x500000

// Code that writes "PrintIM" to JPEG images. A safe place
// To execute code.
#define FIRMWARE_PRINTIM 0x00516c90
#define FIRMWARE_PRINTIM_MAX 236

// Memory address where code can be copied. Need
// A bunch of useless bytes that don't seem important,
// crashes when I go over 2kb
#define MEM_FREE_SPACE 0x00e572e8

// Where to hack on the PTP thumbnail function, 
// Seems to have bytes [0xf0, 0x4d, 0x2d, 0xe9]
#define MEM_PTP_THUMBNAIL 0x00e56fbc

// fujifilm.co.jp text printed by PTP
#define MEM_MODEL_TEXT 0x00e5e228

// "USB" unicode text shown when plugged in
#define MEM_USB_TEXT 0x003276f8

#ifdef STUBS
	#include "stub.h"

	NSTUB(fuji_drive, 0x0072db0c)
	NSTUB(fuji_fopen, 0x0072b87c) // see 0x00e8ed40
	NSTUB(fuji_fread, 0x0072b618)
	NSTUB(fuji_malloc, 0x0073a2cc)

	// Fopen function, calls fine
	NSTUB(fujidemo, 0x0074d0c4)

	NSTUB(fuji_file_do, 0x0074b4cc)

	NSTUB(fuji_file_create, 0x0074ce38)

	/*
	Example: 0x013f7414
	
	sqlite_exec(0x0144c67c, "create table foo()", ); 

	select tm from finf
	*/

	NSTUB(sqlite_alloc, 0x014351ec)

	NSTUB(sqlite_parse, 0x01435224) // not entirely sure
	NSTUB(sqlite_exec, 0x014224b4)
	NSTUB(sqlite_snprintf, 0x013ff32c)

	NSTUB(dumb_test, 0x011d1bec)
	NSTUB(random_strcpy, 0x0072f90c) // nothing much, good testing function
#endif
