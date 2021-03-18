#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Adding updates for art installation project DeeDee Morrison Studios
 * Andrew Mulkey 2021
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

// set send and recieve pin numbers
int send1 = 2;
int recieve1 = 3;
int send2 = 4;
int recieve2 = 5;
int send3 = 6;
int recieve3 = 7;
int send4 = 8;
int recieve4 = 9;
int relay = 12; // set GPIO Relay/Opto Coupler value
int triggerThreshold = 3500;

long capPreviousMillis = 0; //start the counter so we can count and keep sampling capacitive touch
long capInterval = 500;     //amount of time you want to wait until you can send a closure again

CapacitiveSensor cs_send1_recieve1 = CapacitiveSensor(send1, recieve1); // 1M resistor between pins 2 & 3, pin 2 is sensor pin, add a wire and or foil
CapacitiveSensor cs_send2_recieve2 = CapacitiveSensor(send2, recieve2); // 1M resistor between pins 4 & 5, pin 4 is sensor pin, add a wire and or foil
CapacitiveSensor cs_send3_recieve3 = CapacitiveSensor(send3, recieve3); // 1M resistor between pins 6 & 7, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor cs_send4_recieve4 = CapacitiveSensor(send4, recieve4); // 1M resistor between pins 8 & 9, pin 8 is sensor pin, add a wire and or foil

void setup()
{
  //cs_send1_recieve1.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1
  //cs_send2_recieve2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 2
  //cs_send3_recieve3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 3
  //cs_send4_recieve4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 4
  cs_send1_recieve1.set_CS_Timeout_Millis(100000);
  cs_send2_recieve2.set_CS_Timeout_Millis(100000);
  cs_send3_recieve3.set_CS_Timeout_Millis(100000);
  cs_send4_recieve4.set_CS_Timeout_Millis(100000);

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); //set d13 as led output for sensing readout
  pinMode(relay, OUTPUT);
}

void loop()
{
  long start = millis();
  long total1 = cs_send1_recieve1.capacitiveSensor(30);
  long total2 = cs_send2_recieve2.capacitiveSensor(30);
  long total3 = cs_send3_recieve3.capacitiveSensor(30);
  long total4 = cs_send4_recieve4.capacitiveSensor(30);
  long capCurrentMillis = millis();

  if (capCurrentMillis - capPreviousMillis > capInterval)
  {
    Serial.println();
    Serial.print(millis() - start); // check on performance in milliseconds
    Serial.print("\t");             // tab character for debug windown spacing
    Serial.print(total1);           // print sensor output 1
    Serial.print("\t");
    Serial.print(total2); // print sensor output 2
    Serial.print("\t");
    Serial.print(total3); // print sensor output 3
    Serial.print("\t");
    Serial.println(total4); // print sensor output 4
    Serial.print("\t");
  }
  bool relayState = false; // set true/false value for how the relay should switch.

  if (capCurrentMillis - capPreviousMillis > capInterval)
  {

    if (total1 >= triggerThreshold or total2 >= triggerThreshold or total3 >= triggerThreshold or total4 >= triggerThreshold) // look to see if the capacitive sensing value is high enough to trigger relay
    {
      capPreviousMillis = capCurrentMillis;
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(relay, HIGH);
      relayState = true;
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(relay, LOW);
      relayState = false;
    }
  }
}