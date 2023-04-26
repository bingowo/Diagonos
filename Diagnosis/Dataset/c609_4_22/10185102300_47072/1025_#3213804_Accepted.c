#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  {  int num,score,win,loss; } TEAM;

int cmp(const void* e1,const void* e2)
{  TEAM *p1=(TEAM*)e1,*p2=(TEAM*)e2; int delta;
     if (delta=p2->score-p1->score) return delta;
     if (delta=p2->win-p1->win) return delta;
     if (delta=p1->loss-p2->loss) return delta;
     return p1->num-p2->num;
}



int main()
{  int i,n,m,a,b,c; TEAM t[10];
    while(scanf("%d%d",&n,&m),n)
    { for  (i=0;i<n;i++)  t[i].num=i+1, t[i].score= t[i].win= t[i].loss=0;
       for  (i=0;i<m;i++)
       { scanf("%d%d%d\n",&a,&b,&c);
          if (c==1) t[a-1].score+=3,t[a-1].win++,t[b-1].score--,t[b-1].loss++;
          else if (c==-1)  t[b-1].score+=3,t[b-1].win++,t[a-1].score--,t[a-1].loss++;
          else  t[a-1].score++,t[b-1].score++;
       }
       qsort(t,n,sizeof(t[0]),cmp);
       for  (i=0;i<n;i++)  printf("%d%c", t[i].num,i<n-1? ' ':'\n');
    }

    return 0;
}