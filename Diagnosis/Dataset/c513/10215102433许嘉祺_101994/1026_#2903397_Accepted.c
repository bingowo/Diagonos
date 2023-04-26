#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
    long long a1=*(long long*)a,b1=*(long long *)b;
    if(a1>b1)return 1;
    else return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long*email=(long long*)malloc(sizeof(long long)*n);
    long long t;
    int num=0;
    for (int i=0;i<n;i++){
        scanf("%lld",&t);
        email[num++]=t;
    }
    t=0;
    qsort(email,num,sizeof(long long),cmp);
    for (int i=0;i<num;i+=2)
        t=t+email[i+1]-email[i];
    free(email);
    printf("%lld\n",t);
    return 0;
}