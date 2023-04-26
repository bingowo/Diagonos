#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{int num;int score;int win;int defeat;} team;
int cmp (const void *a,const void *b)
{
    team *a1=(team *)a,*b1=(team *)b;
    if (a1->score!=b1->score) return b1->score-a1->score;
    else if(a1->win!=b1->win) return b1->win-a1->win;
    else if(a1->defeat!=b1->defeat) return a1->defeat-b1->defeat;
    else return a1->num-b1->num;
}
int main()
{
    while (1)
    {
        int n,m,a,b,c;
        scanf ("%d%d",&n,&m);
        if (n==0) break;
        team s[11];
        for (int i=1;i<=n;i++)
        {
            s[i].score=0;
            s[i].win=0;
            s[i].defeat=0;
            s[i].num=i;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            switch (c)
            {
                case 1: s[a].score+=3;s[a].win+=1;s[b].score-=1;s[b].defeat+=1;break;
                case -1: s[a].score-=1;s[a].defeat+=1;s[b].score+=3;s[b].win+=1;break;
                case 0: s[a].score+=1;s[b].score+=1;break;
            }
        }
        qsort (s,n+1,sizeof(s[0]),cmp);
        for(int i=0;i<n-1;i++)
        {
            printf("%d ",s[i].num);
        }
        printf("%d\n",s[n-1].num);
    }
    return 0;

}
