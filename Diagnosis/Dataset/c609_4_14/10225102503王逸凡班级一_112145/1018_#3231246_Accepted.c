#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int*)a) - (*(int*)b);
}


int main()
{
    int n;
    int *a;
    scanf ("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    long long sum=0;
    int j=1;
    for (j=1;j<n;j+=2){
        sum+=(a[j]-a[j-1]);
    }
    printf("%d",sum);

    return 0;
}
