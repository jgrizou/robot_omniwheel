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
#include <NXTVoltMeter.h>

// setup for this example:
// attach external power to NXShield.
// attach NXTVoltMeter to Port BAS1
// Open the Serial terminal to view.

//
// declare the NXShield(s) attached to your Arduino.
//
NXShield    nxshield;

//
// declare the i2c devices used on NXShield(s).
//

VoltMeter  vm  (0x26);

void setup()
{
  char str[256];
/**  Start serial for output
 */
  Serial.begin(115200);  // 
/**  Wait, allowing time to activate the serial monitor
 */ 
  delay(500); // wait, allowing time to activate the serial monitor


/**  Initialize the protocol for NXShield
     It is best to use Hardware I2C (unless you want to use Ultrasonic).
 */
  nxshield.init( SH_SoftwareI2C );
/**  Wait until user presses GO button to continue the program
 */
  Serial.println ("Press GO button to continue");
  nxshield.waitForButtonPress(BTN_GO);
/**  Initialize the i2c sensors.
 */
  vm.init( &nxshield, SH_BAS1 );

}

#define DELAY_T 0

void loop()
{
  char aa[80];        
  char str[256];         //sets length of character string
  int  avolt;            //declares "avolt" variable 
  int  rvolt;            //declares "rvolt" variable 
  int  refV;             //declares "refV" variable
  
/**  Displays Firmeware Version of sensor
*/
  strcpy(aa, vm.getFirmwareVersion() );
  sprintf (str, "VMeter: getFirmwareVersion: %s", aa);
  Serial.println(str);
/**  Displays Device ID of sensor
 */
  strcpy(aa, vm.getDeviceID() );
  sprintf (str, "VMeter: DeviceID: %s", aa);
  Serial.println(str);
/**  Gets and displays Vendor ID of sensor
 */
  strcpy(aa, vm.getVendorID() );
  sprintf (str, "VMeter: VendorID: %s", aa);
  Serial.println(str);
/**  Displays Absolute Voltage value
 */
  avolt = vm.getAVoltage();
  sprintf (str, "VMeter: Absolute Volts:     %d", avolt);
  Serial.println(str);
/**  Displays Relative Voltage value
 */  
  rvolt = vm.getRVoltage();
  sprintf (str, "VMeter: Relative Volts:     %d",  rvolt);
  Serial.println(str);
/**  Displays Reference Voltage value
 */    
  refV = vm.getReference();
  sprintf (str, "VMeter: Reference Voltage:  %d",  refV);
  Serial.println(str);
  
  Serial.println( "-------------" );
  delay (1500);
}


