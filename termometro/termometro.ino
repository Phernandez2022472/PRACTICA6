
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define ROJO 2
#define AZUL 4
#define VERD 4
byte Grados[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


OneWire ourWire(5);
DallasTemperature sensors(&ourWire);

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERD, OUTPUT);

  lcd.init();
  lcd.backlight();
  delay(1000);
  Serial.begin(9600);

  sensors.begin();
  lcd.createChar(0, Grados);
}

void loop() {
  temperatura();
  LEDS();  
}
void temperatura() {
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float tempC = sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  float tempF = sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
  Serial.print("Temperatura");
  Serial.print(tempC);
  Serial.println(" C");
  Serial.print("Temperatura");
  Serial.print(tempF);
  Serial.println(" F");
  delay(100);
  //Imprime los grados Farenheit en la primera fila
  lcd.setCursor(0, 0);
  lcd.write(byte(0));//Imprime el caracter de grados en la primera columna y primera fila
  lcd.setCursor(1, 0);
  lcd.print("F");
  lcd.setCursor(2, 0);
  lcd.print("=");
  lcd.setCursor(3, 0);
  lcd.print(tempF);
  //Imprime los grados centigrados en la segunda fila
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.print("C");
  lcd.setCursor(2, 1);
  lcd.print("=");
  lcd.setCursor(3, 1);
  lcd.print(tempC);
}
void LEDS(){
  float tempC = sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  float tempF = sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
  if (tempC > 30)
  {
    digitalWrite(ROJO, HIGH);
    digitalWrite(AZUL, LOW);
    digitalWrite(VERD, LOW);
  }
  if (tempC < 15)
  {
    digitalWrite(VERD, LOW);
    digitalWrite(ROJO, LOW);
    digitalWrite(AZUL, HIGH);
  }
  if ((tempC < 30) && (tempC > 15))
  {
    digitalWrite(AZUL, LOW);
    digitalWrite(ROJO, LOW);
    digitalWrite(VERD, HIGH);

  }
}
