#pragma config(Motor,  port2,           driveL,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           driveR,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           arm,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           claw,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           flap,          tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int leftX = 0;
int leftY = 0;
int rightY = 0;
int rightX = 0;
int thresh = 15;
const bool on = true;

task drive() { //This is the drive task. This is here so that we can drive and operate the manipulator at the same time.
	while(on) {
		motor[driveL] = -rightY - rightX;
		motor[driveR] = rightY - rightX;
	}
}

task manipulator() {

	while(on){
		motor[arm] = leftY; //the arm power is determined by what value the joystick gives it
	}

	if(vexRT[Btn8U]) { //this is claw code
		motor[claw] = 120;
		}else if(vexRT[Btn8D]) {
		motor[claw] = -120;
		}	else{
		motor[claw] = 0;
	}
	if(vexRT[Btn7U]) { //this is servo code
		motor[flap] = -70;
		wait1Msec(500);
		motor[flap] = 70;
	}
		if(vexRT[Btn8U]) { //this is servo code
		motor[flap] = -70;
		wait1Msec(500);
		motor[flap] = 70;
	}
}

task main() { //This holds the main tasks the robot initially starts with.
	startTask(drive); //This starts the drivetask so we can actually drive the robot.
	startTask(manipulator);
	while(on) {
		rightX = vexRT(Ch1);
		if(abs(rightX)<thresh){ //This adds a deadzone in the controller's right X axis, so that drivers have more reliable control of the robot.
			rightX = 0;
		}
		rightY = vexRT(Ch2);
		if(abs(rightY)<thresh){ //This adds a deadzone in the controller's right Y axis, so that drivers have more reliable control of the robot.
			rightY = 0;
		}
		leftY = vexRT(Ch3);
		if(abs(leftY)<thresh){ //This adds a deadzone in the controller's left Y axis, so that drivers have more reliable control of the robot.
			leftY = 0;
		}
		leftX = vexRT(Ch4);
		if(abs(leftX)<thresh){ //This adds a deadzone in the controller's left X axis, so that drivers have more reliable control of the robot.
			leftX = 0;
		}
	}
}
// I lost the game I lost the game I lost the game I lost the game I lost the game :D
