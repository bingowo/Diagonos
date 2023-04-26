#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct{long long int x;long long int y;long long dis;}point;

int cmp(const void*a1,const void*a2)
{
    point a=*(point*)a1;
    point b=*(point*)a2;
    if(a.dis!=b.dis) return a.dis-b.dis;
    else if(a.x!=b.x) return a.x-b.x;
    else return a.y-b.y;
}

int main()
{

    point a;
    scanf("%lld%lld",&a.x,&a.y);
    int n;
    scanf("%lld",&n);
    point *b;
    b=(point*)malloc(n*sizeof(point));
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&b[i].x,&b[i].y);
        b[i].dis=(fabs(b[i].x-a.x)>fabs(b[i].y-a.y))?fabs(b[i].x-a.x):fabs(b[i].y-a.y);
    }
    qsort(b,n,sizeof(point),cmp);
    long long int min=b[0].dis;
    printf("%lld\n",b[0].dis);
    for(int i=0;i<n;i++)
    {
        if(b[i].dis==min) printf("%lld %lld\n",b[i].x,b[i].y);
    }
    return 0;

}