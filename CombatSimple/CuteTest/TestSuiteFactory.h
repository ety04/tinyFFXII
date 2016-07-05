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

#ifndef _TESTCASEFACTORY_H_
#define _TESTCASEFACTORY_H_

#include "cutetest_export.h"

#include <QObject>
#include <QString>

// This #ifndef makes sure that we don't need to specify BUILD_DIR when compiling CuteTest itself.
#ifndef COMPILE_CUTETEST_LIB

// BUILD_DIR must be specified for compilers other than Microsoft Visual C++ (e.g. for g++) as with this compiler 
// "__FILE__" is relative (to the directory the compiler was executed). In this case BUILD_DIR is used to be able to 
// resolve the relative file names.
//
// Add this line to the .pro file to define the BUILD_DIR constant:
//
//   DEFINES += BUILD_DIR=\\\"$$PWD\\\"
//
#ifndef BUILD_DIR
  #ifndef WIN32
    #warning BUILD_DIR should be specified
  #endif
  #define BUILD_DIR ""
#endif

#define TESTSUITE(ClassName) \
  ClassName; \
  static ::CuteTest::TestCaseFactoryImpl<ClassName>* TestCaseFactory_##ClassName \
    = ::CuteTest::TestCaseFactoryImpl<ClassName>::init(#ClassName, BUILD_DIR, __FILE__); \
  class

#endif

namespace CuteTest {

  class CUTETEST_EXPORT TestSuiteFactory {
  public:
    TestSuiteFactory(const QString& suiteName, const QString& buildDir, const QString& filePath);

  public:
    virtual QObject* create() = 0;

    QString suiteName() const {
      return this->m_suiteName;
    }

    QString buildDir() {
      return this->m_buildDir;
    }

    //! The absolute path of the file where this factory's test suite is defined in. Will be empty, if the file couldn't
    //! be determined.
    QString fileName() const {
      return this->m_fileName;
    }

  private:
    QString m_suiteName;
    QString m_buildDir;
    QString m_fileName;
  };


  template<typename T>
  class TestCaseFactoryImpl : public TestSuiteFactory {
  private:
    TestCaseFactoryImpl(QString suiteName, const QString& buildDir, const QString& filePath) 
      : TestSuiteFactory(suiteName, buildDir, filePath) { }

  public:
    static TestCaseFactoryImpl<T>* init(const char* suiteName, const char* buildDir, const char* filePath) {
      // Qt classes (i.e. inheriting from QObject) can't be defined in a ".cpp" file on Visual C++. So they need to be
      // defined in a ".h" file. Without the safeguards of this method, including the ".h" in multiple ".cpp" files 
      // would register the test case multiple times.
      static TestCaseFactoryImpl<T> instance(suiteName, buildDir, filePath);
      return &instance;
    }

    virtual QObject* create() {
      return new T();
    }
  };

}

#endif
