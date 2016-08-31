// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Chassis.h"
#include "../RobotMap.h"
#include "Timer.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/DriveCmd.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Chassis::Chassis() : Subsystem("Chassis") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftMotor1 = RobotMap::chassisLeftMotor1;
    leftMotor2 = RobotMap::chassisLeftMotor2;
    rightMotor1 = RobotMap::chassisRightMotor1;
    rightMotor2 = RobotMap::chassisRightMotor2;
    driveMotors = RobotMap::chassisDriveMotors;
    compressor = RobotMap::chassisCompressor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    climbLS = RobotMap::chassisClimbLS;
    MotorDirect = 1;
	photonOn = false;
    // Do not need to reverse motors with the Rocketbox PTO
    // driveMotors->SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor,false);
    // driveMotors->SetInvertedMotor(RobotDrive::MotorType::kFrontRightMotor,false);
    // driveMotors->SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor,false);
    // driveMotors->SetInvertedMotor(RobotDrive::MotorType::kRearRightMotor,false);

    // Set control mode to direct throttle control, range -1 to 1, and set initial speed to zero
    // per section 3.3.2 C++ in TALON SRX Software Reference Manual (1/31/2016)
    /* leftMotor1->SetControlMode(CANSpeedController::kPercentVbus);
    leftMotor1->Set(0);
    leftMotor2->SetControlMode(CANSpeedController::kPercentVbus);
    leftMotor2->Set(0);
    rightMotor1->SetControlMode(CANSpeedController::kPercentVbus);
    rightMotor1->Set(0);
    rightMotor2->SetControlMode(CANSpeedController::kPercentVbus);
    rightMotor2->Set(0); */

    timer = new Timer;
    photonCannon = RobotMap::chassisPhotonCannon;
    photonOn=false;
}

void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new DriveCmd());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

double Chassis::deadband(double JoystickValue,double DeadbandCutOff) {
	if (JoystickValue < DeadbandCutOff && JoystickValue > DeadbandCutOff*(-1)) {
		return 0;
	} else {
		return (JoystickValue - (abs(JoystickValue)/JoystickValue*DeadbandCutOff))/(1-DeadbandCutOff);
	}
}

void Chassis::DriveWithJoysticks(){
	float left = deadband(Robot::oi->getleftJoy()->GetY(),0.05) * 0.5;

	/*if (photonOn) {
		photonCannon->Set(Relay::kForward);
	} else {
		photonCannon->Set(Relay::kReverse);
	}
	*/
	if (Robot::pneumaticSub->GetGShiftSolenoid()->Get()){
		rightMotor1->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		rightMotor2->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		float right = deadband(-1*Robot::oi->getGamepad()->GetThrottle(),0.05);
		leftMotor1->Set(left);
		leftMotor2->Set(left);
		if (right>0) {
			if (climbLS->Get()) {
				rightMotor1->Set(right*0.7);
				rightMotor2->Set(right*0.7);
			} else {
				rightMotor1->Set(0);
				rightMotor2->Set(0);
			}
		} else {
			rightMotor1->Set(right);
			rightMotor2->Set(right);
		}
	} else {
		rightMotor1->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		rightMotor2->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		float right = deadband(Robot::oi->getrightJoy()->GetY(),0.05) * .5;
		if (Robot::oi->getrightJoy()->GetRawButton(1) && Robot::oi->getleftJoy()->GetRawButton(1)){
			left  = left * -0.5;
			right = right * -0.5;
			driveMotors->TankDrive(right,left);
		} else {
			driveMotors->TankDrive(left,right);
		}
	}
}

void Chassis::Stop(){
	driveMotors->StopMotor();
}

void Chassis::Compress() {
	compressor->SetClosedLoopControl(true);
	compressor->Start();
}

void Chassis::driveFeet(double feet=10,double speed=.5){
	// convert to feet
	feet = feet * 12;
	timer->Start();

	double distance=abs(feet/(3.1415 * diameter)*1000.0);
	while ((leftMotor2->GetEncPosition()<distance) && timer->Get() < 6) {
		leftMotor1->Set(-1 * speed);
		leftMotor2->Set(-1 *speed);
		rightMotor1->Set(speed);
		rightMotor2->Set(speed);
		printf("Timer is %f\n",timer->Get());
	}
	leftMotor1->Set(0);
	leftMotor2->Set(0);
	rightMotor1->Set(0);
	rightMotor2->Set(0);
	timer->Stop();
	timer->Reset();
}

void Chassis::PrintValues() {

	// Print encoder positions
	SmartDashboard::PutNumber("leftMotor2 Position: ",leftMotor2->GetEncPosition());
	SmartDashboard::PutNumber("leftMotor2 Velocity",leftMotor2->GetEncVel());
	SmartDashboard::PutNumber("rightMotor2 Position: ",rightMotor2->GetEncPosition());
	SmartDashboard::PutNumber("rightMotor2 Velocity",rightMotor2->GetEncVel());

}

void Chassis::resetPosition(){
    leftMotor1->SetPosition(0);
    leftMotor2->SetPosition(0);
    rightMotor1->SetPosition(0);
    rightMotor2->SetPosition(0);
}

void Chassis::rotate(double angle) {
	leftMotor1->Set(0.4);
	leftMotor2->Set(0.4);
	rightMotor1->Set(0.4);
	rightMotor2->Set(0.4);
}

/* void Chassis::photonCannonTog() {
	///timer->Reset();
	///timer->Start();
	printf("Entering photoCannonTog\n");
	if (photonOn) {
		photonCannon->Set(Relay::kForward);
		photonOn=false;
		printf("Setting photonOn to False\n");
		SmartDashboard::PutString("DB/String 5","Photon On");
	} else {
		// photonCannon->Set(Relay::kReverse);
		photonOn=true;
		printf("Setting photonOn to True\n");

		SmartDashboard::PutString("DB/String 5","Photon Off");
	}
	// while(timer->Get() < 5) {
		//photonCannon->Set(Relay::kReverse);
	//}
	printf("exiting photoCannonTog\n");
}
*/

std::shared_ptr<Relay> Chassis::GetPhotonCannon() {
	 return photonCannon;
}
