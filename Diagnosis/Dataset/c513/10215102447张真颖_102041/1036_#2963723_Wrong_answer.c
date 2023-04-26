#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long x,y;
}POINT;
long long d(POINT a,POINT b)
{
    long long x=a.x-b.x,y=a.y-b.y;
    if(x<0) x=-x;
    if(y<0) y=-y;
    return x+y;
}
int cmp(const void* pa,const void* pb)
{
    POINT a=*(POINT*)pa,b=*(POINT*)pb;
    POINT m;
    m.x=0,m.y=0;
    if(d(a,m)>d(b,m)) return -1;
    else if(d(a,m)<d(b,m)) return 1;
    else if(a.x>b.x) return 1;
    else if(a.x<b.x) return -1;
    else if(a.y>b.y) return 1;
    else if(a.y<b.y) return -1;
    return 0;
}
POINT go(POINT a,POINT b)
{
             if((b.x-a.x)%2==0)
            {
               long long tx=(b.x-a.x)/2;
               if(tx%2==0)
               {
                  if(tx==0&&b.y-a.y==-1) a.y-=1;
                  else if(tx==0&&b.y-a.y==1) a.y+=1;
                  else if(((b.y-a.y+1)/2)%2!=0) a.y=a.y-1;
                  else a.y=a.y+1;
                }
                else
               {

                   if(((b.y-a.y+1)/2)%2==0) a.y=a.y-1;
                   else a.y=a.y+1;
               }
             }
             else
             {
               long long ty=(b.y-a.y)/2;
               if(ty%2==0)
               {
                   if(ty==0&&b.x-a.x==-1) a.x-=1;
                   else if(ty==0&&b.x-a.x==1) a.x+=1;
                   else if(((b.x-a.x+1)/2)%2!=0) a.x=a.x-1;
                   else a.x=a.x+1;
                }
                else
               {
                if(((b.x-a.x+1)/2)%2==0)
                    a.x=a.x-1;
                else a.x=a.x+1;
               }
           }
           return a;
}

int main()
{
    int n=0;
    POINT parry[100]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&parry[i].x,&parry[i].y);
    qsort(parry,n,sizeof(parry[0]),cmp);
    printf("%lld\n",d(parry[0],parry[1]));
    long long step=0;
    for(int i=0;i<n-1;i++)
    {
         POINT a=parry[i],b=parry[i+1];
         if((b.x-a.x)%2==0&&(b.y-a.y)%2==0||(b.x-a.x)%2!=0&&(b.y-a.y)%2!=0) break;
         while(!(a.x==b.x&&a.y==b.y))
         {
             a=go(a,b);
             b.x=b.x-(b.x-a.x)/2,b.y=b.y-(b.y-a.y)/2;
             step+=1;
         }
    }
    printf("%lld",step);
    return 0;
}