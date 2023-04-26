#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    long long x , y ;
    unsigned long long d ;
}pos ;

int cmp(const void *_a , const void *_b)
{
    pos *a = (pos*)_a ,*b = (pos*)_b ;
    if((*a).d != (*b).d)
        return (*b).d > (*a).d ;
    else if((*a).x != (*b).x)
        return (*a).x > (*b).x ;
    else
        return (*a).y > (*b).y ;
}

long long count(unsigned long long x,unsigned long long y)
{
    int m=0;
    while(x!=0||y!=0)
    {
        if(x%2==1&&y%2==0)
        {   if(x==1&&y==0)x--;
            else if((x+1)/2%2!=y/2%2)x++;
            else x--;
            x/=2;y/=2;m++;
        }
        else if(x%2==0&&y%2==1)
        {   if(x==0&&y==1)y--;
            else if((y+1)/2%2!=x/2%2)y++;
            else y--;
            x/=2;y/=2;m++;
        }
        else break;
    }
    return m;
}

int main()
{
    int n ;
    scanf("%d",&n) ;
    pos p[n] ;
    for(int i=0; i<n; i++){
        scanf("%lld %lld",&p[i].x,&p[i].y) ;
        p[i].d = llabs(p[i].x) + llabs(p[i].y) ;
    }
    qsort(p,n,sizeof(pos),cmp) ;
    unsigned long long d1 =llabs(p[0].x-p[1].x);
    unsigned long long d2 =llabs(p[0].y-p[1].y);
    printf("%llu\n",d1+d2);
    unsigned long long x , y , step = 0 ;
    int m = 1 ; int i = 0 ;
    while(p[i].x==p[i+1].x && p[i].y==p[i+1].y) i++ ;
    for(;i<n-1 && m!= 0; i++){
        x = llabs(p[i].x - p[i+1].x) ;
        y = llabs(p[i].y - p[i+1].y) ;
        m = count(x,y) ;
        step += m ;
    }
    printf("%lld",step) ;
}