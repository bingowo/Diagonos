#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define N 105
int cmp(const void*a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}
int sol(int a[])
{
    int b[8]= {0};
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            b[i]=b[i]*2+a[(i+j)%8];
        }
    }
    qsort(b,8,sizeof(int),cmp);
    return b[0];
}
int main()
{
    int a[N][N],w,h;
    scanf("%d %d",&w,&h);
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            scanf("%d",&a[i][j]);
    for(int i=1; i<=h-2; i++)
    {
        int c[10]= {0};
        for(int j=1; j<=w-2; j++)
        {
            if(a[i][j]>=a[i+1][j+1])
                c[0]=1;
            else
                c[0]=0;
            if(a[i][j+1]>=a[i+1][j+1])
                c[1]=1;
            else
                c[1]=0;
            if(a[i][j+2]>=a[i+1][j+1])
                c[2]=1;
            else
                c[2]=0;
            if(a[i+1][j]>=a[i+1][j+1])
                c[7]=1;
            else
                c[7]=0;
            if(a[i+1][j+2]>=a[i+1][j+1])
                c[3]=1;
            else
                c[3]=0;
            if(a[i+2][j]>=a[i+1][j+1])
                c[6]=1;
            else
                c[6]=0;
            if(a[i+2][j+1]>=a[i+1][j+1])
                c[5]=1;
            else
                c[5]=0;
            if(a[i+2][j+2]>=a[i+1][j+1])
                c[4]=1;
            else
                c[4]=0;
            int ans=sol(c);
            printf("%d ",ans);
        }
        printf("\n");
    }
    return 0;
}
