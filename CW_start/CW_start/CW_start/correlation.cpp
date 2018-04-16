#include "correlation.h"
#include "control.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

Correlation::Correlation()
{
	Input();
}

void Correlation::Input()
{
	cout << "Input prime" << endl;
	cin >> prime;
	if (FermaAlg(prime))
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

void Correlation::Output() const
{
	cout << "Logarithm: " << logarithm << endl;
}

void Correlation::CorrAlgorithm()
{
		//1 step
		high_bound = trunc(sqrt(prime)) + 1;

		// 2 step
		c_number = long long(pow(a_base, high_bound)) % prime;

		// 3 and 4 step
		long long *table1 = new long long[high_bound - 1];
		long long *table2 = new long long[high_bound];
		for (int u = 0; u < high_bound; ++u)
		{
			table1[u] = static_cast<long long>(pow(c_number, u + 1)) % prime;

		}
		for (int v = 0; v <= high_bound; ++v)
		{
			table2[v] = long long(b_value*pow(a_base, v)) % prime;
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
		logarithm = static_cast<long long>((high_bound *u_degree - v_degree)) % (prime - 1);
}