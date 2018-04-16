#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

#include "correlation.h"

/*long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
long long mul(long long a, long long b, long long m) {
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long long t = mul(a, b / 2, m);
		return (2 * t) % m;
	}
	return (mul(a, b - 1, m) + a) % m;
}

long long pows(long long a, long long b, long long m) {
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
}*/

int main()
{
/*	// 1 step
	long long H, p;
	cin >> p;
	if (ferma(p)) {
		H = trunc(sqrt(p)) + 1;
		cout << H;
		// 2 step
		long long c, a, b;
		cin >> a;
		cin >> b;
		c = long long(pow(a, H)) % p;
		cout << c << endl;
		// 3 è 4 step
		long long *mas1 = new long long[H - 1];
		long long *mas2 = new long long[H];
		for (int i = 0; i < H; ++i)
		{
			mas1[i] = static_cast<long long>(pow(c, i + 1)) % p;
			cout << mas1[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i <= H; ++i)
		{
			mas2[i] = long long(b*pow(a, i)) % p;
			cout << mas2[i] << "\t";
		}
		cout << endl;
		// 5 step
		int u, v;
		bool flag = true;
		for (int i = 0; i < H && flag; ++i)
		{
			for (int j = 0; j <= H; ++j)
				if (mas1[i] == mas2[j])
				{
					u = i + 1;
					v = j;
					flag = false;
					break;
				}
		}
		cout << u << endl;
		cout << v << endl;
		// 6 step
		long long x;
		x = long long((H*u - v)) % (p - 1);
		cout << x << endl;
	}*/

	Correlation Alg;
	Alg.CorrAlgorithm();
	Alg.Output();


	getchar();
	getchar();
	return 0;
}