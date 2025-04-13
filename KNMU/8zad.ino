
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  digitalWrite(10, HIGH);//blue
  digitalWrite(8, HIGH); //green
  digitalWrite(6, HIGH);//red
  digitalWrite(4, HIGH);//yellow
  boolean stringComplete;
  String ard;
  while(!stringComplete)
  {  
    unsigned long currentTime = millis() ;
    unsigned long previousTime = currentTime;
    unsigned long interval = 2103;      
    while ( currentTime - previousTime < interval && stringComplete == false  ) 
    {
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Start!"))
      {
        stringComplete = true;        
        break;
      }  
      digitalWrite(6, HIGH);//red        
    }
    currentTime = millis() ;
    previousTime = currentTime;
    interval = 3104;  
    while ( currentTime - previousTime < interval &&  stringComplete == false ) 
    {
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Start!"))
      {        
        stringComplete = true;
        break;
      }  
       digitalWrite(10, HIGH);//blue
       digitalWrite(8, HIGH); //green
       digitalWrite(6, HIGH);//red     
    }
  }
  boolean door_status = false; 
  int i=0;
  for(i=0; i<4; i++) 
  {
    unsigned long currentTime = millis() ;
    unsigned long previousTime = currentTime;
    unsigned long interval = 4000;  
    while ( currentTime - previousTime < interval && door_status == false ) 
    {
      Serial.print("red");
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Stop!"))
      {
        Serial.print("Stop!");
        door_status = true;
        break;
      }  
       digitalWrite(10, LOW);//blue
       digitalWrite(8, LOW); //green
       digitalWrite(6, LOW);//red            
    }
    currentTime = millis() ;
    previousTime = currentTime;
    interval = 5000;  
    while ( currentTime - previousTime < interval && door_status == false ) 
    {
      Serial.print("red");
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Stop!"))
      {
        Serial.print("Stop!");
        door_status = true;
        break;
      }  
      digitalWrite(6, LOW);//red        
    }
  }
  for(i=0; i<5; i++) 
  {
    unsigned long currentTime = millis() ;
    unsigned long previousTime = currentTime;
    unsigned long interval = 4000;  
    while ( currentTime - previousTime < interval && door_status == false ) 
    {
      Serial.print("blue");
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Stop!"))
      {
        Serial.print("Stop!");
        door_status = true;
        break;
      }  
      digitalWrite(10, HIGH);//blue        
    }
    currentTime = millis() ;
    previousTime = currentTime;
    interval = 5000;  
    while ( currentTime - previousTime < interval && door_status == false ) 
    {
      Serial.print("blue");
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Stop!"))
      {
        Serial.print("Stop!");
        door_status = true;
        break;
      }  
      digitalWrite(10, LOW);//blue       
    }
  }
  for(i=0; i<3; i++) 
  {
    Serial.print("red");
    unsigned long currentTime = millis() ;
    unsigned long previousTime = currentTime;
    unsigned long interval = 4000;  
    while ( currentTime - previousTime < interval && door_status == false ) 
    {
      Serial.print("green");
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Stop!"))
      {
        Serial.print("Stop!");
        door_status = true;
        break;
      }  
      digitalWrite(8, HIGH);//green       
    }
    currentTime = millis() ;
    previousTime = currentTime;
    interval = 5000;  
    while ( currentTime - previousTime < interval && door_status == false ) 
    {
      Serial.print("green");
      currentTime = millis();  
      ard = Serial.readString();
      if(ard.compareTo("Stop!"))
      {
        Serial.print("Stop!");
        door_status = true;
        break;
      }  
      digitalWrite(8, LOW);//green       
    }
  }
}
void loop()
{
}
