/*
 * Copyright (c) 2012 by Yvon LE GAL <yvozin@gmail.com>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef RunF_h
#define RunF_h

#include "Arduino.h"

class RunF {
  private :
  
  typedef void (*typeF)(long*, int); 
  typeF *_listF;
  char **_listFname;
  
  char _command[16]; // ça suffit !
  char _param[12]; // le max pour un long
  long *_params;
  int _qtParams;
  int _i;
  boolean _state; // after or before '('
  
  public :
  RunF(typeF *listF, char **listFname);
  
  void waiting();
  
  private :
  void parse(char a);
  void addLong();
  void run();

};


#endif
