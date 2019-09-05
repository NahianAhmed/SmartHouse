
#include<IRremote.h> 
 int pin = 7;
 static int n=1;
 IRrecv irrecv(pin);
 decode_results results;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 irrecv.enableIRIn();
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(irrecv.decode(&results)){
  
  //Serial.println(results.value, HEX);
  int x = (results.value);
 
  if(x==16){
  
    digitalWrite(13,HIGH);
   
    }
    if(x==3088){
    digitalWrite(13,LOW);
    }
    
  
  
else{
  if(x==2064){
    digitalWrite(12,HIGH);
    }
   if(x==528){
    digitalWrite(12,LOW);
    }
}
    

    
  Serial.println(x);
  irrecv.resume();
   //n=0;
  }
  

}
