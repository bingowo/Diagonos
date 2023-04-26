#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int m;
    scanf("%d",&m);
    int a[1000]={0},p;
    for(int i=0,p=1000;i<m;i++,p--)
    {
        int l;
        scanf("%d",&l);
        a[l]=p;
        
    }
    int n;
    scanf("%d",&n);
    int b[n+1];
    
    for(int i=0;i<n;i++)
    printf("%d ",b[i]);
    int cmp(const void*a1,const void*a2)
{
    int m=*(int*)a1;
    int n=*(int*)a2;
    return a[n]-a[m];
    
}
qsort(b,n,sizeof(int),cmp);
    return 0;
    
    
    
}