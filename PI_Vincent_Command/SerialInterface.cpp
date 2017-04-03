// 
// 
// 

#include "SerialInterface.h"


template<typename T>
inline T SerialInterface::read<T>()
{
	T temp;
	SerialInterface::read((pbyte)&temp, sizeof(T));
	return temp;
}
template<typename T>
inline void SerialInterface::write<T>(T const &var)
{
	SerialInterface::write((pbyte)&var, sizeof(var));
	return;
}
void SerialInterface::read(pbyte buffer, uint len)
{
	m_interface.readBytes(buffer,len);
	return;
}
void SerialInterface::write(const pbyte buffer, uint len)
{
	m_interface.write(buffer, len);
	return;
}

inline void Telecommande::start()
{
	while (true)
	{



	}
	return;
}
inline uint Telecommande::readX()
{
	uint var[TRIES];
	FOR(i, TRIES)
	{
		var[i] = analogRead(PIN_X);
	}
	return Telecommande::average<TRIES>(var);
}
inline uint Telecommande::readY()
{
	uint var[TRIES];
	FOR(i, TRIES)
	{
		var[i] = analogRead(PIN_Y);
	}
	return Telecommande::average<TRIES>(var);
}
inline uint Telecommande::readSpeed()
{
	uint var[TRIES];
	FOR(i, TRIES)
	{
		var[i] = analogRead(PIN_SPEED);
	}
	return Telecommande::average<TRIES>(var);
}