#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n;
    int res[300],resnum=0;
    scanf("%d",&n);
    int data[300][300],num[300];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);//每行元素个数 
        for(int j=0;j<num[i];j++)
        {
            scanf("%d",&data[i][j]);
        }
    }//data输入 
    for(int i=0;i<num[0];i++)
    {
        for(int j=0;j<num[1];j++)
            if(data[0][i]==data[1][j])//若第0行第i个元素与第1行第j个元素相同 整理入res； 
            {
                res[resnum++]=data[0][i];
            }
    }
    for(int i=2;i<n;i++)
    {
        int tmp[300],tmpnum=0;
        for(int j=0;j<num[i];j++)
            for(int m=0;m<resnum;m++)//第二行开始每个数与res中对比，相同的整理入tmp 
                if(data[i][j]==res[m])
                {
                    tmp[tmpnum++]=res[m];
                }
        for(int p=0;p<=tmpnum;p++) res[p]=tmp[p];//将res重置为tmp中的元素 
        resnum=tmpnum;
    }
    qsort(res,resnum,sizeof(res[0]),cmp);
    for(int i=0;i<resnum;i++) printf("%d ",res[i]);
    return 0;
}