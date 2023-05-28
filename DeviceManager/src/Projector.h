#pragma once

#include "Device.h"
#include "ICleanable.h"

class Projector : public Device, public ICleanable
{
public:
	Projector();

	virtual void clean() override;

	int getHoursAtLastClean() const { return m_useHoursAtLastClean; }

private:
	int m_useHoursAtLastClean{};	// how many hours it was used for at last clean
};

