#include <stdio.h>
#include <stdlib.h>
int cmp(void* a,void* b){
    int m=*(int*)a,n=*(int*)b;
    return m-n;
}
int main()
{
    int n,i;
    long long int sum=0;
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    qsort(x,n,sizeof(x[0]),cmp);
    for(i=0;i<n/2;i++) sum=sum+x[i*2+1]-x[i*2];
    printf("%d",sum);
    return 0;
}
