/*
Revise (Adafruit Arduino - Lesson 14.)  L12 Actuator
Flight Program: Pulling/Extending two sides A&B of Parawing
Test Program -shorter times- 141108 PullExtendParawingF
*/
 
#include <Servo.h> 
 
int servoPinA = 9;

int servoPinB = 10;

int i = 1;
 
Servo servoA; 

Servo servoB;

volatile boolean cutdown1 = false; //initially no cutdown signal

volatile boolean cutdown2 = false;

volatile boolean cutdownpoint = false;
 
int extend = 140;   // L12 Maximum extention, 30mm, neutral position 
 
void setup() 
{ 
 servoA.attach(servoPinA); 
 
 servoB.attach(servoPinB);
} 
 

 
void loop() 
{ 
  /*
  Put into neutral position- full extention
    140 is max (48 is min)    
  */
  extend=140;
  
                                    
    servoA.write(extend); 
    servoB.write(extend);    
    delay(120); 
  
if (!cutdownpoint) { //if cut down has not occurred keep checking    

 do
   {
     int cutdownlevel = analogRead(A0); //A0 as cutdown input signal pin
     if (cutdownlevel > 335) { // ie > than 1.65 volts
      cutdown1 = true;
     }
     
     //double check signal
      delay(1000); //wait one second to confirm signal
      cutdownlevel = analogRead(A0);
     if (cutdownlevel > 335) {// ie > than 1.65 volts
      cutdown2 = true;
     }
   }while(!cutdown1 || !cutdown2);
  cutdownpoint = true; //cutdown is acknowledged
}  
        
   
  // Hold in neutral test position 2 minutes
 for(i = 1; i < 120; i++)  
    {
    delay(1000); //delay 1 second
    } 
  
  // Pull A for 2 min, scan back from maximum to 0 extention
  for(extend = 140; extend > 48; extend--)    
  {                                
    servoA.write(extend);           
    delay(120);       
  }
 //Hold with A in pulled position 2 min

  for(i = 1; i < 120; i++)  
  {
    delay(1000); //delay 1 second
  }  
 /*
  Put A into neutral position- full extention
   scan from 0 to maximum extention, 48 is min & 140 is max
  */
  for(extend = 48; extend < 140; extend++) 
  
  {                                  
    servoA.write(extend);        
    delay(120);                   
  } 
  // Hold in neutral position 2 minutes
  for(i = 1; i < 120; i++)  
  {
    delay(1000); //delay 1 second
  } 
   // Pull B for 2 min, scan back from maximum to 0 extention
  for(extend = 140; extend > 48; extend--)    
  {                                
    servoB.write(extend);           
    delay(120);       
  }
 //Hold with B in pulled position ~1min

  for(i = 1; i < 120; i++)  
  {
    delay(1000); //delay 1 second
  } 
   /*
  Put B into neutral position- full extention
   scan from 0 to maximum extention, 48 is min & 140 is max
  */
  for(extend = 48; extend < 140; extend++) 
  
  {                                  
    servoB.write(extend);        
    delay(120);                   
  } 
  // Hold in neutral position 2 minutes
  for(i = 1; i < 120; i++)  
  {
    delay(1000); //delay 1 second
  } 
  // Pull A & B for 2 min, scan back from maximum to 0 extention
  for(extend = 140; extend > 48; extend--)    
  {                                
    servoA.write(extend); 
    servoB.write(extend);     
    delay(120);       
  }
 //Hold with A & B in pulled position 2 min

  for(i = 1; i < 120; i++)  
  {
    delay(1000); //delay 1 second
  } 
   /*
  Put A & B into neutral position- full extention
   scan from 0 to maximum extention, 48 is min & 140 is max
  */
  for(extend = 48; extend < 140; extend++) 
  
  {   
    servoA.write(extend);     
    servoB.write(extend);        
    delay(120);                   
  } 
  // Hold in neutral position 2 minutes
  for(i = 1; i < 120; i++)  
  {
    delay(1000); //delay 1 second
  } 
} 

