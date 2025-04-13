// a string to hold incoming data
String inputString = "";
// whether the string is complete         
boolean stringComplete = false, letter = false, digit  = false, symb = false, Rqm = true, pressF=false;


 
byte kod_cikla[6]={14, 41, 21, 13, 32, 41};
byte poryadok[6]={1, 2, 1, 2, 1, 2};
int Tbaz;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  inputString.reserve(200);
  digitalWrite(10, HIGH);//blue
  digitalWrite(8, HIGH); //green
  digitalWrite(6, HIGH);//red
  digitalWrite(4, HIGH);//yellow
  while(!stringComplete)
  {  
    Serial.println("Maket gotov k rabote\n");
    delay(2072);
    String ard = Serial.readString();
    if(ard.length()==17)
    { 
      double decay, glow; 
      int count;      
      int i = 0;
             
      while(ard[i]){   
      if (isalpha(ard[i])) 
          {
            letter=true;
            if(ard[i]=='F'){
              pressF = true;
            }
          }
          else if (isdigit(ard[i])) 
          {
            digit=true;
          }
          else
          { 
            symb = true; 
          }
          if(ard[i]!='R'&&ard[i]!='q'&&ard[i]!='m') 
          {
            Rqm = false; 
          }
          else if(ard[i]='F')
          {
            pressF = true;       
          }
          i++;
       }
       
       if((int)ard[0]+(int)ard[1]+(int)ard[2]>99)
       { 
        int num, sum=0, lenght;
        while(ard[i])
        { 
          num += (int) ard[i]; 
          i++;
        }        
        while(num) sum += num % 10, lenght++, num /= 10;
        decay = (double) sum * 1000 / lenght;  
        glow = ((int) ard[2]/(17-5.00491))*1000;   
        count = (decay + glow)/2;       
      } 
      else if((int)ard[0]+(int)ard[1]+(int)ard[2]+(int)ard[3]+(int)ard[4]<=99&&(int)ard[0]+(int)ard[1]+(int)ard[2]+(int)ard[3]+(int)ard[4]>50)
      {
        int n, first=0;
        while(ard[i])
        { 
          n += (int) ard[i]; 
          i++;
        }        
         while(n>0)
        {
          first=n%10;
          n=n/10;
        }
        decay = first*1000;
        glow = ((int) ard[6]/(17+2.0012))*1000;    
        count = abs(glow-decay);          
      }
      else if((int)ard[0]+(int)ard[1]<=50&&(int)ard[0]+(int)ard[1]>25)
      {
        int num, sum=0, lenght, n, first=0;
        while(ard[i])
        { 
          num += (int) ard[i]; 
          i++;
        }        
        while(num) sum += num % 10, lenght++, num /= 10;
        n = sum/lenght;
        while(n>0)
        {
          first=n%10;
          n=n/10;
        }  
        decay = first*1000/2;  
        glow = ((int) ard[10]/(17+1.2105))*1000;    
        count = (decay + glow)/2;          
      }
      else if((int)ard[0]+(int)ard[1]+(int)ard[2]+(int)ard[3]+(int)ard[4]+(int)ard[5]<=25&&(int)ard[0]+(int)ard[1]+(int)ard[2]+(int)ard[3]+(int)ard[4]+(int)ard[5]>10)
      {
        int num, sum=0, lenght, n, first=0;
        while(ard[i])
        { 
          num += (int) ard[i]; 
          i++;
        }        
        while(num) sum += num % 10, lenght++, num /= 10;
        n = sum/lenght;
        while(n>0)
        {
          first=n%10;
          n=n/10;
        }  
        decay = (first-1)*1000;
        glow = ((int) ard[10]/(17-2.054))*1000;           
        num = (int) glow;
        sum = 0;
        lenght = 0;
        while(num) sum += num % 10, lenght++, num /= 10; 
        count = sum/lenght;                
      }
      else if((int)ard[0]+(int)ard[1]+(int)ard[2]+(int)ard[3]+(int)ard[4]+(int)ard[5]+(int)ard[6]<=10&&(int)ard[0]+(int)ard[1]+(int)ard[2]+(int)ard[3]+(int)ard[4]+(int)ard[5]+(int)ard[6]>0)
      {
        int num, sum=0, lenght, n, first=0;
        while(ard[i])
        { 
          num += (int) ard[i]; 
          i++;
        }        
        while(num) sum += num % 10, lenght++, num /= 10;
        n = sum/lenght;
        while(n>0)
        {
          first=n%10;
          n=n/10;
        }  
        decay = (first+1)*1000;         
        num = (int) decay;
        sum = 0;
        lenght = 0;
        while(num) sum += num % 10, lenght++, num /= 10;        
        glow = ((int) ard[5]/17)*1000;    
        count = sum/lenght;                
      }
        digitalWrite(10, LOW);//blue
        digitalWrite(8, LOW); //green
        digitalWrite(6, LOW);//red
        digitalWrite(4, LOW);//yellow
      if(letter = true)      
      { 
        Serial.println("green red \n");
        Serial.println(glow);
        Serial.println("\n");
        Serial.println(decay);
        Serial.println("\n");
        Serial.println(count);
        Serial.println("\n");
        Serial.println(1);
        Serial.println("\n");
        for(i=0; i<count; i++)
        {       
          digitalWrite(8, HIGH); //green
          digitalWrite(6, HIGH);//red
          delay(glow);
          digitalWrite(8, LOW); //green
          digitalWrite(6, LOW);//red
          delay(decay);
        }    
         delay(3000);           
      }
      if(digit = true)
      { 
        Serial.println("yellow blue \n");
        Serial.println(glow);
        Serial.println("\n");
        Serial.println(decay);
        Serial.println("\n");
        Serial.println(count);
        Serial.println("\n");
        Serial.println(1);
        Serial.println("\n");
        for(i=0; i<count; i++)
        {       
          digitalWrite(4, HIGH); //yellow
          digitalWrite(10, HIGH);//blue
          delay(glow);
          digitalWrite(4, LOW); //yellow
          digitalWrite(10, LOW);//blue
          delay(decay);
        }  
         delay(3000);      
      }
      if(symb = true)
      { 
        Serial.println("yellow green \n");
        Serial.println(glow);
        Serial.println("\n");
        Serial.println(decay);
        Serial.println("\n");
        Serial.println(count);
        Serial.println("\n");
        Serial.println(1);
        Serial.println("\n");
        for(i=0; i<count; i++)
        {       
          digitalWrite(4, HIGH); //yellow
          digitalWrite(8, HIGH); //green
          delay(glow);
          digitalWrite(4, LOW); //yellow
          digitalWrite(8, LOW);//green
          delay(decay);
        }   
         delay(3000);     
      }
      if(symb = false)
      {  
        Serial.println("blue green \n");
        Serial.println(glow);
        Serial.println("\n");
        Serial.println(decay);
        Serial.println("\n");
        Serial.println(count);
        Serial.println("\n");
        Serial.println(1);
        Serial.println("\n");
        for(i=0; i<count; i++)
        {       
          digitalWrite(10, HIGH); //blue
          digitalWrite(8, HIGH); //green
          delay(glow);
          digitalWrite(10, LOW); //blue
          digitalWrite(8, LOW);//green
          delay(decay);
        }     
         delay(3000);   
      }
      if(pressF = true)
      { 
        Serial.println("yellow blue \n");
        Serial.println(glow);
        Serial.println("\n");
        Serial.println(decay);
        Serial.println("\n");
        Serial.println(count);
        Serial.println("\n");
        Serial.println(1);
        Serial.println("\n");
        for(i=0; i<count; i++)
        {       
           digitalWrite(4, HIGH); //yellow
          digitalWrite(10, HIGH);//blue
          delay(glow);
          digitalWrite(4, LOW); //yellow
          digitalWrite(10, LOW);//blue
          delay(decay);
        }      
         delay(3000);  
      }
       for(i=0; i<3; i++)
        {       
          digitalWrite(4, HIGH); //yellow
          digitalWrite(10, HIGH);//blue
          digitalWrite(8, HIGH); //green
          digitalWrite(6, HIGH);//red
          delay(2003.4);
          digitalWrite(4, LOW); //yellow
          digitalWrite(10, LOW);//blue
          digitalWrite(8, LOW); //green
          digitalWrite(6, LOW);//red
          delay(3204.15);
        } 
        stringComplete = true;                 
    }
  }
}

void loop() {
   
   
  
}
