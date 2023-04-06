#include <RunF.h>

typedef void (*typeF)(long*, int); 
char *listFname[] = {"start", "stop", "hu"};
typeF listF[] = {start, stopp, hu};
RunF cmd(listF, listFname);

void setup() {
  Serial.begin(115200);
}

void loop() {
  cmd.waiting();
}

void start(long *vars, int qt){
  Serial.println("start : ");
  for(int i; i<qt; i++){
    Serial.println(vars[i]);
  }
}

void stopp(long *vars, int qt){
  Serial.println("stop : ");
  for(int i; i<qt; i++){
    Serial.println(vars[i]);
  }
}

void hu(long *vars, int qt){
  Serial.println("hu : ");
  for(int i; i<qt; i++){
    Serial.println(vars[i]);
  }
}
