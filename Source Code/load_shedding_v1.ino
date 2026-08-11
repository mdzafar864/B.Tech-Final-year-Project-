#include <LiquidCrystal.h> // Library for LCD
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define ShortLineRelay 13
#define RelayLED 12
#define analogchannel A0 // Connect current sensor with A0 of Arduino

int sensitivity = 20; // for ACS713-05B

float adcvalue = 0;
int offsetvoltage =(2.5)/0.185; 
double Voltage = 0; // Voltage measuring
double ecurrent = 0; // Current measuring

void setup() {
  pinMode(ShortLineRelay, OUTPUT);
  pinMode(RelayLED, OUTPUT);
  Serial.begin(9600);

  lcd.begin(20, 4); // LCD size 20x4
  lcd.setCursor(0, 0); 
  lcd.print("GEC BANKA");
  lcd.setCursor(0, 1);
  lcd.print("Auto Load Sharing TF");
  delay(1000); // Show the initial message for 5 seconds
  lcd.clear(); // Clear the LCD after initial display
}

void loop() {
  unsigned int temp = 0;
  float maxpoint = 0;

  // Read sensor values and find the maximum point
  for (int i = 0; i < 500; i++) {
      temp = analogRead(analogchannel);
   if(temp > maxpoint) {
      maxpoint = temp;
    }
  }

  // Check for no-load condition and set adcvalue accordingly
  if (maxpoint > 1000) {
    adcvalue = 0;  // Set to 0 to represent no load
  } else {
    adcvalue = maxpoint;
  }

  Voltage = (adcvalue / 1024.0) * 5000; // Convert ADC to voltage
  ecurrent = ((Voltage - offsetvoltage) / sensitivity) / sqrt(2); // Calculate current RMS

  Serial.print("Raw Value = ");
  Serial.println(adcvalue);

   // Display ADC and status on the LCD
  lcd.setCursor(0, 0); 
  lcd.print("ADC: ");
  lcd.print(adcvalue);
  
   // Determine load status and display corresponding messages
  if (adcvalue ==512 ) { // No load condition
    lcd.setCursor(0, 2);
    lcd.print("No Load On TF"); // Display no-load message
    digitalWrite(ShortLineRelay, LOW);
    digitalWrite(RelayLED, LOW);
    delay(800);
    lcd.clear();
    
   }  
  else if (adcvalue >= 600 && adcvalue < 700) { // Balanced load condition
    lcd.setCursor(0, 3);
    lcd.print("Balanced Load On TF"); // Display balanced load message
    digitalWrite(ShortLineRelay, LOW);
    digitalWrite(RelayLED, LOW);
    delay(800);
    lcd.clear();
  } 
   else if (adcvalue >= 740) { // Overload condition
    lcd.setCursor(0, 2);
    lcd.print("OverLoad On TF   "); // Display overload message
    lcd.setCursor(0, 3);
    lcd.print("TF2 Shares Power ON");
    digitalWrite(ShortLineRelay, HIGH);
    digitalWrite(RelayLED, HIGH);
    }

  delay(800); // Update delay
  lcd.clear();
}
