#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct{
long long int x,y;
unsigned long long int dis;

}node;
unsigned long long int f(int x)
{
    unsigned long long int ans=1;
    for(int i=0;i<x;i++)
    {
        ans*=2;

    }
    return ans;

}

long long int myabs(long long int x)
{
    long long int ans=x;
    if(ans<0)ans=-ans;
    return ans;
}
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.dis<p2.dis)return 1;
    else if(p1.dis>p2.dis)return -1;
    else {
        if(p1.x<p2.x)return -1;
    else if(p1.x>p2.x)return 1;
        else {
            if(p1.y<p2.y)return -1;
           else return 1;
        }
    }

}
int main()
{

int T;
scanf("%d",&T);
   node p[101]={0};
   for(int i=0;i<T;i++)
   {
       scanf("%lld%lld",&p[i].x,&p[i].y);
       p[i].dis=myabs(p[i].x)+myabs(p[i].y);
   }
   qsort(p,T,sizeof(p[0]),cmp);

  unsigned long long int ans=myabs(p[0].x-p[1].x)+myabs(p[0].y-p[1].y);
   if(myabs(p[0].x-p[1].x)>ans)
   printf("18446744073709551616\n");
   else printf("%llu\n",ans);

   int sum=0;
   for(int i=0;i<T-1;i++)
   {

       unsigned long long  int dis=myabs(p[i].x-p[i+1].x)+myabs(p[i].y-p[i+1].y);
       if(dis==0){continue;}
       if((dis%2)==0){break;}
       int tmp;

       for(tmp=1;tmp<=63;tmp++)
       {
           if((dis>=f(tmp-1))&&(dis<=f(tmp))){sum+=tmp;break;}

       }
       if(tmp==64)sum+=64;

   }
    printf("%d\n",sum);
}

