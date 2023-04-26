#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long myabs(long long a)
{
    if(a>=0)
        return a;
    else
        return -a;
}

int firstnum(long long a)
{
    long long b=myabs(a);
    while(b>=10)
        b=b/10;
    int c=b;
    //printf("%d no firstnum:%d\n",a,c);
    return c;
}

int cmpfuncup (const void * a, const void * b)
{
   int c=*(int*)a - *(int*)b ;
        return c;
}

int cmpfuncdown (const void * a, const void * b)
{
   int c=*(int*)b - *(int*)a ;
        return c;
}
int main()
{
    int quesnum;
    scanf("%d\n",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        int num;
        scanf("%d",&num);
        int groupA[1002]={0};
        int groupB[1002]={0};
        for (int j=0;j<num;j++)
            scanf("%d",&groupA[j]);
        for (int j=0;j<num;j++)
            scanf("%d",&groupB[j]);
        qsort(groupA,num,sizeof(int),cmpfuncup);
        qsort(groupB,num,sizeof(int),cmpfuncdown);
        long long sum=0;
        for (int j=0;j<num;j++)
            sum=sum+groupA[j]*groupB[j];
        printf("%lld\n",sum);
    }

    return 0;
}
