#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int cnp(long long int m)
{
	while(m>10||m<-10){m=m/10;}
	return(m);
}
int cmp(const void *a,const void *b)
{
    long long int*A=(long long int*)a;
    long long int*B=(long long int*)b;
    int result=0;
    if(cnp(*A)!=cnp(*B)) result=abs(cnp(*A))>abs(cnp(*B))? -1:1;
    else result=*A>*B? 1:-1;
    return result;
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
        for(int k=0;k<num;k++)
        {
            if(k!=num-1) printf("%lld ",L[k]);
            else printf("%lld\n",L[k]);
        }
        free(L);
    }
    return 0;
}