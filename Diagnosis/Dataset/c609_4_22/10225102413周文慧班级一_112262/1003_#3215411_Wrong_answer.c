#include<stdio.h>
#include<string.h>
unsigned reverse(unsigned n)
{
    unsigned s[10];
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
	    printf("%llu ",s[m]);
	}
}
int main()
{
    int T,i;
    unsigned long long n;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%lld",&n);
        reverse(n);
        printf("\n");
    }
    return 0;
}
