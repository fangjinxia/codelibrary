#include<iostream>

using namespace std;

long long multi_mod(long long a, long long b, long long c)
{    //返回(a*b) mod c,a,b,c<2^63
	a %= c;
	b %= c;
	long long ret = 0;
	while (b)
	{
		if (b & 1)
			ret = (ret + a) % c;
		a <<= 1;
		a %= c;
		b >>= 1;
	}
	return ret;
}

long long pow_mod(long long x, long long n, long long mod)
{  //返回x^n mod c ,非递归版
	x %= mod;
	if (n == 1)
		return x;
	long long ret = 1;
	while (n)
	{
		if (n & 1)
			ret = multi_mod(ret, x, mod);
		n >>= 1;
		x = multi_mod(x, x, mod);
	}
	return ret;
}



int main(int argc,char*argv[])
{
    long long x, n, mod;
    cin >> x >> n >> mod;
    long long ret = pow_mod(x, n, mod);
    cout  << ret << endl;
    return 0;
}