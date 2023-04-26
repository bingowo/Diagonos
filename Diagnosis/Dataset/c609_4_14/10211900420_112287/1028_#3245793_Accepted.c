#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    int*x,*y,i;
    x=*(int**)a;
    y=*(int**)b;
    for(i=0;i<51;i++)
    {
        if(x[i]==-1 || y[i]==-1)
            break;
        else if(x[i]!=y[i])
        {
            return y[i]-x[i];
        }
    }
    if(x[i]==-1)
        return 1;
    else
        return -1;
}
int main()
{
    int **a,x,N,i,k,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        a=(int**)malloc(N*sizeof(int*));
        for(int j=0;j<N;j++)
        {
            k=0;
            a[j]=(int*)malloc(51*sizeof(int));
            scanf("%d",&x);
            while(x!=-1)
            {
                a[j][k]=x;
                k++;
                scanf("%d",&x);
            }
            a[j][k]=-1;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        for(int j=0;j<N;j++)
        {
            k=0;
            while(a[j][k]!=-1)
            {
                printf("%d ",a[j][k]);
                k++;
            }
            printf("\n");
        }
    }
    return 0;
}
