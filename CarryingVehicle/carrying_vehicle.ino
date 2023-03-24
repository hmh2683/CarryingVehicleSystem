#include <Servo.h>
#define TS 12
#define GS 13

#define EN1 8     
#define EN2 9
#define EN3 10
#define EN4 11 

void put(void);
void hold(void);
void front(void);
void back(void);
void right(void);
void left(void);
void stop(void);

//s0, s1 pins set the size of the frequency
const byte s0 = A0; 
const byte s1 = A1;

//s2, s3 pins specify color
const byte s2 = A2;
const byte s3 = A3;
const byte out_pin = 2; 
const int led_pin = 3;

Servo TiltServo;        
Servo GripServo;

int red_color = 0;
int green_color = 0;
int blue_color = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(EN1,OUTPUT); 
  pinMode(EN2,OUTPUT);
  pinMode(EN3,OUTPUT);
  pinMode(EN4,OUTPUT);

  TiltServo.attach(TS);  
  GripServo.attach(GS);
  
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);  
  pinMode(out_pin,INPUT);
  
  pinMode(led_pin, INPUT);
  
  //frequency output size 20%
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);

  TiltServo.write(50);
  GripServo.write(110);

  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,LOW); 
}

void loop() 
{
  //red color read
  digitalWrite(s2,LOW);               
  digitalWrite(s3,LOW);
  
  //Read the frequency value and output it in the range of 0~255
  red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color,25,72,255,0);  
  red_color = constrain(red_color,0,255);
  
  Serial.print("RED:");
  Serial.print(red_color);
  Serial.println(" ");
  delay(50);
  

  //green color read
  digitalWrite(s2,HIGH);            
  digitalWrite(s3,HIGH);
  
  //Read the frequency value and output it in the range of 0~255
  green_color = pulseIn(out_pin, LOW); 
  green_color = map(green_color, 30,90,255,0);   
  green_color = constrain(green_color, 0, 255);
  
  Serial.print("GREEN:");
  Serial.print(green_color);
  Serial.println(" ");
  delay(50);
  

  //blue color read
  digitalWrite(s2,LOW);               
  digitalWrite(s3,HIGH);             
  
  //Read the frequency value and output it in the range of 0~255
  blue_color = pulseIn(out_pin, LOW);
  blue_color = map(blue_color, 25,70,255,0); 
  blue_color = constrain(blue_color, 0, 255);
  
  Serial.print("BLUE:");
  Serial.print(blue_color);
  Serial.println(" ");
  delay(50);
  
  //Action when red is detected
  if(red_color > 50)
  {               
    hold();
    digitalWrite(led_pin, HIGH);
    right();
    delay(600);
    stop();
    delay(1000);
    
    put();
    left();
    delay(600);
    stop();
    delay(1000);
    digitalWrite(led_pin, LOW);
  } 
  //Action when green is detected
  else if(green_color > 100)
  {  
    hold();
    back();
    delay(1000);
    left();
    delay(1200);
    front();
    delay(2000);
    stop();
    delay(1000);
   
    put();
    back();
    delay(2000);
    left();
    delay(1200);
    front();
    delay(1000);
    stop(); 
    delay(1000);
  }
  //Action when blue is detected
  else if(blue_color > 100)
  {   
    hold();
    back();
    delay(1000);
    left();
    delay(600);
    front();
    delay(1000);
    left();
    delay(600);
    front();
    delay(2000);
    stop();
    delay(1000);
   
    put();
    back();
    delay(2000);
    left();
    delay(600);
    front();
    delay(1000);
    left();
    delay(600);
    front();
    delay(1000);
    stop(); 
    delay(1000);
  }
  else
  {                              
   Put();
  }
}

void put()
{
  TiltServo.write(50);  
  delay(100);
  GripServo.write(110); 
  delay(200);
}

void hold()
{
  GripServo.write(75); 
  delay(200);
  TiltServo.write(75);
  delay(100);
}

void front()
{
  digitalWrite(EN1,HIGH);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,HIGH);
  digitalWrite(EN4,LOW);
}

void back()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,HIGH);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,HIGH);
}

void right()
{
  digitalWrite(EN1,HIGH);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,HIGH);
}

void left()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,HIGH);
  digitalWrite(EN3,HIGH);
  digitalWrite(EN4,LOW);
}

void stop()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,LOW);
}