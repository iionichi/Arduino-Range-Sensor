//Define All pins
#define infraIn 7
#define infraVcc 5
#define ultraVcc 8
#define ultraTrig 9
#define ultraEcho 10
void setup() {
  pinMode(infraIn, INPUT);
  pinMode(infraVcc, OUTPUT);
  pinMode(ultraVcc, OUTPUT);
  pinMode(ultraTrig, OUTPUT);
  pinMode(ultraEcho, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  long duration,distance;
  Serial.begin(9600);
}

void loop() {
  int isObstacle = HIGH;
  long duration,distance;
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(ultraTrig, LOW);
  digitalWrite(infraVcc, LOW);
  digitalWrite(ultraVcc, LOW);
  delayMicroseconds(90);
  digitalWrite(infraVcc, HIGH);
  isObstacle=digitalRead(infraIn);
  if(isObstacle == LOW)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Obstacle Found");
    digitalWrite(ultraVcc, HIGH);
    delay(500);
    digitalWrite(ultraTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultraTrig, LOW);
    duration = pulseIn(ultraEcho, HIGH);
    distance = duration/58.2;
    Serial.print("Distance : ");
    Serial.println(distance);
    delay(3000);
  }
  else
  {
    Serial.println("No obstacle Found");
    delay(3000);
  }
}
