# AnalogUVSensor

Arduino library for analogue UV sensor

## Description

![Foo](https://www.tinytronics.nl/shop/image/cache/catalog/products/product-003601/uv-light-sensor-module-200-370nm-80x80w.jpg)
Image courtesy Tinytronics

This small (type-less) UV-sensor is powered by 3.3 .. 5 V so it can be used by almost any microprocessor.

The sensor has an analogue output that is roughly linear with the UV-index (sunlight assumed, see notes)


| Voltage | UV index |
|:-------:|:--------:|
| <0.050  |     0    |
|  0.227  |     1    |
|  0.318  |     2    |
|  0.408  |     3    |
|  0.503  |     4    |
|  0.606  |     5    |
|  0.696  |     6    |
|  0.795  |     7    |
|  0.881  |     8    |
|  0.976  |     9    |
|  1.079  |    10    |
|  1.170> |    11    |

From this table the formula is derived (spreadsheet) which is pretty linear between UV 1 and 11.


### Notes

Note: The sensor is not calibrated and the table is indicative for sunlight (assumption!) 
and therefore not suitable for e.g. medical or industrial usage. 

Note: UV radiation will not go through glass, so inside you will most likely always read zero. 
This may help to calibrate the zero level of the sensor.

Note: depending on the light source used, the table above is incorrect.


### Sensitivity

The sensor is sensitive for wavelengths from 200 - 370 nm, so mostly in UVB and UVA region and less in the UVC. 

https://en.wikipedia.org/wiki/Ultraviolet


## Interface

- **AnalogUVSensor()** Constructor.
- **void begin(uint8_t analogPin, float volts = 5.0, uint16_t maxADC = 1023)** 
set the parameters of the sensor, analogPin, volts and maxADC to specify the internal ADC. Volts and maxADC have a default so these can be omitted.
Note that one needs to reset these parameters if the settings of the internal ADC are 
changed e.g. to INTERNAL_1V1 to change the accuracy.
- **float read(uint8_t times = 1)** Returns the UV index.  
Read the analogue sensor one (or more) times to average the reading. 
This can improve the accuracy of the reading.
- **float mV2index(uint16_t milliVolt)** Returns the UV index.  The conversion formula from milliVolt to the UV index, used internally by the **read()** function.  
This function can also be called with a voltage measured from an external ADC.
- **char index2color(float index)** Converts an index to the first letter of Green, 
Yellow, Orange, Red or Purple. Can be used as indication on a user interface.  
This function can also be called with an index from an other UV index sensor.


#### Power interface

- **void setPowerPin(uint8_t powerPin, bool invert = false)** 
Can be used to control the power of the sensor e.g. for low power mode. 
Optionally one can set the invert flag to **true** to invert the **HIGH LOW** levels.
- **void switchOff()** idem.
- **void switchOn()** idem.


### Future

- verify vs calibrated sensor
- investigate angle sensitivity e.g. if the UV light comes from an angle - cosine law.
- investigate response time to stabilize e.g. does it react fast on clouds.
- investigate with different light sources (UVled, TL, sunlight).
- investigate time needed to first (stable) measurement.
- **index2time()** calculate max exposure time? dangerous?


## Sponsor 

The development of this library is sponsored by [TinyTronics, Netherlands](https://www.tinytronics.nl/shop/nl).
