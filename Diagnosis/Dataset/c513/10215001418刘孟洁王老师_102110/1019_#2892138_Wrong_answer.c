#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct
{int number,score,win,lose}compitition;

int compare(const void*a,const void*b)
{
    compitition c=*(compitition*)a;
    compitition d=*(compitition*)b;
    if(c.score!=d.score)return d.score-c.score;
    else if(c.win!=d.win)return d.win-c.win;
    else if(c.lose!=d.lose)return c.lose-d.lose;
    else return c.number-d.number;

}
void sort(compitition *a,int n)
{qsort(a,n,sizeof(compitition),compare);}

int main()
{
    int m,n,i,j,a,b,c;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(m==0&&n==0)break;
        compitition *s=(compitition*)malloc(n*sizeof(compitition));
        for(i=0;i<n;i++){s[i].number=i+1;s[i].score=0;s[i].win=0;s[i].lose=0;}
      for(int i=0;i<m;i++)
      {
          scanf("%d%d%d",&a,&b,&c);
          if(c==0)
          {
              s[a-1].score+=1;
              s[b-1].score+=1;

          }
          else if(c==1)
          {
              s[a-1].score+=3;s[a-1].win+=1;
              s[b-1].score-=1;s[b-1].lose+=1;

          }
          else
          {
              s[a-1].score-=1;s[a-1].lose+=1;
              s[b-1].score+=3;s[b-1].win+=1;

          }
      }
      sort(s,n);
      for(j=0;j<n;j++)printf("%d ",s[j].number);
    free(s);
    }
    return 0;
}

