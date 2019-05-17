#include <Servo.h>
#include <DHT.h>
#include <LiquidCrystal.h>


#define DHTPIN 6 //Defiene el pin al que se conectará el sensor
#define DHTTYPE DHT11 //Seleciona el tipo de sensor


int RS = 12;
int E = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

DHT dht(DHTPIN, DHTTYPE);//definir tipo de sensor dht
LiquidCrystal lcd( RS, E, d4, d5, d6, d7); //configurar pantalla lcd


void setup() {
  
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  // analogWrite(VO,50);
   
}

void loop() {
  
  int hum_dht = dht.readHumidity();
  int temp_dht = dht.readTemperature();
  if (isnan(hum_dht)||isnan(temp_dht))
   {
        Serial.print("error sensor DHT11");
        return;
    }
  Serial.print(temp_dht);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("temp: ");
  lcd.print(temp_dht);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("hum: ");
  lcd.print(hum_dht);
  lcd.print("%");

   delay(8000);
    
}
