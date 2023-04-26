#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",T);
    for(int j=0;j<T;j++)
    {
        printf("case #%d",j);
    int i,a,first=0,flag=0;
    for(i=8;i>=0;i--)
    {
        scanf("%d",&a);
        if(a&&!flag){flag=1;first=i;}
        if(first==0&&i==0)pintf("%d",a);
        if(first!=0&&a!=0)
        {
            if(a<0)printf("-");
            if(a>0&&i!=first)printf("+");
            if((int)fabs(a)!=1||i==0)printf("%d",(int)fabs(a));
            if(i>0)printf("x");
            if(i>1)printf("^%d",i);
        }

    }
    printf("\n");
    }
    return 0;
}