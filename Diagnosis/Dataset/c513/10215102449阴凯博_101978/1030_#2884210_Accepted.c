#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    long long value;
    char s[20];
} INT;


int cmp(const void* a,const void* b)
{
    INT* pa=(INT*)a; INT* pb=(INT*)b;
    int i=0;
    if (pa->s[0]!='-' && pb->s[0]!='-')
    {
        if (pa->s[0]>pb->s[0]) return -1;
        if (pa->s[0]<pb->s[0]) return 1;
        if (pa->s[0]==pb->s[0]) return (pa->value>pb->value)?1:-1;
    }
    if (pa->s[0]=='-' && pb->s[0]!='-')
    {
        if (pa->s[1]>pb->s[0]) return -1;
        if (pa->s[1]<pb->s[0]) return 1;
        if (pa->s[1]==pb->s[0]) return -1;
    }
    if (pa->s[0]!='-' && pb->s[0]=='-')
    {
        if (pa->s[0]>pb->s[1]) return -1;
        if (pa->s[0]<pb->s[1]) return 1;
        if (pa->s[0]==pb->s[1]) return 1;
    }
    if (pa->s[0]=='-' && pb->s[0]=='-')
    {
        if (pa->s[1]>pb->s[1]) return -1;
        if (pa->s[1]<pb->s[1]) return 1;
        if (pa->s[1]==pb->s[1]) return (pa->value>pb->value)?1:-1;
    }

}

int main()
{
    int T,N,j,m=0,k=0;
    scanf("%d",&T);
    char s[120]={0};
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        INT* arr=(INT*)malloc(N*sizeof(INT));
        for (j=0;j<N;j++)
        {
            scanf("%s",arr[j].s);
            arr[j].value=atoll(arr[j].s);
        }
        qsort(arr,N,sizeof(INT),cmp);
        for (j=0;j<N;j++)
        {
            printf("%s%c",arr[j].s,(j==N-1)?'\n':' ');
        }

    }
    return 0;
}
