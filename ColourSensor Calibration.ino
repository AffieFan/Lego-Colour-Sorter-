//Defining colour sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Define Variables
int RPW = 0;
int GPW = 0;
int BPW = 0;


void setup() {
  // put your setup code here, to run once:
  // S0 - S3 as outputs
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);

	// Set Pulse Width scaling to 20%
	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);

	// Set Sensor output as input
	pinMode(sensorOut, INPUT);

	Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read Red Pulse Width
	RPW = readRed();
	delay(200);

	// Read Green Pulse Width
	GPW = readGreen();
	delay(200);

	// Read Blue Pulse Width
	BPW = readBlue();
	delay(200);

	// Print output to Serial Monitor
	Serial.println("Red = ");
	Serial.print(RPW);
	Serial.println("Green = ");
	Serial.print(GPW);
	Serial.println("Blue = ");  
	Serial.print(BPW);
} 

int readRed() {
	// Sensor to read Red only
	digitalWrite(S2,LOW);
	digitalWrite(S3,LOW);
	int PW;
	PW = pulseIn(sensorOut, LOW);
	return PW;
}

int readGreen() {
	// Sensor to read Green only
	digitalWrite(S2,HIGH);
	digitalWrite(S3,HIGH);
	int PW;
	PW = pulseIn(sensorOut, LOW);
	return PW;
}

int readBlue() {
	// Sensor to read Blue only
	digitalWrite(S2,LOW);
	digitalWrite(S3,HIGH);
	int PW;
	PW = pulseIn(sensorOut, LOW);
	return PW;
}
