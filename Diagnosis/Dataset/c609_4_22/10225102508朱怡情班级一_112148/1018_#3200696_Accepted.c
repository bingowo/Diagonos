#include <stdio.h>
#include <stdlib.h>

int cmp(void const* a,void const *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[100009];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int sum=0;
    for(int i=1;i<n;i+=2){
        sum+=(a[i]-a[i-1]);
    }
    printf("%d",sum);
    return 0;
}
