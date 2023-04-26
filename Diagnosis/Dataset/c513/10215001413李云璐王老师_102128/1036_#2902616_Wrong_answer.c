#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{long  x;long  y;}point;

void sort(point*s,int n)
{
    int cmp(const void*a1,const void*a2)
    {
        point a=*(point*)a1;
        point b=*(point*)a2;
        if((labs(a.x)+labs(a.y))>labs(b.x)+labs(b.y)) return -1;
        if((labs(a.x)+labs(a.y))<labs(b.x)+labs(b.y)) return 1;
        if((labs(a.x)+labs(a.y))==labs(b.x)+labs(b.y)) 
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
    scanf("%ld %ld\n",&s[i].x,&s[i].y);
    sort(s,n);
    printf("%ld\n",labs(s[0].x-s[1].x)+labs(s[0].y-s[1].y));
    return 0;
}