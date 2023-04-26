#include<stdio.h>
#include<stdlib.h>

struct zs
{
    char s[5];
    int data;
    int flag;
};

int cmp1(const void* a,const void* b)
{
    struct zs* x=(struct zs*)a;
    struct zs* y=(struct zs*)b;
    return x->data-y->data;
}
int cmp2(const void* a,const void* b)
{
    struct zs* x=(struct zs*)a;
    struct zs* y=(struct zs*)b;
    return y->data-x->data;
}


int main()
{
    int a=0,b=0;
    struct zs ans[101];
    for(int i=0;i<101;i++)
    {
        ans[i].data=0;
        ans[i].flag=0;
    }
    char n;
    n=getchar();
    char c=getchar();
    c=getchar();
    while(c!='\n')
    {
        if(c==' ')
        {
            b=0;
            a++;
        }
        else
        {
            ans[a].data=ans[a].data*10+c-48;
        }
        c=getchar();
    }
    int mm[1001];
    for(int i=0;i<1001;i++)
    {
        mm[i]=0;
    }

    for(int i=0;i<a+1;i++)
    {
        if(mm[ans[i].data]==0)
        {
            ans[i].flag=1;
            mm[ans[i].data]=1;
        }
    }
    if(n=='A')
    {
        qsort(ans,a+1,sizeof(ans[0]),cmp1);
    }
    if(n=='D')
    {
        qsort(ans,a+1,sizeof(ans[0]),cmp2);
    }
    int te=a;
    for(int i=a;i>0;i--)
    {
        if(ans[i].data>ans[i-1].data)
        {
            te=i;
            break;
        }
        if(ans[i].data=ans[i-1].data)
        {
            te=i-1;
        }
    }
    for(int i=0;i<te;i++)
    {
        if(ans[i].flag==1)
        {
            printf("%d ",ans[i].data);
        }
    }
    printf("%d",ans[te].data);
    return 0;
}
