//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-06
// PURPOSE: unit tests for the SHT31 temperature and humidity sensor
//          https://github.com/RobTillaart/SHT31
//          https://www.adafruit.com/product/2857
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

#define A0      0

#include "Arduino.h"
#include "AnalogUVSensor.h"


unittest_setup()
{
}


unittest_teardown()
{
}


unittest(constructor)
{
  fprintf(stderr, "VERSION: %s\n",  ANALOG_UVSENSOR_LIB_VERSION);
  AnalogUVSensor AUV;

  AUV.begin(A0);
  fprintf(stderr, "UV: %f\n", AUV.read());
}


unittest(mv2index)
{
  AnalogUVSensor AUV;

  AUV.begin(A0);
  float uvi;
  for (uint16_t milliVolt = 0; milliVolt < 1200; milliVolt += 50)
  {
    uvi = AUV.mV2index(milliVolt);
    fprintf(stderr, "%d\t %f\n", milliVolt, uvi);
  }
}

unittest(index2color)
{
  AnalogUVSensor AUV;

  AUV.begin(A0);
  char c;
  for (uint8_t idx = 0; idx < 12; idx++)
  {
    c = AUV.index2color(idx);
    fprintf(stderr, "%d\t %c\n", idx, c);
  }
}



unittest_main()


// -- END OF FILE --
