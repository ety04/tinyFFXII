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

#ifndef _TESTGUIFRONTEND_H_
#define _TESTGUIFRONTEND_H_

#include <QtGui/QMainWindow>
#include "cutetest_export.h"

class QIcon;
class QModelIndex;
class QStandardItem;


namespace CuteTest {
  class TestRunner;
  class TestSuite;
  class TestCase;
  class TestIncident;

  class CUTETEST_EXPORT TestGuiFrontend : public QMainWindow {
    Q_OBJECT
    Q_DISABLE_COPY(TestGuiFrontend)

  public:
    TestGuiFrontend(TestRunner* testRunner);
    virtual ~TestGuiFrontend();

  public:
    static int main(int argc, char *argv[]);

    virtual bool hideSetupMethodsWhenPassed() const;

  private:
    static QIcon& passedIcon();
    static QIcon& warningIcon();
    static QIcon& failedIcon();

    void updateStatus();
    
    QString createDescription(const TestSuite& testSuite);
    QString createDescription(const TestCase& testCase);
    QString createDescription(const TestIncident& incident);

    void clearSourceCodeView();
    void updateSourceCodeView(const TestIncident& incident);

    QString getIncidentTypeName(const TestIncident& incident);
    QString createIncidentDescriptionText(const TestIncident& incident);

    void insertTestCaseItem(const TestCase& testCase, QStandardItem* parentItem, bool fullQN, 
                            QList<QStandardItem*>* expandendCaseItems);
    void insertIncidentItem(const TestIncident& incident, QStandardItem* parentItem);

    void showSourceFile(const QString& fileName, int line);

  private slots:
    void onTestsStarted();
    void onTestSuiteFinished(const QString& suiteName);
    void onTestsFinished();

    void onItemClicked(const QModelIndex& newItem);

    void showErrorLog();

  private:
    struct Data;
    Data* const m_data;
  };

}

#endif
