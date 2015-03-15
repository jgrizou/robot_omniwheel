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
#include <NXTCam.h>


//
// declare the NXShield(s) attached to your Arduino.
//
NXShield    nxshield;
int             nblobs;
uint8_t         color[8];
uint8_t         left[8];
uint8_t         top[8];
uint8_t         bottom[8];
uint8_t         right[8];

//
// declare the i2c devices used on NXShield(s).
//
NXTCam myCam;  // connect NXTCam to BAS1

void setup()
{
  Serial.begin(115200);  // start serial for output
  delay(500); // wait, allowing time to activate the serial monitor

  //Serial.println (__FILE__);
  Serial.println ("Initializing the devices ...");
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
  myCam.init( &nxshield, SH_BAS1 );

  // if there was previous run of this program,
  // the tracking might still be on, so disable it.
  myCam.disableTracking();

  // setup myCam for Object mode and sort by size.
  // also let it begin tracking.
  myCam.selectObjectMode();
  myCam.sortSize();
  myCam.enableTracking();
  delay(1000);


}

#define DELAY_T 0

void loop()
{
  char aa[80];
  char str[256];
  uint8_t  result;
  char str2[20];

  strcpy(aa, myCam.getFirmwareVersion() );
  sprintf (str, "myCam: getFirmwareVersion: %s", aa);
  Serial.println(str);

  strcpy(aa, myCam.getDeviceID() );
  sprintf (str, "myCam: DeviceID: %s", aa);
  Serial.println(str);

  strcpy(aa, myCam.getVendorID() );
  sprintf (str, "myCam: VendorID: %s", aa);
  Serial.println(str);

  Serial.println( "-------------" );

	myCam.issueCommand('J'); // lock buffer
	delay(500);
  myCam.getBlobs(&nblobs, color, left, top, right, bottom);
	delay(500);
	myCam.issueCommand('K'); // unlock buffer
  Serial.println(nblobs);
  for (int i = 0; i < nblobs; i++) {
      sprintf(str, "color[%d]: %d  ", (i + 1), color[i]);
      Serial.print(str);
      str[0] = '\0';
      sprintf(str, "left[%d]: %d  ", (i + 1), left[i]);
      Serial.print(str);
      str[0] = '\0';
      sprintf(str, "top[%d]: %d  ", (i + 1), top[i]);
      Serial.print(str);
      str[0] = '\0';
      sprintf(str, "right[%d]: %d  ", (i + 1), right[i]);
      Serial.print(str);
      str[0] = '\0';
      sprintf(str, "bottom[%d]: %d  ", (i + 1), bottom[i]);
      Serial.println(str);
      str[0] = '\0';
  }
  Serial.println( "-------------" );

}


