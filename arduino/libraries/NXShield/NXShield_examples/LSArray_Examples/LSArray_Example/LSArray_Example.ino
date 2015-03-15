/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/*
For beginners tutorial (and user guide) visit:
http://www.openelectrons.com/docs/viewdoc/1
*/

#include <Wire.h>
#include <NXShield.h>
#include <LightSensorArray.h>

// setup for this example:
// attach external power to NXShield.
// attach LightSensorArray to Port BAS1
// Open the Serial terminal to view.

//
// declare the NXShield(s) attached to your Arduino.
//
NXShield    nxshield;

//
// declare the i2c devices used on NXShield(s).
//
LightSensorArray lsa (0x14);

void setup()
{
  char str[256];

  Serial.begin(115200);  // start serial for output
  delay(500); // wait, allowing time to activate the serial monitor

//  Serial.println (__FILE__);
//  Serial.println ("Initializing the devices ...");
  //
  // Initialize the protocol for NXShield
  // It is best to use Hardware I2C (unless you want to use Ultrasonic).
  //
  nxshield.init( SH_SoftwareI2C );

  //
  // Wait until user presses GO button to continue the program
  //
  Serial.println ("Press GO button to continue");
  nxshield.waitForButtonPress(BTN_GO);

  //
  // Initialize the i2c sensors.
  //
  lsa.init( &nxshield, SH_BAS1 );
}

#define DELAY_T 0

void loop()
{
  char aa[80];
  char str[256];        //declare character string length           
  uint8_t *cal;         //declare "cal" pointer
  int  i;               //declare integer "i"
  
 /** Display Firmware Version */
  strcpy(aa, lsa.getFirmwareVersion() );
  sprintf (str, "LSArray: getFirmwareVersion: %s", aa);
  Serial.println(str);
/** Display Device ID */
  strcpy(aa, lsa.getDeviceID() );
  sprintf (str, "LSArray: DeviceID: %s", aa);
  Serial.println(str);
/** Display Vendor ID */
  strcpy(aa, lsa.getVendorID() );
  sprintf (str, "LSArray: VendorID: %s", aa);
  Serial.println(str);
/** Display 8 different light sensor values */  
  cal = lsa.getCalibrated();
  for (i=0; i< 8; i++)
  {    
    sprintf (str, "LSArray: sensor array: %d = %d", i, cal[i] );
    Serial.println(str);
  }

  Serial.println( "-------------" );
  delay (1500);
}



