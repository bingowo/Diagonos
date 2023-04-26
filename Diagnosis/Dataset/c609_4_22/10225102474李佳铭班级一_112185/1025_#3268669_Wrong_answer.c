#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int name;
    int score;
    int win;
    int lose;
}member;//参赛球队

typedef struct
{
    int a;
    int b;
    int last;
}play;//一场比赛的情况

//各个与比较有关的参数的计算
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

//比较
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
    member s1[100000];
    play s2[1000000];
    int state = 0;
    do
    {
        /*n = 0;
        while((c = getchar()) != ' ')
        {
            n = n*10 + (c - '0');
        }
        m = 0;
        while((c = getchar()) != '\n')
        {
            m = m*10 + (c - '0');
        }*/
        scanf("%d",&n);
        scanf("%d",&m);

        if(n != 0 && m != 0 && state == 1)
            printf("\n");
        state = 1;

        for(int i = 0; i < n; i++)
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
                if(c == '-')
                {
                    s2[i].last = -1;
                    getchar();
                }
                else
                    s2[i].last = (c - '0');
            }
            /*if((c = getchar()) == '-')
            {
                s2[i].b = -1;
                getchar();//跳过“-”后的“1”
                //getchar();//跳过回车
            }
            else
            {
                s2[i].b = (c - '0');
                getchar();
            }*/
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


   }while(n != 0 && m != 0);
    return 0;
}
