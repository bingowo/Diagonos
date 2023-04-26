#include <stdio.h>
int main()
{
    int t; scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x,j=0,a[32]={0};//初始化数组a为0
        scanf("%d",&x);
        while(x!=0)
        {
            a[j] = x%2;  j++;  x/=2;
        }
        int c=1,max=c;
        for(int i=1;i<j;i++)
        {
            if(a[i]!=a[i-1]) c++;
            else c=1;//将c的值再次初始化
            if(max<c) max=c;//时刻更新最大长度
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}