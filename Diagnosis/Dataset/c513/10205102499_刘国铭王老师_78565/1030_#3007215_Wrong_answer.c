#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char s[20];
    long long int val;
    int top;
}Num;

int cmp(const void *a,const void *b)
{
    if((*(Num *)a).top != (*(Num *)b).top)
        return (*(Num *)b).top-(*(Num *)a).top;
    else
        return (*(Num *)a).val-(*(Num *)b).val;
}

int main()
{
    int T;
    scanf("%d",&T);
    Num num[10001];
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%s",num[j].s);
            if(num[j].s[0]!='-')
            num[j].top=num[j].s[0]-'0';
            else
                num[j].top=num[j].s[1]-'0';
            num[j].val=atof(num[j].s);
        }
        qsort(num,N,sizeof(Num),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N-1;j++)
            printf("%d ",num[j].val);
        printf("%d\n",num[N-1].val);
    }
    return 0;
}
