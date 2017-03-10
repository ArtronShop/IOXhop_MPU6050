/* File              : MPU6050_test.ino
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include <IOXhop_MPU6050.h>

MPU6050 mpu(0x68); // Set I2C address, default 0x68

void setup() {
  Serial.begin(9600);
  mpu.begin();

  Serial.println("Accelerometer\tGyroscope\tTemp");
}

void loop() {
  if (mpu.getValue()) {
    Serial.print("(");
    Serial.print(mpu.GetAccelero(AxisX));
    Serial.print(",");
    Serial.print(mpu.GetAccelero(AxisY));
    Serial.print(",");
    Serial.print(mpu.GetAccelero(AxisZ));
    Serial.print(")\t(");
    Serial.print(mpu.GetGyro(AxisX));
    Serial.print(",");
    Serial.print(mpu.GetGyro(AxisY));
    Serial.print(",");
    Serial.print(mpu.GetGyro(AxisZ));
    Serial.print(")\t");
    Serial.print(mpu.GetTemp());
    Serial.println();
  } else {
    Serial.println("MPU6050 not connect !");
  }
  delay(500);
}