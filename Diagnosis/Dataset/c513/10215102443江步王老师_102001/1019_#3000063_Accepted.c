#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct a
{
    int index;
    int sc;int bc;int pc;
    int score;
}team;

int cmp(const void *a, const void *b);
int main()
{
    int n,m;

    while (scanf("%d %d",&n,&m)==2)
    {
        if (n==0 && m==0) break;
        team *tmp = (team *)malloc(sizeof(team)*n);
        for (int i=0;i<n;++i)
        {
            tmp[i].index=i+1;
            tmp[i].sc=0;tmp[i].bc=0;tmp[i].pc=0;
            tmp[i].score=0;
        }
        
        int a,b,c;

        for (int i=0;i<m;++i)
        {
            scanf("%d %d %d",&a,&b,&c);
            
            if (c==1)
            {
                tmp[a-1].sc++;tmp[b-1].bc++;
            }
            else if (c==0)
            {
                tmp[a-1].pc++;tmp[b-1].pc++;
            }
            else
            {
                tmp[a-1].bc++;tmp[b-1].sc++;
            }

        }

        for (int i=0;i<n;++i)
        {
            tmp[i].score=tmp[i].sc*3-tmp[i].bc+tmp[i].pc;
        }
        
        qsort(tmp,n,sizeof(team),cmp);

        for (int i=0;i<n;++i)
        {
            printf("%d",tmp[i].index);
            putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    team *pa = (team *)a;
    team *pb = (team *)b;

    if (pa->score < pb->score) return 1;
    else if (pa->score == pb->score && pb->sc > pa->sc) return 1;
    else if (pa->score == pb->score && pb->sc == pa->sc && pb->bc < pa->bc) return 1;
    else if (pa->score == pb->score && pb->sc == pa->sc && pb->bc == pa->bc && pb->index <pa->index) return 1;
    else return -1; 
}