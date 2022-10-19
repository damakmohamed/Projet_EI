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
char *Text3 = "--";
char sec[4],sec1[4],sec2[4];
char str1[4],str2[4],str3[4],str4[4],str5[4];
String strn,strn1;

int breset=2;
int bstart=4;
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

void loop() {
int b2;  b2=digitalRead(breset);
 // Serial.println(b2);
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(0, 9,"      " , 5, GRAPHICS_NORMAL);
  dmd.drawString(0, 0,Text1 , 5, GRAPHICS_NORMAL);
int b1;
b1=digitalRead (bstart);
b2=digitalRead (breset);

//Serial.println(b2);
  if(digitalRead (bstart)==0 && digitalRead (breset)==1 )
  {b2=digitalRead (breset);
  delay(1000);
  i=6 ;
  while(i>9)
  {b2=digitalRead (breset);
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
  if (b2==0)
  break;
  }




  while(i>0 && i<10) ///////////////////////////////////////////////////////////////////
{b2=digitalRead (breset);
dmd.selectFont(Arial_Black_16_ISO_8859_1);
dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(1000);
  strn1+=i;
  strn1.toCharArray(sec1,2);
  strcpy(str3,sec1);
  Serial.println(sec1);
  
  strcpy(str4,Text3);
  strcpy(str5,Text3);
  strcat(str4,str3);
  strcat(str4,str5);
  
  dmd.drawString(0, 0,str4 , 5, GRAPHICS_NORMAL);
  strn1="";
  strn1.toCharArray(sec1,2);
  i--;
  delay(1000);
  if (b2==0)
  break;
int j;
  j=15;
  
  while(b2==1 && i<1)
  {
  dmd.selectFont(Arial_Black_16_ISO_8859_1);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(1000);
  strn1+=j;
  strn1.toCharArray(sec2,3);
  strcpy(str3,sec2);
  Serial.println(sec2);
  
  strcpy(str4,Text3);
  strcpy(str5,Text3);
  strcat(str4,str3);
  strcat(str4,str5);
  
  dmd.drawString(0, 0,str4 , 5, GRAPHICS_NORMAL);
  strn1="";
  strn1.toCharArray(sec2,3);
  j--;
  delay(1000);



    
    if(j<1)
   {b2=digitalRead (breset);
   dmd.selectFont(SystemFont5x7);
  dmd.drawString(0, 0,"GAME" , 5, GRAPHICS_NORMAL); 
  dmd.drawString(0, 9,"OVER!" , 5, GRAPHICS_NORMAL);
  delay(1000);
  i=0;
  j=0;}
  }
  }}



  
 
/*    while(i>0 && i<10)
  {if(b2==1)
  {dmd.selectFont(Arial_Black_16_ISO_8859_1);
  dmd.drawString(0, 0, "--9--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
   //(); 
  dmd.drawString(0,0, "--8--" , 5, GRAPHICS_NORMAL);
  delay(500);
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(500);
  i--;
   //();
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
  dmd.drawString(0, 0,"     " , 5, GRAPHICS_NORMAL); 
  delay(200);
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(0, 0,"GAME" , 5, GRAPHICS_NORMAL); 
  dmd.drawString(0, 9,"OVER!" , 5, GRAPHICS_NORMAL);
  delay(500);}
  else if (b2==0)
  break;
}} */
}
