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
    long long int sum = 0;
    if(x%y == 0){
        sum = y*4*(x/y);
        printf("%lld",sum);
        return 0;
    }
    if(m == 1){
        long long int fenmu;
        long long int a = x;
        long long int b = y;
        long long int sh,yu;
        do{
            sh = a/b;
            yu = a%b;
            sum += b*4*sh;
            a = b>yu?b:yu;
            fenmu = b;
            b = b<yu?b:yu;
        }while(yu > 1);
        sum += fenmu*4;
    }
        else{
        long long int a0 = x;
        long long int b0 = y;
        long long int fenmu;
        long long int sh,yu;
        do{
            sh = a0/b0;
            yu = a0%b0;
            sum += b0*4*sh;
            a0 = b0>yu?b0:yu;
            fenmu = b0;
            b0 = b0<yu?b0:yu;
        }while(yu > 1);
        sum += fenmu*4*sh;
    }
    printf("%lld",sum);
}
