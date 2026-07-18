void setup() {
Serial.begin(115200);
pinMode(33,OUTPUT); // Indication LED
pinMode(36,INPUT_PULLDOWN); // 3-pin button module, with an external pull-down resistor.
pinMode(25,INPUT_PULLUP); // 2-pin button module, or an open circuit
}

void loop() {
  Serial.println(" "); // Spaces out the old output
  if (digitalRead(25) == LOW) {
	// If pin 25 is not pressed, the board will read HIGH
	// Press the button to make it read LOW.
	// Alternatively, connet the pin directly to GND works as well.
    digitalWrite(33,HIGH);
    Serial.println("Button pull-up pressed");
  } else{
    digitalWrite(33,LOW);
  }

  if (digitalRead(36) == HIGH) {
	// If pin 36 is not pressed, the board will read LOW
	// Press the button to make it read HIGH
    digitalWrite(33,HIGH); 
    Serial.println("Button pull-down pressed");}
    else {
    digitalWrite(33,LOW);
    }    
}
