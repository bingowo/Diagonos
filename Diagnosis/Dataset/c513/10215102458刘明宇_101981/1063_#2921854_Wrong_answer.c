#include <stdio.h>
#include <stdlib.h>

long long int GCD(long long int m,long long int n)
{
	if(n>m)
	{
		long long int z;
		z = m;
		m = n;
		n = z;
	}
	if(n == 0) return m;
	else if(m % n == 0) return n;
	while(n!=0 && m%n !=0)
	{
		long long int t = m % n;
		m = n;
		n = t;
	}
	return n;
}

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int m = GCD(x,y);
    long long int sum;
    if(m == 1){
        int a = x;
        int b = y;
        while(a != 1 && b != 1){
            int len = a/b;
            sum += 4*b * len;
            if(len > b){
                a = len;
                }

            if(len < b){
                a = b;
                b = len;
            }
        }
        sum += (a/b) *4;
    }
    else {sum = x*4;}
    printf("%lld",sum);
}