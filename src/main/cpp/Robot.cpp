// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <iostream>

void Robot::RobotInit()
{
  rclcpp::init(0, NULL);

  node = std::make_shared<ros::RosNode>();
}

void Robot::RobotPeriodic()
{
  //std::cout << "spinning" << std::endl;
  rclcpp::spin_some(node);
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic()
{
  node->publish();
  double leftData, rightData;
  node->getNewData(leftData, rightData);
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif