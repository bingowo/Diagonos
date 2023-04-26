#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(int a,int b)
{  if (a>b) return -1;
   else return 1;
}
int main()
{int n,m,i,a,b,c; int team[1000]={0};
while(scanf("%d %d",&n,&m)!=EOF)
{for(i=0;i<m;i++)
{ scanf("%d %d %d\n",&a,&b,&c);
  if(c==1) team[a]+=3;
  if(c==0) {team[a]+=1; team[b]+=1;}
  if(c==-1) {team[b]+=3;}
}
qsort(team,n,sizeof(team[0]),cmp);
for (i=0;i<n-1;i++)
{ printf("%d ",team[i]);
}
printf("%d\n",team[n-1]);
}

    
}