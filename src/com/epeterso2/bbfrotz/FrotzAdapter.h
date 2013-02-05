/*
 * FrotzAdapter.h
 *
 *  Created on: Jul 23, 2012
 *      Author: Eric
 */

#ifndef FROTZADAPTER_H_
#define FROTZADAPTER_H_

#include <QObject>
#include <QRunnable>
#include <QString>

#include "frotz.h"

namespace com {
namespace epeterso2 {
namespace bbfrotz {


class FrotzAdapter: public QObject, public QRunnable
{
	Q_OBJECT

/* QObject Properties */

	Q_PROPERTY(QString storyName READ storyName WRITE setStoryName NOTIFY storyNameChanged)

public:
	QString storyName(void);

public slots:
	void setStoryName(QString storyName);

signals:
	void storyNameChanged();

protected:
	QString _storyName;

/* Frotz interface */

public:
	void 	os_beep (int number);
	int  	os_char_width (zchar zc);
	void 	os_display_char (zchar zc);
	void 	os_display_string (const zchar * zc);
	void 	os_draw_picture (int pictureNumber, int y, int x);
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

signals:
	void beep(int number);
	void display(QString text);
	void fatal(QString message);
	void initScreen(void);
	void initSetup(void);
	void mainEnded(void);
	void mainStarted(void);
	void morePrompt(void);
	void resetScreen(void);
	void restartGame(int code);

/* Basic mechanics */

public:
	static FrotzAdapter * instance(void);
	void run(void);

private:
	static FrotzAdapter * _instance;
	FrotzAdapter();
	virtual ~FrotzAdapter();
};

} /* namespace: bbfrotz */
} /* namespace: epeterso2 */
} /* namespace: com */

#endif /* FROTZADAPTER_H_ */
