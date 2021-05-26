//
//    FILE: dht12_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 1.0.0
// PURPOSE: DHT library test sketch for DHT12 && Arduino
//     URL: https://github.com/RobTillaart/DHTstable
//
//  HISTORY:
//  1.0.0   2021-05-26  class name changed to DHTStable  (breaking change)
//
//  0.2.0   use getHumidity() and getTemperature()
//  0.1.1   add URL in header


#include "DHTStable.h"

DHTStable DHT;

#define DHT12_PIN 5


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop()
{
  // READ DATA
  Serial.print("DHT12, \t");
  int chk = DHT.read12(DHT12_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
      Serial.print("OK,\t"); 
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      Serial.print("Checksum error,\t"); 
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      Serial.print("Time out error,\t"); 
      break;
    default: 
      Serial.print("Unknown error,\t"); 
      break;
  }
  // DISPLAY DATA
  Serial.print(DHT.getHumidity(), 1);
  Serial.print(",\t");
  Serial.println(DHT.getTemperature(), 1);

  delay(2000);
}

// END OF FILE
