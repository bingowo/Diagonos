#include <stdio.h>
#include <stdlib.h>

int main()
{
    //直筒法
    int a[1000]={0};
    char c;
    scanf("%c",&c);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(a[n]==0)
        {
            a[n]=n;
        }
    }

    if(c=='A')
    {
        for(int i=0;(a[i])&&i<1000;i++)
        {
                printf("%d",a[i]);
        }
    }
    else
    {
        for(int i=999;a[i]&&i>=0;i--)
        {
            printf("%d",a[i]);

        }

    }
    return 0;
}
