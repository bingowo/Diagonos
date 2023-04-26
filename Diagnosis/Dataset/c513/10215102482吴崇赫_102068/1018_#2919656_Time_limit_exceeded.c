#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long LL;
LL prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
    int input[26];int pi=0;
    while(scanf("%d",&input[pi++])!=EOF);
    LL ret=0;
    LL weight[26];weight[0]=1;
    /*for(int i=1;i<pi;++i){
        weight[i]=1;
        for(int j=0;j<i;++j)weight[i]*=prime[j];
    }*/
    int a[26];
    for(int i=0;i<pi;++i){
        a[i]=input[pi-1-i];
        //ret+=a[i]*weight[i];
        printf("%d",a[i]);
    }
    //printf("%llu",ret);
    return 0;
}
