#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )

//ARDUINO CONNECT MAX_MATRIX7219
//CS ----- PIN10
//DIN ----- PIN11
//CLK ----- PIN13

int numberOfHorizontalDisplays = 1; 
int numberOfVerticalDisplays = 4;   

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays); 

String tape = "Gmail: yaserbag73@gmail.com  >>>TRONGSANG.FEE<<<";   // led ekranda gözükecek yazı 
int wait = 100; 

int spacer = 1; 
int width = 5 + spacer;

void setup() {

                matrix.setIntensity(15); 
              
               
                 matrix.setRotation(3);    
              }

void loop() {

            for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ ) 
            {
          
              matrix.fillScreen(LOW);
          
              int letter = i / width;
              int x = (matrix.width() - 1) - i % width;
              int y = (matrix.height() - 8) / 2; // center the text vertically
          
              while ( x + width - spacer >= 0 && letter >= 0 ) {
                if ( letter < tape.length() ) {
                  matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
                }
          
                letter--;
                x -= width;
              }
          
              matrix.write(); // Send bitmap to display
          
              delay(wait);
            }
            
}
