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

#ifndef _TESTRUNNER_H_
#define _TESTRUNNER_H_

#include "cutetest_export.h"
#include <QObject>

#include <QStringList>
#include <QList>

#include "TestSuite.h"


namespace CuteTest {
  class TestSuiteFactory;

  class CUTETEST_EXPORT TestRunner : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(TestRunner)

  public:
    TestRunner(QObject* parent = NULL, const QString& testRunnerApp = "");

  public:
    enum OutputType {
      //! The output is human readable.
      OT_HumanReadable,
      OT_Xml,
      OT_XunitXml,
      OT_LightXml,
    };

    enum XmlEnvelopeType {
      XET_None,
      XET_SuiteOnly,
      XET_SuitesAndRoot
    };

  public:
    //! Executes QTest in this process, if requested by the command line args (requires a created QCoreApplication or
    //! QApplication). This method must be executed before displaying any frontend to the user. If it returns \c true,
    //! the application must exit after this method returns. Otherwise the application can show the frontend.
    static bool execInnerProc();

    // Runs the tests in a sub process (necessary to parse the output of QTest). Requires a running Qt event loop to be
    // able to complete. (Doesn't have to run though when this method is called.)
    void runAllTests();
    void runTests(const QStringList& testNames);
    void runTest(const QString& testName);

    //! Indicates whether tests are currently run.
    bool isRunning() const;
    //! Indicates whether tests have been run. Only true if "isRunning()" is false. This is set to true just before
    //! finished() is emitted.
    bool isFinished() const;

    // Runs the tests in the current process. A "QCoreApplication" or "QApplication" should have been created.
    static void runAllTestsInThisProc(OutputType outputType = OT_HumanReadable, 
                                      XmlEnvelopeType xmlEnvelope = XET_SuitesAndRoot);
    static void runTestInThisProc(TestSuiteFactory* factory, OutputType outputType = OT_HumanReadable, 
                                  XmlEnvelopeType xmlEnvelope = XET_None);
    static void runTestInThisProc(QObject* testSuite); // Prints human readable output
    static void runTestInThisProc(QObject* testSuite, const QString& testSuiteFile, const QString& buildDir, 
                                  OutputType outputType, XmlEnvelopeType xmlEnvelope);

    int testSuiteCount() const;
    TestSuite testSuite(const QString& testSuiteName) const;
    QList<TestSuite> testSuites() const;

    QList<QString> errorMessages() const;

  signals:
    void started();
    void testSuiteFinished(const QString& suiteName);
    void finished();

  private slots:
    void onSubProcReadyReadStdout();
    void onSubProcReadyReadStderr();
    void onSubProcFinished();

    void onFoundEnvelopedXml(const QString& xml, const QString& fileName, const QString& buildDir);

  private:
    static void writeEnvelopeXmlRootTag(bool startTag);

    void runTestsInSubProc(const QString& paramValue);

  private:
    struct TestRunnerData;
    TestRunnerData* m_data;
  };

}

#endif
