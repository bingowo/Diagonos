#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{long long int x;long long int y;}point;

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
    scanf("%lld %lld\n",&s[i].x,&s[i].y);
    sort(s,n);
    for(int k=0;k<n;k++)
    printf("%lld %lld\n",s[k].x,s[k].y);
    return 0;
}