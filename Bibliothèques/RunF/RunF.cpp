/*
 * Copyright (c) 2012 by Yvon LE GAL <yvozin@gmail.com>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include "Arduino.h"
#include "RunF.h"

  RunF::RunF(typeF *listF, char **listFname){
    _listF = listF;
    _listFname = listFname;
  }
  
  void RunF::waiting(){
    while(Serial.available()) parse(Serial.read());
  }
  
	
  void RunF::parse(char a){
    if(a == '('){
      _state = 1;
      _command[_i] = '\0';
      _i = 0;
      return;
    }else if(a == ','){
      _param[_i] = '\0';
      addLong();
      _i = 0;
      return;
    }else if(a == ')'){
      _param[_i] = '\0';
      addLong();
      run();
      _state = 0;
      _i = 0;
      _qtParams = 0;
      return;
    }
    //----
    if(_state == 0){ // --- before '('
      if(_i == 15){
        _command[16] = '\0';
        return;
      }
      _command[_i] = a;
      _i++;
    }else{ // --- after '('
      _param[_i] = a;
      _i++;
    }
  }
  
  void RunF::addLong(){
    if(strlen(_param) == 0) return;
    long *temp = (long*) malloc((_qtParams+1) * sizeof(long));
    if(temp != NULL){
      memcpy(temp, _params, _qtParams * sizeof(long));
      temp[_qtParams] = strtol(_param, NULL, 10);
      _qtParams++;
      free(_params);
      _params = temp;
    }else{
      Serial.println(F("out of memory !"));
      exit (1);
    }
  }
  
  void RunF::run(){
    int qtF;
    for (qtF=0; _listF[qtF]; qtF++);
    
    for(int i; i<qtF; i++){
      if(!strcmp(_command, _listFname[i])){
        // run
        _listF[i](_params, _qtParams);
        return;
      }
    }
    Serial.print('['); Serial.print(_command); Serial.print(']');
    Serial.println(F(" : commande inconnue !"));
  }
  


