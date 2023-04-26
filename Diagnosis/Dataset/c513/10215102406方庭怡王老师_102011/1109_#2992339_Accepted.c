#include <stdio.h>
int main()
{
 	int n;
 	scanf("%d",&n);
 	for(int k=0;k<n;k++){
    printf("case #%d:\n",k);
 	int i,a,first=0,flag=0;
 	for (i=8;i>=0;i--)
    {
     scanf("%d",&a);
     if (a&&!flag)
     {
         flag=1;
         first=i;
     }
     if (first==0 && i==0)
         printf("%d",a);
     if (first!=0 &&a!=0)
     {
         if(a<0)
             printf("-");
         if(a>0 && i!=first)
             printf("+");
         if((int)fabs(a)!=1||i==0)
             printf("%d",(int)fabs(a));
         if(i>0)
             printf("x");
         if(i>1)
             printf("^%d",i);
     }
	}
	printf("\n");
 	}
}
