#include <Arduino.h>

#include "mastermind.h"

#include "lcd_wrapper.h"
#include "wiring_private.h"


void play_game(char *secret){
  char **history = (char **)calloc(100,sizeof(char*));
  for(int i = 0; i < 100; i++)
  history[i] = (char*)calloc(1,sizeof(char));


  int vstup=0;
  
  
  while(1){
 
  char* guess = (char*)calloc(strlen(secret)+2,sizeof(char));
  
int polohamainbutt=0;
int mainbutt=0;
mainbutt=digitalRead(BTN_ENTER_PIN);
Serial.print("potvrdzovacie tlacidlo:   ");
Serial.println(mainbutt);


   int hodnota1=0;
int postlacidlo1 = 0;

int hodnota2=0;
int postlacidlo2=0;

int hodnota3=0;
int postlacidlo3=0;

int hodnota4=0;
int postlacidlo4=0;


 if(vstup<10)
{char enter[] = { vstup+48, '\0'};
 lcd_print_at(0,0,enter);
 }
  if(vstup>9 && vstup<20)
{char enter[] = {'1', vstup+38, '\0'};
 lcd_print_at(0,0,enter);
 }
    
    char guess1[] = {48, '\0'};
    lcd_print_at(3,0,guess1);
    char guess2[] = {48, '\0'};
    lcd_print_at(5,0,guess2);
    char guess3[] = {48, '\0'};
    lcd_print_at(7,0,guess3);
    char guess4[] = {48, '\0'};
    lcd_print_at(9,0,guess4);
       
    int buttonhelper=0;
    while(buttonhelper==0){
      int tlacidlo1 = digitalRead(BTN_1_PIN); 
      if (tlacidlo1==LOW && postlacidlo1==HIGH) 
      if (tlacidlo1 == LOW) 
        {
          hodnota1++;
          if(hodnota1>9)
          {hodnota1=0;}
          Serial.print("count ");
          Serial.println(hodnota1);
          char guess1[] = {hodnota1+48, '\0'};
          lcd_print_at(3,0,guess1);  
      }
          guess[0]=hodnota1+48;
          postlacidlo1=tlacidlo1;
          delay(10);
            
      int tlacidlo2 = digitalRead(BTN_2_PIN);
      if (tlacidlo2==LOW && postlacidlo2==HIGH) 
      if (tlacidlo2 == LOW) 
        {
          hodnota2++;
          if(hodnota2>9)
          {hodnota2=0;}
          Serial.print("hodnota2 ");
          Serial.println(hodnota2);
          char guess2[] = {hodnota2+48, '\0'};
          lcd_print_at(5,0,guess2);
       }
          guess[1]=hodnota2+48;
          postlacidlo2=tlacidlo2;
          delay(10);
       int tlacidlo3 = digitalRead(BTN_3_PIN);
       if (tlacidlo3==LOW && postlacidlo3==HIGH)
       if (tlacidlo3 == LOW) 
         {
           hodnota3++;
           if(hodnota3>9)
           {hodnota3=0;}
           Serial.print("hodnota3 ");
           Serial.println(hodnota3);
           char guess3[] = {48+hodnota3, '\0'};
           lcd_print_at(7,0,guess3);
         }
           guess[2]=hodnota3+48; 
           postlacidlo3=tlacidlo3;
           delay(10);
       int tlacidlo4 = digitalRead(BTN_4_PIN);
       if (tlacidlo4==LOW && postlacidlo4==HIGH) 
       if (tlacidlo4 == LOW) 
         {
           hodnota4++;
           if(hodnota4>9)
           {hodnota4=0;}
           Serial.print("hodnota4 ");
           Serial.println(hodnota4);      
           char guess4[] = {hodnota4+48, '\0'};
           lcd_print_at(9,0,guess4);
          }
           guess[3]=hodnota4+48; 
           postlacidlo4=tlacidlo4;
           delay(10);
    if(tlacidlo4==LOW && tlacidlo3==LOW )
                { render_history(secret,history,vstup);
                char clean[]={' ',' ', ' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};
                lcd_print_at(0,1,clean);                                              
                 delay(10);
                } 
                mainbutt=digitalRead(BTN_ENTER_PIN);
                if(mainbutt==1){
                  buttonhelper=1;
                  }     
              
}

while(1)
{
  mainbutt=digitalRead(BTN_ENTER_PIN);
  if(mainbutt==HIGH)
  break;
  }
  history[vstup][0]=guess[0];
history[vstup][1]=guess[1];
history[vstup][2]=guess[2];
history[vstup][3]=guess[3];

polohamainbutt=mainbutt;
vstup++;

if(vstup==15)
{
  while(1)
  { 
    //lose
    lcd_clear();
    while(1)
    {
  char prehra[] = { 'P','R','E', 'H', 'R','A','L',' ','S','I','!', '\0'};
 lcd_print_at(0,0,prehra);
  lcd_print_at(9,1,secret);
  char prehra1[] = { 'K','O','D', ' ', 'B','O','L', '\0'};
  lcd_print_at(0,1,prehra1);
  
    }
  }
 }

lcd_set_cursor(0,0);

Serial.print("eneter count :    ");
Serial.println(vstup);

 if(vstup<10)
{char enter[] = { vstup+48, '\0'};
 lcd_print_at(0,0,enter);
 }
  if(vstup>9 && vstup<20)
{char enter[] = {'1', vstup+38, '\0'};
 lcd_print_at(0,0,enter);
 }




Serial.println("pocet stlaceni;    ");
Serial.println(vstup);
for(int i=0;i<4;i++)
{
  Serial.print("secret ::   ");
  Serial.print(secret[i]);
  }
  Serial.print("\n");
  for(int i=0;i<4;i++)
{
  Serial.print("guess ::   ");
  Serial.print(guess[i]);
  }
   Serial.print("\n");
   lcd_set_cursor(12,0);
    get_score(secret,guess,0,0);
 }
 
 }

void render_history(char* secret,char** history,const int entry)
{
  int help=entry-1;
  int mainbutt=digitalRead(BTN_ENTER_PIN);
  int tlacidlo1 = digitalRead(BTN_1_PIN);
  int postlacidlo1=0;
  int tlacidlo2 = digitalRead(BTN_2_PIN);
  int postlacidlo2=0;
  if(mainbutt==HIGH){
    delay(200);
    }
    mainbutt=digitalRead(BTN_ENTER_PIN);
  while(mainbutt==HIGH)
  {
    
    tlacidlo1 = digitalRead(BTN_1_PIN);
    if (tlacidlo1==LOW && postlacidlo1==HIGH) 
      if (tlacidlo1 == LOW) 
      {
        if(help>0){
          help--;
        }             
      }
      postlacidlo1=tlacidlo1;
      tlacidlo2 = digitalRead(BTN_2_PIN);   
      if (tlacidlo2==LOW && postlacidlo2==HIGH)     
      if (tlacidlo2 == LOW){
        if(help<entry-1){
          help++;
        }
      }
    postlacidlo2=tlacidlo2;  
    Serial.print("postlacidlo1:    ");
    Serial.println(postlacidlo1);
    Serial.print("tlacidlo1:    ");
    Serial.println(tlacidlo1);
    Serial.print("help index:  ");
    Serial.println(help);
    mainbutt=digitalRead(BTN_ENTER_PIN);    

    if(help<0 && mainbutt==HIGH){
    char error[]={'C','H','Y','B','A','\0'};

    lcd_set_cursor(0,1);
    lcd_print(error);
    delay(500);
    char error1[]={' ',' ',' ', ' ', '\0'};
    lcd_set_cursor(0,1);
    lcd_print(error1);
    }else{
      lcd_set_cursor(0,1);
      if(help<10){
        char index[]={help+48,' ','\0'};
        lcd_print(index);
        }else{
          char index10[]={'1',help+38,'\0'};
       lcd_print(index10);
       }
       
       char guess[]={history[help][0],history[help][1],history[help][2],history[help][3],'\0'};
       lcd_print_at(3,1,guess); 
       lcd_set_cursor(12,1);
       get_score(secret,guess,0,0);
       //delay(500);
       mainbutt=digitalRead(BTN_ENTER_PIN);
    }
  }
}


void turn_off_leds(){
  digitalWrite(LED_RED_1,LOW);
  digitalWrite(LED_BLUE_1,LOW);
  digitalWrite(LED_RED_2,LOW);
  digitalWrite(LED_BLUE_2,LOW);
  digitalWrite(LED_RED_3,LOW);
  digitalWrite(LED_BLUE_3,LOW);
  digitalWrite(LED_RED_4,LOW);
  digitalWrite(LED_BLUE_4,LOW);
  }
 


void render_leds(const int peg_a, const int peg_b)
{
  
  
    delay(50);

char cervena[]={peg_a+48,'A','\0'};
char modra[]={peg_b+48,'B','\0'};
lcd_print(cervena);
lcd_print(modra);
   if(peg_a==0 && peg_b==0){
    turn_off_leds();    
    }
  if(peg_a==1)
  {
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
  }
   if(peg_a==2)
  {
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_RED_2,HIGH);
  }
  if(peg_a==3)
  {
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_RED_2,HIGH);
    digitalWrite(LED_RED_3,HIGH);
  }
    if(peg_a==4)
  {
    while(1){      
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_RED_2,HIGH);
    digitalWrite(LED_RED_3,HIGH);
    digitalWrite(LED_RED_4,HIGH);
    delay(500);
    digitalWrite(LED_RED_1,LOW);
    digitalWrite(LED_RED_2,LOW);
    digitalWrite(LED_RED_3,LOW);
    digitalWrite(LED_RED_4,LOW);
    digitalWrite(LED_BLUE_1,HIGH);
    digitalWrite(LED_BLUE_2,HIGH);
    digitalWrite(LED_BLUE_3,HIGH);
    digitalWrite(LED_BLUE_4,HIGH);
    delay(500);
    digitalWrite(LED_BLUE_1,LOW);
    digitalWrite(LED_BLUE_2,LOW);
    digitalWrite(LED_BLUE_3,LOW);
    digitalWrite(LED_BLUE_4,LOW);
    lcd_clear();
    lcd_set_cursor(0,0);
   char vyhra[] = {'S','L','A','B','Y',' ','K','O','D','\0'};
   lcd_print(vyhra);
   lcd_set_cursor(0,1);
   char vyhra2[] = {'V','Y','H','R','A','L',' ','S','I','\0'};
   lcd_print(vyhra2);
    }
  }
 
  if(peg_b==1)
  {
    turn_off_leds();
    digitalWrite(LED_BLUE_1,HIGH);}
   if(peg_b==2)
  {
    turn_off_leds();
    digitalWrite(LED_BLUE_2,HIGH);
    digitalWrite(LED_BLUE_1,HIGH);
  }
  if(peg_b==3)
  {
    turn_off_leds();
    digitalWrite(LED_BLUE_1,HIGH);
    digitalWrite(LED_BLUE_2,HIGH);
    digitalWrite(LED_BLUE_3,HIGH);
  }
    if(peg_b==4)
  {
    turn_off_leds();
    digitalWrite(LED_BLUE_1,HIGH);
    digitalWrite(LED_BLUE_2,HIGH);
    digitalWrite(LED_BLUE_3,HIGH);
    digitalWrite(LED_BLUE_4,HIGH);
  }

  if(peg_a==1 && peg_b==1){
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_BLUE_2,HIGH);
  }
  if(peg_a==1 && peg_b==2){
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_BLUE_2,HIGH);
    digitalWrite(LED_BLUE_3,HIGH);
  }
  if(peg_a==1 && peg_b==3){
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_BLUE_2,HIGH);
    digitalWrite(LED_BLUE_3,HIGH);
    digitalWrite(LED_BLUE_4,HIGH);
  }
   if(peg_a==2 && peg_b==1){
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_RED_2,HIGH);
    digitalWrite(LED_BLUE_3,HIGH);
  }
   if(peg_a==2 && peg_b==2){
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_RED_2,HIGH);
    digitalWrite(LED_BLUE_3,HIGH);
    digitalWrite(LED_BLUE_4,HIGH);
  }
   if(peg_a==3 && peg_b==1){
    turn_off_leds();
    digitalWrite(LED_RED_1,HIGH);
    digitalWrite(LED_RED_2,HIGH);
    digitalWrite(LED_RED_3,HIGH);
    digitalWrite(LED_BLUE_4,HIGH);
  }
     
}

