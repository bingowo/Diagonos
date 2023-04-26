#include <stdio.h>
#include <stdlib.h>

typedef struct {int score,win,lose,id;} team;

int cmp(const void* a,const void* b)
{
    team* a_ = (team*)a; team* b_ = (team*)b;
    if (a_->score!=b_->score) return b_->score-a_->score;
    if (a_->win!=b_->win) return b_->win-a_->lose;
    if (a_->lose!=b_->lose) return a_->lose - b_->lose;
    return a_->id - b_->id;
}

main()
{
    while (1)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        if (!n&&!m) break;
        team a[10] = {};
        for (int i=1;i<=n;i++) a[i].id = i;
        int t1,t2,c;
        for (int i=0;i<m;i++)
        {
            scanf("%d %d %d",&t1,&t2,&c);
            if (c==1) {a[t1].score += 3; a[t2].score--; a[t1].win++; a[t2].lose++;}
            else if (c==0) {a[t1].score++; a[t2].score++;}
            else {a[t2].score += 3; a[t1].score--; a[t2].win++; a[t1].lose++;}
        }
        qsort(a+1,n,sizeof(a[0]),cmp);
        for (int i=1;i<=n;i++) printf("%d ",a[i].id);
        printf("\n");
    }
    system("pause");
    return 0;
}