#include "enrol.h"
#include "fingerprint.h"

// Icon of Fingerprint
#define LOGO_HEIGHT   64
#define LOGO_WIDTH    128
static const unsigned char PROGMEM logo_bmp[] =
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x83, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x03, 0xff, 0xc0, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0xff, 0xf8, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0xff, 0xff, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xe1, 0xff, 0x00, 0xff, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xc7, 0xf0, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x8f, 0xc0, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x03, 0xff, 0xc1, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x0f, 0xff, 0xf0, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x3f, 0xff, 0xfc, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0x00, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0xf8, 0x00, 0x1f, 0x8f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xe3, 0xf0, 0x18, 0x0f, 0xc7, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xc7, 0xc1, 0xff, 0x83, 0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xc7, 0x87, 0xff, 0xe1, 0xf1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0x8f, 0x1f, 0xff, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0x1e, 0x3f, 0x01, 0xf8, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0x1e, 0x7e, 0x00, 0x7c, 0x79, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x78, 0x00, 0x3e, 0x3d, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xf0, 0xff, 0x1f, 0x3d, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0xe1, 0xff, 0x8f, 0x1c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0xe3, 0xff, 0xc7, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xe3, 0xc7, 0xc3, 0xc7, 0x9e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0xe3, 0x8f, 0x01, 0xe7, 0x9e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xc7, 0x8f, 0x00, 0xe3, 0x9e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x9e, 0x18, 0xf3, 0x9e, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0x1e, 0x38, 0xf3, 0x9e, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x3c, 0x38, 0xf3, 0x9e, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0x78, 0xf7, 0x9c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x78, 0x78, 0xe7, 0x9c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0xf0, 0xf1, 0xe7, 0x9c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xe1, 0xf1, 0xe1, 0xe7, 0x3c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xc3, 0xe3, 0xe3, 0xc7, 0x3c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x87, 0xc3, 0xc3, 0xcf, 0x3c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x87, 0x87, 0x8f, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x0f, 0x0f, 0x8f, 0x38, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x1f, 0x1f, 0x0f, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3e, 0x1e, 0x0f, 0x3d, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x7c, 0x3c, 0xcf, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0xf8, 0x79, 0xcf, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xc1, 0xf0, 0xf9, 0xcf, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x07, 0xe1, 0xf1, 0xc7, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0xc3, 0xe3, 0xc7, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x07, 0xc3, 0xc7, 0x87, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x1f, 0x83, 0xc3, 0xc3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3e, 0x01, 0xc3, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x7c, 0x01, 0xc1, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0xf8, 0x01, 0xe0, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xc3, 0xf3, 0xf8, 0xf0, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe7, 0xfc, 0xf8, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xcf, 0xfe, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x1e, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x3e, 0x0f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x0f, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



void setup()
{
  // put your setup code here, to run once:

  pinMode(Relay, OUTPUT);
  digitalWrite(buzzer, LOW);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  initWifi();

  digitalWrite(buzzer, LOW);

}



void loop() {
  // put your main code here, to run repeatedly:

  char customKey = customKeypad.getKey();

  if (customKey)
  {
    Serial.println(customKey);

    // Maze Lock Mode
    if (customKey == 'A')
    {
      Serial.println("A");
      Serial.println("Maze Lock Mode");
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(10, 0);            // Start at top-left corner
      display.println(("Maze Lock"));
      display.setCursor(35, 30);
      display.println(("Mode"));
      display.display();
      beep(200);
      beep(200);
      delay(1000);

      Serial.println("Enter the \nFour Digit \nCode");

      fingerprint_flag = 0;
    }
    
    // Enrollment Mode
    if (customKey == 'C')
    {
      beep(200);
      if (Keypad_Input() == Secret_Code)
      {
        Serial.println("D");
        Serial.println("Enrollment mode");
        display.clearDisplay();
        display.setTextSize(2);             // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE);        // Draw white text
        display.setCursor(0, 0);            // Start at top-left corner
        display.println(("Enrollment"));
        display.setCursor(35, 30);
        display.println(("Mode"));
        display.display();
        beep(200);
        beep(200);
        delay(1000);
        Serial.println("Enter ID");
        display.clearDisplay();
        display.setTextSize(2);             // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE);        // Draw white text
        display.setCursor(35, 20);            // Start at top-left corner
        display.println(("ID XXX"));
        display.display();
        ID_e = "";
        i = 0;
        fingerprint_flag = 2;
        setup_e();
        loop_e();
        fingerprint_flag = 1;
      }
      else
      {
        Serial.println("Wrong Code");
        display.clearDisplay();
        display.setTextSize(2);             // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE);        // Draw white text
        display.setCursor(0, 20);            // Start at top-left corner
        display.println(("Wrong Code"));
        display.display();
        beep(200);
        beep(200);
        delay(1000);
      }
    }
  }


  if (fingerprint_flag == 1)
  {
    finger.fingerID = 0;
    delay(50);
    setup_f();
    loop_f();
    display.clearDisplay();
    display.drawBitmap(0, 0, logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    customKey = customKeypad.getKey();
    switch (customKey) {
      case 'C':
        break;
      case 'A':
        break;
    }
    delay(1000);
  }


  if (fingerprint_flag == 0)
  {
    if (Keypad_Input() == Secret_Code)
    {
      Serial.println("Correct Code");
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0, 20);            // Start at top-left corner
      display.println(("Correct Code"));
      beep(1000);
      display.display();
      Door_control();
      ID = 200;
      makeIFTTTRequest();

      delay(1000);

      fingerprint_flag = 1;
    }
    else
    {
      Serial.println("Wrong Code");
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0, 20);            // Start at top-left corner
      display.println(("Wrong Code"));
      display.display();
      beep(200);
      beep(200);
      delay(1000);
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(35, 20);            // Start at top-left corner
      display.println(("Code"));
      display.display();
    }
    ID_e = "";
  }
}


// Establish a Wi-Fi connection with your router
void initWifi()
{
  Serial.print("Connecting to: ");
  Serial.print(ssid);
  display.clearDisplay();

  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.println(("Connecting"));
  display.setCursor(0, 50);
  display.println((ssid));
  display.display();
  delay(2000);
  WiFi.begin(ssid,password);

  int timeout = 10 * 4; // 10 seconds
  while (WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect, going back to sleep");
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(0, 30);            // Start at top-left corner
    display.println(("Not \nConnected"));
    display.display();
  }
  else
  {
    Serial.print("WiFi connected in: ");
    Serial.print(millis());
    Serial.print(", IP address: ");
    Serial.println(WiFi.localIP());
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(0, 30);            // Start at top-left corner
    display.println(("Connected"));
    display.display();
  }
  delay(2000);
}
