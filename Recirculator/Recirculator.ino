#include <Servo.h>
Servo myservo;
bool flag=false;
bool buttn=false;
unsigned long timer100mils;
bool cycle100mils=true;
void setup() {
     myservo.attach(3);//достаточно 1.5с на 180
     pinMode(2, INPUT_PULLUP);
     pinMode(4, OUTPUT);
     digitalWrite(4, HIGH);
     Serial.begin(9600);
     Serial.println("");
     myservo.write(0);
}
void loop(){
     timersWorks();
     buttn=!digitalRead(2);
     if (buttn&&!flag&&cycle100mils){
        flag=true;
        if (myservo.read()==0){myservo.write(180);digitalWrite(4, LOW);}
        else {myservo.write(0);digitalWrite(4, HIGH);}
        Serial.println(myservo.read());
     }
     else if (!buttn&&flag) flag=false;
     eraseCyclos();
}
void timersInit(){
    unsigned long uptimeMils = millis();
     timer100mils=uptimeMils;
}
void timersWorks(){
     unsigned long timeMils = millis();
     if (timeMils - timer100mils > 100) {timer100mils =  timeMils; cycle100mils = true;}
}
void eraseCyclos(){
     cycle100mils=false;
}
