#include "correlation.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

long long gcd(long long a, long long b) 
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
long long mul(long long a, long long b, long long m) 
{
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long long t = mul(a, b / 2, m);
		return (2 * t) % m;
	}
	return (mul(a, b - 1, m) + a) % m;
}

long long pows(long long a, long long b, long long m) 
{
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		long long t = pows(a, b / 2, m);
		return mul(t, t, m) % m;
	}
	return (mul(pows(a, b - 1, m), a, m)) % m;
}

bool ferma(long long x) {
	if (x == 2)
		return true;
	srand(time(NULL));
	for (int i = 0; i<100; i++) {
		long long a = (rand() % (x - 2)) + 2;
		if (gcd(a, x) != 1)
			return false;
		if (pows(a, x - 1, x) != 1)
			return false;
	}
	return true;
}

Correlation::Correlation()
{
	Input();
}

void Correlation::Input()
{
	cout << "Input prime" << endl;
	cin >> prime;
	if (ferma(prime))
	{
		cout << "Input base" << endl;
		cin >> a_base;
		cout << "Input value" << endl;
		cin >> b_value;
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