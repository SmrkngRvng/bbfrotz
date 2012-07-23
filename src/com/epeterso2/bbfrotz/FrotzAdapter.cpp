/*
 * FrotzAdapter.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: Eric
 */

#include "FrotzAdapter.h"

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
