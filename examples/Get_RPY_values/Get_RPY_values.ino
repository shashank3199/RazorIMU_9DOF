/*
  Get_RPY_values.ino - Sample Code to read Yaw, Pitch and Roll values from RazorIMU_9DOF. 
  Copyright (c) 2018 RoboManipal. All Right Reserved.
  File created by : Shashank Goyal
*/

#include <RazorIMU_9DOF.h>

// Declare an object of RazorIMU_9DOF type
RazorIMU_9DOF IMU;

void setup() 
{
	// Initialize the Serials
	Serial1.begin(57600);
	// Attach the IMU Serial
	IMU.AttachIMUSerial(&Serial1);
}

void loop() 
{
	// Update data from IMU
	IMU.UpdateData();
	// Get the YAW value
	float yaw = IMU.GetYaw();         	// Raw YAW value (-180 to 180)
	float pitch = IMU.GetPitch();       // Raw PITCH value (-180 to 180)
	float roll = IMU.GetRoll();         // Raw PITCH value (-180 to 180)
	String msg = "Yaw, Pitch Roll: ";
	msg.concat(yaw);
	msg.concat(" ");
	msg.concat(pitch);
	msg.concat(" ");
	msg.concat(roll);
	// Print this message on the serial
	Serial.println(msg);
}