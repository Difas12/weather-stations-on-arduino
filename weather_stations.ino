#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <RTClib.h>


// Определяем настройки для LCD, DHT и DS3231
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Адрес LCD
DHT dht(2, DHT11);                   // Пин DHT11
RTC_DS3231 rtc;                      // объект для работы с RTC

void setup() {
  lcd.backlight();  // включаем подсветку LCD дисплея
  lcd.init();       // Инициализируем LCD
  dht.begin();      // Инициализируем DHT11
  rtc.begin();      // Инициализируем DS3231
 
  lcd.print("Init...");
  delay(2000);
}

void loop() {
   
  
  // данные с DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // текущее время и дата
  DateTime now = rtc.now();

  // Вывод информаци на LCD
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("T");
  lcd.print(t);
  lcd.print("C ");
// вывод информации на lcd с dht11
  lcd.print(" ");
  lcd.print("H");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 0);
// вывод даты и часов
  lcd.setCursor(0, 0);
  lcd.print(now.year(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.day(), DEC);
  lcd.print(" ");
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);

  delay(5000);
}