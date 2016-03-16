// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoDriveForward2.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoDriveForward2::AutoDriveForward2(double distance, double speed): Command() {
    m_distance = distance;
    m_speed = speed;
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetTimeout(6);
	completed = false;
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoDriveForward2::Initialize() {
	// distance * 12 /(3.1415 * diameter)*1000.0 == distance * 1273 - went to far
	// 1 foot (12 inches) went 1600
	// 10 foot (120 inches) went 13076

	m_distance=abs(m_distance*1273);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveForward2::Execute() {
	printf("Running AutoDrive\n");
	completed = Robot::chassis->driveFeet2(m_distance,m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForward2::IsFinished() {
	if (IsTimedOut()) {
		return true;
	} else {
		return completed;
	}
}

// Called once after isFinished returns true
void AutoDriveForward2::End() {
	Robot::chassis->resetPosition();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveForward2::Interrupted() {

}
