#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "Arial_black_16.h"
#include "Arial_Black_16_ISO_8859_1.h"
#include "Arial14.h"
#include "SystemFont5x7.h"
#include<stdio.h>

#define DISPLAYS_ACROSS 1 //-> Number of P10 panels used, side to side.
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

char *Text1 = "01:00";
char *Text2 = "00:";
char sec[4];
char str1[4],str2[4];
String strn;

int breset=;///////////////////////////////////////////////////////////a5tar 2 pin fa4yiin
int bstart=;///////////////////////////////////////////////////////////
int i;
void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void setup(void) {
  Timer1.initialize(1000);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);
  //Serial.begin(115200);
  Serial.begin(9600);
  pinMode(bstart,INPUT);
  pinMode(breset,INPUT);
  
}

void loop(void) {
  
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(0, 9,"      " , 5, GRAPHICS_NORMAL);
  dmd.drawString(0, 0,Text1 , 5, GRAPHICS_NORMAL);

  if(bstart ==1 && breset==0)
  {   /////////////////////////////////start
  delay(1000);
  i=59;
  while(i>9)
  {
  strn+=i;
  strn.toCharArray(sec,3);
  strcpy(str1,sec);
  strcpy(str2,Text2);
  strcat(str2,str1);
  //Serial.println(str2);
  dmd.drawString(0, 0,str2 , 5, GRAPHICS_NORMAL);
  strn="";
  strn.toCharArray(sec,3);
  i--;
  delay(1000);
  }
 
    while(i>0 && i<10)
  {
  dmd.selectFont(Arial_Black_16_ISO_8859_1);
  dmd.drawString(0, 0, "--9--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--8--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--7--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--6--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--5--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--4--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--3--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--2--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--1--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  dmd.drawString(0, 0, "--0--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
  
  }


  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(200);
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(0, 0,"GAME" , 5, GRAPHICS_NORMAL); 
  dmd.drawString(0, 9,"OVER!" , 5, GRAPHICS_NORMAL);
  
  while(breset==0) ///////// pas de reset
  {delay(500);}
  
  dmd.drawString(0, 0,"        " , 5, GRAPHICS_NORMAL); 
  dmd.drawString(0, 9,"        " , 5, GRAPHICS_NORMAL);
  delay(1000);}///////////////////////////bstart

  else if(breset == 1)
  {dmd.selectFont(SystemFont5x7);
  dmd.drawString(0, 9,"      " , 5, GRAPHICS_NORMAL);
  dmd.drawString(0, 0,Text1 , 5, GRAPHICS_NORMAL);
    }

}
