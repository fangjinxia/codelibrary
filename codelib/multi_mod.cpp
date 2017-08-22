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

