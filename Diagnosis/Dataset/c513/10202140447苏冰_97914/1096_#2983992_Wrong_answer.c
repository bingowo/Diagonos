#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    int n;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&n);
        int flag=1;
        int a[101];
        int b[101];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            scanf("%d",&b[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i]==b[j])
                {
                    flag=0;break;
                }
            }
        }
        if(flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}

