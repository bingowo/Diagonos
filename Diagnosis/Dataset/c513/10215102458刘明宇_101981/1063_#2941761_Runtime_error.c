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
    //x>=y
    if(m == 1){
        long long int a = x;
        long long int b = y;
        int sh,yu;
        do{
            sh = a/b;
            yu = a%b;
            sum += b*4*sh;

                a = b>yu?b:yu;
                b = b<yu?b:yu;

        }while(yu != 1);
        sum += b*4;
    }
    //如果最大公约数不是1就直接*4
    else {sum = x*4;}
    printf("%lld",sum);
}
