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

#ifndef _QTESTPROXY_H_
#define _QTESTPROXY_H_

#include "cutetest_export.h"

#include <QString>
#include <QMetaType>

#include "ToString.h"

class QTestData;

namespace CuteTest {

  enum SkipMode { SkipSingle = 1, SkipAll = 2 };
  enum TestFailMode { Abort = 1, Continue = 2 };

  class CUTETEST_EXPORT QTestProxy {
  public:
    static bool qVerify(bool statement, const char *statementStr, const char *description,
                        const char *file, int line);
    static void qFail(const char *statementStr, const char *file, int line);
    static void qSkip(const char *message, SkipMode mode, const char *file, int line);
    static bool qExpectFail(const char *dataIndex, const char *comment, TestFailMode mode,
                            const char *file, int line);
    static void qWarn(const char *message);

    //
    // qCompare
    //

#define QCOMPARE_DEFAULT_PARAMS const char *actual, const char *expected, const char *file, int line

    template <typename T>
    static inline bool qCompare(T const &t1, T const &t2, QCOMPARE_DEFAULT_PARAMS) {
      return (t1 == t2) ? compare_helper(true, "COMPARE()", file, line)
                        : compare_helper(false, "Compared values are not the same",
                                         Conversion::toString(t1), Conversion::toString(t2), 
                                         actual, expected, file, line);
    }

    template <typename T>
    static inline bool qCompare(const T *t1, const T *t2, QCOMPARE_DEFAULT_PARAMS) {
      return compare_ptr_helper(t1, t2, actual, expected, file, line);
    }

    // Strings

    static inline bool qCompare(const char *t1, const char *t2, QCOMPARE_DEFAULT_PARAMS) {
      return compare_string_helper(t1, t2, actual, expected, file, line);
    }

    static inline bool qCompare(const QString& t1, const char *t2, QCOMPARE_DEFAULT_PARAMS) {
      return compare_string_helper(t1, QString(t2), actual, expected, file, line);
    }

    static inline bool qCompare(const char *t1, const QString& t2, QCOMPARE_DEFAULT_PARAMS) {
      return compare_string_helper(QString(t1), t2, actual, expected, file, line);
    }

    static inline bool qCompare(const QString& t1, const QString& t2, QCOMPARE_DEFAULT_PARAMS) {
      return compare_string_helper(t1, t2, actual, expected, file, line);
    }

    // Floating points type are compared with fuzzy compare (epsilon comparison)
    static bool qCompare(double const &t1, double const &t2, QCOMPARE_DEFAULT_PARAMS);

#undef QCOMPARE_DEFAULT_PARAMS

  private:
    static bool compare_ptr_helper(const void *t1, const void *t2, const char *actual, const char *expected, 
                                   const char *file, int line);

    static bool compare_string_helper(const char *t1, const char *t2, const char *actual, const char *expected, 
                                      const char *file, int line);
    static bool compare_string_helper(const QString& t1, const QString& t2, const char *actual, const char *expected, 
                                      const char *file, int line);

    static bool compare_helper(bool success, const char *msg, const char *file, int line);
    static bool compare_helper(bool success, const char *msg, char *val1, char *val2,
                               const char *expected, const char *actual, const char *file, int line);
  };

  //
  // Data Set management
  //
  CUTETEST_EXPORT void* qData(const char* dataSetName, int typeId);
    
  CUTETEST_EXPORT void addDataSetColumnInternal(int id, const char *name);
    
  template <typename T>
  inline void addDataSetColumn(const char *name, T * = 0) {
    addDataSetColumnInternal(qMetaTypeId<T>(), name);
  }
    
    
  class CUTETEST_EXPORT QTestDataProxy {
    friend CUTETEST_EXPORT QTestDataProxy newDataSet(const char* dataSetName);
    QTestDataProxy(QTestData* data);
  public:
    const char* dataSetName() const;

    void append(int type, const void *data);
    void* data(int index) const;
    int dataCount() const;

  private:
    QTestData* m_data;
  };

  CUTETEST_EXPORT QTestDataProxy newDataSet(const char* dataSetName);

  // NOTE: This operators are defined outside the class to allow the user to expand them.
  template<typename T>
  CuteTest::QTestDataProxy operator<<(CuteTest::QTestDataProxy data, const T& value) {
    data.append(qMetaTypeId<T>(), &value);
    return data;
  }
  
  inline CuteTest::QTestDataProxy operator<<(CuteTest::QTestDataProxy data, const char* value) {
    QString str = QString::fromAscii(value);
    data.append(QMetaType::QString, &str);
    return data;
  }    

}

#endif
