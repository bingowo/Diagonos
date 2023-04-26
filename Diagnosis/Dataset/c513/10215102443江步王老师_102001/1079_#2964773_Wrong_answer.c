#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


void solve(int k,int n,int m);
int cmp(const void*_a, const void *_b);

int main()
{
    int t;
    int i;
    scanf("%d",&t);
    for (i=0;i<t;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        solve(i,n,m);
    }
    return 0;
}

void solve(int k,int n,int m)
{
    int i,j;
    int *a = (int *)malloc(sizeof(int)*n);
    int *b = (int *)malloc(sizeof(int)*(n*(n+1)/2));
    //创建数组a，b，a数组保存原数列，b数组保存新的子数列和数组

    for (i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }

    int sum;
    int num=0;
    for (i=0;i<n;i++)
    {
        sum=0;
        for (j=1;j<n-i+1;j++)
        {
            sum=sum+a[i+j-1];
        }

        b[num++]=sum;
    }

    qsort(b,num,sizeof(int),cmp);
    
    printf("case #%d:\n",k);
    for (i=0;i<m;i++)
    {
        int l,u;
        long long res=0;
        scanf("%d %d",&l,&u);
        l--;u--;

        for (j=l;j<=u;j++)
        {
            res+=b[j];
        }
        printf("%lld\n",res);
    }
    free(a);free(b);
    return ;
}

int cmp(const void *_a, const void *_b)
{
    int *a = (int *)_a;
    int *b = (int *)_b;
    return (*a-*b);
}