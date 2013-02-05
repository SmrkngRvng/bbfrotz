/*
 * ZsciiTextCodec.cpp
 *
 *  Created on: Feb 5, 2013
 *      Author: Eric
 */

#include "ZsciiTextCodec.h"

ZsciiTextCodec::ZsciiTextCodec()
{
	_zsciiTable << QChar(0);
}

ZsciiTextCodec::~ZsciiTextCodec()
{
}

QByteArray ZsciiTextCodec::name(void) const
{
	return QByteArray("ZSCII");
}

QList<QByteArray> ZsciiTextCodec::aliases(void) const
{
	QList<QByteArray> list;

	return list;
}

int ZsciiTextCodec::mibEnum(void) const
{
	return 2600;
}

QString ZsciiTextCodec::convertToUnicode(const char* chars, int len,
		ConverterState* state) const
{
	return QString("");
}

QByteArray ZsciiTextCodec::convertFromUnicode(const QChar * in, int length,
		ConverterState* state) const
{
	return QString(*in).toAscii();
}
