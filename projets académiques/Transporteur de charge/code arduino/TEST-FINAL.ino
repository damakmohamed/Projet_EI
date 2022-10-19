//**************declaration des pins*************//

const int motA_pin1=8;               //moteur droit 
const int motA_pin2=7;         
const int motA_EN=6;
//--
const int motB_pin1=13;             // moteur gauche 
const int motB_pin2=12;
const int motB_EN=11;

const int led=9;                    // led
const int C1=2;                     // capteur 1
const int C2=3;                     //capteur 2
const int C3=5;                     //capteur 3
const int C4=4;                     //capteur 4
//--

const int P1=15;                    // piece 1
const int P2=16;                    // piece 2
//--
const int qr1=17;                  // code qr1
const int qr2=18;                  // code qr2
const int cam=19;                  // caméra 
//--
int RC1=0;                         //Variable pour le 1er capteur
int RC2=0;                         //variable pour le 2eme capteur
int RC3=0;                         //Variable pour le 3eme capteur
int RC4=0;                         //Variable pour le 4eme capteur
//--

int RP1=0;                         //Variable pour la 1ere piece
int RP2=0;                         //Variable pour la 2eme piece 
int Rqr1=0;                        //Variable pour la lecture du 1er code QR
int Rqr2=0;                        //Variable pour la lecture du 2eme code QR
//--
int Speed=190;                     // Vitesse des moteurs
int pos=0;                         //Variable pour la position du robot
int x=0;
void setup() {
  //************************************ Configurations des pins (IN/OUT)***************************************************
Serial.begin(9600);
pinMode (motA_pin1,OUTPUT);      
pinMode (motA_pin2,OUTPUT);
pinMode (motA_EN,OUTPUT);
//--
pinMode (motB_pin1,OUTPUT);
pinMode (motB_pin2,OUTPUT);
pinMode (motB_EN,OUTPUT);
//--
pinMode(led,OUTPUT);
//--
pinMode(P1,INPUT);
pinMode(P2,INPUT);
pinMode(qr1,INPUT);
pinMode(qr2,INPUT);
pinMode(cam,OUTPUT);
}
//**************************************Définitions des fonnctions*******************************************//
void FWD(int Speed)                      //Marche avant
{
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,HIGH); 
digitalWrite(motB_pin2,LOW);
analogWrite(motB_EN,Speed);
Serial.println("fwd");
}

void LEFT(int Speed)                    //Tourner à gauche
{

digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW); 
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH); 
analogWrite(motB_EN,Speed);
Serial.println("L");
}
void RIGHT(int Speed)                 //Tourner à droite
{
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH); 
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW); 
analogWrite(motB_EN,Speed);
Serial.println("R");
}
void REV(int Speed)                 //Marche arriere
{
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH);
analogWrite(motB_EN,Speed);
Serial.println("REV");
}
void UP_LEFT(int Speed)            //avancer et tourner à gauche
{
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW); 
analogWrite(motA_EN,Speed);
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,LOW);  
analogWrite(motB_EN,Speed);
Serial.println("UL");
}
void UP_RIGHT(int Speed)          //avancer et tourner à droite 
{
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);
analogWrite(motB_EN,Speed); 
Serial.println("UR");
}
void DOWN_RIGHT(int Speed) {       //reculer et tourner à droite 
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH); 
analogWrite(motB_EN,Speed);
Serial.println("DR");
 
} 
void DOWN_LEFT(int Speed){          //reculer et tourner à gauche
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,LOW);  
analogWrite(motB_EN,Speed);  
Serial.println("DL");
}
void STOP(int Speed){               // stop
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,Speed); 
//--
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,LOW); 
analogWrite(motB_EN,Speed);
Serial.println("S");
}

