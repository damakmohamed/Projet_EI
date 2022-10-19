#include <SPI.h>
#include <MFRC522.h>   
#include <Servo.h> 




#define RST_PIN  9    //RC522 reset
#define SS_PIN  10   //SS (SDA) of RC522 module
MFRC522 mfrc522(SS_PIN, RST_PIN); //Create a new RC522 object
Servo motor_1;


//Variables
boolean door_opened=false;
boolean first_read=false;
boolean normal_mode=true;
boolean countdown = false;
int timer=0;
int user_added=0;
int  add_ID_counter = 0;

//I/O
int buzzer_pin=7;
int outside_close = 4;      //the button of the outside open
int inside_close = 6;       //the button of the inside close
int inside_open = 5;        //the button of the inside open


void setup() {Serial.begin(9600);
  SPI.begin();                 //Start a new SPI bus
  mfrc522.PCD_Init();          // Startt the MFRC522  
  motor_1.attach(3);           // servo motor
  pinMode(buzzer_pin,OUTPUT);  //buzzer 
  motor_1.writeMicroseconds(1000); //Put the servo in to the close position
}

byte ActualUID[4];                        //This will store the ID each time we read a new ID code

byte USER1[4]= {0x09, 0x92, 0x53, 0x28} ; //Master ID code Change it for yor tag. First use the READ exampel and check your ID

byte USER2[4]= {0x00, 0x00, 0x00, 0x00} ; //Empty ID of USER2
byte USER3[4]= {0x00, 0x00, 0x00, 0x00} ; //Empty ID of USER3
byte USER4[4]= {0x00, 0x00, 0x00, 0x00} ; //Empty ID of USER4
byte USER5[4]= {0x00, 0x00, 0x00, 0x00} ; //Empty ID of USER5



