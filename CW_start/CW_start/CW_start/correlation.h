#ifndef  _CORRELATION_H_
#define  _CORRELATION_H_
#include <NTL/ZZ.h>
using namespace NTL;

class Logarithm
{
private:
	//ZZ 
	ZZ prime;
	//ZZ 
	ZZ a_base;
	//ZZ 
	ZZ b_value;
	//ZZ 
	ZZ log_value;
public:
	Logarithm();
	void CorrAlgorithm();
	void Input();
	~Logarithm() {};
	void Output() const;
};

#endif