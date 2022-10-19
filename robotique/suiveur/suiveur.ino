const int motA_pin1=8;               //motor right 
const int motA_pin2=7;         
const int motA_EN=3;
//--
const int motB_pin1=10;             // motor left 
const int motB_pin2=9;
const int motB_EN=11;
//--
const int led=2;///////////////////////////////////////////////////////////////////////////changement avec 13
const int C1=4;
const int C2=5;
const int C3=6;
const int C4=12;
const int C5=13;///////////////////////////////////////////////////////////////////////////changement avec 2
//--
int RC1=0;
int RC2=0;
int RC3=0;
int RC4=0;
int R5=0;
int Speed=180;
void setup() {
  // put your setup code here, to run once:
pinMode (motA_pin1,OUTPUT);      
pinMode (motA_pin2,OUTPUT);
pinMode (motA_EN,OUTPUT);
//--
pinMode (motB_pin1,OUTPUT);
pinMode (motB_pin2,OUTPUT);
pinMode (motB_EN,OUTPUT);
pinMode(led,OUTPUT);}
//Functions
void FWD(int Speed) {
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,HIGH); 
digitalWrite(motB_pin2,LOW);
analogWrite(motB_EN,Speed);
}

void LEFT(int Speed) {

digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW); 
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH); 
analogWrite(motB_EN,Speed);
}
void RIGHT(int Speed) {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH); 
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW); 
analogWrite(motB_EN,Speed);
}
void REV(int Speed) {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH);
analogWrite(motB_EN,Speed);
}
void UP_LEFT(int Speed){
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW); 
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,LOW);  
analogWrite(motB_EN,Speed);
}
void UP_RIGHT(int Speed) {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);
analogWrite(motB_EN,Speed); 
}
void DOWN_RIGHT(int Speed) {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH); 
analogWrite(motB_EN,Speed);
 
} 
void DOWN_LEFT(int Speed){
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,LOW);  
analogWrite(motB_EN,Speed);  
}
void STOP(int Speed){
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,LOW); 
analogWrite(motB_EN,Speed);
}

void loop() {
  // put your main code here, to run repeatedly:
RC1=digitalRead(C1);
RC2=digitalRead(C2);
RC3=digitalRead(C3);
RC4=digitalRead(C4);
R5=digitalRead(C5);
if(RC1==0 && RC2==0 && RC3==0 && RC4==0)//0/////// lezem tetbaddel lel interrempu !! twalli FWD
if(RC1==0 && RC2==0 && RC3==0 && RC4==0)//0/////// lezem tetbaddel lel interrempu !! twalli FWD
LEFT(80);
else if(RC1==0 && RC2==0 && RC3==0 && RC4==1)//1
UP_LEFT(80);
else if(RC1==0 && RC2==0 && RC3==1 && RC4==0)//2
LEFT(80);
else if(RC1==0 && RC2==0 && RC3==1 && RC4==1)//3
LEFT(80);
else if(RC1==0 && RC2==1 && RC3==0 && RC4==0)//4---
LEFT(80);
else if(RC1==0 && RC2==1 && RC3==0 && RC4==1)//5--
FWD(80);
else if(RC1==0 && RC2==1 && RC3==1 && RC4==0 && R5==1)//6----
UP_RIGHT(80);
else if(RC1==0 && RC2==1 && RC3==1 && RC4==0 && R5==0)// inversion
FWD(80);
else if(RC1==0 && RC2==1 && RC3==1 && RC4==1)//7
LEFT(80);
else if(RC1==1 && RC2==0 && RC3==0 && RC4==0)//8
UP_LEFT(80);
else if(RC1==1 && RC2==0 && RC3==0 && RC4==1)//9
FWD(80);
else if(RC1==1 && RC2==0 && RC3==1 && RC4==0)//10-----
LEFT(80);
else if(RC1==1 && RC2==0 && RC3==1 && RC4==1)//11
LEFT(80);
else if(RC1==1 && RC2==1 && RC3==0 && RC4==0)//12
RIGHT(80);
else if(RC1==1 && RC2==1 && RC3==0 && RC4==1)//13
UP_LEFT(80);
else if(RC1==1 && RC2==1 && RC3==1 && RC4==0)//14
RIGHT(80);
else if(RC1==1 && RC2==1 && RC3==1 && RC4==1 && R5==1)///////
UP_LEFT(80);
else if(RC1==1 && RC2==1 && RC3==1 && RC4==1 && R5==0)
{STOP(80);
digitalWrite(led,HIGH);
delay(5000);
digitalWrite(led,LOW);
UP_RIGHT(80);
delay(480);
}
else
STOP(100);

}
