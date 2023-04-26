#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 4611686018427387904


int cmp(const void* a,const void *b)
{

    int a1=*(int*)a;
    int b1=*(int*)b;
    return a1>b1?-1:1;

}



int main(void)
{

    int n,m;
    scanf("%d%d",&n,&m);
    int *num=(int*)malloc((n+1)*sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    qsort(num,n,sizeof(int),cmp);
    int ret = 1e6;
    for(int i=0;i<n-m+1;i++)
    {
//        printf("pass");
        int max =num[i];
        int tmp=0;
        for(int j=i;j<i+m;j++)
        {

            tmp+=abs(num[i]-num[j]);
        }
        ret=tmp<ret?tmp:ret;
    }
    printf("%d",ret);
    free(num);
}
