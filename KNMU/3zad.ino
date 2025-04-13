 String sd2 = "green";
 String sd4 = "red";
 String sd6 = "blue";
 String sd8 = "red";
 String sd10 = "green";
 String sd12 = "blue";
 boolean a1=true, a2=true, a3=true, a4 = true;
void Last()
{ 
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  delay(1589.4);
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);
  delay(2403.4);
 
}

void Green(){
delay(3000);
 Serial.println("Cvet svetodioda: "+sd2);
 Serial.println("Period svecheniya: 2351.09");          
 Serial.println("Period zatuhaniya: 2351.09");          
 Serial.println("Kolichestvo miganii: 7");
for(int i=0; i<7; i++){                
  digitalWrite(2, LOW);
  delay(2351.09); 
  digitalWrite(2, HIGH);
  delay(2351.09); 
}
delay(3000);
}

void setup() {
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);
  while(a4){
  String ard = Serial.readString();
        if(ard=="W1")
        {         
          int z1 = (int) ard[0] / 10;
          int z2 = (int) ard[1] % 10;
          Serial.println("Stroka "+ard);
          Serial.println("Cveta pari svetodiodov: "+sd12+" "+sd10);
          Serial.println("Period svecheniya pari svetodiodov:"+((String)z1));          
          Serial.println("Period zatuhaniya pari svetodiodov:"+((String)z2));          
          Serial.println("Kolichestvo miganii: 3");
          a1 = false;
          for(int i=0; i<3; i++)
          {            
            digitalWrite(12, LOW);
            digitalWrite(10, LOW);
            delay(z2*1000); 
                       
            digitalWrite(12, HIGH);
            digitalWrite(10, HIGH);
            delay(z1*1000);
          }
          Green();
          Last();
        }
          
        else if(ard=="3E")
        {            
            double z1 = ((int) ard[0] / 10+(int) ard[1] % 10)/2+1.2466;
            double z2 = ((int) ard[0] / 10+(int) ard[1] % 10)/1.3206;
            Serial.println("Stroka "+ard);
            Serial.println("Cveta pari svetodiodov: "+sd8+" "+sd6);
            Serial.println("Period svecheniya pari svetodiodov:"+((String)z1));          
            Serial.println("Period zatuhaniya pari svetodiodov:"+((String)z2));          
            Serial.println("Kolichestvo miganii: 4");     
            a2 = false;            
            for(int i=0; i<4; i++)
            {
              digitalWrite(6, LOW);
              digitalWrite(8, LOW);
              delay(z2*1000);
              
              digitalWrite(6, HIGH);
              digitalWrite(8, HIGH);
              
              delay(z1*1000);
            }
             Green();
             Last();
          }
            
          else if(ard=="7J")
          {
              double z1 = abs((int) ard[0] % 10-(int) ard[1] / 10);
              double z2 = abs((int) ard[1] / 10-(int) ard[0] % 10);
              Serial.println("Stroka "+ard);
              Serial.println("Cveta pari svetodiodov: "+sd4+" "+sd2);
              Serial.println("Period svecheniya pari svetodiodov:"+((String)z1));          
              Serial.println("Period zatuhaniya pari svetodiodov:"+((String)z2));          
              Serial.println("Kolichestvo miganii: 2");
              a3 = false;
              for(int i=0; i<2; i++)
              {
                digitalWrite(4, LOW);
                digitalWrite(2, LOW);
                delay(z2*1000);
                
                digitalWrite(4, HIGH);
                digitalWrite(2, HIGH);
                delay(z1*1000);
              }
                Green();
                Last();
       } 
       
       else if(ard.length()>1){
          Serial.println("Cveta pari svetodiodov: "+sd10+" "+sd8);
          Serial.println("Period svecheniya pari svetodiodov: 2870.6");          
          Serial.println("Period zatuhaniya pari svetodiodov: 1378");          
          Serial.println("Kolichestvo miganii: 3");
        for(int i=0; i<3; i++)
        {
          digitalWrite(10, LOW);
          digitalWrite(8, LOW);
          delay(2870.6);
          digitalWrite(10, HIGH);
          digitalWrite(8, HIGH);
          delay(1378);
       }
       a4 = false;
    }
  }



  
  
}

void loop() 
{
}
