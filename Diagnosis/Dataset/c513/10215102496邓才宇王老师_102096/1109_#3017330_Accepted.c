#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int first=0,flag=0;
        for(int j=8;j>=0;j--)
        {
            int d;
            scanf("%d",&d);
            if(flag==0&&d!=0)
            {
                first=j;
                flag=1;
            }
            if(first==0&&j==0)
            {
                printf("%d",d);
            }
            if(d!=0&&first!=0)
            {
                if(d>0&&j!=first) printf("+");
                if(d<0) printf("-");
                if(j>1)
                {
                    if(abs(d)!=1)
                        printf("%dx^%d",abs(d),j);
                    else printf("x^%d",j);
                }
                if(j==1)
                {
                    if(abs(d)!=1)
                        printf("%dx",abs(d));
                    else printf("x");
                }
                if(j==0) printf("%d",abs(d));
            }
        }
         printf("\n");
    }
}
