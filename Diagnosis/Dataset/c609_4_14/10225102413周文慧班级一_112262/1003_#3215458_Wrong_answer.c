#include<stdio.h>
#include<string.h>
void reverse(long long n)
{
    unsigned long long s[10];
    int len;
	for(int i=0;i<10;i++)
	{
		if(n>2332)
		{
			s[i]=n%2333;
		    n=n/2333;
	    }
		else
		{
		    s[i]=n;
		    len=i+1;
			break;
		}
	}
	for(int m=len-1;m>=0;m--)
	{
	    printf("%lld ",s[m]);
	}
}
int main()
{
    int T,i;
    long long n;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%lld",&n);
        if(n==0)
            printf("0");
        else
        {
            reverse(n);
            printf("\n");
        }
    }
    return 0;
}
