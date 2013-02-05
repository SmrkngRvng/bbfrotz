/*
 * ZsciiTextCodec.h
 *
 *  Created on: Feb 5, 2013
 *      Author: Eric
 */

#ifndef ZSCIITEXTCODEC_H_
#define ZSCIITEXTCODEC_H_

#include <QByteArray>
#include <QChar>
#include <QList>
#include <QString>
#include <QTextCodec>

class ZsciiTextCodec: public QTextCodec
{
public:
	ZsciiTextCodec();
	virtual ~ZsciiTextCodec();

	virtual QByteArray name(void) const;
	virtual QList<QByteArray> aliases(void) const;
	virtual int mibEnum(void) const;
	virtual QString convertToUnicode(const char * chars, int len, ConverterState * state) const;
    virtual QByteArray convertFromUnicode(const QChar *in, int length, ConverterState *state) const;

protected:
    QList<QChar> _zsciiTable;
};

#endif /* ZSCIITEXTCODEC_H_ */
