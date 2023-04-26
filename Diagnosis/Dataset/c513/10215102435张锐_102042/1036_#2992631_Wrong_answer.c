#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    long long int x;
    long long int y;
    unsigned long long mah;
}zuo;
int cmp(const void *a,const void *b)
{
    zuo *s1=(zuo*)a,*s2=(zuo*)b;
    if(s1->mah>s2->mah) return -1;
    if(s1->mah<s2->mah) return 1;
    if(s1->mah==s2->mah)
    {
        if(s1->x>s1->x) return 1;
        else if(s1->x<s2->x) return -1;
        else
        {
            if(s1->y>s2->y) return 1;
            else return -1;
        }
    }
}
unsigned long long a_x(int x)
{
    unsigned long long sum=1;
    for(int i=0;i<x;i++) sum=sum*2;
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    zuo* s=(zuo*)malloc(t*sizeof(zuo));
    for(int i=0;i<t;i++)
    {
        scanf("%lld%lld",&s[i].x,&s[i].y);
    }
    for(int i=0;i<t;i++)
    {
        long long int ta,tb;
        if(s[i].x>=0) ta=s[i].x;
        else ta=-s[i].x;
        if(s[i].y>=0) tb=s[i].y;
        else tb=-s[i].y;
        s[i].mah=ta+tb;
    }
    qsort(s,t,sizeof(s[0]),cmp);
    long long int x1=s[0].x,x2=s[1].x,y1=s[0].y,y2=s[1].y;
    long long unsigned x,y;
    if(x1-x2<0) x=x2-x1;
    else x=x1-x2;
    if(y1-y2<0) y=y2-y1;
    else y=y1-y2;
    if(x+y<y||x+y<x) printf("18446744073709551616\n");
    else printf("%llu\n",x+y);
    unsigned long long sum=0;
    for(int i=0;i<t-1;i++)
    {
        x1=s[i].x,x2=s[i+1].x,y1=s[i].y,y2=s[i+1].y;
        if(x1-x2<0) x=x2-x1;
        else x=x1-x2;
        if(y1-y2<0) y=y2-y1;
        else y=y1-y2;
        unsigned long long num=x+y;
        if(num%2==0&&num!=0) break;
        else if(num>a_x(63)) {sum+=64;continue;}
        else
        {
            int j=0;
            for(j=0;j<64;j++)
            {
                if(num<a_x(j)) break;
            }
            sum=sum+j;
        }
    }
    printf("%llu\n",sum);
    free(s);
    return 0;
}
