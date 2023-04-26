#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct data
{
    long long int x;
    long long int y;
    long long int r;
};
long long int dx(struct data p1,struct data p2)
{
    return fabs(p1.x-p2.x);
}
long long int dy(struct data p1,struct data p2)
{
    return fabs(p1.y-p2.y);
}
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.r==b.r)
    {
        if(a.x==b.x)
        {
            return a.y-b.y;
        }
        else
        {
            return a.x-b.x;
        }
    }
    else
    {
        return b.r-a.r;
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    struct data p[number];
    for(int i=0;i<number;i++)
    {
        scanf("%lld",&p[i].x);
        scanf("%lld",&p[i].y);
        p[i].r=fabs(p[i].x)+fabs(p[i].y);
    }
    qsort(p,number,sizeof(p[0]),cmp);
    printf("%lld\n",dx(p[0],p[1])+dy(p[0],p[1]));
    int t=0;
    for(int i=0;i<number;i++)
    {
        if((dx(p[i],p[i+1])*dy(p[i],p[i+1]))%4==2)
        {
        	
        }
        else
        {
        	break;
		}
    }
    printf("%d",t);
    return 0;
}