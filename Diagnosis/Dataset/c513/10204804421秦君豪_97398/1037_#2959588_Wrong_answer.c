#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 4611686018427387904


int cmp(const void* a,const void *b)
{

    unsigned long long int a1=*(unsigned long long int*)a;
    unsigned long long int b1=*(unsigned long long int*)b;
    return a1>b1?-1:1;

}



int main(void)
{

    long long int n,m;
    scanf("%lld%lld",&n,&m);
    unsigned long long int *num=(unsigned long long int*)malloc((n+1)*sizeof(unsigned long long int));
    for (int i=0;i<n;i++)
    {
        scanf("%llu",&num[i]);
    }
    qsort(num,n,sizeof(unsigned long long int),cmp);
    unsigned long long int ret = 1e19;
    for(int i=0;i<n-m+1;i++)
    {
//        printf("pass");
        unsigned long long int max =num[i];
        unsigned long long int tmp=0;
        for(int j=i;j<i+m;j++)
        {
            tmp+=abs(num[i]-num[j]);
            if (tmp>ret) break;
        }
        ret=tmp<ret?tmp:ret;
    }
    printf("%llu",ret);
    free(num);
}
