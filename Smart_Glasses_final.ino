#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     4 
Adafruit_SSD1306 display(OLED_RESET);




void setup() {
Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C) ;
  display.clearDisplay(); 
}



int g=0;
int flag=0,a,i=0,j=0,h=0,k=0;
char c[100];


void loop() {
  while (Serial.available()>0){
  a=Serial.read();
  c[j]=a;
  Serial.println(c[j]);
  if (c[j] == '-')
  {
  i=0;
  h+=13;
  g=0;
  }
  else{
  text(c[j],i,h,1);
  i+=6;
  }
   g++;
 if (g==20)
 {
  i=0;
  h+=13;
  g=0;
 }
 j++;
 
  }
  delay(3000);
  display.clearDisplay();
  i=0;
  h=0;
  g=0;
  display.drawLine(0,11,display.width()-1,11, WHITE);
}
  void text(char tex,int x,int y,int siz){
  display.setCursor(x,y);
  display.setTextColor(WHITE);
  display.setTextSize(siz);
  display.print(tex);
  display.display();   
  delay(100) ;
  }
