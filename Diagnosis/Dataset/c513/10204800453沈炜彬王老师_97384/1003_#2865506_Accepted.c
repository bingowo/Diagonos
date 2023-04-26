#include <stdio.h>
#include <stdlib.h>

int cmp(void* num1,void* num2);

int
main()
{
    int questions;

    scanf("%d",&questions);
    for (int i=0;i<questions;i++)
    {
        int N;

        scanf("%d",&N);

        long long int *pnumber = (long long int*)malloc(N*sizeof(long long int));
        for (int i=0;i<N;i++)
        {
            scanf("%lld",pnumber+i);
        }
        qsort(pnumber,N,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for (int i=0;i<N;i++)
        {
            printf("%lld",*(pnumber+i));
            if (i<N-1) printf(" ");
            else printf("\n");
        }

        free(pnumber);
    }

    return 0;
}

int
cmp(void* num1,void* num2)
{
    long long int a = *(long long int*)num1;
    long long int b = *(long long int*)num2;
    int count1=0,count2=0;
    for (int i=0;i<64;i++)
    {
        if (((a>>i)&1) == 1)    count1++;
    }
    for (int i=0;i<64;i++)
    {
        if (((b>>i)&1) == 1)    count2++;
    }

    if (count1<count2) return 1;
    else if (count1==count2)
    {
        if (a>b) return 1;
        else return -1;
    }
    else return -1;
}