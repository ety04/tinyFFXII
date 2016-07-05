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

#ifndef _TESTRESULT_H_
#define _TESTRESULT_H_

#include "cutetest_export.h"

#include <QString>
#include <QList>
#include <QExplicitlySharedDataPointer>
#include <QMetaType>

#include "CuteTest/TestIncident.h"


namespace CuteTest {
  class TestSuite;

  class CUTETEST_EXPORT TestCase {
  public:
    enum OutcomeType {
      //! The test case passed without failures (but possibly with skipped tests and expected failures).
      Passed,
      //! The test case failed (i.e. one check failed or one check passed unexpectedly)
      Failed,
      //! The whole test was skipped. If data sets were used, all(!) data sets were skipped.
      Skipped
    };

  public:
    TestCase();
    TestCase(const TestSuite& testSuite, const QString& name);

    TestCase(const TestCase& other);
    TestCase& operator=(const TestCase& other);

    ~TestCase();

  public:
    //! The name of the setup method ("initTestCase")
    static const QString SETUP_METHOD_NAME;
    //! The name of the teardown method ("cleanupTestCase")
    static const QString TEARDOWN_METHOD_NAME;

  public:
    //! Indicates whether this instance contains any data. You must not call any method of this class unless this method
    //! returns false.
    bool isNull() const {
      return this->m_data.constData() == NULL;
    }

    //! Returns the test suite this test case belongs to.
    const TestSuite& testSuite() const;

    //! The name of this test case.
    QString name() const;

    //! The outcome of this test case (i.e. passed, failed, or skipped). This value is dynamically computed based on the
    //! incidents added to this test case result.
    OutcomeType outcome() const;

    //! The list of incidents that happened in this test case run. For skipped or failed tests will contain at least 
    //! one item. For passed tests this will be empty in most case, it may, however, contain skipped data sets, 
    //! expected failures, and warnings.
    QList<TestIncident> incidents() const;

    //! Returns the number of incidents (all incident types) in this test case.
    int incidentCount() const;
    //! Returns the number of incidents of the specified incident type in this test case.
    int incidentCount(TestIncident::IncidentType type) const;

    void addIncident(const TestIncident& incident);

  private:
    struct Data;
    QExplicitlySharedDataPointer<Data> m_data;
  };

}

// Must be outside the namespace; otherwise it may not compile on gcc
Q_DECLARE_METATYPE(CuteTest::TestCase)

#endif
