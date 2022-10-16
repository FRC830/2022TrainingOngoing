// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>
#include <rev/CANSparkMax.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>




class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  
  frc::XboxController pilot{0};
  rev::CANSparkMax motorFL = rev::CANSparkMax(1, rev::CANSparkMaxLowLevel::MotorType::kBrushless); 
  rev::CANSparkMax motorFR = rev::CANSparkMax(3, rev::CANSparkMaxLowLevel::MotorType::kBrushless); 
  rev::CANSparkMax motorBL = rev::CANSparkMax(2, rev::CANSparkMaxLowLevel::MotorType::kBrushless); 
  rev::CANSparkMax motorBR = rev::CANSparkMax(4, rev::CANSparkMaxLowLevel::MotorType::kBrushless);

  frc::MotorControllerGroup motorGroupLeft = frc::MotorControllerGroup(motorFL, motorBL);
  frc::MotorControllerGroup motorGroupRight = frc::MotorControllerGroup(motorFR, motorBR);

  ctre::phoenix::motorcontrol::can::TalonFX leftFlywheelTalon {4};
  ctre::phoenix::motorcontrol::can::TalonFX rightFlywheelTalon {9};
  ctre::phoenix::motorcontrol::can::TalonFX backSpinTalon {5};





  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
