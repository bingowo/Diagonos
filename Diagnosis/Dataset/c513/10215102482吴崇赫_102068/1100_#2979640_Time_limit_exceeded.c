#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

long long Labs(long long a){return a>0?a:-a;}

typedef struct
{
    long long x;
    long long y;
}point;

void Move(point *p,char c)
{
    if(c=='R')p->x++;
    if(c=='L')p->x--;
    if(c=='U')p->y++;
    if(c=='D')p->y--;
}

int point_equal(point* a,point b)
{
    if(a->x==b.x&&a->y==b.y)return 1;
    else return 0;
}

long long Man_dist(point* p,point t)
{
    return Labs(p->x-t.x)+Labs(p->y-t.y);
}

int solve(point* p,char* s,point tag)
{
    int n=strlen(s);
    int d1,d2;
    for(int i=0;i<n;){
        if(i==0)d1=Man_dist(p,tag);

        if(point_equal(p,tag))return 1;
        else Move(p,s[i]);

        if(i==n-1){
            d2=Man_dist(p,tag);
            if(d2>d1)break;
            else i=0;
        }
        else i++;

    }
    return 0;
}

int main()
{
    char input[N];
    for(int i=0;i<N;++i)input[i]=0;
    scanf("%s",input);
    int n;scanf("%d\n",&n);
    for(int i=0;i<n;++i){
        point t,o;
        scanf("%lld %lld",&t.x,&t.y);
        o.x=o.y=0;
        if(solve(&o,input,t))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
