#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int f(int w[],int n,int target)
{
    int x[]={1,-1,0};
    int r=0;
    if(target==0) return 1;
    if(n==0) return 0;
    for(int i=0;i<3;i++)
    {
        r=f(w+1,n-1,target+x[i]*w[0]);
        if(r==1)
            return 1;
    }
    return 0;
}
int main()
{
    int w[10000];
    int n;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    for(int target=1;target<=sum;target++)
    {
        printf("%d", f(w,n,target));
    }
    return 0;
}
