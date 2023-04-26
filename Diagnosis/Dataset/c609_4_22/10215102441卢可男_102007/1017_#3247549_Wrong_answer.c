#include <stdio.h>
#include <stdlib.h>

int main()
{
    //直筒法
    int a[1000]={0};
    char c;
    scanf("%c",&c);
    char tem=getchar();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(a[n]==0)
        {
            a[n]=1;
        }
    }

    if(c=='A')
    {
        int i=0;
        while(a[i])
        {
          printf("%d",i);
          i++;
        }
    }
    else
    {
        int i=999;
        while(a[i])
        {
            printf("%d",i);
        }
        i--;
    }
    return 0;
}
