#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int judge(long long int n)
{
    long long int flag=1;
    while(n){
        if(n%10==9)
            {
                flag=0;
                break;
            }
    n=n/10;
    }
    return flag;
}
int main()
{
	long long int n;
	scanf("%lld",&n);
	n++;
	while(n%9==0||judge(n)==0) n++;
	printf("%lld",n);
	return 0;
}
