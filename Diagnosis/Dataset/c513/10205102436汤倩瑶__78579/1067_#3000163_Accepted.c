#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    unsigned long long int a[74]={0};
    a[0]=0;
    a[1]=1;a[2]=1;
    for(int i=3;i<74;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%llu\n",i,a[n]);
        
        
    }
    return 0;
}