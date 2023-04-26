#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int q[10000]={0};
    int ans[10000]={0};
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&q[cnt]);
            cnt++;
        }
    }
    qsort(q,cnt,sizeof(q[0]),cmp);
    /*for(int i=0;i<cnt;i++)
    {
        printf("%d ",q[i]);
    }*/
    int temp=q[0];
    int flag=1;
    int k=0;
    for(int i=1;i<cnt;i++)
    {
        while(q[i]==temp)
        {
            flag++;
            i++;
        }
        if(flag==n)
        {
            ans[k]=q[i-1];
            k++;
        }
        flag=1;
        temp=q[i];
    }
    qsort(ans,k,sizeof(ans[0]),cmp);
    for(int i=0;i<k;i++)
    {
        printf("%d ",ans[i]);
    }

}
