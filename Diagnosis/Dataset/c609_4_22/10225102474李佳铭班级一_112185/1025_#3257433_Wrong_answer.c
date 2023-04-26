#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int name;
    int score;
    int win;
    int lose;
}member;

typedef struct
{
    int a;
    int b;
    int last;
}play;

void count(play x,member* s1)
{
    if(x.last == 1)
    {
        s1[x.a - 1].score += 3;
        s1[x.b - 1].score -= 1;
        s1[x.b - 1].lose += 1;
        s1[x.a - 1].win += 1;
    }
    else if(x.last == -1)
    {
        s1[x.a - 1].score -= 1;
        s1[x.b - 1].score += 3;
        s1[x.a - 1].lose += 1;
        s1[x.b - 1].win += 1;
    }
    else
    {
        s1[x.a - 1].score += 1;
        s1[x.b - 1].score += 1;
    }

}

int cmp(const void*a,const void*b)
{
    member A = *(member*)a;
    member B = *(member*)b;
    if(A.score != B.score)
    {
        return A.score < B.score;
    }
    else
    {
        if(A.win != B.win)
        {
            return A.win < B.win;
        }
        else
        {
            if(A.lose != B.lose)
            {
                return A.lose > B.lose;
            }
            else
            {
                return A.name > B.name;
            }
        }
    }

}

int main()
{
    int n,m;
    char c;
    member s1[1000];
    play s2[10000];
    do
    {
        n = 0;
        while((c = getchar()) != ' ')
        {
            n = n*10 + (c - '0');
        }
        m = 0;
        while((c = getchar()) != '\n')
        {
            m = m*10 + (c - '0');
        }

        for(int i =0; i < n; i++)
        {
            s1[i].name = i + 1;
            s1[i].win = 0;
            s1[i].lose = 0;
            s1[i].score = 0;

        }

        for(int i = 0; i < m; i++)
        {
               while((c = getchar()) != ' ')
            {
                s2[i].a = (c - '0');
            }
            while((c = getchar()) != ' ')
            {
                s2[i].b = (c - '0');
            }
            while((c = getchar()) != '\n')
            {
                s2[i].last = (c - '0');
            }
        }

        for(int i = 0; i < m; i++)
        {
            count(s2[i],s1);
        }

        qsort(s1,n,sizeof(s1[0]),cmp);

        for(int i = 0; i < n;i++)
        {
            printf("%d ",s1[i].name);
        }

        /*member* s1 = (member*)malloc(sizeof(member)*n);
        member*p1 = s1;
        for(int i =0; i < n; i++)
        {
            p->name = i + 1;
            p++;
        }
        p1 = s1;
        play* s2 = (play*)malloc(sizeof(play)*m);
        play* p2 = s2;

        for(int i = 0; i < m; i++)
        {
               while((c = getchar()) != ' ')
            {
                p2->a.name = (c - '0');
            }
            while((c = getchar()) != ' ')
            {
                p2->b.name = (c - '0');
            }
            while((c = getchar()) != '\n')
            {
                p2->last = (c - '0');
            }
            p2++;
        }
        p2 = s2;
        for(int i = 0; i < m; i++)
        {
            play *h = *p2;
            count(h);
            p2++;
        }
        qsort(s1;n;sizeof(s1[0]),cmp);
        for(int i = 0; i < n;i++)
        {
            printf("%d ",p1->name);
            p1++;
        }
        printf("\n");*/


   }while(n != 0 && m != 0);
    return 0;
}
