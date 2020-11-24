#include <Wire.h>       //include Wire.h I2C library

byte error, address;    // define variables for error and I2C address
int nDevices;


void setup()
{
  Wire.begin();         // Initialize the I2C to enable communication on the bus
  Serial.begin(9600);   // Intitialize the serial monitor to display results later
}


void loop()
{
  Serial.println("Scanning...");

  nDevices = 0;

  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("No I2C devices found");
  else
    Serial.println("done");

  delay(5000); // wait 5 seconds for the next I2C scan
}
