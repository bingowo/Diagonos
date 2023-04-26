#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ZM(long long int a,long long int b)//a<b  辗转相除法求最大公约数
{
	long long int n = 0;
	while (a%b)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return n > 0 ? n : 1ll;
}

int main()
{
    char NUM[40];
    scanf("%s",NUM);
    long long int sum = 0;
    int i = 0;
    char c=0;
    if (NUM[0] = '0')  {printf("0");}
    else 
    {
        while(((c = NUM[i]) != '.')&&(c!= '\0'))
    {
        if (c == '1')  sum = sum * 3 + 1;
        else if (c == '0')  sum = sum * 3;
        else  sum = sum * 3 - 1;
        i++;
    }
    if (NUM[i]== '\0'&& sum != 0)  printf("%lld ",sum);
    else
    {
        long long int zi = 0;
        long long int mu = 1;
        while((c = NUM[++i]) != '\0')
        {
            mu *= 3;
        if (c == '1')  zi = zi * 3 + 1;
        else if (c == '0')  zi = zi * 3;
        else  zi = zi * 3 - 1;
        }
        if (zi<0 && sum > 0) {sum = sum - 1;zi = mu +zi;}
        else if (zi<0 && sum<0)  zi = abs(zi);
        else if (zi>0 && sum <0)  {sum = sum + 1;zi = mu - zi;}
        long long int G = ZM(zi,mu);
        zi = zi/G;
        mu = mu/G;
        if (sum)  printf("%lld ",sum);
        printf("%lld %lld",zi,mu);
    }}
    return 0;
}
