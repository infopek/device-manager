#pragma once

#include "Device.h"

#include "Laptop.h"
#include "Monitor.h"
#include "Projector.h"

#include <stack>
#include <string>

class PickupPoint
{
public:
	PickupPoint() = default;
	PickupPoint(const std::string& name);

	void dropOff(Device& device);

	/* 
	* 'type' is the start of the device's id, such as 'M' or 'L' .
	* Note: assumes a device of type 'type' is at the dropoff place already.
	*/
	void pickUp(char type);

	const std::string& getName() const { return m_name; }

private:
	std::string m_name{};

	std::stack<Laptop*> m_laptopStack{};
	std::stack<Monitor*> m_monitorStack{};
	std::stack<Projector*> m_projectorStack{};
};

