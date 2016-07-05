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

#ifndef _TESTCASEREGISTRY_H_
#define _TESTCASEREGISTRY_H_

#include "cutetest_export.h"

#include <QString>
#include <QHash>


namespace CuteTest {
  class TestSuiteFactory;

  class CUTETEST_EXPORT TestSuiteRegistry {
    TestSuiteRegistry() { }
    Q_DISABLE_COPY(TestSuiteRegistry)

  public:
    static TestSuiteRegistry& getInstance();

    void registerFactory(TestSuiteFactory* factory);

    TestSuiteFactory* getFactory(const QString& name) {
      return this->m_factories.value(name, NULL);
    }

    QList<TestSuiteFactory*> getAllFactories() const {
      return this->m_factories.values();
    }

  private:
    QHash<QString, TestSuiteFactory*> m_factories;
  };

}

#endif
