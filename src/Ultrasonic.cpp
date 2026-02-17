#include <Arduino.h>
#include <stdint-gcc.h>
#include "Ultrasonic.h"

#define CM_DIVISOR 58.0f
#define M_DIVISOR 5800.0f

Ultrasonic::Ultrasonic(
	uint8_t TRIGGER_PIN,
	uint8_t ECHO_PIN
): _TRIGGER_PIN(TRIGGER_PIN), _ECHO_PIN(ECHO_PIN) {}

void Ultrasonic::setup_pins() {
	pinMode(_TRIGGER_PIN, OUTPUT);
	pinMode(_ECHO_PIN, INPUT);

	_outReg = portOutputRegister(digitalPinToPort(_TRIGGER_PIN));
	_pinMask = digitalPinToBitMask(_TRIGGER_PIN);
}

unsigned long Ultrasonic::get_duration() {
	*_outReg &= ~_pinMask;
	delayMicroseconds(2);
	*_outReg |= _pinMask; 
    delayMicroseconds(10);
    *_outReg &= ~_pinMask;

	return pulseIn(_ECHO_PIN, HIGH, 30000);
}

void Ultrasonic::Init() {
	setup_pins();
}

float Ultrasonic::GetDistanceCM() {
    unsigned long duration = get_duration();
    if (duration == 0) return -1.0f; // Return -1 if out of range
	return (float)duration / CM_DIVISOR;
}

float Ultrasonic::GetDistanceM() {
    unsigned long duration = get_duration();
    if (duration == 0) return -1.0f;
    return (float)duration / M_DIVISOR;
}