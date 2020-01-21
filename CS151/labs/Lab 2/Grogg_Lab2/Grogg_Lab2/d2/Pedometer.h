#ifndef Pedometer_h
#define Pedometer_h

class Pedometer
{

private:
		//Step variable
	int nsteps;

		//Stride variable
	int nstride;
		
		//Count increment variable
	int nincrement;

		//Overloaded >> operator
	friend std::istream& operator>>(std::istream& stream, Pedometer& p);

		//Overloaded << operator
	friend std::ostream& operator<<(std::ostream& stream, const Pedometer& p);


public:
		
		//Default Constructor
	Pedometer();

		//Overloaded Constructor, ste step variable, str stride variable
	Pedometer(int ste, int str);
	
		//Step mutator and accessor
	int GetSteps();
	void SetSteps(int s);

		//Stride mutator and accessor
	int GetStride();
	void SetStride(int s);
	
		//Unique Functions
	void Reset();
	void Increment(int I);

};
#endif
