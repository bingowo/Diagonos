#include <stdio.h>
#include <stdlib.h>
int cmp(const void *k1,const void *k2)
{
    long long int *p1=(long long int*)k1;
    long long int *p2=(long long int*)k2;
    long long int *p3=(long long int*)k1;
    long long int *p4=(long long int*)k2;
    
    int num1=0,num2=0;
    int d=1;
	for(int t=0;t<64;t++)
	{
		if(*p1&d) num1++;
		if(*p2&d) num2++;
		d=d<<1;
	}
	if(num1==num2)
	{
		if(*p3>*p4) return 1;
		else return -1;
	}
	else return(num2-num1);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        long long int *L = (long long int*)malloc(sizeof(long long int)*num);
        for(int t=0;t<num;t++)
        {
            scanf("%lld",&L[t]);
        }
        qsort(L,num,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<num;i++)
        {
            if(i==num-1) printf("%lld\n",L[i]);
            else printf("%lld ",L[i]);
        }
        free(L);
    }
    return 0;
}