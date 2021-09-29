//
//    FILE: AnalogUVSensor.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2021-09-25
// PURPOSE: AnalogUVSensor library
//
//  HISTORY:
//  0.1.0  2021-09-25  initial version


#include "AnalogUVSensor.h"


AnalogUVSensor::AnalogUVSensor()
{
  // defaults from UNO.
  _analogPin = A0;
  _volts     = 5;
  _maxADC    = 1023;
}


void AnalogUVSensor::begin(uint8_t analogPin, float volts, uint16_t maxADC)
{
  _analogPin = analogPin;
  _volts     = volts;
  _maxADC    = maxADC;
}


float AnalogUVSensor::read(uint8_t times)
{
  uint32_t sum = 0;
  for (int i = 0; i < times; i++)
  {
    sum += analogRead(_analogPin);
  }
  uint16_t milliVolt = sum * (_volts * 1000.0) / (times * _maxADC);
  return mV2index(milliVolt);
}


float AnalogUVSensor::mV2index(uint16_t milliVolt)
{
  if (milliVolt < 50)  return 0.0;
  // linear interpolation between 0..1
  if (milliVolt < 227) return 0.0 + (1.0 * milliVolt - 50.0) / (227.0 - 50.0);
  // linear interpolation between 1..11
  // formula derived with spreadsheet.
  return 0.0104865310 * milliVolt - 1.289154988;
}


char AnalogUVSensor::index2color(float index)
{
  if (index <=  2) return 'G';
  if (index <=  5) return 'Y';
  if (index <=  7) return 'O';
  if (index <= 10) return 'R';
  return 'P';
}


void AnalogUVSensor::setPowerPin(uint8_t powerPin, bool invert)
{
  _invert = invert;
  _powerPin = powerPin;
  pinMode(_powerPin, OUTPUT);
  switchOn();
}

// -- END OF FILE --

