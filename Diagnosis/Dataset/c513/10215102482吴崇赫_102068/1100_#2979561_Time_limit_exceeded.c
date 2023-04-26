#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

typedef struct
{
    int x;
    int y;
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

int solve(point* p,char* s,point tag)
{
    int n=strlen(s);int cnt=0;
    for(int i=0;i<n;){
        if(point_equal(p,tag))return 1;
        else Move(p,s[i]);
        if(i==n-1)i=0;
        else i++;
        cnt++;
        if(cnt>1000000005)break;
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
        scanf("%d %d",&t.x,&t.y);
        o.x=o.y=0;
        if(solve(&o,input,t))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}