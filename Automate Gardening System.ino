int pump    = 7; //water pump pin
int sensor  = A0; //Analog sensor pin
int standard = 200; //standard analog moisture reading.
int lowmoisture = 1; //low moisture value.
int highmoisture = 500; // High moisture value.
int moisture; //moisture reading will be store in this.
int percentage; //percentage calculate.
int count = 0;
int dcount = 0;
int led = 13;

void setup()
{
  pinMode(pump, OUTPUT);
  pinMode(sensor, INPUT);
  digitalWrite(pump, HIGH);
  digitalWrite(led, HIGH);
  Serial.begin(9600);
}

void loop()
{
  if (count < 3) {
    Serial.print(count);
    Serial.print("\n");
    moisture = analogRead(sensor);
    Serial.print(moisture);
    Serial.print("\n");
    if (moisture < standard)
    {
      Serial.print("Low moisture leval :");
      percentage = map(moisture, lowmoisture, highmoisture, 0, 100);
      Serial.print(percentage);
      Serial.print("%");
      Serial.print("\n");
      digitalWrite(pump, LOW);  // motor turn on
      digitalWrite(led, HIGH);
      delay(5000);
      digitalWrite(pump, HIGH); // motor turn off
      digitalWrite(led, LOW);
      delay(100000);
      count++;
    }
    else
    {
      Serial.print("High moisture leval :");
      percentage = map(moisture, lowmoisture, highmoisture, 0, 100);
      Serial.print(percentage);
      Serial.print("%");
      Serial.print("\n");
      count = 0;
      if (moisture > standard) {
        digitalWrite(pump, HIGH);
      }
      delay(1000);
    }
  }
  else {
    delay(1000000);
    dcount++;
    if (dcount == 4) {
      count = 0;
    }
  }
}
