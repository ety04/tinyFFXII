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

#ifndef _PROXYMACROS_H_
#define _PROXYMACROS_H_

// These macros can't be defined in "QTestProxy.h" as "QTestProxy.cpp" includes this file as well as "QTest" and this
// would lead to macro redefinition warnings.

#define QVERIFY(statement) \
  do { \
    if (!::CuteTest::QTestProxy::qVerify((statement), #statement, "", __FILE__, __LINE__)) \
      return; \
  } while (0)

#define QFAIL(message) \
  do { \
    ::CuteTest::QTestProxy::qFail(message, __FILE__, __LINE__); \
    return; \
  } while (0)

#define QVERIFY2(statement, description) \
  do {\
    if (statement) { \
      if (!::CuteTest::QTestProxy::qVerify(true, #statement, (description), __FILE__, __LINE__)) \
        return; \
    } else { \
      if (!::CuteTest::QTestProxy::qVerify(false, #statement, (description), __FILE__, __LINE__)) \
        return; \
    } \
  } while (0)

#define QCOMPARE(actual, expected) \
  do { \
    if (!::CuteTest::QTestProxy::qCompare(actual, expected, #actual, #expected, __FILE__, __LINE__)) \
      return; \
  } while (0)

#define QSKIP(statement, mode) \
  do { \
    ::CuteTest::QTestProxy::qSkip(statement, ::CuteTest::mode, __FILE__, __LINE__); \
    return; \
  } while (0)

#define QEXPECT_FAIL(dataIndex, comment, mode) \
  do { \
    if (!::CuteTest::QTestProxy::qExpectFail(dataIndex, comment, ::CuteTest::mode, __FILE__, __LINE__)) \
      return; \
  } while (0)

#define QTEST(actual, testElement) \
  do { \
    if (!::CuteTest::QTestProxy::qTest(actual, testElement, #actual, #testElement, __FILE__, __LINE__)) \
      return; \
  } while (0)

#define QWARN(msg) \
  ::CuteTest::QTestProxy::qWarn(msg)

#define QFETCH(type, name)\
  type name = *static_cast<type*>(::CuteTest::qData(#name, ::qMetaTypeId<type>()))


#endif
