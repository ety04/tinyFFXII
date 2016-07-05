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

#ifndef _TESTSUITERESULT_H_
#define _TESTSUITERESULT_H_

#include "cutetest_export.h"

#include <QList>
#include <QExplicitlySharedDataPointer>
#include <QMetaType>

#include "TestCase.h"


namespace CuteTest {
  //!
  //! Container for test cases (a.k.a. test functions).
  //!
  class CUTETEST_EXPORT TestSuite {
  public:
    TestSuite();
    TestSuite(const QString& name, const QString& file, const QString& buildDir);

    TestSuite(const TestSuite& other);
    TestSuite& operator=(const TestSuite& other);

    ~TestSuite();

  public:
    //! Indicates whether this instance contains any data. You must not call any method of this class unless this method
    //! returns false.
    bool isNull() const {
      return this->m_data.constData() == NULL;
    }

    //! The name of this test suite. This is the full qualified class name (i.e. including namespace), for example
    //! "MyTestSuiteWithoutNamespace" or "MyNamespace::MyTestSuiteWithNamespace".
    QString name() const;

    //! Returns the file in which this test suite is defined. May be empty, if the file couldn't be determined.
    QString srcFile() const;

    //! The directory from which the test suite was built. May be empty if it's unknown.
    QString buildDir() const;

    //! Returns the test case with the specified name (including the life cycle test cases "initTestCase" and
    //! "cleanupTestCase"). If the test case is unknown, a empty instance ("isNull() = true") will be returned.
    TestCase testCase(const QString& name) const;
    //! Returns all test cases belonging to this test suite. This includes the life cycle test cases ("initTestCase" and
    //! "cleanupTestCase").
    QList<TestCase> testCases() const;

    //! Returns the test case for the setup method ("initTestCase") of this test suite. This test case always exist, 
    //! even if it's not written explicitly. This is one of the two "life cycle test cases".
    TestCase setupMethod() const;
    //! Returns the test case for the teardown method ("cleanupTestCase") of this test suite. This test case always 
    //! exist, even if it's not  written explicitly. This is one of the two "life cycle test cases".
    TestCase teardownMethod() const;

    //! Returns the number of test cases in this test suite. This includes the life cycle test cases ("initTestCase" and
    //! "cleanupTestCase").
    int testCaseCount() const;
    //! Returns the number of failed test cases in this test suite.
    //! @param includingLifeCycleMethods  indicates whether the life cycle test cases ("initTestCase" and 
    //!   "cleanupTestCase") are to be included in the count. Of course, this only matters if they actually failed.
    int failedCount(bool includingLifeCycleMethods = true) const;
    //! Returns the number of skipped test cases in this test suite.
    //! @param includingLifeCycleMethods  indicates whether the life cycle test cases ("initTestCase" and 
    //!   "cleanupTestCase") are to be included in the count. Of course, this only matters if they were actually 
    //!   skipped.
    int skippedCount(bool includingLifeCycleMethods = true) const;
    //! Returns the number of passed (i.e. not failed) test cases in this test suite.
    //! @param includingLifeCycleMethods  indicates whether the life cycle test cases ("initTestCase" and 
    //!   "cleanupTestCase") are to be included in the count. Of course, this only matters if they actually passed.
    int passedCount(bool includingLifeCycleMethods = true) const;
    //! Returns the number of warnings (warning incidents) in this test suite.
    int warningCount() const;

    void addTestCase(const TestCase& result);

  private:
    struct Data;
    QExplicitlySharedDataPointer<Data> m_data;
  };
    
}

// Must be outside the namespace; otherwise it may not compile on gcc
Q_DECLARE_METATYPE(CuteTest::TestSuite)


#endif
