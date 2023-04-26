#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int judge(int n)
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
	int n;
	scanf("%d",&n);
	n++;
	while(n%9==0||judge(n)==0) n++;
	printf("%d",n);
	return 0;
}
