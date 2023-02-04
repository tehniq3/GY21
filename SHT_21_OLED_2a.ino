/* This code works with SHT-21/HTU-21/GY-21 Digital temperature and humidity sensor and 128*64 OLED screen
 * It displays the Temperature in Fahrenheit and Humidity in %RH only one of them every 2s
 * Refer to www.surtrtech.com for more details
 * https://surtrtech.com/2020/03/16/sht-21-htu-21-measure-temperature-and-himidity-with-arduino-oled-lcd/
 * small changes by Nicu FLORICA (niq_ro) 
 */

#include <SHT21.h>               //SHT21 and OLED libraries
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

SHT21 sht;                      //SHT on OLED entities
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 
 

float Temp;          //Here we store the temperature and humidity valuesui;ju
float Humidity;

void setup() {
  
  Wire.begin();                              //Start the i²c communication
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.clearDisplay();
  display.display();

}

void loop() {
  
  Temp = sht.getTemperature();       //To get the temperature and humidity values and store them in their respective variable
  Humidity = sht.getHumidity();

  display.clearDisplay();            //Clear the display everytime
             
  display.setTextColor(WHITE);                             
  Print_T();                         //Function that displays the Temperature in °F
  display.display();
  delay(2000);                       //Wait 2s
  display.clearDisplay();
  Print_H();                         //Function that displays the Humidity in %RH
  display.display();
  delay(2000);

}

void Print_T(){
  display.setTextSize(4);            //Setting the text size and color         
  display.setCursor(20,22);
//  display.print("T: ");
//  Temp=Temp*1.8+ 32;         //The value is given by °C here we convert it to °F
  display.print(Temp,0);     //Here since I'm using a bigger text size, I've chosen to display the float variables as integers: Temp,0 means it will display no number after the comma
//  display.print(" F");
  display.print(" C");
  display.setTextSize(3);            //Setting the text size and color         
  display.setCursor(70,12);
  display.print("o");
}
void Print_H(){
  display.setTextSize(4);            //Setting the text size and color         
  display.setCursor(20,22);
 // display.print("H: ");
  display.print(Humidity,0);
  display.print("%");
}
