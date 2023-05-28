#pragma once

#include "Device.h"
#include "ICleanable.h"

class Laptop : public Device, public ICleanable
{
public:
	Laptop();

	virtual void clean() override;

	int getHoursAtLastClean() const { return m_useHoursAtLastClean; }

private:
	int m_useHoursAtLastClean{};
};

