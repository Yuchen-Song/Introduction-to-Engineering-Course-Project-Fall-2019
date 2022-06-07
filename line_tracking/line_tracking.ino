/*#include <Servo.h>*/
const int L298pin1 = 5; // 控制左右两个电机
const int L298pin2 = 6;
const int L298pin3 = 9;
const int L298pin4 = 10;
const int ENA = 3;//控制PWM
const int ENB = 11;
const int sensor1 = 2;//5路传感器
const int sensor2 = 4;
const int sensor3 = 7;
const int sensor4 = 8;
const int sensor5 = 12;
int q = 0, w = 0, e = 0, r = 0, t = 0, a = 0;

/* Servo s1;
Servo s2;
Servo s3;
Servo s4;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0; */

void setup() 
{ 
    Serial.begin(9600);
    pinMode(L298pin1,OUTPUT);
    pinMode(L298pin2,OUTPUT);
    pinMode(L298pin3,OUTPUT);
    pinMode(L298pin4,OUTPUT);
    pinMode(ENA,OUTPUT);
    pinMode(ENB,OUTPUT);
    pinMode(sensor1,INPUT);
    pinMode(sensor2,INPUT);
    pinMode(sensor3,INPUT);
    pinMode(sensor4,INPUT);
    pinMode(sensor5,INPUT);
} 

/*********以下为前进时运用的子函数***************/

void RUN_BACKWARD()    //电机反装 BACKWARD就是我们的前进
{
  
  
  analogWrite(ENA, 120); 
  analogWrite(ENB, 120);
  digitalWrite(L298pin1,HIGH);
  digitalWrite(L298pin2,LOW);
  digitalWrite(L298pin3,HIGH);
  digitalWrite(L298pin4,LOW);
}

void RUN_BACKWARD_SLOW()    //电机反装 BACKWARD就是我们的前进
{
  
  analogWrite(ENA, 90); 
  analogWrite(ENB, 90);
  digitalWrite(L298pin1,HIGH);
  digitalWrite(L298pin2,LOW);
  digitalWrite(L298pin3,HIGH);
  digitalWrite(L298pin4,LOW);
}

void TURNLEFT_HARD_B()
{
  
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0);
  digitalWrite(L298pin1,HIGH);
  digitalWrite(L298pin2,LOW);
  digitalWrite(L298pin3,HIGH);
  digitalWrite(L298pin4,LOW);
}
  

void TURNRIGHT_HARD_B()
{
  
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0);
  digitalWrite(L298pin1,HIGH);
  digitalWrite(L298pin2,LOW);
  digitalWrite(L298pin3,HIGH);
  digitalWrite(L298pin4,LOW);
}

void TURNLEFT_ADJUST_B()
{
  
  analogWrite(ENA, 90); 
  analogWrite(ENB, 55);
  digitalWrite(L298pin1,HIGH);
  digitalWrite(L298pin2,LOW);
  digitalWrite(L298pin3,HIGH);
  digitalWrite(L298pin4,LOW);
}

void TURNRIGHT_ADJUST_B()
{
  
  analogWrite(ENA, 55); 
  analogWrite(ENB, 90);
  digitalWrite(L298pin1,HIGH);
  digitalWrite(L298pin2,LOW);
  digitalWrite(L298pin3,HIGH);
  digitalWrite(L298pin4,LOW);
}


/*********以下为倒退时运用的函数***************/


void RUN_FORWARD()// 电机反装 FORWARD就是我们的倒退
{
 
  analogWrite(ENA, 60);//设置PWM输出，value设置速度
  analogWrite(ENB, 60);//
  digitalWrite(L298pin1,LOW);
  digitalWrite(L298pin2,HIGH);
  digitalWrite(L298pin3,LOW);
  digitalWrite(L298pin4,HIGH);
}

void RUN_FORWARD_SLOW()// 电机反装 FORWARD就是我们的倒退
{
 
  analogWrite(ENA, 10);//设置PWM输出，value设置速度
  analogWrite(ENB, 10);//
  digitalWrite(L298pin1,LOW);
  digitalWrite(L298pin2,HIGH);
  digitalWrite(L298pin3,LOW);
  digitalWrite(L298pin4,HIGH);
}


void TURNLEFT_HARD_F()
{
  
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0);
  digitalWrite(L298pin1,LOW);
  digitalWrite(L298pin2,HIGH);
  digitalWrite(L298pin3,LOW);
  digitalWrite(L298pin4,HIGH);
}

void TURNRIGHT_HARD_F()
{
  
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0);
  digitalWrite(L298pin1,LOW);
  digitalWrite(L298pin2,HIGH);
  digitalWrite(L298pin3,LOW);
  digitalWrite(L298pin4,HIGH);
}

void TURNLEFT_ADJUST_F()
{
  
  analogWrite(ENA, 0); //
  analogWrite(ENB, 0);//
  digitalWrite(L298pin1,LOW);
  digitalWrite(L298pin2,HIGH);
  digitalWrite(L298pin3,LOW);
  digitalWrite(L298pin4,HIGH);
}

void TURNRIGHT_ADJUST_F()
{
  
  analogWrite(ENA, 0); //
  analogWrite(ENB, 0);//
  digitalWrite(L298pin1,LOW);
  digitalWrite(L298pin2,HIGH);
  digitalWrite(L298pin3,LOW);
  digitalWrite(L298pin4,HIGH);
}

/************停车子函数代码***********/

void STOP()
{
  
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0);
  digitalWrite(L298pin1,LOW);
  digitalWrite(L298pin2,LOW);
  digitalWrite(L298pin3,LOW);
  digitalWrite(L298pin4,LOW);
}
 

void loop() 
{   
  /**********读取四个传感器值 (旧三路传感器是 1为黑；0为非黑)   （新五路传感器是  0为黑 ； 1为非黑 ***********/                 //   用a记录五路传感器共黑的次数
   q = digitalRead(sensor1);//  前进时   最左侧     pin 2   倒退时    最右侧
   w = digitalRead(sensor2);//  前进时   次左侧     pin 4   倒退时    次右侧
   e = digitalRead(sensor3);//  前进时   中间位     pin 7   倒退时    中间位 
   r = digitalRead(sensor4);//  前进时   次右侧     pin 8   倒退时    次左侧
   t = digitalRead(sensor5);//  前进时   最右侧     pin 9   倒退时    最左侧
  Serial.println(e);
 

  /************前进时的代码*********/
 
  if ( q == 0 && w == 0 && e == 0 && r == 0 && t == 0)
  {
   STOP();
   
  }


  else if ( (q == 1 && w == 1 && e == 0 && r == 1 && t == 1) || (q == 1 && w == 0 && e == 0 && r == 0 && t == 1))
  {
    RUN_BACKWARD();
    
  }


  else if ( q == 1 && w == 1 && e == 1 && r == 1 && t == 1 )
  {
    RUN_BACKWARD_SLOW();
    
  }

  
  else if ( q == 1 && w == 0 && e == 1 && r == 1 && t == 1)
  {
    TURNLEFT_ADJUST_B();
    
  }


  else if ( q == 1 && w == 1 && e == 1 && r == 0 && t == 1)
  {
    TURNRIGHT_ADJUST_B();
    
  }


  else if ( q == 0 && w == 1 && e == 0 && r == 1 && t == 0)
  {
    STOP();
  }

  }
