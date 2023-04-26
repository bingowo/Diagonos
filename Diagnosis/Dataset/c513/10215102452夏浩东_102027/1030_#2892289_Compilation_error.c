#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    long long int*A=(long long int*)a;
    long long int*B=(long long int*)b;
    long long int*C=A;
    long long int*D=B;
    while(A>10||A<-10){A=A/10;}
    while(B>10||B<-10){B=B/10;}
    if(A!=B) A>B? return -1:return 1;
    else C>D? return 1:return -1;
    
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        long long int *L=(long long int*)malloc(num*sizeof(long long int));
        for(int k=0;k<num;k++)
        {
            scanf("%lld",&L[k]);
        }
        qsort(L,num,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<num-1;k++)
        {
            printf("%lld ",L[k]);
        }
        printf("%lld\n",L[k]);
    }
    return 0;
}