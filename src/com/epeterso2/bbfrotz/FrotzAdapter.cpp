/*
 * FrotzAdapter.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: Eric
 */

#include "FrotzAdapter.h"

#include <stdio.h>

#include <QDebug>
#include <QMutex>

#include "frotz.h"

extern "C" {
	f_setup_t f_setup;
}

using namespace com::epeterso2::bbfrotz;

FrotzAdapter * FrotzAdapter::_instance = 0;

FrotzAdapter * FrotzAdapter::instance(void)
{
	if (! _instance)
	{
		static QMutex monitor;
		monitor.lock();

		if (! _instance)
		{
			_instance = new FrotzAdapter();
		}

		monitor.unlock();
	}

	return _instance;
}

// The name of the story file to load
extern "C"
{
	extern char * story_name;
}

FrotzAdapter::FrotzAdapter()
{
}

FrotzAdapter::~FrotzAdapter()
{
}


QString FrotzAdapter::storyName(void)
{
	return _storyName;
}

void FrotzAdapter::setStoryName(QString storyName)
{
	_storyName = storyName;

	if (story_name)
	{
		free(story_name);

		story_name = (char *) malloc(_storyName.length() + 1);

		if (story_name == 0)
		{
			os_fatal("malloc failed for story_name");
		}
	}

	emit storyNameChanged();
}


extern "C"
void 	os_beep (int number)
{
	FrotzAdapter::instance()->os_beep(number);
}

void FrotzAdapter::os_beep(int number)
{
	emit beep(number);
}


extern "C"
int  	os_char_width (zchar z)
{
	FrotzAdapter::instance()->os_char_width(z);
}

int FrotzAdapter::os_char_width(zchar z)
{
	return 1;
}


extern "C"
void 	os_display_char (zchar zc)
{
	FrotzAdapter::instance()->os_display_char(zc);
}

void FrotzAdapter::os_display_char(zchar zc)
{
	;
}


extern "C"
void 	os_display_string (const zchar * zc)
{
	FrotzAdapter::instance()->os_display_string(zc);
}

void FrotzAdapter::os_display_string(const zchar * zc)
{
	;
}


extern "C"
void 	os_draw_picture (int pictureNumber, int y, int x)
{
	; // unsupported
}


extern "C"
void 	os_erase_area (int, int, int, int)
{
	;
}


extern "C"
void 	os_fatal (const char * message)
{
	FrotzAdapter::instance()->os_fatal(message);
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
	FrotzAdapter::instance()->os_init_screen();
}

void FrotzAdapter::os_init_screen(void)
{
	emit initScreen();
}

extern "C"
void 	os_more_prompt (void)
{
	; // Not needed
}

extern "C"
FILE *  os_path_open (char * filename, char * mode)
{
	return fopen(filename, mode);
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
void 	os_process_arguments (int argc, char * argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	; // Nothing to do here
}

extern "C"
int	    os_random_seed (void)
{
	return 0; // unused
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
	FrotzAdapter::instance()->os_reset_screen();
}

void FrotzAdapter::os_reset_screen(void)
{
	emit resetScreen();
}


extern "C"
void 	os_restart_game (int code)
{
	FrotzAdapter::instance()->os_restart_game(code);
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
	; // Not supported
}

extern "C"
void 	os_stop_sample (int)
{
	; // Not supported
}

extern "C"
int  	os_string_width (const zchar *)
{
	return 0;
}


extern "C"
void	os_init_setup (void)
{
	FrotzAdapter::instance()->os_init_setup();
}

void FrotzAdapter::os_init_setup(void)
{
	emit initSetup();
}


extern "C"
int	os_speech_output(const zchar *)
{
	return 0; // Not supported
}


void FrotzAdapter::run(void)
{
	char * argv[] = {};

	emit mainStarted();
	frotz_main(sizeof(argv), argv);
	emit mainEnded();
}
