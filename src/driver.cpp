#include "main.h"
#include "lemlib/api.hpp"
#include "globals.hpp"
#include "lemlib/chassis/chassis.hpp"


// Moves intake depending on the controller input
bool intakeR = false;
bool intakeF = false;

// Sets the intake to turn on and off when triggered
void intake(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intakeF = !intakeF;
        if(intakeF) {
            intake_motors.move(127);
        }
        else{
            intake_motors.move(0);
        }
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intakeR = !intakeR;
        if(intakeR) {
            intake_motors.move(-127);
        }
        else{
            intake_motors.move(0);
        }
    }    
}
// Setting the mogo mechanism to start off
bool pneumatics_clamp = false; 

// Sets the pneumatics to turn on and off
void clamp(){
     if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
     {
        pneumatics_clamp = !pneumatics_clamp;
        clamp1.set_value(pneumatics_clamp); 
        clamp2.set_value(pneumatics_clamp);
        pros::delay(20);
    }
}

void drive(){
    
    int dir = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    chassis.arcade(dir, turn);
    pros::delay(20);
}
