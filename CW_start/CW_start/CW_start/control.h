#ifndef  _CONTROL_H_
#define  _CONTROL_H_
#include "NTL/ZZ.h"
using namespace NTL;

long long GCD1(long long a, long long b);
long long Multipl(long long a, long long b, long long m);
long long Powe(long long a, long long b, long long m);
bool FermaAlg(long long x);

bool Generator(ZZ gen, ZZ p);

#endif
