#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{
	// 1 этап
	long int H, p;
	cin >> p;
	H = trunc(sqrt(p)) + 1;
	cout << H;
	// 2 этап
	long int c, a, b;
	cin >> a;
	cin >> b;
	c = pow(a, H) - p*trunc(pow(a, H) / p);
	cout << c << endl;
	// 3 и 4 этап
	long int *mas1 = new long int[H - 1];
	long int *mas2 = new long int[H];
	for (int i = 0; i < H; ++i)
	{
		mas1[i] = pow(c, i + 1) - p*trunc(pow(c, i + 1) / p);
		cout << mas1[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i <= H; ++i)
	{
		mas2[i] = b*pow(a, i) - p*trunc(b*pow(a, i) / p);
		cout << mas2[i] << "\t";
	}
	cout << endl;
	// 5 этап
	int u, v;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j <= H; ++j)
		{
			if (mas1[i] == mas2[j])
			{
				u = i + 1;
				v = j;
			}
		}
	cout << u << endl;
	cout << v << endl;
	// 6 этап
	long int x;
	x = (H*u - v) - (p - 1)*trunc((H*u - v) / (p - 1));
	cout << x << endl;
	getchar();
	getchar();
	return 0;
}