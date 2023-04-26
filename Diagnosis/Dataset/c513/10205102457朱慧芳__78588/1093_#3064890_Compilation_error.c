#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int judge(_uint8 n)
{
    int flag=1;
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
    _uint8 n;
	scanf("%lld",&n);
	n++;
	while(n%9==0||judge(n)==0) n++;
	printf("%lld",n);
	return 0;
}
