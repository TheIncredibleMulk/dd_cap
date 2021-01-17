#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


// set send and recieve values
int send = 4;
int recieve = 5;
// set relay control value
int relay = 2;

CapacitiveSensor   cs_send_recieve = CapacitiveSensor(4,5);        // 1M resistor between pins 4 & 5, pin 5 is sensor pin, add a wire and or foil



void setup()  {
   //cs_send_recieve.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   cs_send_recieve.set_CS_Timeout_Millis(100000);

   Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);                         //set d13 as led output for sensing readout
   pinMode(relay, OUTPUT);
   
}


void loop()                    
{
    long start = millis();
       long total3 =  cs_send_recieve.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3

    if (total3 >= 500)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(relay, HIGH);
      delay(1000);
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(relay,LOW);
    }
    
    
    // TESTING AREA 
  
    
    


    /* if (total3 > 20) digitalWrite(LED_BUILTIN, HIGH);
    else delay(1000); 
    digitalWrite(LED_BUILTIN, LOW); */


    // need to set output delay so touch is instant but off is delayed
    

  }