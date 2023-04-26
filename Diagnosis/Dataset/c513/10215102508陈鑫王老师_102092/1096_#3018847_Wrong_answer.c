#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int a;
    int b;
}order;
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int com(int a[],int b[],int n)
{
    int flag=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                flag=0;
                break;
            }
            else if(a[i]<b[j])break;

        }
        if(flag==0)break;
    }
    if(flag)
    {
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1]||b[i]==b[i-1])
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}
int disappear(order *ans,int ai,int bi,int index)
{
    int flag=1;
    for(int i=0;i<=index;i++)
    {
        if(ans[i].a==ai&&ans[i].b==bi)
        {
            flag=0;
            break;
        }
    }
    return flag;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        order ans[n];
        int index=0;
        for(int i=0;i<n;i++)
        {
            int ai,bi;
            scanf("%d %d",&ai,&bi);
            if(disappear(ans,ai,bi,index-1))
            {
                a[index]=ai;
                b[index]=bi;
                ans[index].a=ai;
                ans[index].b=bi;
                index++;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        int flag=com(a,b,n);
        if(flag==0)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");

    }
    return 0;
}
