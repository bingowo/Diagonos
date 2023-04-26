#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


typedef struct{
long long int x,y,dis;

}node;
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
   for(int i=0;i<T;i++)
   {
       printf("%lld %lld\n",p[i].x,p[i].y);

   }

   long long int ans=myabs(p[0].x-p[1].x)+myabs(p[0].y-p[1].y);
   printf("%lld\n",ans);
   int sum=0;
   for(int i=0;i<T-1;i++)
   {
       int dis=myabs(p[i].x-p[i+1].x)+myabs(p[i].y-p[i+1].y);
       int tmp=1;
       while(1)
       {
           if((dis>(int)(pow(2,tmp-1)))&&(dis<=((int)pow(2,tmp)-1)))break;
           tmp++;
       }
       sum+=tmp;

   }
    printf("%d\n",sum);
}
