#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct st{
    char s[13];
    int sco;
};

typedef struct st stu;

int cmp(const void * a,const void* b)
{
    stu m=*(stu*)a;
    stu n=*(stu*)b;
    if(m.sco==n.sco)
    {
        int i=atoi(m.s);
        int j=atoi(n.s);
        printf("%d\n",i-j);
        return i-j;
    }
    else
    {
        return n.sco-m.sco;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        int a[M];
        for(int j=0;j<M;j++)
        {
            scanf("%d",&a[j]);
        }
        stu S[N];
        int cnt=0;
        for(int k=0;k<N;k++)
        {
            scanf("%s",S[k].s);
            int d;
            scanf("%d",&d);
            int x;
            S[k].sco=0;
            while(d)
            {
                scanf("%d",&x);
                x--;
                S[k].sco=S[k].sco+a[x];
                d--;
            }
            if(S[k].sco>=G) cnt++;
        }
        //printf("%d\n",cnt);
        qsort(S,N,sizeof(S[0]),cmp);
        for(int k=0;k<N;k++)
        {
            if(S[k].sco<G);
            else
            {
                //printf("%s %d\n",S[k].s,S[k].sco);
            }
        }
    }
}

