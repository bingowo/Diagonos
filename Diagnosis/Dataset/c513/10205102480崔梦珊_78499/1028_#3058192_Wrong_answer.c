#include<stdio.h>
#include<stdlib.h>

int cmp1(const void* a,const void* b)
{
    return *(int *)a-*(int *)b;
}
int cmp2(const void* a,const void* b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    char c;
    c=getchar();
    int ans[101];
    int iff[1000]={0};
    int temp;
    int i=0;
    while(scanf("%d",&temp)!=EOF)
    {
        if(iff[temp]==0)
        {
            ans[i]=temp;
            iff[temp]=1;
            i++;
        }
        else
        {
            continue;
        }
    }
    if(c=='A')
    {
        qsort(ans,i+1,sizeof(ans[0]),cmp1);
    }
    if(c=='D')
    {
        qsort(ans,i+1,sizeof(ans[0]),cmp2);
    }
    for(int j=0;j<i-1;j++)
    {
        printf("%d ",ans[j]);
    }
    printf("%d",ans[i-1]);

}
