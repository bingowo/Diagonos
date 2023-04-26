#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{double x;double y;}point;

void sort(point*s,int n)
{
    int cmp(const void*a1,const void*a2)
    {
        point a=*(point*)a1;
        point b=*(point*)a2;
        if((fabs(a.x)+fabs(a.y))>fabs(b.x)+fabs(b.y)) return -1;
        if((fabs(a.x)+fabs(a.y))<fabs(b.x)+fabs(b.y)) return 1;
        if((fabs(a.x)+fabs(a.y))==fabs(b.x)+fabs(b.y)) 
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
    scanf("%lf %lf\n",&s[i].x,&s[i].y);
    sort(s,n);
    printf("%lf\n",fabs(s[0].x-s[1].x)+labs(s[0].y-s[1].y));
    double bs=0;
    double p[63];
    
    for(int k=0;k<n-1;k++)
    {
        double dy,dx;
        dx=fabs(s[k+1].x-s[k].x);dy=fabs(s[k+1].y-s[k].y);
        if(dx==0&&dy==0) ;
        else
        {
            if((dx+dy)%2==0) break;
            else 
            {for(int j=1;j<=64;j++)
              if((dx+dy)<=pow(2,j)&&(dx+dy)>=pow(2,j-1)) { bs+=j; break;}   
              if((dx+dy)>pow(2,63)) {bs+=64;break;}
            }
        }
        
        
        
    }
    printf("%d",bs);
    return 0;
}
