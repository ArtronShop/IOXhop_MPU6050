/* File              : IOXhop_MPU6050.cpp 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include "IOXhop_MPU6050.h"

MPU6050::MPU6050(int addr) {
	_addr = addr;
}

bool MPU6050::begin() {
	Wire.begin();
	
	// Setting
	Wire.beginTransmission(_addr);
	Wire.write(0x6B);
	Wire.write(0);
	Wire.endTransmission(true);
}

bool MPU6050::Connected() {
	Wire.beginTransmission(_addr);
    return Wire.endTransmission() == 0;
}

bool MPU6050::getValue() {
	Wire.beginTransmission(_addr);
	Wire.write(0x3B);
	if (Wire.endTransmission(false) != 0)
		return false;
	
	Wire.requestFrom(_addr, 14, true); // Request data from MPU6050
	delay(1); // wait 1mS

	if (!Wire.available()) // if not send data in 1mS
		return false;
	
	// Read & Save to buffer
	_AcX_Raw = Wire.read()<<8|Wire.read();
	_AcY_Raw = Wire.read()<<8|Wire.read();
	_AcZ_Raw = Wire.read()<<8|Wire.read();
	_Temp_Raw = Wire.read()<<8|Wire.read();
	_GyX_Raw = Wire.read()<<8|Wire.read();
	_GyY_Raw = Wire.read()<<8|Wire.read();
	_GyZ_Raw = Wire.read()<<8|Wire.read();
	return true;
}

int MPU6050::GetAccelero(int axis, bool raw) {
	switch (axis) {
		case AxisX:
			return raw ? _AcX_Raw : map(_AcX_Raw, -17000, 17000, 0, 179);
		case AxisY:
			return raw ? _AcY_Raw : map(_AcY_Raw, -17000, 17000, 0, 179);
		case AxisZ:
			return raw ? _AcZ_Raw : map(_AcZ_Raw, -17000, 17000, 0, 179);
	}
	return 0;
}

int MPU6050::GetGyro(int axis, bool raw) {
	switch (axis) {
		case AxisX:
			return raw ? _GyX_Raw : _GyX_Raw;
		case AxisY:
			return raw ? _GyY_Raw : _GyY_Raw;
		case AxisZ:
			return raw ? _GyZ_Raw : _GyZ_Raw;
	}
	return 0;
}

int MPU6050::GetTemp(bool raw) {
	return raw ? _Temp_Raw : _Temp_Raw / 340.00 + 36.53;
}

