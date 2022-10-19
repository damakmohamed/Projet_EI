int n=12;
char charn[4];
String strn;

void setup()
{Serial.begin(9600);

Serial.print("Num: ");
Serial.print(n);

strn+=n;
Serial.print("strNum: ");
Serial.print(strn);

strn.toCharArray(charn,5);
Serial.print("Numchar : ");
Serial.print(charn);
}
void loop(){
   
}
