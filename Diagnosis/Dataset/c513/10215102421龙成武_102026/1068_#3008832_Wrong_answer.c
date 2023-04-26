//递归，截短实现，先别想着dp，先就搜索，如果发现时间复杂度高了再记忆化，不然会加大难度
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int func(int n,int m)
{
    int ans=0;
    if(n==m)
        ans=1;
    else if(n>m)
    {
        for(int i=0;i<m;i++)
        {
            ans+=func(n-(i+1),m);
        }
        ans+=pow(2,n-m);
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",func(n,m));
    return 0;
}
