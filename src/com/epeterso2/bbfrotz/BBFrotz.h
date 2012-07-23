/*
 * BBFrotz.h
 *
 *  Created on: Jul 23, 2012
 *      Author: Eric
 */

#ifndef BBFROTZ_H_
#define BBFROTZ_H_

#include <QObject>

namespace com {
namespace epeterso2 {
namespace bbfrotz {

class BBFrotz: public QObject
{
	Q_OBJECT
public:
	BBFrotz();
	virtual ~BBFrotz();
};

} /* namespace bbfrotz */
} /* namespace epeterso2 */
} /* namesapce com */

#endif /* BBFROTZ_H_ */
