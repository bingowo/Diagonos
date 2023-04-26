#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct count
{ int number;
  int digit;
  int win;
  int lose;
};
int cmp(const void* a,const void* b)
{ struct count d1,d2;
  d1=*((struct count*)a);
  d2=*((struct count*)b);
    if (d1.digit!=d2.digit) return d2.digit-d1.digit;
    else if (d1.digit==d2.digit) 
    { if (d1.win!=d2.win) return d2.win-d1.win;
      else if (d1.win==d2.win) 
      {if (d1.lose!=d2.lose) return d1.lose-d2.lose;
       else if (d1.lose==d2.lose) return d1.number-d2.number;
       }
        
    }
}
int main()
{int n,m,i,a,b,c,x; struct count team[1000];
for (x=0;x<1000;x++)
{team[x].number=x+1; team[x].digit=0;team[x].win=0;team[x].lose=0;}
while(scanf("%d %d",&n,&m))
{ if ((n==0)&&(m==0)) break;
  for(i=0;i<m;i++)
{ scanf("%d %d %d",&a,&b,&c);
  if(c==1) {team[a-1].digit+=3;team[a-1].win+=1;team[b-1].lose+=1;team[b-1].digit-=1;}
  if(c==0) {team[a-1].digit+=1; team[b-1].digit+=1;}
  if(c==-1) {team[b-1].digit+=3;team[b-1].win+=1;team[a-1].lose+=1;team[a-1].digit-=1;}
}
qsort(team,n,sizeof(team[0]),cmp);
for (i=0;i<n-1;i++)
{ printf("%d ",team[i].number);
}
printf("%d\n",team[n-1].number);
for (x=0;x<1000;x++)
{team[x].number=x+1; team[x].digit=0;team[x].win=0;team[x].lose=0;}
}
return 0;
    
}