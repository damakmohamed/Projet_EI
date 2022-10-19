#include <Wire.h>   //  library for I2C protocol
#include <LiquidCrystal_I2C.h>  // library for I2C LCD
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
int x,y;
#define DHTPIN 2   
#define buzzer 16
#define rouge 13
#define vert 15
// What digital pin we're connected to
// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "VDyXCRFvl-z4GvxuZF94Rl0XjkIzRRgU";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Damouka";
char pass[] = "azertyazerty";

BlynkTimer timer;

void setup()
{ pinMode(buzzer,OUTPUT);
pinMode(rouge,OUTPUT);
pinMode(vert,OUTPUT);
pinMode(2,INPUT);
lcd.init();                      // initialize the lcd 
 
   lcd.backlight(); // backlight ON
   
  lcd.print("Projet Semestriel");
  
  lcd.setCursor(2,1);
  Serial.print("ok1");
  lcd.print("Controle temp");
  
 
  delay(1000);
  lcd.init();
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  
  dht.begin();
  
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
  
}
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
   

  
  if (isnan(h) || isnan(t)) 
    {Serial.println("Failed to read from DHT sensor!");
    
    return;
    
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  if (t>=28)
   
    {x=255;
    y=0;
    Blynk.virtualWrite(V7,x);
  Blynk.virtualWrite(V8,y);
      digitalWrite(vert,LOW);
      digitalWrite(buzzer,HIGH);
    digitalWrite(rouge,HIGH);
    delay(500);
    x=0;
    Blynk.virtualWrite(V7,x);
  Blynk.virtualWrite(V8,y);
    digitalWrite(buzzer,LOW);
    digitalWrite(rouge,LOW);
    delay(500);
    }
else
{y=255;
x=0;
Blynk.virtualWrite(V7,x);
  Blynk.virtualWrite(V8,y);
  digitalWrite(buzzer,LOW);
    digitalWrite(rouge,LOW);
    digitalWrite(vert,HIGH);
    
    }
  lcd.init();     

   lcd.print("Temperature:");
  lcd.print(t);
  lcd.setCursor(2,1);
  lcd.print("Humidite:");
   lcd.print(h);

  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  
  
  
}
