#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);//t为测试数据的组数
    for(int i=0;i<t;i++)
    {
        int x,j=0,a[32]={0};//初始化数组a为0
        scanf("%d",&x);
        while(x!=0)
        {
            a[j] = x%2;
            j++;
            x/=2;
        }
        int c=1;
        for(int i=1;i<j;i++) 
        {
            if(a[i]!=a[i-1]) c++;
            else c=1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",c);
    }
    return 0;
}




