
// LightSensorArray.cpp
//
// This is a class for reading from LightSensorArray made by Mindsensors.
// See http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=168

// Initial version: 2013-01-25 by Michael Giles
// Large parts of the code is ported from the NXC library for the device,
// written by Deepak Patil.

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


#include "LightSensorArray.h"


LightSensorArray::LightSensorArray(uint8_t i2c_address)
: NXShieldI2C(i2c_address)
{
}

uint8_t LightSensorArray::issueCommand(char command)
{
	return writeByte(LightSensorArray_Command, (uint8_t)command);
}

bool LightSensorArray::calibrateWhite()
{
	return issueCommand('W');
}

bool LightSensorArray::calibrateBlack()
{
	return issueCommand('B');
}

bool LightSensorArray::sleep()
{
	return issueCommand('D');
}

bool LightSensorArray::wakeUp()
{
	return issueCommand('P');
}

bool LightSensorArray::configureUS()
{
	return issueCommand('A');
}

bool LightSensorArray::configureEurope()
{
	return issueCommand('E');
}

bool LightSensorArray::configureUniversal()
{
	return issueCommand('U');
}

uint8_t* LightSensorArray::getCalibrated()
{
	return (uint8_t *) readString (LightSensorArray_Calibrated, 8);
}

uint8_t* LightSensorArray::getUncalibrated()
{
	return (uint8_t *) readString (LightSensorArray_Uncalibrated, 16);
}

uint8_t* LightSensorArray::getWhiteLimit()
{
	return (uint8_t *)readString (LightSensorArray_White_Limit, 8);
}

uint8_t* LightSensorArray::getBlackLimit()
{
	return (uint8_t *)readString (LightSensorArray_Black_Limit, 8);
}

uint8_t* LightSensorArray::getWhiteCalibration()
{
	return (uint8_t *)readString (LightSensorArray_White_Calibration, 8);
}

uint8_t* LightSensorArray::getBlackCalibration()
{
	return (uint8_t *)readString (LightSensorArray_Black_Calibration, 8);
}
