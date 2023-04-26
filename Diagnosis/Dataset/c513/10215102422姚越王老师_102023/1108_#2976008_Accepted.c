#include<stdio.h>
#define C 100
typedef struct{int divisor,quotient,remainder;} div;
int main()
{
    int T,i,j,integer,n,m;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d %d",&n,&m);
        integer=n/m;
        n-=integer*m;
        if(!n){printf("case #%d:\n%d\n",cas,integer);continue;}
        div a[C];a[1].divisor=n*10;a[1].quotient=a[1].divisor/m;a[1].remainder=a[1].divisor-a[1].quotient*m;
        if(!a[1].remainder){printf("case #%d:\n%d.%d\n",cas,integer,a[1].quotient);continue;}
        int flag1=0,flag2=0;
        for(i=2;;++i)
        {
            a[i].divisor=a[i-1].remainder*10;
            for(j=1;j<i;++j)if(a[j].divisor==a[i].divisor){flag2=1;break;}
            a[i].quotient=a[i].divisor/m;
            a[i].remainder=a[i].divisor-a[i].quotient*m;
            if(!a[i].remainder){flag1=1;break;}
            if(flag2)break;
        }
        if(flag1)
        {
            printf("case #%d:\n%d.",cas,integer);
            for(j=1;j<=i;++j)printf("%d",a[j].quotient);
            printf("\n");
        }
        else if(flag2)
        {
            printf("case #%d:\n%d.",cas,integer);
            for(int k=1;k<i;++k)printf("%d",a[k].quotient);
            printf("\n%d-%d\n",j,i-1);
        }
    }
    return 0;
}