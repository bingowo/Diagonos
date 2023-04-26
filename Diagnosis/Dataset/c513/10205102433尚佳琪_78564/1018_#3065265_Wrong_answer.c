#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int p[35]={1,2,3,5,7,11,13,17,19,23,29,
31,37,41,43,47,53,59,61,67,71,
73,79,83,89,91,97};
unsigned long long Rto10(int a[],int len)
{
	int i;
	unsigned long long sum = 0;
	for (i = 0; i < len; i++)
	{
		sum = sum * p[len-i] + a[i];
	}
	return sum;
}
int main()
{
    char s[150];
    int a[50]={0},k=0;
    int b[50]={0},t=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]!=',')
            a[k]=a[k]*10+s[i]-'0';
        else
            k++;
    }
    k++;
    for(int i=k-1;i>=0;i--)
        b[t++]=a[i];
    unsigned long long sum=Rto10(a,t);
    printf("%llu",sum);
   // for(int i=0;i<t;i++)
   //     printf("%d ",a[i]);
    return 0;
}
