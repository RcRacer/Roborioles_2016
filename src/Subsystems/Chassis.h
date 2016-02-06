// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<CANTalon> leftMotor1;
	std::shared_ptr<CANTalon> leftMotor2;
	std::shared_ptr<CANTalon> rightMotor1;
	std::shared_ptr<CANTalon> rightMotor2;
	std::shared_ptr<RobotDrive> driveMotors;
	std::shared_ptr<Compressor> compressor;
	std::shared_ptr<Solenoid> gShiftSolen;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	Chassis();
	void InitDefaultCommand();
	double deadband(double JoystickValue,double DeadbandCutOff);
	void DriveWithJoysticks();
	void Stop();
 	void Compress();
 	void GShift();
 	void InvertMotors();
 	int MotorDirect;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
