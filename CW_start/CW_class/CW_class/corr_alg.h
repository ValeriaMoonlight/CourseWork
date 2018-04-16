#ifndef  _CORRALG_H_
#define  _CORRALG_H_

class CorrAlg
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
	CorrAlg();
	long long CorrAlgorithm();
	//~CorrAlg() {};
	void Output() const;
};
#endif