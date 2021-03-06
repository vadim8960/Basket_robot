#pragma config(Sensor, S4,     ,               sensorEV3_Ultrasonic)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void reload(){
	resetMotorEncoder(motorB);
	while (getMotorEncoder(motorB) > -30) motor[motorB] = -100;
	sleep(200);
	while (getMotorEncoder(motorB) < 0) motor[motorB] = 100;
	sleep(500);
}

void fire(){
	sleep(1000);
	motor[motorA] = -100;
	sleep(1500);
	motor[motorA] = 80;
	sleep(1500);
	stopMotor(motorA);
}

float math(float l){
	l -= 5;
	float a = (asin(l / 60) * 57) / 2;
	/*string poww = a, len = l;
	displayString(4, len);
	displayString(5, poww);
	sleep(50000);*/
	return a;
}

void setDeg(float deg){
	reload();
	resetMotorEncoder(motorC);
	resetMotorEncoder(motorD);
	while (getMotorEncoder(motorC) < deg){
		motor[motorC] = 15;
		motor[motorD] = 15;
	}
	motor[motorC] = 0;
	motor[motorD] = 0;
	fire();
	motor[motorC] = -20;
	motor[motorD] = -20;
	sleep(2000);
}

task main()
{
	ev3;
	motor[motorA] = 100;
	sleep(1000);
	/*while (true){
		motor
		if (getUSDistance(S4) < 60) break;
	}*/
	setDeg(math(getUSDistance(S4)));
}
