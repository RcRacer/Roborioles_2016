// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutoDriveForward.h"
#include "Commands/AutoGroup1.h"
#include "Commands/AutoPortcullis.h"
#include "Commands/VisionCom.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Chassis> Robot::chassis;
std::shared_ptr<Pickup> Robot::pickup;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<PneumaticSub> Robot::pneumaticSub;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Command *autonomousCommand;

void Robot::RobotInit() {
	RobotMap::init();
	chooser = new SendableChooser();
	chooser->AddDefault("Do Nothing",new AutonomousCommand());
	chooser->AddObject("Cross Defense",new AutoDriveForward(10,0.4));
	chooser->AddObject("Cross Defense and Rotate",new AutoGroup1());
	chooser->AddObject("Portcullis/LowBar", new AutoPortcullis());
	SmartDashboard::PutData("Autonomous Modes",chooser);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    chassis.reset(new Chassis());
    pickup.reset(new Pickup());
    shooter.reset(new Shooter());
    pneumaticSub.reset(new PneumaticSub());
    VisionCom::startGrip();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	//autonomousCommand.reset(new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
	chassis->PrintValues();
}

void Robot::AutonomousInit() {
//	if (autonomousCommand.get() != nullptr)
	chassis->resetPosition();
	Robot::pneumaticSub->ResetSoleniods();

	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand -> Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.

	chassis->resetPosition();
	Robot::pneumaticSub->ResetSoleniods();
	oi->addButton();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	Robot::pneumaticSub->PrintValues();
	shooter->PrintValues();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

