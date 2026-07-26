#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 26
#define SS_PIN 5
String cardID = "";
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Pin list for connecting MFRC522 to the ESP32-32D
// Other variants may vary.
// SDA       ---->      GPIO 5
// SCK       ---->      GPIO 18
// MOSI      ---->      GPIO 23
// MISO      ---->      GPIO 19
// IRQ       --X->
// GND       ---->      GND
// RST       ---->      GPIO 26
// 3.3V      ---->      3.3V
// Almost all pins are on the right side of the ESP32-32D, with the wifi module facing up

void setup() {
  Serial.begin(115200);

  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
 if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) return;
  cardID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    
     cardID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     cardID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  cardID.toUpperCase();
  Serial.println(cardID);
  delay(1000);
}

