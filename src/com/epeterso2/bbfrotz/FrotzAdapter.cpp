/*
 * FrotzAdapter.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: Eric
 */

#include "FrotzAdapter.h"

#include <stdio.h>

#include <QMutex>

#include "frotz.h"

extern "C" {
	f_setup_t f_setup;
}

FrotzAdapter * FrotzAdapter::instance;

FrotzAdapter * FrotzAdapter::getInstance(void)
{
	if (! instance)
	{
		static QMutex monitor;
		monitor.lock();

		if (! instance)
		{
			instance = new FrotzAdapter();
		}

		monitor.unlock();
	}

	return instance;
}

FrotzAdapter::FrotzAdapter()
{
}

FrotzAdapter::~FrotzAdapter()
{
}


extern "C"
void 	os_beep (int number)
{
	FrotzAdapter::getInstance()->os_beep(number);
}

void FrotzAdapter::os_beep(int number)
{
	emit beep(number);
}


extern "C"
int  	os_char_width (zchar)
{
	return 0;
}


extern "C"
void 	os_display_char (zchar zc)
{
	FrotzAdapter::getInstance()->os_display_char(zc);
}

void FrotzAdapter::os_display_char(zchar zc)
{
	emit display(convert(zc));
}


extern "C"
void 	os_display_string (const zchar * zc)
{
	FrotzAdapter::getInstance()->os_display_string(zc);
}

void FrotzAdapter::os_display_string(const zchar * zc)
{
	emit display(convert(zc));
}


extern "C"
void 	os_draw_picture (int, int, int)
{
	;
}

extern "C"
void 	os_erase_area (int, int, int, int)
{
	;
}


extern "C"
void 	os_fatal (const char * message)
{
	FrotzAdapter::getInstance()->os_fatal(message);
}

void FrotzAdapter::os_fatal(const char * message)
{
	emit fatal(QString(message));
}


extern "C"
void 	os_finish_with_sample (int)
{
	;
}

extern "C"
int  	os_font_data (int, int *, int *)
{
	return 0;
}

extern "C"
void 	os_init_screen (void)
{
	FrotzAdapter::getInstance()->os_init_screen();
}

void FrotzAdapter::os_init_screen(void)
{
	emit initScreen();
}

extern "C"
void 	os_more_prompt (void)
{
	;
}

extern "C"
FILE *  os_path_open (char * filename, char * mode)
{
	return 0;
}

extern "C"
int  	os_peek_colour (void)
{
	return 0;
}

extern "C"
int  	os_picture_data (int, int *, int *)
{
	return 0;
}

extern "C"
void 	os_prepare_sample (int)
{
	;
}

extern "C"
void 	os_process_arguments (int, char *[])
{
	;
}

extern "C"
int	    os_random_seed (void)
{
	return 0;
}

extern "C"
int  	os_read_file_name (char *, const char *, int)
{
	return 0;
}

extern "C"
zchar	os_read_key (int, int)
{
	return 0;
}

extern "C"
zchar	os_read_line (int, zchar *, int, int, int)
{
	return 0;
}

extern "C"
zword   os_read_mouse(void)
{
	return 0;
}


extern "C"
void 	os_reset_screen (void)
{
	FrotzAdapter::getInstance()->os_reset_screen();
}

void FrotzAdapter::os_reset_screen(void)
{
	emit resetScreen();
}


extern "C"
void 	os_restart_game (int code)
{
	FrotzAdapter::getInstance()->os_restart_game(code);
}

void FrotzAdapter::os_restart_game(int code)
{
	emit restartGame(code);
}


extern "C"
void 	os_scroll_area (int, int, int, int, int)
{
	;
}

extern "C"
void 	os_set_colour (int, int)
{
	;
}

extern "C"
void 	os_set_cursor (int, int)
{
	;
}

extern "C"
void 	os_set_font (int)
{
	;
}

extern "C"
void 	os_set_text_style (int)
{
	;
}

extern "C"
void 	os_start_sample (int, int, int, zword)
{
	;
}

extern "C"
void 	os_stop_sample (int)
{
	;
}

extern "C"
int  	os_string_width (const zchar *)
{
	return 0;
}


extern "C"
void	os_init_setup (void)
{
	FrotzAdapter::getInstance()->os_init_setup();
}

void FrotzAdapter::os_init_setup(void)
{
	emit initSetup();
}


extern "C"
int	os_speech_output(const zchar *)
{
	return 0;
}


QString FrotzAdapter::convert(zchar zc)
{
	return QString(zc);
}

QString FrotzAdapter::convert(const zchar * zc)
{
	return QString("X");
}
