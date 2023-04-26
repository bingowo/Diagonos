#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int result=0;
    for(int j=1;j<n;j=j+2)
    {
        result=result+a[j]-a[j-1];
    }
    printf("%d",result);
    return 0;
}