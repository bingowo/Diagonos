#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
#define N 105

long long llabs(long long a){return a>0?a:-a;}

typedef struct
{
    long long x,y;
}Point;

long long mandist_O(Point* p)
{
    return llabs(p->x)+llabs(p->y);
}

long long mandist(Point p1,Point p2)
{
    return llabs(p1.x-p2.x)+llabs(p2.y-p1.y);
}

int cmp(const void* a,const void* b)
{
    Point* pa=(Point*)a;Point* pb=(Point*)b;
    if(mandist_O(pa)!=mandist_O(pb))return mandist_O(pa)>mandist_O(pb)?-1:1;
    else if(pa->x!=pb->x)return pa->x>pb->x?1:-1;
    else if(pa->y!=pb->y)return pa->y>pb->y?1:-1;
    else return 0;
}

long long solve(long long n)
{
    if(n==0)return 0;
    if(n%2==0)return -1;
    int cnt=0;
    while(n){
        cnt++;
        n>>=1;
    }
    //printf("%d\n",cnt);
    return cnt;
}

int main()
{
    int pn;
    scanf("%d",&pn);
    Point p[N];
    //Point o;o.x=0;o.y=0;
    for(int i=0;i<pn;++i)scanf("%lld %lld",&p[i].x,&p[i].y);
    qsort(p,pn,sizeof(p[0]),cmp);
    long long cnt=0;
    for(int i=0;i<pn-1;++i){
        long long t=solve(mandist(p[i],p[i+1]));
        if(t==-1){cnt=0;break;}
        cnt+=t;
    }
    printf("%lld %lld",mandist(p[0],p[1]),cnt);
    return 0;
}
