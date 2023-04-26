#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{long long int x;long long int y;long long int dis;}point;

int cmp(const void*a1,const void*a2)
{
    point a=*(point*)a1;
    point b=*(point*)a2;
    if(a.dis!=b.dis) 
    {
        if(a.dis>b.dis) return 1;
        else return -1;
        
    }
    else if(a.x!=b.x) 
    {
        if(a.x>b.x)return 1;
        else return -1;
    }
    else 
    {
        if(a.y>b.y) return 1;
        else if(a.y<b.y) return -1;
        else return 0;
    }
}

int main()
{

    point a;
    scanf("%lld%lld",&a.x,&a.y);
    long long int n;
    scanf("%lld",&n);
    point *b;
    b=(point*)malloc(n*sizeof(point));
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&b[i].x,&b[i].y);
        long long int k,j;
        k=llabs(b[i].x-a.x);
        j=llabs(b[i].y-a.y);
        //printf("%lld %lld\n",k,j);
        b[i].dis=(k>j)?k:j;

    }
    qsort(b,n,sizeof(b[0]),cmp);
    long long int min=b[0].dis;
    printf("%lld\n",min);
    printf("%lld %lld\n",b[0].x,b[0].y);
    
    return 0;

}