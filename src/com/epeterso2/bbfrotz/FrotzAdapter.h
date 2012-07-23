/*
 * FrotzAdapter.h
 *
 *  Created on: Jul 23, 2012
 *      Author: Eric
 */

#ifndef FROTZADAPTER_H_
#define FROTZADAPTER_H_

#include <QObject>

#include "frotz.h"

class FrotzAdapter: QObject
{
	Q_OBJECT

public:
	static FrotzAdapter * getInstance(void);

	void 	os_beep (int);
	int  	os_char_width (zchar);
	void 	os_display_char (zchar);
	void 	os_display_string (const zchar *);
	void 	os_draw_picture (int, int, int);
	void 	os_erase_area (int, int, int, int);
	void 	os_fatal (const char *);
	void 	os_finish_with_sample (int);
	int  	os_font_data (int, int *, int *);
	void 	os_init_screen (void);
	void	os_init_setup (void);
	void 	os_more_prompt (void);
	int  	os_peek_colour (void);
	int  	os_picture_data (int, int *, int *);
	void 	os_prepare_sample (int);
	void 	os_process_arguments (int, char *[]);
	int		os_random_seed (void);
	int  	os_read_file_name (char *, const char *, int);
	zchar	os_read_key (int, int);
	zchar	os_read_line (int, zchar *, int, int, int);
	void 	os_reset_screen (void);
	void 	os_restart_game (int);
	void 	os_scroll_area (int, int, int, int, int);
	void 	os_set_colour (int, int);
	void 	os_set_cursor (int, int);
	void 	os_set_font (int);
	void 	os_set_text_style (int);
	void 	os_start_sample (int, int, int, zword);
	void 	os_stop_sample (int);
	int  	os_string_width (const zchar *);
	int		os_speech_output(const zchar *);

public slots:

signals:
	void beep(int number);
	void display(QString text);
	void fatal(QString message);
	void initScreen(void);
	void initSetup(void);
	void resetScreen(void);
	void restartGame(int code);

private:
	static FrotzAdapter * instance;
	FrotzAdapter();
	virtual ~FrotzAdapter();
	QString convert(zchar zc);
	QString convert(const zchar * zc);
};

#endif /* FROTZADAPTER_H_ */
