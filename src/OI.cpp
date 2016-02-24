// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoDriveForward.h"
#include "Commands/AutoGroup1.h"
#include "Commands/AutoGroup2.h"
#include "Commands/AutoPortcullis.h"
#include "Commands/AutoRotate.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DefenseSolTog.h"
#include "Commands/DriveCmd.h"
#include "Commands/GShiftSolTog.h"
#include "Commands/PickyUppy.h"
#include "Commands/RatchetSolTog.h"
#include "Commands/ScissorSolTog.h"
#include "Commands/ShootCmd.h"
#include "Commands/holdBoulderTog.h"
#include "Commands/lowshootGroup.h"
#include "Commands/lowshootPrep.h"
#include "Commands/shootGroup.h"
#include "Commands/shootPrep.h"
#include "Commands/shootReset.h"
#include "Commands/shootShoot.h"
#include "Commands/RatchetSolTog.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    rightJoy.reset(new Joystick(1));
    leftJoy.reset(new Joystick(0));
    
    climb11.reset(new JoystickButton(leftJoy.get(), 3));
    climb11->WhenPressed(new GShiftSolTog());
    
    gamepad.reset(new Joystick(2));
    
    holdBoulder.reset(new JoystickButton(gamepad.get(), 6));
    holdBoulder->WhenPressed(new holdBoulderTog());
    lowGoal4.reset(new JoystickButton(gamepad.get(), 4));
    lowGoal4->WhenPressed(new lowshootGroup());
    highGoal1.reset(new JoystickButton(gamepad.get(), 1));
    highGoal1->WhenPressed(new shootGroup());
    scissorlift8.reset(new JoystickButton(gamepad.get(), 8));
    scissorlift8->WhenPressed(new ScissorSolTog());
    defense5.reset(new JoystickButton(gamepad.get(), 5));
    defense5->WhenPressed(new DefenseSolTog());
    ratchet2.reset(new JoystickButton(rightJoy.get(), 3));
    ratchet2->WhenPressed(new RatchetSolTog());

    // SmartDashboard Buttons
    SmartDashboard::PutData("AutoPortcullis", new AutoPortcullis());
    SmartDashboard::PutData("AutoRotate", new AutoRotate(0));
    SmartDashboard::PutData("AutoDriveForward", new AutoDriveForward(0,0));
    SmartDashboard::PutData("AutoGroup2", new AutoGroup2());
    SmartDashboard::PutData("AutoGroup1", new AutoGroup1());
    SmartDashboard::PutData("holdBoulderTog", new holdBoulderTog());
    SmartDashboard::PutData("lowshootPrep", new lowshootPrep());
    SmartDashboard::PutData("lowshootGroup", new lowshootGroup());
    SmartDashboard::PutData("shootReset", new shootReset());
    SmartDashboard::PutData("shootShoot", new shootShoot());
    SmartDashboard::PutData("shootPrep", new shootPrep());
    SmartDashboard::PutData("shootGroup", new shootGroup());
    SmartDashboard::PutData("RatchetSolTog", new RatchetSolTog());
    SmartDashboard::PutData("ScissorSolTog", new ScissorSolTog());
    SmartDashboard::PutData("GShiftSolTog", new GShiftSolTog());
    SmartDashboard::PutData("DefenseSolTog", new DefenseSolTog());
    SmartDashboard::PutData("ShootCmd", new ShootCmd());
    SmartDashboard::PutData("PickyUppy", new PickyUppy());
    SmartDashboard::PutData("DriveCmd", new DriveCmd());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getGamepad() {
   return gamepad;
}

std::shared_ptr<Joystick> OI::getleftJoy() {
   return leftJoy;
}

std::shared_ptr<Joystick> OI::getrightJoy() {
   return rightJoy;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