void loop() {

  if(digitalRead(outside_close))        //If the button is pressed, we close the door
  {
     door_opened=false;
     first_read=false;
     countdown = false;
     add_ID_counter = 0;
     motor_1.writeMicroseconds(1000); 
     Serial.println("  Door  closed  ");
     Serial.println();
     Serial.println("  from OUTSIDE  ");
     Serial.println();
     digitalWrite(buzzer_pin,HIGH);
     delay(300);
     digitalWrite(buzzer_pin,LOW);
     delay(4000);
     Serial.println();
     Serial.println("Place card here!");
     Serial.println();
     Serial.println("  DOOR  CLOSED  ");
     Serial.println();
  }


  if(digitalRead(inside_close))         //If the button is pressed, we close the door
  {
     door_opened=false;
     first_read=false;
     countdown = false;
     add_ID_counter = 0;
     motor_1.writeMicroseconds(1000); 
     Serial.println();
     Serial.println("  Door  closed  ");
     Serial.println();
     Serial.println("  from  INSIDE  ");
     digitalWrite(buzzer_pin,HIGH);
     delay(300);
     digitalWrite(buzzer_pin,LOW);
     delay(4000);
     Serial.println();
     Serial.println("Place card here!");
     Serial.println();
     Serial.println("  DOOR  CLOSED  ");
  }



  if(digitalRead(inside_open))        //If the button is pressed, we open the door
  {
     door_opened=true;
     first_read=false;
     countdown = false;
     add_ID_counter = 0;
     motor_1.writeMicroseconds(1500); 
     Serial.println();
     Serial.println("   Door  open   ");
     Serial.println();
     Serial.println("  from  INSIDE  ");
     digitalWrite(buzzer_pin,HIGH);
     delay(300);
     digitalWrite(buzzer_pin,LOW);
     delay(4000);
     Serial.println();
     Serial.println("Place card here!");
     Serial.println();
     Serial.println("  DOOR  OPENED  ");
  }

  
  if(normal_mode)
  {

    if(countdown)
    {
      if(add_ID_counter > 300)
      {
        countdown = false;
        first_read=false; 
        add_ID_counter = 0;
        Serial.println();
        Serial.println("New ID  canceled");
        Serial.println();
        Serial.println("                ");
        digitalWrite(buzzer_pin,HIGH);
        delay(1000);
        digitalWrite(buzzer_pin,LOW);
        delay(4000);
        Serial.println();
        Serial.println("Place card here!");
        Serial.println();
        Serial.println("                ");
      }

      if(add_ID_counter == 50)
      {
        Serial.println();
        Serial.println("5");
        digitalWrite(buzzer_pin,HIGH);
        delay(100);
        digitalWrite(buzzer_pin,LOW);
      }

      if(add_ID_counter == 100)
      {
        Serial.println();
        Serial.println("4");
        digitalWrite(buzzer_pin,HIGH);
        delay(100);
        digitalWrite(buzzer_pin,LOW);
      }

      if(add_ID_counter == 150)
      {
        Serial.println();
        Serial.println("3");
        digitalWrite(buzzer_pin,HIGH);
        delay(100);
        digitalWrite(buzzer_pin,LOW);
      }

      if(add_ID_counter == 200)
      {
        Serial.println();
        Serial.println("2");
        digitalWrite(buzzer_pin,HIGH);
        delay(100);
        digitalWrite(buzzer_pin,LOW);
      }

      if(add_ID_counter == 250)
      {
        Serial.println();
        Serial.println("1");
        digitalWrite(buzzer_pin,HIGH);
        delay(100);
        digitalWrite(buzzer_pin,LOW);
      }

      
      add_ID_counter = add_ID_counter+1;
      delay(10);
    }


    
    // Check if there are any new ID card in front of the sensor
    if ( mfrc522.PICC_IsNewCardPresent()) 
          {  
        //Select the found card
              if ( mfrc522.PICC_ReadCardSerial()) 
              {
                    // We store the read ID into 4 bytes with a for loop                  
                    for (byte i = 0; i < mfrc522.uid.size; i++) {
                      ActualUID[i]=mfrc522.uid.uidByte[i];          
                    } 
                                    
                    //Compare the UID and check if the new iD is on the user listz
  
                    
                             if(first_read)
                            {
                                    if(compareArray(ActualUID,USER1))
                                    { 
                                        countdown=false;
                                        add_ID_counter = 0;
                                        digitalWrite(buzzer_pin,HIGH);
                                        delay(300);
                                        digitalWrite(buzzer_pin,LOW);
                                        normal_mode=false;
                                        Serial.println();
                                        Serial.println("Place New ID in:");
                                        Serial.println();
                                        Serial.println("       3        ");
                                        digitalWrite(buzzer_pin,HIGH);
                                        delay(100);
                                        digitalWrite(buzzer_pin,LOW);                                        
                                        delay(1000);
                                        Serial.println();
                                        Serial.println("       2        ");
                                        digitalWrite(buzzer_pin,HIGH);
                                        delay(100);
                                        digitalWrite(buzzer_pin,LOW);
                                        delay(1000);
                                        Serial.println();
                                        Serial.println("       1       ");
                                        digitalWrite(buzzer_pin,HIGH);
                                        delay(100);
                                        digitalWrite(buzzer_pin,LOW);
                                        delay(1000);
                                        Serial.println();
                                        Serial.println("      NOW!      ");
                                        digitalWrite(buzzer_pin,HIGH);
                                        delay(500);
                                        digitalWrite(buzzer_pin,LOW);
                                       
                                        
                                    }
                                    else
                                    {
                                      first_read=false;                  
                                     
                                    }
                            }
                            
                            if(!first_read)
                            {
                                    if(compareArray(ActualUID,USER1))
                                    {
                                        Serial.println();
                                        Serial.println(" Access granted ");
                                        Serial.println();
                                        Serial.println("  MASTER  USER  ");
                                        digitalWrite(buzzer_pin,HIGH);    //use analogWrite(buzzer_pin,200); for non active buzzer
                                        delay(300);
                                        digitalWrite(buzzer_pin,LOW);    //use analog write for non active buzzer
                                        motor_1.writeMicroseconds(1500); 
                                        door_opened=true;
                                        first_read=true;
                                        countdown=true;
                                        delay(3000);
                                        Serial.println();
                                        Serial.println("Put  MASTER card");
                                        Serial.println();
                                        Serial.println("for new ID     6");
                                        digitalWrite(buzzer_pin,HIGH);
                                        delay(100);
                                        digitalWrite(buzzer_pin,LOW);
                                        
                                    }
                                    else if(compareArray(ActualUID,USER2))
                                    {
                                        Serial.println();
                                        Serial.println(" Access granted ");
                                        Serial.println();
                                        Serial.println("     USER 2     ");
                                        digitalWrite(buzzer_pin,HIGH);    
                                        delay(300);
                                        digitalWrite(buzzer_pin,LOW);    
                                        motor_1.writeMicroseconds(1500); 
                                        door_opened=true;
                                        first_read=true;
                                        delay(3000);
                                        Serial.println();
                                        Serial.println("Last use: USER2");
                                        Serial.println();
                                        Serial.println("  Door OPENED  ");
                                    }
                                    else if(compareArray(ActualUID,USER3))
                                    {
                                        Serial.println();
                                        Serial.println(" Access granted ");
                                        Serial.println();
                                        Serial.println("     USER 3     ");
                                        digitalWrite(buzzer_pin,HIGH);    
                                        delay(300);
                                        digitalWrite(buzzer_pin,LOW);    
                                        motor_1.writeMicroseconds(1500); 
                                        door_opened=true;
                                        first_read=true;
                                        delay(3000);
                                        Serial.println();
                                        Serial.println("Last use: USER3");
                                        Serial.println();
                                        Serial.println("  Door OPENED  ");
                                    }
                                    else if(compareArray(ActualUID,USER4))
                                    {
                                        Serial.println();
                                        Serial.println(" Access granted ");
                                        Serial.println();
                                        Serial.println("     USER 4     ");
                                        digitalWrite(buzzer_pin,HIGH);    
                                        delay(300);
                                        digitalWrite(buzzer_pin,LOW);    
                                        motor_1.writeMicroseconds(1500); 
                                        door_opened=true;
                                        first_read=true;
                                        delay(3000);
                                        Serial.println();
                                        Serial.println("Last use: USER4");
                                        Serial.println();
                                        Serial.println("  Door OPENED  ");
                                    }
                                    else if(compareArray(ActualUID,USER5))
                                    {
                                        Serial.println();
                                        Serial.println(" Access granted ");
                                        Serial.println();
                                        Serial.println("     USER 5     ");
                                        digitalWrite(buzzer_pin,HIGH);    
                                        delay(300);
                                        digitalWrite(buzzer_pin,LOW);    
                                        motor_1.writeMicroseconds(1500); 
                                        door_opened=true;
                                        first_read=true;
                                        delay(3000);
                                        Serial.println();
                                        Serial.println("Last use: USER5");
                                        Serial.println();
                                        Serial.println("  Door OPENED  ");
                                    }
                                    else
                                    {
                                        Serial.println();
                                        Serial.println(" Access  denied ");
                                        Serial.println();
                                        Serial.println("   UNKNOWN ID   ");
                                        analogWrite(buzzer_pin,200);    
                                        delay(1500);
                                        analogWrite(buzzer_pin,LOW);   
                                        motor_1.writeMicroseconds(1000); 
                                        door_opened=false;
                                        first_read=false;
                                        delay(3000);
                                        Serial.println();
                                        Serial.println("Place card here!");
                                        Serial.println();
                                        Serial.println("  Door CLOSED  ");
                                    }
                            }
                          
                            
                            
                        
                            mfrc522.PICC_HaltA();
  
                                            
  
  
                            
              }
        
    }
  }//end  normal mode












  if(!normal_mode)
  {
    // Revisamos si hay nuevas tarjetas  presentes
    if ( mfrc522.PICC_IsNewCardPresent()) 
          {  
        //Seleccionamos una tarjeta
              if ( mfrc522.PICC_ReadCardSerial()) 
              {
                    // Enviamos serialemente su UID
                    
                    for (byte i = 0; i < mfrc522.uid.size; i++) {
                               
                            ActualUID[i]=mfrc522.uid.uidByte[i];          
                    } 
                                    
                    //Compare the read ID and the stored USERS
                    if(user_added==4)
                    {
                      Serial.println();
                      Serial.println("  User list is  ");
                      Serial.println();
                      Serial.println("      FULL      "); 
                      digitalWrite(buzzer_pin,HIGH);    
                      delay(3000);
                      digitalWrite(buzzer_pin,LOW);                      
                      Serial.println();
                      Serial.println("Place card here!");
                      Serial.println();
                      Serial.println("                ");
                    } 
                    
                    if(user_added==3)
                    {
                      USER5[0] = ActualUID[0];
                      USER5[1] = ActualUID[1];
                      USER5[2] = ActualUID[2];
                      USER5[3] = ActualUID[3];  
                      user_added = user_added+1;
                      Serial.println();
                      Serial.println("New user stored ");
                      Serial.println();
                      Serial.println("   as  USER 5   ");
                      digitalWrite(buzzer_pin,HIGH);    
                      delay(300);
                      digitalWrite(buzzer_pin,LOW);   
                      delay(1000);
                      normal_mode=true;
                      first_read=false;
                      delay(3000);
                      Serial.println();
                      Serial.println("Place card here!");
                      Serial.println();
                      Serial.println("                ");
                    } 
                    
                    if(user_added==2)
                    {
                      USER4[0] = ActualUID[0];
                      USER4[1] = ActualUID[1];
                      USER4[2] = ActualUID[2];
                      USER4[3] = ActualUID[3];  
                      user_added = user_added+1;
                      Serial.println();
                      Serial.println("New user stored ");
                      Serial.println();
                      Serial.println("   as  USER 4   "); 
                      digitalWrite(buzzer_pin,HIGH);    
                      delay(300);
                      digitalWrite(buzzer_pin,LOW);    
                      delay(1000);
                      normal_mode=true;
                      first_read=false;
                      delay(3000);
                      Serial.println();
                      Serial.println("Place card here!");
                      Serial.println();
                      Serial.println("                ");
                    } 
                    
                    if(user_added==1)
                    {
                      USER3[0] = ActualUID[0];
                      USER3[1] = ActualUID[1];
                      USER3[2] = ActualUID[2];
                      USER3[3] = ActualUID[3];  
                      user_added = user_added+1;
                      Serial.println();
                      Serial.println("New user stored ");
                      Serial.println();
                      Serial.println("   as  USER 3   "); 
                      digitalWrite(buzzer_pin,HIGH);    
                      delay(300);
                      digitalWrite(buzzer_pin,LOW);    
                      delay(1000);
                      normal_mode=true;
                      first_read=false;
                      delay(3000);
                      Serial.println();
                      Serial.println("Place card here!");
                      Serial.println();
                      Serial.println("                ");
                    } 
                    
                    if(user_added==0)
                    {
                      USER2[0] = ActualUID[0];
                      USER2[1] = ActualUID[1];
                      USER2[2] = ActualUID[2];
                      USER2[3] = ActualUID[3];  
                      user_added = user_added+1;
                      Serial.println();
                      Serial.println("New user stored ");
                      Serial.println();
                      Serial.println("   as  USER 2   ");
                      digitalWrite(buzzer_pin,HIGH);    
                      delay(300);
                      digitalWrite(buzzer_pin,LOW);    
                      delay(1000);
                      normal_mode=true;
                      first_read=false;
                      delay(3000);
                      Serial.println();
                      Serial.println("Place card here!");
                      Serial.println();
                      Serial.println("                ");
                    }                
                    
              }
        
    }
  }//end  ID add mode
  
}

//Compare the 4 bytes of the users and the received ID
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
