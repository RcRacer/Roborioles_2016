// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::chassisLeftMotor1;
std::shared_ptr<CANTalon> RobotMap::chassisLeftMotor2;
std::shared_ptr<CANTalon> RobotMap::chassisRightMotor1;
std::shared_ptr<CANTalon> RobotMap::chassisRightMotor2;
std::shared_ptr<RobotDrive> RobotMap::chassisDriveMotors;
std::shared_ptr<Compressor> RobotMap::chassisCompressor;
std::shared_ptr<SpeedController> RobotMap::pickupThePickupMotor;
std::shared_ptr<CANTalon> RobotMap::shooterLeftShooterMotor;
std::shared_ptr<CANTalon> RobotMap::shooterRightShooterMotor;
std::shared_ptr<Solenoid> RobotMap::shooterShooterSolenoid;
std::shared_ptr<Solenoid> RobotMap::pneumaticSubDefenseSolen;
std::shared_ptr<Solenoid> RobotMap::pneumaticSubGShiftSolen;
std::shared_ptr<Solenoid> RobotMap::pneumaticSubScissorSolen;
std::shared_ptr<Solenoid> RobotMap::pneumaticSubRatchetSolen;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    chassisLeftMotor1.reset(new CANTalon(4));
    lw->AddActuator("Chassis", "LeftMotor1", chassisLeftMotor1);
    
    chassisLeftMotor2.reset(new CANTalon(3));
    lw->AddActuator("Chassis", "LeftMotor2", chassisLeftMotor2);
    
    chassisRightMotor1.reset(new CANTalon(2));
    lw->AddActuator("Chassis", "RightMotor1", chassisRightMotor1);
    
    chassisRightMotor2.reset(new CANTalon(1));
    lw->AddActuator("Chassis", "RightMotor2", chassisRightMotor2);
    
    chassisDriveMotors.reset(new RobotDrive(chassisLeftMotor1, chassisLeftMotor2,
              chassisRightMotor1, chassisRightMotor2));
    
    chassisDriveMotors->SetSafetyEnabled(false);
        chassisDriveMotors->SetExpiration(0.1);
        chassisDriveMotors->SetSensitivity(0.5);
        chassisDriveMotors->SetMaxOutput(1.0);

    chassisCompressor.reset(new Compressor(0));
    
    
    pickupThePickupMotor.reset(new Talon(9));
    lw->AddActuator("Pickup", "ThePickupMotor", std::static_pointer_cast<Talon>(pickupThePickupMotor));
    
    shooterLeftShooterMotor.reset(new CANTalon(5));
    lw->AddActuator("Shooter", "LeftShooterMotor", shooterLeftShooterMotor);
    
    shooterRightShooterMotor.reset(new CANTalon(6));
    lw->AddActuator("Shooter", "RightShooterMotor", shooterRightShooterMotor);
    
    shooterShooterSolenoid.reset(new Solenoid(0, 1));
    lw->AddActuator("Shooter", "ShooterSolenoid", shooterShooterSolenoid);
    
    pneumaticSubDefenseSolen.reset(new Solenoid(0, 3));
    lw->AddActuator("PneumaticSub", "DefenseSolen", pneumaticSubDefenseSolen);
    
    pneumaticSubGShiftSolen.reset(new Solenoid(0, 2));
    lw->AddActuator("PneumaticSub", "GShiftSolen", pneumaticSubGShiftSolen);
    
    pneumaticSubScissorSolen.reset(new Solenoid(0, 4));
    lw->AddActuator("PneumaticSub", "ScissorSolen", pneumaticSubScissorSolen);
    
    pneumaticSubRatchetSolen.reset(new Solenoid(0, 0));
    lw->AddActuator("PneumaticSub", "RatchetSolen", pneumaticSubRatchetSolen);
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
