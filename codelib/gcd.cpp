/*
 *求最大公约数
 *最大公倍数 = a * b / 最大公约数
 */
int gcd(int a, int b){
    if (a==0) 
		return 1;
    if (a<0) 
		return gcd(-a,b);
    while (b){
        int t = a%b; 
		a=b; 
		b=t;
    }
    return a;
}

