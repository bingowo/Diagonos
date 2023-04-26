#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int a;
    int b;
}order;
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
int cmp(const void*a,const void*b)
{
    order* x=(order*)a;
    order *y=(order*)b;
    if(x->a!=y->a)return x->a<y->a?-1:1;
    else return x->b<y->b?-1:1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        order ans[n];
        int flag=1,index=0;
        for(int i=0;i<n;i++)
        {
            int ai,bi;
            scanf("%d %d",&ai,&bi);
            if(disappear(ans,ai,bi,index-1))
            {
                ans[index].a=ai;
                ans[index].b=bi;
                index++;
            }
        }
        qsort(ans,index,sizeof(ans[0]),cmp);
        for(int k=1;k<index;k++)
        {
           if(ans[k].a==ans[k-1].a)
           {
               flag=0;
               break;
           }
        }
        if(flag)
        {
            for(int k=0;k<index;k++)
            {
                for(int l=0;l<index;l++)
                {
                   if(ans[l].a==ans[k].b)
                   {
                       flag=0;
                       break;
                   }
                   else if(ans[k].b<ans[l].a)continue;
                }
                if(flag==0)break;
            }
        }
        if(flag)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");

    }
    return 0;
}
