#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{long long x;long long y;}point;

void sort(point*s,int n)
{
    int cmp(const void*a1,const void*a2)
    {
        point a=*(point*)a1;
        point b=*(point*)a2;
        if((llabs(a.x)+llabs(a.y))>llabs(b.x)+llabs(b.y)) return -1;
        if((llabs(a.x)+llabs(a.y))<llabs(b.x)+llabs(b.y)) return 1;
        if((llabs(a.x)+llabs(a.y))==llabs(b.x)+llabs(b.y)) 
        {
            if(a.x>b.x) return 1;
            if(a.x<b.x) return 1;
            if(a.x==b.x) 
            {if(a.y>b.y) return 1;
            if(a.y<b.y) return -1;
            else return 0;}
        }
    }
    qsort(s,n,sizeof(point),cmp);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    point* s=NULL;
    s=(point*)malloc(n*sizeof(point));
    for(int i=0;i<n;i++)
    scanf("%lld %lld\n",&s[i].x,&s[i].y);
    sort(s,n);
    printf("%lld\n",labs(s[0].x-s[1].x)+labs(s[0].y-s[1].y));
    int bs=0;
    int p[63];
    for(int r=0;r<63;r++)
    p[r]=pow(2,r+1)-1;
    for(int k=0;k<n-1;k++)
    {
        long int dy,dx;
        dx=llabs(s[k+1].x-s[k].x);dy=llabs(s[k+1].y-s[k].y);
        if(dx==0&&dy==0) ;
        else
        {
            if((dx+dy)%2==0) break;
            else 
            {for(int j=1;j<=64;j++)
              if((dx+dy)<=pow(2,j)&&(dx+dy)>=pow(2,j-1)) { bs+=j; break;}   
              
            }
        }
        
        
        
    }
    printf("%d",bs);
    return 0;
}