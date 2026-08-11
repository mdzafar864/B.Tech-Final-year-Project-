#include <LiquidCrystal.h> // Library for LCD
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define ShortLineRelay 13
#define RelayLED 12
#define analogchannel A0 // Current sensor
#define tempSensorPin A1 // LM35 sensor connected here

int sensitivity = 185; // For ACS713-05B
int offsetvoltage = 2500; // in millivolts

float adcvalue = 0;
double Voltage = 0; 
double ecurrent = 0;
float temperature = 0;

unsigned long previousMillis = 0; 
const long interval = 300; 

void setup() {
  pinMode(ShortLineRelay, OUTPUT);
  pinMode(RelayLED, OUTPUT);
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.setCursor(0, 0); 
  lcd.print("GEC BANKA");
  lcd.setCursor(0, 1);
  lcd.print("Auto Load Sharing TF");
  delay(1000);
  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    unsigned int temp = 0;
    float maxpoint = 0;

    for (int i = 0; i < 500; i++) {
      temp = analogRead(analogchannel);
      if (temp > maxpoint) {
        maxpoint = temp;
      }
    }

    adcvalue = maxpoint;
    Voltage = (adcvalue / 1024.0) * 5000; 
    ecurrent = ((Voltage - offsetvoltage) / sensitivity) / sqrt(2);

    // --- Read LM35 temperature ---
    int tempReading = analogRead(tempSensorPin);
    float tempVoltage = (tempReading / 1024.0) * 5000; // in mV
    temperature = tempVoltage / 10.0; // LM35 gives 10mV per °C

    Serial.print("Raw Value = ");
    Serial.println(adcvalue);
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.println(" °C");

    // --- LCD Display ---
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current: "); 
    lcd.print(ecurrent, 2);
    lcd.print(" A");

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print((char)223); // degree symbol
    lcd.print("C");

    // --- Load Logic ---
    if (adcvalue >= 500 && adcvalue <= 530) {
      lcd.setCursor(0, 2);
      lcd.print("No Load TF OFF");  
      digitalWrite(ShortLineRelay, LOW);
      digitalWrite(RelayLED, LOW);

    } else if (adcvalue >= 540 && adcvalue < 570) {
      lcd.setCursor(0, 3);
      lcd.print("Normal Load TF1 ON");  
      digitalWrite(ShortLineRelay, LOW);
      digitalWrite(RelayLED, LOW);

    } else if (adcvalue >= 608 && adcvalue < 620) {
      lcd.setCursor(0, 3);
      lcd.print("Balanced Load TF1 ON");  
      digitalWrite(ShortLineRelay, LOW);
      digitalWrite(RelayLED, LOW);

    } else if (adcvalue >= 650) {
      lcd.setCursor(0, 2);
      lcd.print("OverLoad TF2 ON");
      lcd.setCursor(0, 3);
      lcd.print("TF2 Shares Power ON");
      digitalWrite(ShortLineRelay, HIGH);
      digitalWrite(RelayLED, HIGH);
    }
  }
}
