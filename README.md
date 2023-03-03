# Carrying Vehicle System
* 개발 기간 : 2021.04 ~ 2021.06 (3개월) 
* 개발 인원 : 5 명
* 개발 환경 : ArduinoIDE
* 개발 언어 : C++
* 개발 목표  
  * 차량은 물체를 감지하고 물체의 색상에 따라 이동 경로를 파악합니다.
  * 차량은 서보 모터를 통해 감지된 물체를 들어 올리거나 내려놓습니다.
  * 차량은 물체를 들고 목적지까지 이동합니다.

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
* RGB(0~255)를 추출하기 위해 S0 : HIGH, S1 : LOW 로 설정하여 주파수를 20% 크기로 출력합니다. (0%, 2%, 20%, 100%)
* S2, S3 상태에 따라을 선택합니다. (S2 : LOW S3: HIGH -> BULE, S2 S3 : HIGH -> GREEN)  
* pulseIn, map, constrain 함수를 통해 순수 주파수를 0-255 범위의 값으로 반환합니다.
|S0|S1|출력(주파수 스케일링)|
|---|---|---|
|L |L |Power down|  
|L |H |2%| 
|H |L |20%| 
|H |H |100&| 
|제목|내용|설명|
|------|---|---|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|
```C
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);
  
  digitalWrite(s2,LOW);               
  digitalWrite(s3,LOW);
  
  red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color,25,72,255,0);  
  red_color = constrain(red_color,0,255);
```

<br/>

* 두 개의 서보 모터는 12번, 13번 핀으로 구성합니다.
* 서보 12는 75도와 50도를 설정하여 물체를 수직으로 올리거나 내립니다.
* 서보 13은 75도 및 110도 설정으로 물체를 수평으로 잡거나 놓습니다.

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
