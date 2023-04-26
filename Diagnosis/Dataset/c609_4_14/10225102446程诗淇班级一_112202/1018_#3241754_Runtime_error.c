#include <stdio.h>
#include <stdlib.h>
long long int cmp(const void *a,const void *b){
    return *(long long int*)b-*(long long int*)a;
}

int main()
{
    long long int T;
    scanf("%lld",&T);
    long long int s[100];
    for(long long int j=0;j<T;j++){
        scanf("%lld",&s[j]);
    }
    qsort(s,T,sizeof(s[0]),cmp);
    long long int sum=0;
    for(long long int i=0;i<T-1;i=i+2){
        sum=sum+s[i]-s[i+1];

    }
    printf("%lld",sum);
    return 0;

}
