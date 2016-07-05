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

#ifndef _TESTCONSOLERUNNER_H_
#define _TESTCONSOLERUNNER_H_

#include "cutetest_export.h"
#include <QObject>


namespace CuteTest {
  class TestRunner;
  class TestCase;
  class TestIncident;

  class CUTETEST_EXPORT TestConsoleFrontend : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(TestConsoleFrontend)

  public:
    TestConsoleFrontend(TestRunner* testRunner, QObject* parent = NULL);

  public:
    static int main(int argc, char *argv[]);

  private slots:
    void onTestSuiteFinished(const QString& suiteName);
    void onRunnerFinished();

  private:
    void printIncidents(const TestCase& testCase);
    void printIncident(const TestIncident& incident, int incidentNumber);

  private:
    TestRunner* m_runner;
  };

}

#endif
