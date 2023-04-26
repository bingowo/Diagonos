#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long LL;
LL prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
    long long input[26];int pi=0;
    while(scanf("%lld",&input[pi++])!=EOF);
    //printf("%d\n",pi--);
    pi--;
    long long ret=0;
    long long weight[26];weight[0]=1;
    for(int i=1;i<pi;++i){
        weight[i]=1;
        for(int j=0;j<i;++j)weight[i]*=prime[j];
    }
    long long a[26];
    for(int i=0;i<pi;++i){
        a[i]=input[pi-1-i];
        ret+=a[i]*weight[i];
        //printf("%d",a[i]);
    }
    printf("%lld",ret);
    return 0;
}
