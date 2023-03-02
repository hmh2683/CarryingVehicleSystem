# Carrying Vehicle System
* Period : 2021.04-2021.06 (3 months)
* Personnel : 5 person
* Development environment : ArduinoIDE
* Development language : C++
* Development goals  
  * The vehicle uses two DC motors to accurately reach its destination.
  * Raises and lowers objects safely detected by two servo motors.
  * The sensor detects the color of the object and moves along the set path according to the color.

<br/> <br/>

## Microcontroller
<a href="#"><img src="https://github.com/hmh2683/vehicle.project/blob/main/images/mcu.png" width="400px" height="300px"></a> 
* Board : Arduino Uno (M3)
* Core : AVR ATMega328 
* Clock Speed : 16MHz
* Digital I/O Pins : 14 (of which 6 provide PWM output)
* Analog Input Pins : 6

<br/> <br/>

## Pinout Configuration
* LED -> OUTPUT -> 2
* DCMotor -> OUTPUT -> 8, 9, 10, 11
* ServoMotor -> OUTPUT -> 12, 13 
* ColorSensor -> OUTPUT -> A0, A1, A2, A3
* ColorSensor -> INPUT -> 3

<br/> <br/>

## Code Review
* Set the s0 pin to HIGH and the s1 pin to LOW to output the frequency at 20% size.
* The s2, s3 pins are combined to receive frequency values of red, green, and blue.
* Get the value of the frequency through the pulseIn function and get the value in the range 0-255.

```C
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);
  
  digitalWrite(s2,LOW);               
  digitalWrite(s3,LOW);
  
  red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color,25,72,255,0);  
  red_color = constrain(red_color,0,255);
```

* Two servo motors for vertical and horizontal control are composed of pins 12 and 13.
* Servo 12 raises and lowers objects vertically by setting 75 and 50 degrees.
* Servo 13 holds and places objects horizontally with 75 degree and 110 degree settings.

```C
  tiltservo.attach(12);  
  gripservo.attach(13);

  gripservo.write(75); 
  delay(200);
  tiltservo.write(75);
  delay(100);
  
  tiltservo.write(50);  
  delay(100);
  gripservo.write(110); 
  delay(200);
```

<br/> <br/>

## Result
<a href="#"><img src="https://github.com/hmh2683/vehicle.project/blob/main/images/motor.png" width="400px" height="300px"></a>
<a href="#"><img src="https://github.com/hmh2683/vehicle.project/blob/main/images/sensor.png" width="400px" height="300px"></a>
<a href="#"><img src="https://github.com/hmh2683/vehicle.project/blob/main/images/result2.png" width="400px" height="300px"></a>
<a href="#"><img src="https://github.com/hmh2683/vehicle.project/blob/main/images/result.png" width="400px" height="300px"></a>

<br/> <br/>

## Realization
* Using the datasheet and open source of the hardware used in the project, I was able to feel the joy of operating the hardware myself.
* It was very helpful to design and proceed the project directly rather than proceeding with the Arduino practice according to the lecture.
* By communicating with the four team members, I was able to complete the targeted results, and it was an opportunity to take responsibility for the roles I was assigned.
