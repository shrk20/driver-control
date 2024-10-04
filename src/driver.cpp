#include "main.h"
#include "lemlib/api.hpp"
#include "auton.cpp"
#include "globals.hpp"
#include "drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "globals.cpp"


// Moves intake depending on the controller input
bool intakeR = false;
bool intakeF = false;

// Sets the intake to turn on and off when triggered
void intake(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intakeF = !intakeF;
        if(intakeF) {
            intake_motor.move(127);
        }
        else{
            intake_motor.move(0);
        }
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intakeR = !intakeR;
        if(intakeR) {
            intake_motor.move(-127);
        }
        else{
            intake_motor.move(0);
        }
    }    
}
// Setting the mogo mechanism to start off
bool pneumatics_clamp = false; 

// Sets the pneumatics to turn on and off
void clamp(){
     if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
     {
        pneumatics_clamp = !pneumatics_clamp;
        clamp_1.set_value(pneumatics_clamp); 
        clamp_2.set_value(pneumatics_clamp);
        pros::delay(20);
    }
}

void drive(){
    
    int dir = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    chassis.curvature(dir, turn);

}
