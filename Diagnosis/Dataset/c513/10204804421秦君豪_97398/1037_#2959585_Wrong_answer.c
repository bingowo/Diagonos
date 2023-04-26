#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 4611686018427387904


int cmp(const void* a,const void *b)
{

    long long int a1=*(long long int*)a;
    long long int b1=*(long long int*)b;
    return a1>b1?-1:1;

}



int main(void)
{

    long long int n,m;
    scanf("%lldll%d",&n,&m);
    long long int *num=(long long int*)malloc((n+1)*sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&num[i]);
    }
    qsort(num,n,sizeof(long long int),cmp);
    long long int ret = 1e6;
    for(int i=0;i<n-m+1;i++)
    {
//        printf("pass");
        long long int max =num[i];
        int tmp=0;
        for(int j=i;j<i+m;j++)
        {

            tmp+=abs(num[i]-num[j]);
        }
        ret=tmp<ret?tmp:ret;
    }
    printf("%lld",ret);
    free(num);
}
