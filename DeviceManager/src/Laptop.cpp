#include "Laptop.h"

#include <iostream>

Laptop::Laptop()
{
	static_cast<void>(*m_id.insert(m_id.begin(), 'L'));
}

void Laptop::clean()
{
	std::cout << m_id << " was cleaned when it had been used for " << m_useHoursAtLastClean
		<< " hours and currently it has been used for " << m_hoursUsed << " hours\n";

	m_useHoursAtLastClean = m_hoursUsed;
}
