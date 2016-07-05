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

#ifndef _QTTESTING_H_
#define _QTTESTING_H_

#include "CuteTest/TestSuiteFactory.h"

// Replace QTest defines with our own, if they've not yet been defined. This way the user only needs to link against
// this library (i.e. he's not required to link against QTestLib directly).
//
// The contents of the following #ifdef block are directly copied from "qtestcase.h"
#ifndef QTESTCASE_H 
#define QTESTCASE_H

#include "CuteTest/QTestProxy.h"
#include "CuteTest/ProxyMacros.h"

#define ADD_DATASET_COL ::CuteTest::addDataSetColumn
#define NEW_DATASET  ::CuteTest::newDataSet

#else

#define ADD_DATASET_COL ::QTest::addColumn
#define NEW_DATASET  ::QTest::newRow

#endif

#endif
