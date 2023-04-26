#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct man
{
    long long int x;
    long long int y;
    unsigned long long int z;
};
int cmp(const void *a,const void *b)
{
    struct man *p1,*p2;
    p1=(struct man *)a;
    p2=(struct man *)b;
    if(p2->z!=p1->z)
        {
            if(p2->z>p1->z)
                return 1;
            else
                return -1;
        }
    else if(p2->x!=p1->x)
        {
            if(p2->x>p1->x)
                return -1;
            else
                return 1;
        }
    else
        {
            if(p2->y>p1->y)
                return -1;
            else
                return 1;
        }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    struct man m[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&m[i].x,&m[i].y);
        m[i].z=llabs(m[i].x)+llabs(m[i].y);
    }
    qsort(m,n,sizeof(m[0]),cmp);
    unsigned long long int ch,bu=0;
    for(i=0;i<n-1;i++)
    {
        unsigned long long int ch1,ch2;
        if(m[i].x-m[i+1].x>=0)
            ch1=m[i].x-m[i+1].x;
        else
            ch1=-(m[i].x-m[i+1].x);
        if(m[i].y-m[i+1].y>=0)
            ch2=m[i].y-m[i+1].y;
        else
            ch2=-(m[i].y-m[i+1].y);
        ch=ch1+ch2;
        if(i==0)
            printf("%llu\n",ch);
        if((ch%2)==1)
            bu+=(unsigned long long int)(log10(ch)/log10(2))+1;
        else
            break;
    }
    printf("%llu",bu);
    return 0;
}
