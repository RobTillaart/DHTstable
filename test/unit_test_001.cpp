//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-20
// PURPOSE: unit tests for the DHT temperature and humidity sensor
//          https://github.com/RobTillaart/DHTstable
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "dht.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  dht dht;

  fprintf(stderr, DHT_LIB_VERSION);

  assertFalse(dht.getDisableIRQ());

  dht.setDisableIRQ(true);
  assertTrue(dht.getDisableIRQ());

  dht.setDisableIRQ(false);
  assertFalse(dht.getDisableIRQ());
}


unittest(test_read)
{
  dht dht;

  assertEqual(-2, dht.read(4));  // DHTLIB_ERROR_TIMEOUT
  assertEqual(-999, dht.humidity);
  assertEqual(-999, dht.temperature);

  assertEqual(-2, dht.read11(5));  // DHTLIB_ERROR_TIMEOUT
  assertEqual(-999, dht.humidity);
  assertEqual(-999, dht.temperature);
}


unittest_main()

// --------
