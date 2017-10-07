//可参考poj1061
/*
 * 如果gcd(a, b) = d, 则存在x, y, 使得d = a*x + b*y
 */
void gcd_extend(long long a,long long b,long long &g,long long &x,long long &y)
{
	if (!b)
	{
		g = a;
		x = 1;
		y = 0;
		return;
	}
	gcd_extend(b, a % b, g, y, x);
	y -= a / b * x;
}
