#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void*a1,connst void*a2)
{
    int a=*(int*)a1;
    int b=*(int*)a2;
    
}
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
    qsort(b,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
    printf("%d ",b[i]);
    return 0;
    
    
    
}