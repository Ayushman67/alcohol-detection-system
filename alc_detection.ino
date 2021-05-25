#include <Servo.h>


#include <LiquidCrystal.h>


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int ledPin = 12;

int sensorPin = A1;


Servo myservo;


int pos = 0;


int value;


void setup()

{


Serial.begin(9600);

lcd.begin(16,2);


pinMode(ledPin,OUTPUT);


 myservo.attach(10);

}


void loop() 

{


int Value = analogRead(sensorPin);

value = analogRead(A1);



lcd.print("Alcohollevel:");

lcd.println(value);

Serial.println(value);


if (Value > 500) 

{

    digitalWrite(ledPin,HIGH);

    

     lcd.setCursor(0, 2);

     lcd.print("Alert....!!!");

    Serial.print ("Alert");

    

      myservo.write(100); 

    

  } 

  else {

    digitalWrite(ledPin,LOW); 

    

      lcd.setCursor(0, 2);

      lcd.print("Normal... :)");

    Serial.print("Normal");

    

     myservo.write(0); 

  }


  



delay(1000);

lcd.clear();


}
