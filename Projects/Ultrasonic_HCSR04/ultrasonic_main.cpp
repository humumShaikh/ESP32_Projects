int trigPin=25;
int echoPin=26;

int pingTravelTime;
float pingTravelDistance;
float targetDistance;

void setup(){

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(115200);
}

void loop(){

  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTravelTime = pulseIn(echoPin,HIGH);

  pingTravelDistance = 0.0348*pingTravelTime;

  targetDistance = pingTravelDistance/2;

  Serial.print("Distance: ");
  Serial.print(targetDistance);
  Serial.println(" cm");
  Serial.println();

  delay(100);
}
