/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/addisonsimon/lab11/src/lab11.ino"
#include "Blynk.h"
#include "LIS3DH.h"
void setup();
void loop();
#line 3 "/Users/addisonsimon/lab11/src/lab11.ino"
SYSTEM_THREAD(ENABLED);
LIS3DHSPI accel(SPI, A4, WKP);

void setup() {
	Serial.begin(9600);
  Blynk.begin("4Oy-pMhtDGrpu_zi1ocegBaiy6ty8yea", IPAddress(167, 172, 234, 162), 9090);
	LIS3DHConfig config;
	config.setAccelMode(LIS3DH::RATE_100_HZ);
	bool setupSuccess = accel.setup(config);
}

void loop() {
  Blynk.run();
	LIS3DHSample sample;
	if (accel.getSample(sample)) {
    Blynk.virtualWrite(V0, sample.x);
    Blynk.virtualWrite(V1, sample.y);
    Blynk.virtualWrite(V2, sample.z);
	}
  delay(100);
}
