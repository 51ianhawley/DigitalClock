
#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DS3231 clock;
RTCDateTime dt;
  /*Serial.begin(9600);
  Serial.print(dt.hour);   
  Serial.print(":");
  Serial.print(dt.minute); 
  Serial.print(":");
  Serial.print(dt.second); 
  Serial.println(":");
  */
  // Initialize DS3231
  //Serial.println("Initialize DS3231");
  void setup()
  {
    
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__); 
  //comment this out as soon as you reset the clock QUICKLY!!!!!!!!
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
}

void loop()
{
  // Instantiates the dt for the Date and Time module.
  dt = clock.getDateTime();
  // Prints the Date with dashes for example 2/21/2020
  //dt = clock.dateFormat("js, M Y h:ia", dt);
  lcd.setCursor(0, 0);
  lcd.print(dt.month);
  lcd.print("/");
  lcd.print(dt.day);
  lcd.print("/");
  lcd.print(dt.year);
  // For leading zero look to DS3231_dateformat example

  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    // read all the available characters
    //while (Serial.available() > 0) {
      // display each character to the LCD
      //lcd.write(Serial.read());
    }
  
  delay(1000);

  //lcd.print(Serial.read());
  lcd.setCursor(0, 2);
  //lcd.print(dt.hour);
  //if (dt.hour =12
  int printedHour;
  if (dt.hour > 12) {
    printedHour = dt.hour - 12;

  }
  else {
    printedHour = dt.hour;
  }

  // In lcd.print(printedHour); add a 2 after printedHour. To make it this: lcd.print(printedHour, 2);
  // Updates the screen.
  lcd.clear();
  // Prints the time on the lcd.
  lcd.print(printedHour);
  //.print(printedHour, 2);
  lcd.print(":");
  lcd.print(dt.minute);
  lcd.print(" ");
  lcd.print(dt.second);
  if (dt.hour < 12) {
    lcd.print(" ");
    lcd.print("AM");
  }
  if (dt.hour >= 12) {
    lcd.print(" ");
    lcd.print("PM");
  }
  if (dt.minute >= 10) {
    lcd.print("0" + dt.minute);
  }
  if (dt.second >= 10) {
    lcd.print("0" + dt.second);
  }
  //lcd.print(clock.dateFormat("h:ia s", dt));
  //Serial.print(dt.minute) Serial.print(":")
  //Serial.print(dt.second) Serial.println(""))));
  //lcd.print(Serial));
}
