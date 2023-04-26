#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    scanf("%d\n",&a);
    for (int i=0;i<a;i++)
    {
       int count =0;
       char c[121]={'\0'};
       gets(c);
       for (int j=0;j<strlen(c);j++)
       {
           int num=c[j];
           while(num){if (num%2) count++;
           num=num/2;
       }}
       int m=count;
       int n=8*strlen(c);
       for(int x=m;x>=1;x--)
	{
		if((m%x==0)&&(n%x==0))
		{
			m=m/x;
			n=n/x;
		}
	}
       printf("%d/%d\n",m,n);


    }
    return 0;
}
