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

#ifndef _CUTETEST_EXPORT_H_
#define _CUTETEST_EXPORT_H_

#include <QtCore/qglobal.h>

// WARNING!!! Don't use Q_DECL_EXPORT directly (like "class Q_DECL_EXPORT ClassName") as this may result in linker 
//   errors. See:
//   http://manski.net/2011/11/09/creating-a-dll-project/
//   http://developer.qt.nokia.com/faq/answer/when_creating_a_library_with_qt_windows_and_using_it_in_an_application_then
#ifdef COMPILE_CUTETEST_LIB
  #define CUTETEST_EXPORT Q_DECL_EXPORT
#else
  #define CUTETEST_EXPORT Q_DECL_IMPORT
#endif

#endif
