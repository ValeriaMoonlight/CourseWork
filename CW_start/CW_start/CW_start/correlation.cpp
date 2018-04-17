#include "correlation.h"
#include "control.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
using namespace NTL;

Logarithm::Logarithm()
{
	Input();
}

void Logarithm::Input()
{
	cout << "Input prime" << endl;
	cin >> prime;
	if (ProbPrime(prime))
	{
		cout << "Input base" << endl;
		cin >> a_base;
		if (Generator(a_base, prime))
		{
			cout << "Input value" << endl;
			cin >> b_value;
		}
		else
		{
			cout << "Number is not generator" << endl;
			Input();
		}
	}
	else
	{
		cout << "Number is not prime" << endl;
		Input();
	}
}

void Logarithm::Output() const
{
	cout << "Logarithm: " << log_value << endl;
}

void Logarithm::CorrAlgorithm()
{
	ZZ high_bound, c_number, u_degree, v_degree;
		//1 step
		high_bound = SqrRoot(prime) + 1;

		// 2 step
		c_number = PowerMod(a_base, high_bound, prime);

		// 3 and 4 step
		long hb;
		conv(hb, high_bound);
		ZZ *table1 = new ZZ [hb - 1];
		ZZ *table2 = new ZZ [hb];
		for (int u = 0; u < high_bound; ++u)
		{
			table1[u] = PowerMod(c_number, u + 1, prime);

		}
		for (int v = 0; v <= high_bound; ++v)
		{
			table2[v] = b_value*PowerMod(a_base, v, prime);
		}
		// 5 step
		bool flag = true;
		for (int u = 0; u < high_bound  && flag; ++u)
		{
			for (int v = 0; v <= high_bound; ++v)
				if (table1[u] == table2[v])
				{
					u_degree = u + 1;
					v_degree = v;
					flag = false;
					break;
				}
		}
		// 6 step
		log_value = SubMod(MulMod(high_bound,u_degree, prime-1),v_degree,prime-1);
}