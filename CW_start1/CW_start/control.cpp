#include "control.h"
#include <iostream>
#include <time.h>

long long GCD(long long a, long long b)
{
	if (b == 0)
		return a;
	return GCD(b, a%b);
}
long long Mult(long long a, long long b, long long m)
{
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long long t = Mult(a, b / 2, m);
		return (2 * t) % m;
	}
	return (Mult(a, b - 1, m) + a) % m;
}

long long Pows(long long a, long long b, long long m)
{
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		long long t = Pows(a, b / 2, m);
		return Mult(t, t, m) % m;
	}
	return (Mult(Pows(a, b - 1, m), a, m)) % m;
}

bool FermaAlg(long long x) {
	if (x == 2)
		return true;
	srand(time(NULL));
	for (int i = 0; i<100; i++) {
		long long a = (rand() % (x - 2)) + 2;
		if (GCD(a, x) != 1)
			return false;
		if (Pows(a, x - 1, x) != 1)
			return false;
	}
	return true;
}

bool Generator(long long gen, long long p)
{
	/*for (int i = 1; i < p; ++i)
	{
		if (static_cast<long long>(pow(gen, i)) % p == 1 && i != p - 1)
			return false;
	}*/
	return true;
}