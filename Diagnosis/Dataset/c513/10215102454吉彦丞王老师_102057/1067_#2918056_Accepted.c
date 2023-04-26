#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        if(n==0)
    	{
        	printf("%d\n",0);
    	}
    	else if(n==1||n==2)
    	{
    	    printf("%d\n",1);
    	}
    	else
    	{
        	long long int a1=0,a2=1,a3=1;
        	long long int a4;
        	for(int j=0;j<n-2;j++)
        	{
            	a4=a1+a2+a3;
            	a1=a2;
            	a2=a3;
            	a3=a4;
        	}
        	printf("%lld\n",a4);
    	}
    }
    return 0;
}