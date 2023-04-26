#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
unsigned long long hash[64];
typedef struct
{
    long long x,y;
    unsigned long long d;
}POINT;
unsigned long long pow2(int j);
void gethash();
int compar(const void *p1,const void *p2);
void myPrint(char*a);
int main()
{
    int i,j,n;
    unsigned long long ans1,ans2,eachd;
    scanf("%d",&n);
    POINT *point=(POINT*)malloc(n*sizeof(POINT));
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&point[i].x,&point[i].y);
        point[i].d=(unsigned long long)llabs(point[i].x)+(unsigned long long)llabs(point[i].y);
    }
    qsort(point,n,sizeof(POINT),compar);
    ans2=0;
    ans1=(unsigned long long)llabs(point[0].x-point[1].x)+(unsigned long long)llabs(point[0].y-point[1].y);
    gethash();
    for(i=0;i<n-1;i++)
    {
        eachd=(unsigned long long)llabs(point[i].x-point[i+1].x)+(unsigned long long)llabs(point[i].y-point[i+1].y);
        if(eachd%2==0)      //如果是偶数的话，铁定到不了
        {
            ans2=0;
            break;
        }
        else
        {
            for(j=0;j<64;j++)
            {
                if(eachd<=hash[j])
                    break;
            }
            ans2+=j+1;
        }
    }
    printf("%d\n%d",ans1,ans2);
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0;
    POINT *a=(POINT*)p1,*b=(POINT*)p2;
    if(a->d>b->d)
        flag=-1;
    else if(a->d<b->d)
        flag=1;
    else
    {
        if(a->x<b->x)
            flag=-1;
        else if(a->x>b->x)
            flag=1;
        else
        {
            if(a->y<b->y)
                flag=-1;
            else
                flag=1;
        }
    }
    return flag;
}
unsigned long long pow2(int j)
{
    unsigned long long res=2;
    while(j--)
        res=res*2;
    return res;
}
void gethash()
{
    int i;
    for(i=0;i<64;i++)
    {
        hash[i]=pow2(i)-1;
    }
}
void myPrint(char*a)
{
    static int tim=0;
    int i=0;
    printf("case #%d:\n",tim++);
    printf("%s\n",a);
}
