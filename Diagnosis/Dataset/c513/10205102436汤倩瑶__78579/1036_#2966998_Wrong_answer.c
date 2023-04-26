#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct{
long long int x,y,dis;

}node;
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.dis<p2.dis)return 1;
    else return -1;

}
int main()
{
int T;
scanf("%d",&T);
   node p[101]={0};
   for(int i=0;i<T;i++)
   {
       scanf("%lld%lld",&p[i].x,&p[i].y);
       p[i].dis=abs(p[i].x)+abs(p[i].y);
   }
   qsort(p,T,sizeof(p[0]),cmp);
   long long int ans=p[0].dis-p[1].dis;
   printf("%lld\n",ans);
}
