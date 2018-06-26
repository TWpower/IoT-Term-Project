#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
int analog_a0 = A0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }

  //블루투스와 아두이노의 통신속도를 9600으로 설정
  mySerial.begin(9600);
}

void loop() { //코드를 무한반복합니다.
 
  Serial.println(analogRead(analog_a0));

  if(analogRead(analog_a0) < 500){

    mySerial.write("a");
    
  }
  else if(analogRead(analog_a0) > 600){

    mySerial.write("b");
    
  }

  if (mySerial.available()) { //블루투스에서 넘어온 데이터가 있다면
    Serial.write(mySerial.read()); //시리얼모니터에 데이터를 출력
  }
  
  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
  }
  
  Serial.println();
 
 
   delay(1000); 
}