void loop() {
// commander le transporteur de deplacer la piéce P1
while(digitalRead(P1)==1 && digitalRead(P2)==0)
{
RC1=digitalRead(C1);
RC2=digitalRead(C2);
RC3=digitalRead(C3);
RC4=digitalRead(C4);
Serial.print(RC1);
Serial.print(RC2);
Serial.print(RC3);
Serial.print(RC4);
if(RC1==0 && RC2==0 && RC3==0 && RC4==0 ) // les quatres capteurs detectent la couleur noire 
{ //--pos0 
  if(pos==0)
  { 
    STOP(Speed);
    digitalWrite(cam,HIGH);              //Donner l'ordre au camera pour capturer une image du code QR
    Serial.println("cam high");
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);             //clignotement  du led 
    delay(1500);
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);
    
    delay(1000); ///////////////////////// delais pour capter une image du code QR  
    digitalWrite(cam,LOW); //arreter la caméra  
    Serial.println("cam low");
    Rqr1=digitalRead(qr1);  //recevoir et lire l'information fournie par le code QR  (envoyée par la raspberry)
    delay(500);
    if(Rqr1==1)                              //Si le code QR est validé
    {Serial.println("qr1");
    FWD(Speed);                           //avancer pour serrer la piece
    delay(400);
    STOP(Speed);                           //arreter pour serrer la piece 
    delay(1500);
    digitalWrite(led,HIGH);               //allumer la led
    delay(2000);
    REV(Speed);                           
    delay(1100);                         //reculer et tourner à droite pour retourner a ligne ///////////////////////////////////////////////////
    RIGHT(Speed);
    delay(100);
    UP_RIGHT(Speed);                     
    delay(200); /////////////////////////200
    pos+=1;                              //mettre a jour la position 
    }
    else                                 //Si le code QR n'est pas validé
    {Serial.println("not qr1");
      REV(Speed);
    delay(800); /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    RIGHT(Speed);                     //reculer et tourner à droite pour retourner a ligne-------------------------UP_RIGHT
    delay(200);/////////////////////200
    pos+=1;}                            //mettre a jour la position 
   }
   //--pos1
  else if(pos == 1)
  { STOP(Speed);
    delay(200); /////////////////////////500 
    UP_RIGHT(Speed);                            //tourner à droite pour retourner a ligne
    delay(300);////////////////////200
    pos+=1;                                     //mettre a jour la position 
  }
  //--pos2
  else if(pos ==2)                          //Si le robot est à la deuxieme place
   {STOP(Speed);
    delay(2000);
    Rqr1=digitalRead(qr1);                  //recevoir et lire l'information fournie par le code QR  (envoyée par la raspberry)
    if(Rqr1==0)
    {digitalWrite(cam,HIGH);                //Donner l'ordre au camera pour capturer une image du code QR
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);
    delay(1500);                           ////clignotement  du led 
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);
    delay(1500);
    delay(1000);  ///////////////////////////////////////10000 camera
    digitalWrite(cam,LOW);                //Donner l'ordre au camera pour arreter de prendre une image du code QR
    Rqr1=digitalRead(qr1);                //recevoir et lire l'information fournie par le code QR  (envoyée par la raspberry)
    delay(500);
    x=1;}
    
    if(Rqr1==1 && x==1)                   //Si le robot est à la position 2 est n'a pas serrer la piece à la position 1
    {FWD(Speed);
    delay(400);
    STOP(Speed);
    delay(1500);
    digitalWrite(led,HIGH);
    delay(2000);                          //Amener la piece et retourner à la ligne (meme processus que pos=1) et mettre à jour la position
    REV(Speed);
    delay(1100); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UP_RIGHT(Speed);
    delay(300);////////////////////200
    pos+=1;
    }
    else if(Rqr1==1 && x==0)            //Si le robot est à la position 2 est a serrer la piece à la position 1
    {REV(Speed);
    delay(800); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UP_RIGHT(Speed);
    delay(200);                        //retourner à la ligne (meme processus que pos=1) et mettre à jour la position
    pos+=1;}
    else
    pos+=1;
    }
   
    //-- pos3 //////////////////////////////////////
    else if(pos == 3)                 //Si la position est 3 avancer et tourner à droite et mettre à jour la position
  { STOP(Speed);
    delay(200);
    UP_RIGHT(Speed);
    delay(200);/////////////////////////////////////////////////////////////////////////
    pos+=1;
  }
    else
  { STOP(Speed);                    //Si la position est autre que 3 clignoter la led et mettre à jour la position
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(led,LOW);
    delay(1500);
    pos+=1;
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
/*
//////////////////////////////////////////////////////////////////////////// commander le transporteur de deplacer la piéce P2
while(digitalRead(P2)==1 && digitalRead(P1)==0)
{
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

}*/
}
