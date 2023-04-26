#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
int main()
{
    int n,i,j;
    int sum=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    for(j=0;j+1<n;j+=2)
        sum+=a[j]-a[j+1];
    printf("%d",sum);
    return 0;
}
