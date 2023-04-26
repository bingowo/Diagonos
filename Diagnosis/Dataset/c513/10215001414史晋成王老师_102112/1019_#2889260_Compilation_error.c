#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct count
{ int number=0;
  int digit=0;
}
int cmp(const void* a,const void* b)
{ struct count d1,d2;
  d1=*((struct count*)a);
  d2=*((struct count*)b);
    
    if (d1.digit>d2.digit) return 1;
   else return -1;
}
int main()
{int n,m,i,a,b,c,x; struct count team[1000];
for (x=0;x<1000;x++)
team[x].number=x;
while(scanf("%d %d\n",&n,&m))
{ if ((n==0)&&(m==0)) break;
  for(i=0;i<m;i++)
{ scanf("%d %d %d\n",&a,&b,&c);
  if(c==1) team[a].digit+=3;
  if(c==0) {team[a].digit+=1; team[b].digit+=1;}
  if(c==-1) {team[b].digit+=3;}
}
qsort(team,n,sizeof(team[0]),cmp);
for (i=0;i<n-1;i++)
{ printf("%d ",team[i].number);
}
printf("%d\n",team[n-1].number);
}

    
}