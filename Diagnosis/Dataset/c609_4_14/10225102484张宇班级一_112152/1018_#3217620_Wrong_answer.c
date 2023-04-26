#include <stdio.h>
#include <stdlib.h>
int cmp1(const void*a,const void*b){
 int num1=*(int*)a;int num2=*(int*)b;
return num1-num2;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {  scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp1);
    int k;int sum=0;
    for(k=0;k<n;k=k+2)
    sum=a[k+1]-a[k];
    printf("%d",sum);
    return 0;
}
