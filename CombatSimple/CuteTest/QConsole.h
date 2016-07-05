//////////////////////////////////////////////////////////////////////////
//                                                                      //
//  Copyright (C) 2012  Maya Studios (http://mayastudios.com)           //
//  All rights reserved.                                                //
//                                                                      //
//  Licensed under the Apache License, Version 2.0 (the "License");     //
//  you may not use this file except in compliance with the License.    //
//  You may obtain a copy of the License at                             //
//                                                                      //
//    http://www.apache.org/licenses/LICENSE-2.0                        //
//                                                                      //
//  Unless required by applicable law or agreed to in writing, software //
//  distributed under the License is distributed on an "AS IS" BASIS,   //
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or     //
//  implied. See the License for the specific language governing        //
//  permissions and limitations under the License.                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef _QCONSOLE_H_
#define _QCONSOLE_H_

#include "cutetest_export.h"

#include <qglobal.h>
#include <QString>


namespace QtExtensions {

  class CUTETEST_EXPORT QConsole {
  private:
    QConsole() { }
    Q_DISABLE_COPY(QConsole)

  public:
    enum Colors {
      //! Uses the default color, i.e. doesn't change it. Not every console uses white text on black background.
      DefaultColor,
      Black,
      White,
      Red,
      Green,
      Blue,
      Yellow,
      Purple,
      Cyan,
      // Bright colors
      BrightWhite,
      BrightRed,
      BrightGreen,
      BrightBlue,
      BrightYellow,
      BrightPurple,
      BrightCyan,
    };

  public:
    static void write(const QString& text, Colors foreground = DefaultColor, Colors background = DefaultColor);
    static void write(const char* text, Colors foreground = DefaultColor, Colors background = DefaultColor);
    static void writeln(const QString& text, Colors foreground = DefaultColor, Colors background = DefaultColor);
    static void writeln(const char* text, Colors foreground = DefaultColor, Colors background = DefaultColor);
    static void writeln();
  };

}

#endif
