#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MyInt
{
    long long myInt;
    int high;
}myInt;

int getHigh(long long n)
{
    char s[20];
    sprintf(s,"%lld",n);
    if(s[0] == '-'){return s[1]-'0';}
    else{return s[0]-'0';}
}

int cmp(const void *a, const void *b)
{
    myInt A = *(myInt*)a, B = *(myInt*)b;
    if(A.high!=B.high){return B.high-A.high;}
    else{return A.myInt>B.myInt;}
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int N = 0;
        scanf("%d",&N);
        myInt NL[N];memset(NL,0,N*sizeof(myInt));
        for(int j = 0;j<N;j++)
        {
            scanf("%lld",&NL[j].myInt);
            NL[j].high = getHigh(NL[j].myInt);
        }

        qsort(NL,N,sizeof(myInt),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j<N;j++)
        {
            printf("%lld ",NL[j].myInt);
        }
        printf("\n");
    }

    return 0;
}
