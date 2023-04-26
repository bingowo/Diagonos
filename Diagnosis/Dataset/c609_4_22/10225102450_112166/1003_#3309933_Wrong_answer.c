#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%ld",&n);
        int y=0;
        int qqq[100];
        if(n<2333)
        {
            printf("%ld",n);
        }
        
        while(n>=2333)
        {
            qqq[y]=n%2333;
            y=y+1;
		    n=n/2333;
        }
        y=y;
        qqq[y]=n%2333;
        for(int s=0;s<y+1;s++)
        {
            printf("%ld",qqq[y-s]);
            printf(" ");
        }
        printf("\n");
    }
	return 0;
}
