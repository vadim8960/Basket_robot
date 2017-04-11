#pragma config(Sensor, S1,     left_sen,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     right_sen,               sensorEV3_Ultrasonic)

void colibr(){
	while (true){
		float err = (getUSDistance(left_sen) - getUSDistance(right_sen)) * 0.5;
		motor[motorB] = err;
		motor[motorC] = -err;
		if (getUSDistance(left_sen) == getUSDistance(right_sen)) break;
	}
	sleep(1500);
}

void go_to_target(){
	while (getUSDistance(left_sen) >= 58 && getUSDistance(right_sen) >= 58){
		motor[motorB] = 20;
		motor[motorC] = 20;
		if (getUSDistance(left_sen) != getUSDistance(right_sen)) colibr();
	}
	sleep(1000);
	colibr();
}

task main(){
	while (getUSDistance(left_sen) >= 100 || getUSDistance(right_sen) >= 100){
		motor[motorB] = 20;
		motor[motorC] = -20;
	}
	stopAllMotors();
	go_to_target();
}
