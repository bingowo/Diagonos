#include<stdio.h>
#include<string.h>
long long int zhishu(int a,long long int b)
{
	long long int c=1;
    for(int i=0;i<a;i++)
    {
        c=c*b;
    }
    return c;
}
int main( )
{
    int number;
    scanf("%d",&number);
    char s[number][100];
    long long int result[number];
    for(int i=0;i<number;i++)
    {
        scanf("%s",s[i]);
        int length=strlen(s[i]);
        int real[length];
        for(int j=0;j<strlen(s[i]);j++)
        {
            if(s[i][j]=='-')
            {
            	real[j]=-1;
            }
            else if(s[i][j]=='1')
            {
            	real[j]=1;
            }
            else
            {
            	real[j]=0;
            }
        }
        long long int d=0;
        for(int k=0;k<length;k++)
        {
        	d=d+real[k]*zhishu(length-k-1,3);
		}
		result[i]=d;
    }
    for(int i=0;i<number;i++)
    {
        printf("case #%d:\n",i);
        printf("%lld\n",result[i]);
    }
    return 0;
}