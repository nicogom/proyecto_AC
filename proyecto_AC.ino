
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <LiquidCrystal.h>

//HAY QUE CAMBIAR LOS PINES!!!
#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

#define DHTPIN 6 //Defiene el pin al que se conectará el sensor
#define DHTTYPE DHT11 //Seleciona el tipo de sensor


int RS = 12;
int E = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

Adafruit_BMP280 bmp; // definir sensor barometrico
DHT dht(DHTPIN, DHTTYPE);//definir tipo de sensor dht
LiquidCrystal lcd( RS, E, d4, d5, d6, d7); //configurar pantalla lcd


void setup() {
  
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  // analogWrite(VO,50);
  
   if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
   
}

void loop() {
  
  int hum_dht = dht.readHumidity();
  int temp_dht = dht.readTemperature();

  int pres_bmp = bmp.readPressure();

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
  lcd.setCursor(8, 0);
  lcd.print("hum: ");
  lcd.print(hum_dht);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("presion: ");
  lcd.print(pres_bmp);
  lcd.print("Hpa");
  
   delay(8000);
    
}
