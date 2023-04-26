#include <stdio.h>

int main()
{
    int n,t,i,j,x;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        x=1;
        scanf("%d",&n);
        for(j=0;j<n;j++)
            x=x*2;
        printf("case #%d:\n",i);
        printf("%d\n",x);
    }
    return 0;
}
