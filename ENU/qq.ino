// подключение библиотеки
#include <iarduino_SensorPulse.h>
// создание экземпляра объекта
// подключение к контакту A0
iarduino_SensorPulse Pulse(A0);
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX, TX pins

// VCC - 3.3V
//GND - GND 

//LCD NOKIA
#include <LCD5110_Graph.h>
LCD5110 myGLCD(8,9,10,11,12);
extern unsigned char TinyFont[];
extern unsigned char SmallFont[];
extern unsigned char MediumNumbers[];


//SCL - PIN 17
//SDA - PIN 16
//GND - GND
//VCC - 3.3V
#include <Wire.h> 
#include "RTClib.h"
#include <LiquidCrystal.h>

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
RTC_DS1307 RTC;
int f, h, t;

void setup() {
  pinMode(6, OUTPUT);
  //Pulsometr
  //Serial.begin(9600);
  pinMode(13, OUTPUT); //Инициализируйте вывод 13 как цифровой выход (светодиод)
  pinMode(8, INPUT); // Our button pin
  mySerial.begin(4800); // Открытое последовательное соединение со скоростью 4800 бод
  // запуск датчика пульса
 // Pulse.begin();   

  //Modulo Reloj
  Wire.begin(); // Запустите порт I2C
 // RTC.begin(); // Начать общение с RTC
 // RTC.adjust(DateTime(__DATE__, __TIME__)); //Установите дату и время (комментарий, как только время установлено)
  //Serial.begin(9600); // Установите скорость передачи данных последовательного порта
  //lcd.begin(20,4);

  // LCD NOKIA
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.print("ARDUINO", CENTER, 0);
  myGLCD.print("WATCH", CENTER, 10);
  myGLCD.print("SPORT", CENTER, 20);
  myGLCD.drawRect(26, 8, 58,18);
  for (int i=0; i<6; i++)
  {
    myGLCD.drawLine(58, 8+(i*2), 83-(i*3), 8+(i*2));
    myGLCD.drawLine((i*3), 18-(i*2), 26, 18-(i*2));
  }
  
  myGLCD.setFont(TinyFont);
  myGLCD.print("(C)2019 by", CENTER, 36);
  myGLCD.print("Nazerke (alt+159) Akyltay", CENTER, 42);
  myGLCD.update();
  //delay(2000);
  
 for (int p=5; p>0; p--)
 {
    myGLCD.setFont(SmallFont);
    myGLCD.drawRect(73,37, 82,47);
    myGLCD.printNumI(p,75,39, 1);
    myGLCD.update();
    delay(1000);
  }
  myGLCD.clrScr();

}

void loop() {
    
    myGLCD.setFont(TinyFont);
    myGLCD.print("Pulse GSM", CENTER, 32);
    myGLCD.setFont(SmallFont);
      // если датчик подключен к пальцу
   if(Pulse.check(ISP_VALID)==ISP_CONNECTED){
    // печать аналогового сигнала
    myGLCD.printNumI(Pulse.check(ISP_PULSE),57,39);
     
  } 
  else {
    myGLCD.print("error",57,39);
       }
       
  if (digitalRead(8) == HIGH) {// при нажатии кнопки
    digitalWrite(13, HIGH); // Включить светодиод.
    mySerial.println("AT"); //Посылает AT команду, чтобы разбудить мобильный телефон
    delay(500);
    mySerial.println("AT+CMGF=1");// переводит телефон в режим смс
    delay(1000); // Подожди секунду
    mySerial.println("AT+CMGW=\"+77072225021\""); // ВАШ НОМЕР ЗДЕСЬ; Создает новое сообщение на номер
    delay(1000);
    mySerial.print("Sent from my Arduino."); // Содержание сообщения
    delay(1000);
    mySerial.write(byte(26));// (сигнализирует конец сообщения)
    delay(1000);
    mySerial.println("AT+CMSS=1");// Отправляет сообщение с индексом 1
    digitalWrite(13, LOW);// выключаем светодиод
    delay(250);
    digitalWrite(13, HIGH);// Включить светодиод.
    delay(10000);// Даем телефону время отправить смс
    mySerial.println("AT+CMGD=1");// удаляет сообщение с индексом 1
    digitalWrite(13, LOW); // Выключить светодиод.
    delay(250);
  }
    //Pulse
    myGLCD.printNumI(h,57,39);
    myGLCD.print("pm",69,39);
    // myGLCD.drawRect(48,30,83,40);
  
    //GSM
    myGLCD.printNumI(t,13,39 , 1);// Распечатать переменную
    myGLCD.drawLine(47,30,47,47);
    myGLCD.drawRect(0,30, 82,47); // прямоугольник
    myGLCD.drawRect(26,38,28,41); // Степень
    myGLCD.print("C",29,39);     // стоградусный

  //Modulo Reloj
    DateTime now = RTC.now(); // Получить дату и время RTC
    myGLCD.drawRect(0,0,82,10);// прямоугольник
    myGLCD.printNumI(now.day(),12,2, 1); // Распечатать переменную
    myGLCD.print("/",25,2);
    myGLCD.printNumI(now.month(),31,2 , 1); // Распечатать переменную
    myGLCD.print("/",44,2);
    myGLCD.printNumI(now.year(),50,2, 1); // Распечатать переменную
    
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumI(now.hour(),1,13); // Распечатать переменную
    myGLCD.drawRect(26,17,28,19);
    myGLCD.drawRect(26,22,28,24);
    myGLCD.printNumI(now.minute(),30,13); // Распечатать переменную
    myGLCD.drawRect(55,17,57,19);
    myGLCD.drawRect(55,22,57,24);
    myGLCD.printNumI(now.second(),59,13);
    f=now.second();
    Serial.println(f);
    delay(100);
    myGLCD.update();
    myGLCD.clrScr();
    
    
}
