#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *a0=(int*)a;
    int *b0=(int*)b;
    if(a0[1]!=-1 && b0[1]!=-1)
        return a0[1]-b0[1];
    else if(a0[1]==-1 && b0[1]!=-1)
        return 1;
    else if(a0[1]!=-1 && b0[1]==-1)
        return -1;
    else
        return a0[0]-b0[0];
}
int main()
{
    int a[500];
    int b[500][2];
    int m,n,i,j;
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&b[i][0]);
        b[i][1]=-1;
        for(j=0;j<m;j++)
            if(b[i][0]==a[j])
                b[i][1]=j;
    }
    qsort(b,n,sizeof(b[0]),cmp);
    for(i=0;i<n;i++){
        printf("%d",b[i][0]);
        if(i==n-1)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
