void setup() 
{

  pinMode(D6, INPUT);
  pinMode(D7, OUTPUT);
}

void loop() 
{  
  int reading = 0;
  reading = digitalRead(D6);
  if(reading == LOW)
  {
    digitalWrite(D7, HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(D7, LOW);
    delay(50);
}
}
