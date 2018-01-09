#include<SoftwareSerial.h>

SoftwareSerial mySerial(2,3);//to make pin 9,10 as Rx,Tx respectively for serial communication between bluetooth module and arduino
int t;
int bright=0;
int fade=5;
void setup()
{ //motoff();
  Serial.begin(9600);//baud rate 9600 between serial monitor and arduino serial ports 0,1
  delay(1000);
  mySerial.begin(9600);//baud rate 9600 between bluetooth module and arduino serial ports 9,10
  delay(1000);
  pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(6,OUTPUT);
    
}
void loop()
{
  if(mySerial.available()>0)
  {
    t= mySerial.read();
    mySerial.flush();
    t=t-48;
    if(t==1)
    {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    analogWrite(6,LOW);
    }
    else if(t==2)
    {
     digitalWrite(13,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(11,LOW);
    analogWrite(6,LOW);
    }
    else if(t==3)
    {
     digitalWrite(13,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(11,HIGH);
     analogWrite(6,HIGH);

    }
    
    else if(t==4)
    {
      for(int i=0; i<5; i++)
      {
      digitalWrite(13,HIGH);
      delay(500);
      digitalWrite(13,LOW);
      delay(500);
     digitalWrite(12,HIGH);
     delay(500);
     digitalWrite(12,LOW);
     delay(500);
     digitalWrite(11,HIGH);
     delay(500);
     digitalWrite(11,LOW);
     delay(500);
      }
    }
    else if(t=5)
    {
      
       digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    analogWrite(6,bright);
    {
      
      bright=bright+fade;
      if (bright<=0||bright>=255)
      fade=-fade;
      }
      delay(30);
      } 
    else
    {
      digitalWrite(13,LOW);
     digitalWrite(12,LOW);
     digitalWrite(11,LOW);
      }
    }
}
