#include "Device.h"

int Device::m_nextId = 0;

Device::Device()
	: m_id{ std::to_string(++m_nextId) }
{
}
