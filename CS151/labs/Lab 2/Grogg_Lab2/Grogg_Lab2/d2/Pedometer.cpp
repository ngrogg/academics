#include "Pedometer.h"

Pedometer::Pedometer()
{
	nsteps = 0;

		//cm, will be in output
	nstride = 110; 
}

Pedometer::Pedometer(int ste, int str)
{
	nsteps 	= ste;
	nstride = str;
}

int Pedometer::GetSteps()
{
	return nsteps;
}

void Pedometer::SetSteps(int s)
{
	nsteps = s;
}

int Pedometer::GetStride()
{
	return nstride;
}

void Pedometer::SetStride(int s)
{
	nstride = s;	
}

void Pedometer::Reset()
{
	nsteps = 0;
}

void Pedometer::Increment(int I)
{
	nincrement = I;
}

//friend, Pedometer::operator
std::istream& operator>>(std::istream& stream, Pedometer& p)
{
	stream >> p.nsteps >> p.nstride;

	return stream;
}

//friend
std::ostream& operator<<(std::ostream& stream, const Pedometer& p)
{
	
	stream << "Steps: " << p.nsteps << "\n";
	
	stream << "Distance walked: " << p.nsteps/(p.nsteps * 1000) << "km" << "\n";
	
	stream << "Calories burned: " << (p.nsteps/36)/1000 << "\n";
	
	return stream;
}


