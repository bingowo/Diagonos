#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
long long int first(long long int b)
{
    while(b>=10||b<-10)
    {
        b=b/10;
    }
    return abs(b);
}
int cmp(const void *a,const void *b)
{
    long long int*A=(long long int*)a;
    long long int*B=(long long int*)b;
    int result=0;
    if(first(*A)!=first(*B)) result=first(*A)>first(*B)? -1:1;
    else result=*A>*B? 1:-1;
    return result;
}
int main()
{
    int number=0;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a=0;
        scanf("%d",&a);
        long long int *b=(long long int*)malloc(a*sizeof(long long int));
        for(int j=0;j<a;j++)
        {
            scanf("%lld",&b[j]);
        }
        qsort(b,a,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<a-1;k++)
        {
            printf("%lld ",b[k]);
		}
		printf("%lld\n",b[a-1]);
		free(b);
    }
    return 0;
}