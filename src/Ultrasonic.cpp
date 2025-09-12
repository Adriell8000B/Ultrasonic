#include <Arduino.h>
#include <stdint-gcc.h>
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(
	const uint8_t& TRIGGER_PIN,
	const uint8_t& ECHO_PIN
): _TRIGGER_PIN(TRIGGER_PIN), _ECHO_PIN(ECHO_PIN) {}

void Ultrasonic::setup_pins() {
	pinMode(this->_TRIGGER_PIN, 0x1);
	pinMode(this->_ECHO_PIN, 0x0);
}

unsigned long Ultrasonic::get_duration() {
	digitalWrite(this->_TRIGGER_PIN, 0x1);
	digitalWrite(this->_TRIGGER_PIN, 0x0);

	return pulseIn(this->_ECHO_PIN, 0x1);
}

void Ultrasonic::Init() {
	this->setup_pins();
}

float Ultrasonic::GetDistanceCM() {
	return (this->get_duration() * 0.034) / 2;
}

float Ultrasonic::GetDistanceM() {
	return (this->get_duration() * 0.034) / 200;
}