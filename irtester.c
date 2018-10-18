#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"
#include <curl/curl.h>

int main(int argc, char *argv[])
{
	extern int ifttt(char*, char*, char*, char*);
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT); 
  pinMode(2, OUTPUT);
  while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/prince160", "Alert", "call", "help");
    digitalWrite(1, HIGH); delay(500);
    printf("Blue led is already on before the user waved hand and after\n");
    printf("waiting for event\n");
    while(digitalRead(0) == 0);
    digitalWrite(2, HIGH); delay(1000);
    printf("Alarm\n");
    digitalWrite(2, LOW);
    printf("Red Led turns off after a delay\n");  
  }
  /*NOTREACHED*/
  return 0 ;
}
