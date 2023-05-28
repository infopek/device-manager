#pragma once

#include <memory>
#include <string>

class PickupPoint;

// Base class for a computing device
class Device
{
public:
	Device();
	virtual ~Device() = default;

	virtual const std::string& getId() const { return m_id; }

	virtual int getHoursUsed() const { return m_hoursUsed; }
	virtual void setHoursUsed(int hoursUsed) { m_hoursUsed = hoursUsed; }

	virtual PickupPoint* getPickupPoint() const { return m_point; }
	virtual void setPickupPoint(PickupPoint* pickupPoint) { m_point = pickupPoint; }

protected:
	std::string m_id;

	int m_hoursUsed{};

	// Linker was complaining about incomplete class issues, and I didn't want circular dependency, so I 
// just used raw pointers
	PickupPoint* m_point{ nullptr };

private:
	static int m_nextId;
};

