//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-01-01
// PURPOSE: unit tests for the temperature library
//          https://github.com/RobTillaart/Temperature
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "temperature.h"



unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_conversion)
{
  fprintf(stderr, "VERSION: %s\n", TEMPERATURE_VERSION);
  
  assertEqualFloat(-40, Fahrenheit(-40), 0.0001);
  assertEqualFloat(-40, Celsius(-40), 0.0001);
  assertEqualFloat(273.15, Kelvin(0), 0.0001);
}


unittest(test_dewpoint)
{
  assertEqualFloat(0, dewPoint(20, 50), 0.0001);
  assertEqualFloat(0, dewPointFast(20, 50), 0.0001);
  assertEqualFloat(0, humidex(20, 10),  0.0001);
}


unittest(test_heatIndex)
{
  assertEqualFloat(0, heatIndex(20, 50), 0.0001);
  assertEqualFloat(0, heatIndexC(20, 50), 0.0001);
}


unittest(test_windChill)
{
  assertEqualFloat(0, WindChill_F_mph (100, 10, true), 0.0001);
  assertEqualFloat(0, WindChill_C_kmph(37, 10, true),  0.0001);
  assertEqualFloat(0, WindChill_C_mps (37, 10, true),  0.0001);
  assertEqualFloat(0, WindChill_F_mph (100, 10, false), 0.0001);
  assertEqualFloat(0, WindChill_C_kmph(37, 10, false),  0.0001);
  assertEqualFloat(0, WindChill_C_mps (37, 10, false),  0.0001);
}


unittest_main()

// --------
