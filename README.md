# Carrying Vehicle System
* 개발 기간 : 2021.04 ~ 2021.06 (3개월) 
* 개발 인원 : 5 명
* 개발 환경 : ArduinoIDE
* 개발 언어 : C++
* 개발 목표  
  * 차량의 센서는 물체를 감지하고 물체의 색상에 따라 이동 경로를 파악합니다.
  * 차량의 서보 모터는 감지된 물체를 들어 올리거나 내려놓습니다.
  * 차량의 DC 모터를 통해 목적지까지 이동합니다.

<br/> <br/>

## Microcontroller
<a href="#"><img src="https://github.com/hmh2683/CarryingVehicleSystem/blob/main/image/mcu.png" width="400px" height="300px"></a> 
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
* 주파수를 20% 크기로 출력하려면 s0 핀을 HIGH로, s1 핀을 LOW로 설정합니다.
* s2, s3 핀은 빨간색, 녹색 및 파란색의 주파수 값을 수신하기 위해 결합됩니다.
* pulseIn 함수를 통해 주파수 값을 얻고 0-255 범위의 값을 얻습니다.

```C
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);
  
  digitalWrite(s2,LOW);               
  digitalWrite(s3,LOW);
  
  red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color,25,72,255,0);  
  red_color = constrain(red_color,0,255);
```

* 수직 및 수평 제어를 위한 두 개의 서보 모터는 핀 12 및 13으로 구성됩니다.
* 서보 12는 75도와 50도를 설정하여 물체를 수직으로 올리고 내린다.
* 서보 13은 75도 및 110도 설정으로 물체를 수평으로 고정하고 배치합니다.

<br/>

```C
  TiltServo.attach(12);  
  GripServo.attach(13);

  GripServo.write(75); 
  delay(200);
  TiltServo.write(75);
  delay(100);
  
  TiltServo.write(50);  
  delay(100);
  GripServo.write(110); 
  delay(200);
```

<br/> <br/>

## Result
<a href="#"><img src="https://github.com/hmh2683/CarryingVehicleSystem/blob/main/image/motor.png" width="400px" height="300px"></a>
<a href="#"><img src="https://github.com/hmh2683/CarryingVehicleSystem/blob/main/image/sensor.png" width="400px" height="300px"></a>
<a href="#"><img src="https://github.com/hmh2683/CarryingVehicleSystem/blob/main/image/result2.png" width="400px" height="300px"></a>
<a href="#"><img src="https://github.com/hmh2683/CarryingVehicleSystem/blob/main/image/result.png" width="400px" height="300px"></a>

<br/> <br/>

## Realization
* 프로젝트에 사용된 하드웨어의 데이터시트와 오픈소스를 이용해 하드웨어를 직접 조작하는 즐거움을 느낄 수 있었다.
* 강의에 따라 아두이노 실습을 진행하는 것보다 직접 프로젝트를 설계하고 진행하는 것이 큰 도움이 되었다.
* 팀원 4명과 소통하면서 목표한 결과를 완성할 수 있었고, 맡은 역할을 책임지는 계기가 됐다.
