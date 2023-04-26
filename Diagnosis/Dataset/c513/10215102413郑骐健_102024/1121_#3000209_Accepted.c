#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>



int cmp(const void*p1,const void *p2)
{
    int a =*(int*)p1;
    int b =*(int*)p2;
    return (a>b)?-1:1;
}

void set(int *p,int*res,int n,int mid,int po)
{
    if(mid>=0&&res[mid]==0)res[mid]=1;
    if(po==n)return ;
    else
    {
        set(p,res,n,mid+p[po],po+1);
        set(p,res,n,mid-p[po],po+1);
        set(p,res,n,mid,po+1);
    }
}

int main()
{
    int init[200];
    int i2[2000];

    int n;
    memset(init,0,sizeof(init));
    memset(i2,0,sizeof(i2));
    scanf("%d",&n);
    for(int q =0;q<n;q++)
    {
        scanf("%d",&init[q]);
    }
    qsort(init,n,sizeof(int),cmp);
    set(init,i2,n,0,0);
    int sum=0;
    for(int g =0;g<n;g++)
    {
        i2[init[g]] = 1;
        sum+=init[g];
    }
    for(int k =1;k<=sum;k++)
    {
        printf("%d",i2[k]);
    }
    return 0;
}
