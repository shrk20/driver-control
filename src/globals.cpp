#include "lemlib/api.hpp"
#include "main.h"
#include "lemlib/chassis/chassis.hpp"

//Initialize controller + driver and intake motors
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_motors({-1, -2, -3}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({21, 19, 13}, pros::MotorGearset::blue);
pros::MotorGroup intake_motors({7}, pros::MotorGearset::blue);
  
// vertical and horizontal tracking wheel encoder
pros::adi::Encoder vertical_encoder('C', 'D', true);
pros::Rotation horizontal_encoder(20);
pros::Imu imu(10);

// Create the pneumatics clamps
pros::adi::Pneumatics clamp1('A', false);
pros::adi::Pneumatics clamp2('B', false);


// Create Tracking wheels
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -2.5);


// Create the drivetrain 
lemlib::Drivetrain drivetrain(&left_motors, 
                              &right_motors, 
                              12.5, 
                              lemlib::Omniwheel::NEW_325, 
                              480, 
                              2);

// Create the angular and lateral PID controllers
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20  // maximum acceleration (slew)
);

lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::OdomSensors sensors(nullptr, 
                            nullptr, 
                            nullptr, 
                            nullptr, 
                            &imu);

lemlib::Chassis chassis(drivetrain, // drivetrain setting
                        lateral_controller, // later PID settings
                        angular_controller, //angular PID settings
                        sensors // odometry sensors
                        );


