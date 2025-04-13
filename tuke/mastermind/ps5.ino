
#include "mastermind.h"
#include "lcd_wrapper.h"
#include "wiring_private.h"

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A1));
    cbi(ADCSRA, ADEN); //setnutie na dig. piny
    pinMode(BTN_1_PIN,INPUT_PULLUP);
    pinMode(BTN_2_PIN,INPUT_PULLUP);
    pinMode(BTN_3_PIN,INPUT_PULLUP);
    pinMode(BTN_4_PIN,INPUT_PULLUP);
    pinMode(BTN_ENTER_PIN,INPUT_PULLUP);
    pinMode(LED_BLUE_1, OUTPUT);
    pinMode(LED_RED_1, OUTPUT);
    pinMode(LED_BLUE_2, OUTPUT);
    pinMode(LED_RED_2, OUTPUT);
    pinMode(LED_BLUE_3, OUTPUT);
    pinMode(LED_RED_3, OUTPUT);
    pinMode(LED_BLUE_4, OUTPUT);
    pinMode(LED_RED_4, OUTPUT);
    lcd_clear();
    lcd_set_cursor(0,0);
    lcd_init();
    delay(2350);
    lcd_clear();
}

void loop() 
{
 char* code = generate_code(false,4);
 
  for(int i=0;i<4;i++)
  {
    Serial.print(code[i]);
   }
    Serial.print("\n");
    play_game(code);  
    free(code);
}
  