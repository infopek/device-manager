#include "Monitor.h"

Monitor::Monitor()
{
	static_cast<void>(*m_id.insert(m_id.begin(), 'M'));
}