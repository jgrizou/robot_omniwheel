
// PFMate.cpp
//
// This is a class for controlling the PF Motor Controller, made by Mindsensors.
// See http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=107 .

// Initial version: 2010-06-17 by Andrew Sylvester
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


#include "PFMate.h"



PFMate::PFMate(uint8_t i2c_address)
: NXShieldI2C(i2c_address)
{
}
uint8_t PFMate::issueCommand(char command)
{
	return writeByte(PF_Commmand, (uint8_t)command);
}

bool PFMate::sendSignal()
{
	return issueCommand('G');
}

bool PFMate::setChannel(uint8_t channel)
{
	return writeByte(PF_Channel, (uint8_t)channel);
}

bool PFMate::setControl(uint8_t control)
{
	return writeByte(PF_Control, (uint8_t)control);
}

bool PFMate::setOperationA(uint8_t operation)
{
	return writeByte(PF_Operation_A, (uint8_t)operation);
}

bool PFMate::setOperationB(uint8_t operation)
{
	return writeByte(PF_Operation_B, (uint8_t)operation);
}

bool PFMate::setSpeedA(uint8_t speed)
{
	return writeByte(PF_Speed_A, (uint8_t)speed);
}

bool PFMate::setSpeedB(uint8_t speed)
{
	return writeByte(PF_Speed_B, (uint8_t)speed);
}

void PFMate::controlMotor(
		uint8_t channel,			    // PF_Channel_1, 2, 3, or 4
		uint8_t control,				// PF_Contol_Both, A, or B
		uint8_t operation,				// PF_Operation_Forward, Reverse, Float, or Brake
		uint8_t speed)		     		// [1, 7] or PF_Speed_Full, Medium, or Slow

{
	if (control == PF_Contol_Both)
	{
		setOperationA(operation);
		setSpeedA(speed);
		setOperationB(operation);
		setSpeedB(speed);
	}

	else if (control == PF_Contol_A)
	{
		setOperationA(operation);
		setSpeedA(speed);
	}

	else if (control == PF_Contol_B)
	{
		setOperationB(operation);
		setSpeedB(speed);
	
	}
}

