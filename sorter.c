#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, in2,    lineFollower,   sensorLineFollower)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           beginMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           stopServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           woodServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           lastServo,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           plasticServo,  tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*************************************

  Task Description: Sort the four different types of marbles


  Pseudocode:
  Set lastservo to 20
  Set stopservo to 0
  flashlight on at 127
  Start beginMotor to -27
  wait 0.18 seconds
  Stop beginMotor
  while true
  wait 2 seconds
  Set stopservo to -120
  Set lastservo to -120
  wait 0.5 seconds
  Set stopservo to 0
  Set lastservo to 15
  wait 1 second
  Set stopservo to -80
  wait 2 seconds
  if(lightsensor > 30)
  Set woodservo to 70
  else 
  Set woodservo to 0
  if(linefollower < 350)
  Set plasticservo to 120
  else
  Set plasticservo to -120
  Set lastservo to -125
  wait 0.65 seconds
  Set lastservo to 20
  wait 1 second
  Start beginMotor to -27
  wait 0.18 seconds
  Stop beginMotor

  //

****************************************/
//***** Declare Variables

//***** Declare functions
void motors();
void firstMotor();
task main()
{
	setServo(lastServo, 20);
	setServo(stopServo, 0);
	turnFlashlightOn(flashlight,127);
	firstMotor();
	while(1==1)
	{
		wait(2);
		motors();
		wait(1);
		setServo(stopServo, -80);
		wait(2);
		if(SensorValue[lightSensor]>30)
		{
			setServo(woodServo, 70);
		}
		else
		{
			setServo(woodServo, 0);
		}
		if(SensorValue[lineFollower]<350)
		{
			setServo(plasticServo, 120);
		}
		else
		{
			setServo(plasticServo, -120);
		}
		setServo(lastServo, -125);
		wait(0.65);
		setServo(lastServo,20);
		wait(1);
		firstMotor();
	}
}
//*****Function Definition Library********
void motors()
{
		setServo(stopServo, -120);
		setServo(lastServo, -120);
		waitInMilliseconds(500);
  	setServo(stopServo, 0);
  	setServo(lastServo, 15);
}

void firstMotor()
{
	startMotor(beginMotor, -27);
	waitInMilliseconds(180);
	stopMotor(beginMotor);
}

