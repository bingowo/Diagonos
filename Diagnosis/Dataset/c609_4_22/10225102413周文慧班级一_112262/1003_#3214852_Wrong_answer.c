#include<stdio.h>
#include<string.h>
int reverse(int n)
{
    int s[10];
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
	    printf("%d ",s[m]);
	}
}
int main()
{
    int T,n,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        reverse(n);
        printf("\n");
    }
    return 0;
}
