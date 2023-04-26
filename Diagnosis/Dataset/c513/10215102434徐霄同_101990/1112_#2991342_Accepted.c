#include <stdio.h>

int main()
{
    int t,i,j,k,n,s;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        s=0;
        for(j=0;j<=n/4;j++)
            for(k=0;k<=(n-4*j)/3;k++)
                s=s+(n-4*j-3*k)/2+1;
        printf("%d\n",s);
    }
    return 0;
}
