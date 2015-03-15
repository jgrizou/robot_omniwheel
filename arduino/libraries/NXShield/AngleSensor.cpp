// AngleSensor.cpp
// 
// This is a class for controlling the AngelSensor, made by Mindsensors.
// See http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=173

// Initial version: 2012-09-17 by Deepak Patil

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



#include "AngleSensor.h"

AngleSensor::AngleSensor(uint8_t i2c_address)
 : NXShieldI2C(i2c_address)
{

}


long      AngleSensor::getAngle()
{
  return readLong(ANGLE);
}

long      AngleSensor::getRawReading()
{

  return readLong(RAW_READING);
}

void AngleSensor::reset()
{
	writeByte(0x41, (uint8_t)'r');
}
