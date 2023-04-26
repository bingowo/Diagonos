#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 50
int p[35]={1,2,3,5,7,11,13,17,19,23,29,
31,37,41,43,47,53,59,61,67,71,
73,79,83,89,91,97};
void mul(int *result,int a)//大整数乘普通整数
{
    int i,carry=0;
    for (i=0; i<N; i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
    }
}
void addi(int result[],int b[])
{
    for(int i=0;i<N;i++)
    {
        result[i] += b[i];
        result[i+1]+=result[i]/10;
        result[i]%=10;
    }
}
void Rto10(int a[],int result[],int len)
{
	int i;
	unsigned long long sum = 0;
	for (i = 0; i < len; i++)
	{

		mul(result,p[len-i]);
		/*for(int i=0;i<N;i++)
            printf("%d ",result[i]);
        printf("\n");*/
        int a1[50]={0};
        a1[0]=a[i]%10;
        a1[1]=a[i]/10;
		addi(result,a1);
		/*for(int i=0;i<N;i++)
            printf("%d ",result[i]);
        printf("\n");*/
	}
	//printf("\n");
}

int main()
{
    char s[150];
    int a[50]={0},k=0;
    int b[50]={0},t=0;
    int result[100]={0};
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
   // unsigned long long sum=Rto10(a,t);
    Rto10(a,result,t);
    int i=N;
    while(result[i]==0)i--;
    if(strcmp(s,"0")==0)
        printf("0");
    else
    {
        for(;i>=0;i--)
            printf("%d",result[i]);
    }
    return 0;
}
