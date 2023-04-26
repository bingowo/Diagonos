#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char s[20];
    long long val;
    int top;
}Num;

int cmp(const void *a,const void *b)
{
    if((*(Num *)a).top != (*(Num *)b).top)
        return (*(Num *)b).top-(*(Num *)a).top;
    else
        return (*(Num *)a).val>(*(Num *)b).val;
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
            //printf("%s ",num[j].s);
            num[j].top=0;
            num[j].val=0;
            if(num[j].s[0]!='-')
            {
                num[j].top=num[j].s[0]-'0';
                int len=strlen(num[j].s);
                //printf("%d\n",len);
                for(int k=0;k<len;k++)
                {
                    num[j].val=num[j].val*10+num[j].s[k]-'0';
                }
            }
            else
            {
                num[j].top=num[j].s[1]-'0';
                int len=strlen(num[j].s);
                //printf("%d\n",len);
                for(int k=1;k<len;k++)
                {
                    num[j].val=num[j].val*10+num[j].s[k]-'0';
                }
                num[j].val=-num[j].val;
            }
        }
        qsort(num,N,sizeof(Num),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N-1;j++)
            printf("%lld ",num[j].val);
        printf("%lld\n",num[N-1].val);
    }
    return 0;
}
