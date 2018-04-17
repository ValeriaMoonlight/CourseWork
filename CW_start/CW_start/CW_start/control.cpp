#include "control.h"
#include <iostream>
#include <time.h>

long long GCD1(long long a, long long b)
{
	if (b == 0)
		return a;
	return GCD1(b, a%b);
}

long long Multipl(long long a, long long b, long long m)
{
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long t = Multipl(a, b / 2, m);
		return (2 * t) % m;
	}
	return (Multipl(a, b - 1, m) + a) % m;
}

long long Powe(long long a, long long b, long long m)
{
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		long t = Powe(a, b / 2, m);
		return Multipl(t, t, m) % m;
	}
	return (Multipl(Powe(a, b - 1, m), a, m)) % m;
}

bool FermaAlg(long long x) {
	if (x == 2)
		return true;
	srand(time(NULL));
	for (int i = 0; i<100; i++) {
		long a = (rand() % (x - 2)) + 2;
		if (GCD1(a, x) != 1)
			return false;
		if (Powe(a, x - 1, x) != 1)
			return false;
	}
	return true;
}

bool Generator(ZZ gen, ZZ p)
{
	for (int i = 1; i < p; ++i)
	{
		if (PowerMod(gen, i,p) == 1 && i != p - 1)
			return false;
	}
	return true;
}