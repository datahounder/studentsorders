byte kod_cikla[3]={12, 23, 31};
byte poryadok[3]={1, 2, 3};
double Tbaz;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
  digitalWrite(10, LOW);//blue
  digitalWrite(8, LOW); //green
  digitalWrite(6, LOW);//red
  digitalWrite(4, LOW);//blue
  int i;
  int light; 
  double Tsrl; 
  int j;
  for(i=0; i<7; i++){
   light = analogRead(A0); 
   Tsrl+=light;  
   delay(3000);   
  }  
  for(i=0; i<7; i++){
   light = analogRead(A0); 
   Tsrl+=light;  
   delay(3000);   
  }  
  Tbaz = Tsrl/7;
  
  j=0;
  int del_time=kod_cikla[j]/10;
  del_time*=1000;
  for(i=0; i<7; i++){
   light = analogRead(A0); 
   Tsrl+=light;     
   delay(del_time);  
   Serial.print(poryadok[j]);
   Serial.print(" ");
   Serial.print(kod_cikla[j]);
   Serial.print(" "); 
   Serial.print(light);   
   Serial.print(" "); 
   Serial.print(del_time);   
   Serial.print(" ");
   Serial.print(7);   
   Serial.print(" "); 
   Serial.print(Tbaz+1.037);   
   Serial.print(" \n");   
  }  
  delay(3000);
  
  j=1;
  del_time=kod_cikla[j]%10;
  del_time*=1000;
  for(i=0; i<3; i++){
   light = analogRead(A0); 
   Tsrl+=light;     
   delay(del_time);  
   Serial.print(poryadok[j]);
   Serial.print(" ");
   Serial.print(kod_cikla[j]);
   Serial.print(" "); 
   Serial.print(light);   
   Serial.print(" "); 
   Serial.print(del_time);   
   Serial.print(" ");
   Serial.print(3);   
   Serial.print(" "); 
   Serial.print(Tbaz-1.037);   
   Serial.print(" \n");
  }  
  delay(3000);

  j=2;
  del_time=kod_cikla[j]/10;
  del_time*=1000;
  for(i=0; i<5; i++){
   light = analogRead(A0); 
   Tsrl+=light;     
   delay(del_time);  
   Serial.print(poryadok[j]);
   Serial.print(" ");
   Serial.print(kod_cikla[j]);
   Serial.print(" "); 
   Serial.print(light);   
   Serial.print(" "); 
   Serial.print(del_time);   
   Serial.print(" ");
   Serial.print(5);   
   Serial.print(" "); 
   Serial.print(Tbaz/1.037);   
   Serial.print(" \n");
  }  
  delay(3000); 
 

    while(1){
      digitalWrite(10, HIGH);//blue
      digitalWrite(6, HIGH);//red
      digitalWrite(8, HIGH);//green
      digitalWrite(4, HIGH);//blue
      delay(1759);
      digitalWrite(10, LOW);//blue
      digitalWrite(6, LOW);//red
      digitalWrite(8, LOW);//green
      digitalWrite(4, LOW);//blue
      delay(2011);    
    }
  

}

void loop() {
   
   
  
}
