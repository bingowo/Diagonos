#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int a[1000]={0};
    int m;
    scanf("%c",&c);
    while(scanf("%d",&m)!=EOF)
    {
        a[m]=m;
    }
    if(c=='A')
    {
        for(int i=0; i<1000; i++) //输出去重排序后的序列
        {
            if(a[i])
                printf( "%d ",a[i]);

        }
    }
    else
    {
        for(int i=999; i>=0; i--) //输出去重排序后的序列
        {
            if(a[i])
                printf("%d ",a[i]);

        }
    }
    return 0;
}