char *generate_code(bool repeat, int length){
    if(repeat==false){
      if(length>10){
        return NULL;
        }
    }
    if(length<1){
      return NULL;
    }
    
    int i=0;
    char* code = (char*)calloc(length+2,sizeof(char));
    if (repeat==true){
      for(i=0;i<length;i++){
        code[i]=random(10)+48;
        }
    }
    if(repeat==false){
      int j=0;
      for(i=0;i<length;i++){
        code[i]=random(10)+48;
      }
      for(int k=0;k<100;k++){
        for(i=0;i<length;i++){
          j=length;
          while(j>-1){
            if(i!=j){
              while(code[i]==code[j]){
                code[i]=random(10)+48; 
              }
            }
            j--;
          }
        }
      }
    }
  return code;
} 
  
void get_score(const char* secret,const char* guess,int* peg_a,int* peg_b){
  int i=0;
  int j=0;
  int red=peg_a;
  int blue=peg_b;
  char skip[4];
  for(i=0;i<strlen(guess);i++)
  {
    if(guess[i]==secret[i]){
      red++;
      skip[i]=guess[i];
    }
  }
 
  for(int x=0;x<strlen(guess);x++){
         for(int y=0;y<strlen(guess);y++){
            if(x==y){
              continue;
            }
            
            if(secret[x]==guess[y] && secret[x]!=skip[0] && secret[x]!=skip[1] && secret[x]!=skip[2] && secret[x]!=skip[3]){
              blue++;
              break;
            }
         }
   }
    
    
      render_leds(red,blue);
}
    
  