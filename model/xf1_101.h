/*
Fujifilm X-F1
Mirrorless fixed lens

*/

#define MODEL_NAME "Fujifilm XF-1"
#define MODEL_CODE "000192710001927200019273000192740001927500019276000192770001927800019279000192810001928200019286"

// Firmware doesn't seem to use any thumb code
#define NO_THUMB

// Confirmed tests:
#define CAN_DO_EXECUTER
#define CAN_CUSTOM_FIRMWARE
#define PRINTIM_HACK_WORKS
#define MEMO_HACK_WORKS

// Code that writes "PrintIM" to JPEG images. A safe place
// To execute code.
#define FIRM_PRINTIM 0x00516c90
#define MEM_PRINTIM 0x0
#define FIRM_PRINTIM_MAX 236

// Injection details for "voice memo" feature
#define FIRM_MEMO 0x0063fe20
#define MEM_MEMO 0x01397dd8
#define FIRM_MEMO_MAX 100

// Memory address where code can be copied. Need
// A bunch of useless bytes that don't seem important,
// TODO: This is actually where a screen buffer is...
#define MEM_FREE_SPACE 0x019a0000

// Where to hack on the PTP thumbnail function, 
// Seems to have bytes [0xf0, 0x4d, 0x2d, 0xe9]
#define MEM_PTP_THUMBNAIL 0x00e56fbc

// fujifilm.co.jp text printed by PTP
#define MEM_MODEL_TEXT 0x00e5e228

// "USB" unicode text shown when plugged in
#define MEM_USB_TEXT 0x003276f8

// addr of ".WAV" text used by voice memo
#define MEM_WAV_TEXT 0x0137cea4

// Addresses exposed in memory and in firmware
#define FIRM_DUMP_ADDR 0x006e3748
#define MEM_DUMP_ADDR 0x0143b700

// Where "corrupted" firmware data starts
#define MEM_CRYPT_START 0x96b10c0

#define FIRM_CRYPT_START 0x001c8048

// Where unencrypted firmware data starts
#define MEM_FIRM_START 0xda30e5

// EEPRom data
#define MEM_EEP_START 0x409a7e00

// "Seems to work" screen buffer
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MEM_SCREEN_BUFFER (0x01901800 + (640 * 4 * 170) - 520)
#define GET_SCREEN_LAYER(x) (MEM_SCREEN_BUFFER + (SCREEN_WIDTH * SCREEN_HEIGHT * 4) * x)

#define MEM_DEV_FLAG 0x007a117c
#define MEM_DEV_MODE 0x007a7250

#define FUJI_FOPEN_HANDLER 0x00fd45b4
#define FUJI_FWRITE_HANDLER 0x00fd462c
#define FUJI_FREAD_HANDLER 0x00e8e754
#define FUJI_FCLOSE_HANDLER 0x00fd45dc

#define MEM_INPUT_MAP 0x00795370
#define MEM_LAYER_INFO 0x0152e0f4
#define MEM_SQLITE_STRUCT 0x0144c670

// Beginning of the function that shows additional photo properties
#define MEM_SHOW_PHOTO_PROPERTIES 0x011dd210

#ifdef STUBS
	#include "stub.h"

	NSTUB(fuji_drive, 0x0072db0c)

	NSTUB(fuji_fopen, 0x0072b87c)
	NSTUB(fuji_fread, 0x0072b618)
	NSTUB(fuji_fwrite, 0x0072b428)
	NSTUB(fuji_fclose, 0x0072b250)

	NSTUB(fuji_malloc, 0x0073a2cc)

	NSTUB(fuji_toggle, 0x00fd5a1c)
	NSTUB(fuji_zero, 0x00fd4590)

	NSTUB(fuji_create_fixedmemory, 0x0073a4f4)

	NSTUB(fuji_init_sqlite, 0x013c24a8)
	NSTUB(sqlite_exec, 0x014224b4)
	NSTUB(sqlite_snprintf, 0x013ff32c)
	NSTUB(sqlite_mallocAlarm, 0x013fddcc)

	NSTUB(random_strcpy, 0x0072f90c) // good emulator testing function
	NSTUB(random_strncat, 0x0072f9d8)

	NSTUB(fuji_screen_write, 0x011d1fb4)
	NSTUB(fuji_discard_text_buffer, 0x011d1f90)
	NSTUB(fuji_update_buffer, 0x00e8d418)

	//         Experimental:

	NSTUB(fuji_rst_config1, 0x011d2704) // Configures transparency, colors?
	NSTUB(fuji_rst_config2, 0x011fbb38) // configures order?

	// From show_photo_properties
	NSTUB(fuji_rst_rect, 0x0122c35c)

	NSTUB(fuji_rst_bmp, 0x0122ea68)

	NSTUB(test_bmp, 0x0122d3d8)

	NSTUB(test_halt, 0x00e8c704)

	NSTUB(fuji_rst_print, 0x011f2a5c)

	NSTUB(fuji_task_sleep, 0x0073ba3c)
	NSTUB(fuji_create_semaphore, 0x0073b3a4)
	NSTUB(fuji_return_semaphore, 0x00734848)
	NSTUB(fuji_get_semaphore, 0x00734938)

	NSTUB(fuji_task_suspend, 0x00734038)
	NSTUB(fuji_task_create, 0x00735c2c)
	NSTUB(fuji_task_check, 0x00734610)
	NSTUB(fuji_task_test, 0x00734848)

	NSTUB(apply_eeprom, 0x00633d1c)

	NSTUB(fuji_get_key, 0x00d17d4c)

	NSTUB(fuji_dir_open, 0x0070ae18) // ?
	NSTUB(fuji_dir_next, 0x0070acd8)

	NSTUB(sensor_info, 0x00fee158)
	NSTUB(key_push, 0x011d2650)
	NSTUB(run_auto_act, 0x00fd5aa4)

	NSTUB(fuji_ptp_return, 0x00e507c0)
	NSTUB(fuji_ptp_finish, 0x00e514f4)

	NSTUB(fuji_show_gui, 0x00e13030)
	NSTUB(fuji_beep, 0x00e14d18)

	NSTUB(render_eep_menu, 0x00e2e720)

	NSTUB(run_s3_file, 0x00fd2480)

	NSTUB(fuji_get_task, 0x007332cc)

	NSTUB(drive_info, 0x0072bde0)
#endif
