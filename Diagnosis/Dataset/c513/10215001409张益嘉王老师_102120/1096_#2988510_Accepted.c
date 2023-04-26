#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int a;
    int b;
    int sum;
    int cha;
}bian;

int cmp1(const void*p,const void* q)
{
    bian pp=*((bian*)p);
    bian qq=*((bian*)q);

    if(pp.a<qq.a) return -1;
    else if(pp.a>qq.a) return 1;
    else
    {
        if(pp.b>qq.b) return 1;
        else if(pp.b<qq.b) return -1;
        else return 0;
    }

}

int cmp2(const void*p,const void* q)
{
    bian pp=*((bian*)p);
    bian qq=*((bian*)q);
    if(pp.sum>qq.sum) return 1;
    else if(pp.sum<qq.sum) return -1;
    else
    {
        if(pp.cha<qq.cha) return -1;
        else if(pp.cha>qq.cha) return 1;
        else return 0;
    }
}

int havesamea(bian s[],int n)
{
    int i;
    qsort(s,n,sizeof(bian),cmp1);
    for(i=0;i<n-1;i++)
    {
        if((s[i].a==s[i+1].a)&&(s[i].b!=s[i+1].b)) return 1;
    }
    return 0;
}

int judcircle(bian s[],int n)
{
    int i;
    qsort(s,n,sizeof(bian),cmp2);
    for(i=0;i<n-1;i++)
    {
        if((s[i].sum==s[i+1].sum)&&(s[i].cha==s[i+1].cha)&&(s[i].a!=s[i+1].a)) return 1;
    }
    return 0;
}

int judlian(bian s[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((s[i].b==s[j].a)&&(s[i].b!=s[j].b)) return 1;
        }
    }
    return 0;
}

int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n,j;
        bian s[120];
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&s[j].a,&s[j].b);
            s[j].sum=s[j].a+s[j].b;
            s[j].cha=abs(s[j].a-s[j].b);
        }
        int islucky=1;
        if(havesamea(s,n)) islucky=0;
        else if(judcircle(s,n)) islucky=0;
        else if(judlian(s,n)) islucky=0;

        if(islucky) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");

    }
    return 0;
}
