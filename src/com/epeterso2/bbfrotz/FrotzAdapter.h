/*
 * FrotzAdapter.h
 *
 *  Created on: Jul 23, 2012
 *      Author: Eric
 */

#ifndef FROTZADAPTER_H_
#define FROTZADAPTER_H_

#include <QObject>

class FrotzAdapter: QObject
{
	Q_OBJECT

public:
	static FrotzAdapter * getInstance(void);

private:
	static FrotzAdapter * instance;
	FrotzAdapter();
	virtual ~FrotzAdapter();
};

#endif /* FROTZADAPTER_H_ */
