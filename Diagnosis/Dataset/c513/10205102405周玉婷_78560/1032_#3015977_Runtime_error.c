#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int s[51];
} num;

int cmp(const void *pa ,const void *pb)
{
    num a=*(num*)pa;
    num b=*(num*)pb;
    int i;
    for(i = 0; a.s[i]!=-1 && b.s[i]!=-1; i++)
    {
        if(a.s[i] == b.s[i]) continue;
        else if(a.s[i] < b.s[i]) return 1;
        else if(a.s[i] > b.s[i]) return -1;
    }
    if(a.s[i] == b.s[i]) return -1;
    else return (a.s[i]==-1)?1:-1;
}

int main()
{
  int N;
  scanf("%d",&N);
  for(int j = 0; j < N; j++)
  {
      int n;
      scanf("%d",&n);
      num* p = malloc(sizeof(num)*n);
      int index=0;
      for(int i = 0; i < n; i++)
      {
          while(scanf("%d",&p[i].s[index++]) != -1);
          index=0;
      }
      qsort(p,n,sizeof(num),cmp);
      for(int i = 0; i < n; i++)
      {
          index=0;
          while(p[i].s[index]!=-1) printf("%d ",p[i].s[index++]);
          printf("\n");
      }
  }
  return 0;
}