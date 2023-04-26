#include <stdio.h>
#include <stdlib.h>
#define N 32700

int main()
{
    int n,*p,i,count0=1,j;
    scanf("%d",&n);
    p=(int*)malloc(N*sizeof(int));
    p[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<count0;j++)
        {
            if(p[j]==1)
                p[j+count0]=0;
            else
                p[j+count0]=1;
        }
        count0=count0*2;
    }
    for(i=0;i<count0;i++)
    {
        printf("%d",p[i]);
    }
    free(p);
    return 0;
}
