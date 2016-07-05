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

#ifndef _TESTINCIDENT_H_
#define _TESTINCIDENT_H_

#include "cutetest_export.h"

#include <QString>
#include <QExplicitlySharedDataPointer>
#include <QMetaType>


namespace CuteTest {
  class TestCase;

  //!
  //! An incident that happened while running a test case.
  //!
  class CUTETEST_EXPORT TestIncident {
  public:
    enum IncidentType {
      //! A warning was issued.
      Warning,
      //! The test case (or one of its data sets) was skipped.
      Skipped,
      //! The test case (or one of its data sets) failed.
      Failed,
      //! A check in the test case failed expectedly. This is usually used when the programmer knows about an error but
      //! can't currently fix it (e.g. because it'll be fixed later).
      FailedExpectedly,
      //! A check in the test case was expected to fail (see \c FailedExpectedly), but it didn't. Either the bug was 
      //! fixed or something else is wrong
      PassedUnexpectedly,
      //! The number of incident types
      // IMPORTANT: Must always be the last item
      IncidentTypeCount
    };

  public:
    TestIncident();
    TestIncident(const TestCase& testCase, IncidentType type, QString file, int line, QString description, 
                 QString dataSetName);
    
    TestIncident(const TestIncident& other);
    TestIncident& operator=(const TestIncident& other);
    
    ~TestIncident();

  public:
    //! Indicates whether this instance contains any data. You must not call any method of this class unless this method
    //! returns false.
    bool isNull() const {
      return this->m_data.constData() == NULL;
    }

    //! The test case this incident belongs to.
    const TestCase& testCase() const;

    //! The type of the incident.
    IncidentType type() const;

    //! The file (absolute file path) where this incident happened. May be empty, if unknown or if the file doesn't 
    //! exist.
    QString file() const;

    //! The line where this incident happened (in the file returned by \c file() ).
    int line() const;

    //! The description of this incident, if provided.
    QString description() const;

    //! The name of the data set that was involved in this incident. Is empty if the test case didn't use data sets.
    QString dataSetName() const;
    
  private:
    struct Data;
    QExplicitlySharedDataPointer<Data> m_data;
  };

}

// Must be outside the namespace; otherwise it may not compile on gcc
Q_DECLARE_METATYPE(CuteTest::TestIncident)

#endif
