// Nokia 5110 LCD-Display (84x48 Bildpunkte)

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// D7 - Serial clock out (CLK oder SCLK)
// D6 - Serial data out (DIN)
// D5 - Data/Command select (DC oder D/C)
// D4 - LCD chip select (CE oder CS)
// D3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);


void setup()   {

 
  display.begin();


  display.setContrast(60);
  display.clearDisplay();   
}


void loop() {
  
  display.setTextSize(1);
  set_text(11,0,"Hallo Welt!",BLACK);
  delay(500);
  
  display.drawLine(7,11,77,11,BLACK);
  display.display();
  delay(500);
  
  display.drawCircle(8,23,5,BLACK);
  display.display();
  delay(500);
  
  display.fillCircle(11,26,5,BLACK);
  display.display();
  delay(500);
  
  display.drawRect(25,18,10,10,BLACK);
  display.display();
  delay(500);

  display.fillRect(28,21,10,10,BLACK);
  display.display();
  delay(500);

  display.drawRoundRect(47,18,10,10,2,BLACK);
  display.display();
  delay(500);
  
  display.fillRoundRect(50,21,10,10,2,BLACK);
  display.display();
  delay(500);
  
  display.drawTriangle(68,18,68,28,78,23,BLACK);
  display.display();
  delay(500);

  display.fillTriangle(71,21,71,31,81,26,BLACK);
  display.display();
  delay(500);
  
 
  int x=0;
  for(int i=0;i<(5.6*8);i++){
    set_text(x,40,"blog.simtronyx.de",BLACK);
    delay(i==0?1000:100);
    if(i<(5.6*8)-1)set_text(x,40,"blog.simtronyx.de",WHITE);
    if((i)<(2.74*8))x-=1;else x+=1;
  }
  delay(250);
  
  display.clearDisplay();    
}

void set_text(int x,int y,String text,int color){
  
  display.setTextColor(color); /
  display.setCursor(x,y);     
  display.println(text);       
  display.display();           
}
