// SerialInterface.h

#include <SoftwareSerial\src\SoftwareSerial.h>
#ifndef _SERIALINTERFACE_h
#define _SERIALINTERFACE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define TRIES 10
#define FOR(var,min,max) for(uint var = min;var<max;++var)
#define FOR(var,max) for(uint var = 0;var<max;++var)

typedef unsigned int uint;
typedef byte *pbyte;

typedef struct TelecommandeToSystem
{
	byte x;
	byte y;
	byte speed;
	int sum;
}TDATA,*PTDATA;
typedef struct SytemToTelecommande
{
	byte power;

}SDATA,*PSDATA;



class SerialInterface
{
public:
	SerialInterface(const byte &RX, const byte &TX,const uint &bps = 9600) : PIN_TX(TX), PIN_RX(RX),m_interface(RX,TX)
	{
		m_interface.begin(bps);
	}

protected:
	void read(pbyte buffer, uint len);
	void write(const pbyte buffer, uint len);
	template<typename T>
	inline T read();
	template<typename T>
	inline void write(T const &var);

	const byte PIN_TX;
	const byte PIN_RX;
	SoftwareSerial m_interface;
};

class Telecommande : SerialInterface
{
public:
	Telecommande(const byte &RX, const byte &TX, const byte &POT_SPEED, const byte &POT_X, const byte &POT_Y, const uint &bps = 9600) : SerialInterface(RX, TX, bps), PIN_SPEED(POT_SPEED), PIN_X(POT_X), PIN_Y(POT_Y)
	{}
	inline void start();

protected:
	inline uint readX();
	inline uint readY();
	inline uint readSpeed();
	
	template<uint num>
	average(uint* value)
	{
		uint rep;
		FOR(i, num)
		{
			rep += value[i];
		}
		return rep / num;
	}


	const byte PIN_SPEED;
	const byte PIN_X;
	const byte PIN_Y;

	TDATA tdata[2];
	CDATA cdata[2];
};




#endif

