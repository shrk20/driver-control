#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"

// Intialize controller
extern pros::Controller master;

// Initialize the  motor groups
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::MotorGroup intake_motor;

// Intialize horizontal and vertical encoders
extern pros::adi::Encoder vertical_encoder;
extern pros::Rotation horizontal_encoder;

//Tracking Wheels
extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;

//Create the drivertrain
extern lemlib::Drivetrain drivetrain;

//PID
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::OdomSensors sensors;

//Chassis
extern lemlib::Chassis chassis;

//pneumatics and inertial sensors
extern pros::ADIDigitalOut clamp_1;
extern pros::ADIDigitalOut clamp_2;
extern pros::Imu imu;




