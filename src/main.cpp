#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Adding updates for art installation project.
 * Andrew Mulkey 2021
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


// set send and recieve pin numbers
int send1 = 2;
int recieve1 = 3;
int send2 = 5;
int recieve2 = 4;
int send3 = 7;
int recieve3 = 6;
int send4 = 9;
int recieve4 = 8;
// set GPIO Relay/Opto Coupler value
int relay = 12;

CapacitiveSensor   cs_send1_recieve1 = CapacitiveSensor(send1,recieve1);        // 1M resistor between pins 6 & 3, pin 3 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_send2_recieve2 = CapacitiveSensor(send2,recieve2);        // 1M resistor between pins 7 & 4, pin 5 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_send3_recieve3 = CapacitiveSensor(send3,recieve3);        // 1M resistor between pins 8 & 5, pin 5 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_send4_recieve4 = CapacitiveSensor(send4,recieve4);        // 1M resistor between pins 11 & 9, pin 5 is sensor pin, add a wire and or foil

void setup()  {
  //cs_send1_recieve1.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1
  //cs_send2_recieve2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 2
  //cs_send3_recieve3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 3
  //cs_send4_recieve4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 4
  cs_send1_recieve1.set_CS_Timeout_Millis(100000);
  cs_send2_recieve2.set_CS_Timeout_Millis(100000);
  cs_send3_recieve3.set_CS_Timeout_Millis(100000);
  cs_send4_recieve4.set_CS_Timeout_Millis(100000);

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);                         //set d13 as led output for sensing readout
  pinMode(relay, OUTPUT);
   
}


void loop()                    
{
    long start = millis();
      long total1 =  cs_send1_recieve1.capacitiveSensor(30);
      long total2 =  cs_send2_recieve2.capacitiveSensor(30);
      long total3 =  cs_send3_recieve3.capacitiveSensor(30);
      long total4 =  cs_send4_recieve4.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

  Serial.print(total1);                // print sensor output 1
  Serial.print("\t");

  Serial.print(total2);                // print sensor output 2
  Serial.print("\t");
  

  Serial.print(total3);                // print sensor output 3
  Serial.print("\t");

  
  Serial.println(total4);                // print sensor output 4
  
  bool relayState = false;              // set true/false value for how the relay should switch. 


    if (total1 >= 500)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(relay, HIGH);
      relayState = true;
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(relay,LOW);
      relayState = false;
    }
    
    bool switchFunction (bool sense,)
    {
      if (relayState = true){
        digitalWrite(relay, HIGH);

      }
    }
    // TESTING AREA 
  
    
    


    /* if (total3 > 20) digitalWrite(LED_BUILTIN, HIGH);
    else delay(1000); 
    digitalWrite(LED_BUILTIN, LOW); */


    // need to set output delay so touch is instant but off is delayed
    

  }