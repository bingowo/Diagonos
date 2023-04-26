#include <stdio.h>
#include <stdlib.h>
struct team {int scare;int win;int lose;int number};
 int cmp(const void*a,const void*b)
{if((*(struct team*)a).scare>(*(struct team*)b).scare) return -1;
if((*(struct team*)a).scare<(*(struct team*)b).scare) return 1;
if((*(struct team*)a).win>(*(struct team*)b).win) return -1;
if((*(struct team*)a).win<(*(struct team*)b).win) return 1;
if((*(struct team*)a).lose>(*(struct team*)b).lose) return 1;
if((*(struct team*)a).lose<(*(struct team*)b).lose) return -1;
if((*(struct team*)a).number>(*(struct team*)b).number) return 1;
if((*(struct team*)a).number<(*(struct team*)b).number) return -1;}
int main()
{int n,m,k;
struct team*p=0;
scanf("%d%d",&n,&m);
do{p=(struct team*)malloc(sizeof(struct team)*n);
for(int l=0,j=1;j<=n;j++){p[l].number=j;}
for(int k=0;k<m;k++)
{int a,b,c;
 scanf("%d%d%d",&a,&b,&c);
 switch(c)
 {case 1:p[a-1].scare+=3;p[a-1].win++;p[b-1].scare-=1;p[b-1].lose++;break;
 case -1:p[b-1].scare+=3;p[b-1].win++;p[a-1].scare-=1;p[a-1].lose++;break;
 case 0:p[a-1].scare++;p[b-1].scare++;break;}}
 qsort(p,n,sizeof(p[0]),cmp);
 for(k=0;k<n-1;k++) printf("%d ",p[k].number);
printf("%d\n",p[k].number);
scanf("%d%d",&n,&m);}
while(n!=0||m!=0);}
