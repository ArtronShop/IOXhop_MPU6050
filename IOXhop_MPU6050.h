/* File              : IOXhop_MPU6050.h  
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include <Arduino.h>
#include <Wire.h>

enum {
	AxisX,
	AxisY,
	AxisZ
} __Axis_h;

class MPU6050 {
	public:
		MPU6050(int addr) ;
		bool begin(void) ;
		bool Connected(void) ;
		bool getValue(void) ;
		int GetAccelero(int axis, bool raw=false) ;
		int GetGyro(int axis, bool raw=false) ;
		int GetTemp(bool raw=false) ;
		
	private:
		int _addr, _AcX_Raw, _AcY_Raw, _AcZ_Raw, _Temp_Raw, _GyX_Raw, _GyY_Raw, _GyZ_Raw;

}
;
   