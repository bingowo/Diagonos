#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int s[1010];
int cmp(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *a-*b;
}
int AllSubsets(int *arr,int len,int b[])
{
    int i,j,k;
    int index=0;
    int num=1<<len;
    for(i=0; i<num; i++)
    {
        j=i;
        k=0;
        int sum=0;
        while(j)
        {
            if(j&1)
            {
                sum+=arr[k];
            }
            j>>=1;
            k++;
        }
        s[sum]=1;
        b[index++]=sum;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[11];
    int ans=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    int b[1000];
    int k=AllSubsets(a,n,b);
    qsort(b,k,sizeof(b[0]),cmp);
    for(int i=0; i<k-1; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            int d=abs(b[j]-b[i]);
            printf("%d\n",d);
            s[d]=1;
        }
    }
    for(int i=1; i<=ans; i++) printf("%d",s[i]);
    return 0;
}
