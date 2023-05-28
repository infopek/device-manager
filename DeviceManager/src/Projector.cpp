#include <iostream>

#include "Projector.h"

Projector::Projector()
{
	static_cast<void>(*m_id.insert(m_id.begin(), 'P'));
}

void Projector::clean()
{
	if (m_hoursUsed - m_useHoursAtLastClean > 100)
	{
		std::cout << "It's time to clean projector " << m_id << '\n';
		std::cout << m_id << " was last cleaned when it had been used for " << m_useHoursAtLastClean
			<< " hours and currently it has been used for " << m_hoursUsed << " hours\n";
		m_useHoursAtLastClean = m_hoursUsed;
	}
}
