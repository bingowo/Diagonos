#include<stdio.h>
int reverse(int n)
{
    int m;
	if()
	for(int i=0;i<10;i++)
	{
		if(i==0)
		{
		    if(n>2332)
		    {
		        printf("%d",n%2333);
		        n=n/2333;
		    }
		    else
		    {
		        printf("%d",n);
			    break;
		    }
		}
		else
		{
		    if(n>2332)
		    {
			     printf(" %d\n",n%2333);
		     	 n=n/2333;
	    	}
		    else
		    {
		    	printf(" %d",n);
			    break;
		    }
		}
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
    }
    return 0;
}