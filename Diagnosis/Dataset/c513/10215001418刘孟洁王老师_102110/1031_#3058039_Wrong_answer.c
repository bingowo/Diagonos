#include<stdio.h>
#include<string.h>
#include<math.h>

int cmp1(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c>d) return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c>d) return 1;
    else return -1;
}

int main()
{
    int T,i,j,k,n,x[1007],y[1007],ans=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&x[j]);
        qsort(x,j,sizeof(int),cmp1);
        for(k=0;k<n;k++)
            scanf("%d",&y[k]);
        qsort(y,k,sizeof(int),cmp2);
        for(j=0;j<n;j++)
        {
            ans+=x[j]*y[j];
        }
        printf("case #%d:\n",i);
        printf("%d",ans);

    }
    return 0;
}
