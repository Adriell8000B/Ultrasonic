#ifndef ULTRASONIC_H_INCLUDED
#define ULTRASONIC_H_INCLUDED

#include <Arduino.h>
#include <stdint-gcc.h>

/*
	@class Ultrasonic HC-SR04
	@brief This class has methods to return distance in centimeters and meters.
*/
class Ultrasonic {
	private:
	uint8_t _TRIGGER_PIN;
	uint8_t _ECHO_PIN;
	volatile uint8_t* _outReg;
	uint8_t _pinMask;
	
	/*
	* @private setup_pins()
	* @brief Setup the pins with pinMode()
	*/
	void setup_pins();

	/*
	* @private get_duration()
	* @brief Returns the duration of the ultrasonic pulse
	*/
	unsigned long get_duration();

	public:
	/*
	Constructor of the main class Ultrasonic
	*/
	Ultrasonic(
		uint8_t TRIGGER_PIN,
		uint8_t ECHO_PIN
	);

	/*
	* @public
	* @brief Init the setup_pins()
	*/
	void Init();

	/*
	*	@public
	* @brief Returns the distance in centimeters using the formula: (c * t) / 2 
	* 
	* c » speed of sound in microseconds (µs)
	*
	* t » duration of pulse
	*/
	float GetDistanceCM();
	
	/*
	*	@public
	* @brief Returns the distance in meters using formula: (c * t) / 200 
	* 
	* c » speed of sound in microseconds (µs)
	*
	* t » duration of pulse
	*/
	float GetDistanceM();
};

#endif
