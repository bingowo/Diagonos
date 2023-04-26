#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        int flag=0;
        int a[100001]={0};
        int b[101]={0};
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(a[x]&&y!=b[a[x]-1])
            {
                flag=1;
            }
            a[x]=j+1;
            b[j]=y;
        }
        if(n==1)
        {
            printf("Lucky dxw!\n");
            continue;
        }
        if(flag==1)
        {
            printf("Poor dxw!\n");
            continue;
        }
        for(int p=0;p<n;p++)
        {
            if(a[b[p]]>0)
            {
                flag=1;
                printf("Poor dxw!\n");
                break;
            }
        }
        if(flag==1)
            continue;
        else
            printf("Lucky dxw!\n");
    }
}
