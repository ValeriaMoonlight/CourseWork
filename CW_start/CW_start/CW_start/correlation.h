#ifndef  _CORRELATION_H_
#define  _CORRELATION_H_

class Correlation
{
private:
	long long prime;
	long long high_bound;
	long long c_number;
	long long a_base;
	long long b_value;
	long long u_degree;
	long long v_degree;
	long long logarithm;
public:
	Correlation();
	void CorrAlgorithm();
	void Input();
	~Correlation() {};
	void Output() const;
};

#endif