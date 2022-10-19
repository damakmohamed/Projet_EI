
const int motA_pin1=8;               //motor right 
const int motA_pin2=7;         
const int motA_EN=6;
//--
const int motB_pin1=13;             // motor left 
const int motB_pin2=12;
const int motB_EN=11;
//--
const int led=9;
const int C1=2;
const int C2=3;
const int C3=4;
const int C4=5;

//--
int RC1=0;
int RC2=0;
int RC3=0;
int RC4=0;
int Speed=190;
int pos=0;
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

if(RC1==0 && RC2==0 && RC3==0 && RC4==0 ) //0
{
  if(pos==0)
  {
    STOP(Speed);
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);
    delay(1500);
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);
    delay(1500);  
    REV(Speed);
    delay(650);
    UP_RIGHT(Speed);
    delay(200);
    pos+=1;
   }
  else if(pos == 1)
  { STOP(Speed);
    delay(500);
    UP_RIGHT(Speed);
    delay(200);
    pos+=1;
  }
  else
  { STOP(Speed);
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);
    delay(1500);
    }
}

else if(RC4==0 && RC3==0 && RC2==0 && RC1==1) //1      
LEFT(Speed);

else if(RC4==0 && RC3==0 && RC2==1 && RC1==0) //2      
UP_LEFT(Speed);

else if(RC4==0 && RC3==0 && RC2==1 && RC1==1) //3
LEFT(Speed);

else if(RC4==0 && RC3==1 && RC2==0 && RC1==0) //4     
RIGHT(Speed);

else if(RC4==0 && RC3==1 && RC2==0 && RC1==1) //5      
LEFT(Speed);

else if(RC4==0 && RC3==1 && RC2==1 && RC1==0) //6      
LEFT(Speed);

else if(RC4==0 && RC3==1 && RC2==1 && RC1==1) //7
LEFT(Speed);

else if(RC4==1 && RC3==0 && RC2==0 && RC1==0) //8      
LEFT(Speed);

else if(RC4==1 && RC3==0 && RC2==0 && RC1==1) //9
FWD(Speed);

else if(RC4==1 && RC3==0 && RC2==1 && RC1==0) //A
LEFT(Speed);

else if(RC4==1 && RC3==0 && RC2==1 && RC1==1) //B
LEFT(Speed);

else if(RC4==1 && RC3==1 && RC2==0 && RC1==0) //C
RIGHT(Speed);

else if(RC4==1 && RC3==1 && RC2==0 && RC1==1) //D
FWD(Speed);

else if(RC4==1 && RC3==1 && RC2==1 && RC1==0) //E
RIGHT(Speed);

else if(RC4==1 && RC3==1 && RC2==1 && RC1==1 ) //F 
{UP_RIGHT(Speed);}
}
