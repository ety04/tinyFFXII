//////////////////////////////////////////////////////////////////////////
//                                                                      //
//  Copyright (C) 2012  Maya Studios (http://mayastudios.com)           //
//  All rights reserved.                                                //
//                                                                      //
//  This file is part of CuteTest.                                      //
//                                                                      //
//  CuteTest is free software: you can redistribute it and/or modify    //
//  it under the terms of the GNU Lesser General Public License as      //
//  published by the Free Software Foundation, either version 3 of the  //
//  License, or (at your option) any later version.                     //
//                                                                      //
//  CuteTest is distributed in the hope that it will be useful,         //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of      //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the       //
//  GNU Lesser General Public License for more details.                 //
//                                                                      //
//  You should have received a copy of the GNU Lesser General Public    //
//  License along with CuteTest.  If not, see                           //
//  <http://www.gnu.org/licenses/>.                                     //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef _TOSTRING_H_
#define _TOSTRING_H_

#include "cutetest_export.h"

#include <qglobal.h>

class QLatin1String;
class QString;
class QByteArray;
class QTime;
class QDate;
class QDateTime;
class QChar;
class QPoint;
class QSize;
class QRect;
class QRectF;
class QPointF;
class QSizeF;
class QUrl;
class QVariant;


namespace CuteTest {
  // NOTE: These functions are defined in a namespace (rather than a class) to allow the users to provide their own
  //   specializations.
  //
  namespace Conversion {
    //
    // toString() function
    // Primarily used by qCompare to output value on inequality
    //

    // Returns an empty string for unsupported types - this must be a template to accept all types
    // NOTE: The string must be created via "new" - it'll be deleted(!) later on.
    template <typename T>
    char* toString(const T&) {
      return NULL; // NOTE: Don't return "" as this will be deleted. Return NULL instead.
    }

    CUTETEST_EXPORT char* toString(short);
    CUTETEST_EXPORT char* toString(ushort);
    CUTETEST_EXPORT char* toString(int);
    CUTETEST_EXPORT char* toString(uint);
    CUTETEST_EXPORT char* toString(long);
    CUTETEST_EXPORT char* toString(ulong);
    CUTETEST_EXPORT char* toString(qint64);
    CUTETEST_EXPORT char* toString(quint64);

    CUTETEST_EXPORT char* toString(bool);
    CUTETEST_EXPORT char* toString(char);
    CUTETEST_EXPORT char* toString(float);
    CUTETEST_EXPORT char* toString(double);

    CUTETEST_EXPORT char* toString(const char*);
    CUTETEST_EXPORT char* toString(const void*);

    CUTETEST_EXPORT char* toString(const QLatin1String&);
    CUTETEST_EXPORT char* toString(const QString&);
    CUTETEST_EXPORT char* toString(const QByteArray&);
    CUTETEST_EXPORT char* toString(const QTime&);
    CUTETEST_EXPORT char* toString(const QDate&);
    CUTETEST_EXPORT char* toString(const QDateTime&);
    CUTETEST_EXPORT char* toString(const QChar&);
    CUTETEST_EXPORT char* toString(const QPoint&);
    CUTETEST_EXPORT char* toString(const QSize&);
    CUTETEST_EXPORT char* toString(const QRect&);
    CUTETEST_EXPORT char* toString(const QRectF&);
    CUTETEST_EXPORT char* toString(const QPointF&);
    CUTETEST_EXPORT char* toString(const QSizeF&);
    CUTETEST_EXPORT char* toString(const QUrl&);
    CUTETEST_EXPORT char* toString(const QVariant&);
  }
}

#endif
