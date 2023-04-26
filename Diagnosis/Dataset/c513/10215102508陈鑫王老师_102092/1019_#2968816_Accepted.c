#include<stdio.h>
#include<stdlib.h>
struct all
{
    int score;
    int win;
    int fail;
    int num;
};
int cmp(const void*a,const void*b)
{
    struct all* x=(struct all*)a;
    struct all* y=(struct all*)b;
    if(x->score!=y->score)return x->score>y->score?-1:1;
    else if(x->win!=y->win)return x->win>y->win?-1:1;
    else if(x->fail!=y->fail)return x->fail<y->fail?-1:1;
    else return x->num<y->num?-1:1;
}
int main()
{
  while(1)
  {
      int m,n;
      scanf("%d %d",&n,&m);
      if(m==0&&n==0)break;
      struct all ans[n];
      memset(ans,0,sizeof(ans));
      for(int i=0;i<n;i++)
      {
          ans[i].num=i+1;
      }
      for(int i=0;i<m;i++)
      {
          int a,b,c;
          scanf("%d %d %d",&a,&b,&c);
          if(c==1)
          {
              ans[a-1].score+=3;
              ans[b-1].score-=1;
              ans[a-1].win+=1;
              ans[b-1].fail+=1;
          }
          else if(c==-1)
          {
              ans[a-1].score-=1;
              ans[b-1].score+=3;
              ans[a-1].fail+=1;
              ans[b-1].win+=1;
          }
          else
          {
              ans[a-1].score+=1;
              ans[b-1].score+=1;
          }
      }
      qsort(ans,n,sizeof(ans[0]),cmp);
      for(int i=0;i<n;i++)
      {
          printf("%d%c",ans[i].num,(i==n-1)?'\n':' ');
      }




  }
  return 0;
}
