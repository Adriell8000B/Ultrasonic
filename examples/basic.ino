#include <Ultrasonic.h>

Ultrasonic hi_mom(8, 7);

void setup() {
	hi_mom.Init();
	Serial.begin(9600);
}

void loop() {
	auto distanceCM = hi_mom.GetDistanceCM();

	Serial.print(distanceCM);
	Serial.println("cm");
}