#define trigpin 2
#define echopin 3
#define Ena 10
#define In1  9
#define In2  8
#define enb 7
#define in3 6
#define in4 5

void setup()
{
  // All motor control pins are outputs
  pinMode(Ena, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

}

void loop()
{
  int duration,distance;
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=(duration/2)/29.1;
  if(distance>=40) 
  //no movement
  { analogWrite(Ena, 200);
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  analogWrite(enb,200);
  digitalWrite(in3,LOW);
  digitalWrite(in4, LOW);
  delay(2000);
  }
   else if(distance>=25)
  {
    
  //forward
   analogWrite(Ena, 200);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(enb,200);
  digitalWrite(in3,HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
  }
  else
    {
  //reverse
    analogWrite(Ena, 200);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(enb,200);
  digitalWrite(in3,LOW);
  digitalWrite(in4, HIGH);
  delay(2000);
    }
}
