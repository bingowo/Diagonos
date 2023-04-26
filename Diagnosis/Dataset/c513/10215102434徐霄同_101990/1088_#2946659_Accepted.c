#include <stdio.h>

int main()
{
    double a;
    int i,j,t,m,n;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&m,&n);
        a=1.0;
        for(j=m;j>=m-n+1;j--)
            a=a*(double)j/(double)(j-m+n);
        printf("case #%d:\n",i);
        printf("%.0f\n",a);
    }
    return 0;
}
