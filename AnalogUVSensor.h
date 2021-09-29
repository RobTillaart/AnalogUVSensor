#pragma once
//
//    FILE: AnalogUVSensor.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2021-09-25
// PURPOSE: AnalogUVSensor library
//
// library for analogue UV sensor
//


#include "Arduino.h"

#define ANALOG_UVSENSOR_LIB_VERSION        (F("0.1.0"))


class AnalogUVSensor
{
public:

  AnalogUVSensor();

  void begin(uint8_t analogPin, float volts = 5.0, uint16_t maxADC = 1023);

  float read(uint8_t times = 1);
  float mV2index(uint16_t milliVolt);
  char  index2color(float index);

  //  POWER
  void setPowerPin(uint8_t powerPin, bool invert = false);
  void switchOff() { digitalWrite(_powerPin, _invert ? HIGH : LOW); };
  void switchOn()  { digitalWrite(_powerPin, _invert ? LOW : HIGH); };


private:
  uint8_t  _analogPin = A0;
  uint8_t  _powerPin  = -1;
  bool     _invert    = false;
  float    _volts     = 5;
  uint16_t _maxADC    = 1023;
};


// -- END OF FILE --
