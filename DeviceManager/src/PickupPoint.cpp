#include "PickupPoint.h"

#include <iostream>

PickupPoint::PickupPoint(const std::string& name)
	: m_name{ name }
{
}

void PickupPoint::dropOff(Device& device)
{
	device.setPickupPoint(this);

	std::cout << "\nHow many hours has the device " << device.getId() << " been used since last pickup? ";
	int hoursUsed;
	std::cin >> hoursUsed;
	device.setHoursUsed(device.getHoursUsed() + hoursUsed);

	Laptop* laptop = dynamic_cast<Laptop*>(&device);
	Monitor* monitor = dynamic_cast<Monitor*>(&device);
	Projector* projector = dynamic_cast<Projector*>(&device);

	std::cout << "Dropped off at " << m_name << " and it was used for " 
		<< device.getHoursUsed() << " hours\n";

	// Not the best solution, but the dynamic casts are needed anyway
	if (laptop)
	{
		laptop->clean();
		m_laptopStack.push(laptop);
	}
	else if (monitor)
	{
		m_monitorStack.push(monitor);
	}
	else
	{
		projector->clean();
		m_projectorStack.push(projector);
	}
}

void PickupPoint::pickUp(char type)
{
	Device* device = nullptr;
	switch (type)
	{
	case 'L':
		device = m_laptopStack.top();
		m_laptopStack.pop();
		break;;
	case 'M':
		device = m_monitorStack.top();
		m_monitorStack.pop();
		break;
	case 'P':
		device = m_projectorStack.top();
		m_projectorStack.pop();
		break;
	default:
		break;
	}

	if (device)
	{
		device->setPickupPoint(nullptr);

		std::cout << "Picked up " << device->getId() << " from " << m_name
			<< " with use of " << device->getHoursUsed() << " hours\n";
	}
}
