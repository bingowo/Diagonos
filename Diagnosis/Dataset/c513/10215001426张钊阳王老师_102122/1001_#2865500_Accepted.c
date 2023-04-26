#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m,g;
    int N,R;
    int j=0,k=0;
    int *a=(int*)malloc(sizeof(int)*100);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        j=0;
        scanf("%d %d",&N,&R);
        if(N<0) printf("-");
        N=abs(N);
        while(N!=0)
        {
            g=N%R;
            N=N/R;
            if(g>=10) a[j]=g+55;
            else a[j]=g;
            j++;
        }
        for(k=j-1;k>=0;k--)
        {
            if(a[k]>=10) printf("%c",a[k]);
            else printf("%d",a[k]);
        }
        printf("\n");
    }
    return 0;
}