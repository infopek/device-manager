#include "PickupPoint.h"

#include "Laptop.h"
#include "Monitor.h"
#include "Projector.h"

#include <iostream>
#include <map>
#include <vector>

/* Saves all devices which are not currently dropped off anywhere to a map */
std::map<std::string, int> saveToMap(const std::vector<Device*>& devices)
{
	// Stores <device_id, use_in_hours>
	std::map<std::string, int> map{};
	for (const auto* device : devices)
	{
		if (!device->getPickupPoint())
			map[device->getId()] = device->getHoursUsed();
	}

	return map;
}

void test()
{
	PickupPoint point1("Gera");
	PickupPoint point2("Kira");
	PickupPoint point3("Opre");

	Laptop l1;
	Laptop l2;
	Laptop l3;
	Laptop l4;
	Laptop l5;

	Monitor m1;
	Monitor m2;
	Monitor m3;
	Monitor m4;

	Projector p1;
	Projector p2;
	Projector p3;

	// Vector of pointers to prevent slicing
	std::vector<Device*> devices
	{
		&l1, &l2, &l3, &l4, &l5,
		&m1, &m2, &m3, &m4,
		&p1, &p2, &p3
	};

	point1.dropOff(*devices[4]);
	point1.dropOff(*devices[7]);
	point2.dropOff(*devices[0]);
	point3.dropOff(*devices[1]);
	point3.dropOff(*devices[10]);

	point2.pickUp('L');

	std::map<std::string, int> map1 = saveToMap(devices);

	point1.pickUp('L');
	point3.pickUp('L');
	point3.pickUp('P');

	point2.dropOff(*devices[0]);

	std::map<std::string, int> map2 = saveToMap(devices);

	point3.dropOff(*devices[10]);
}

int main()
{
	test();
}