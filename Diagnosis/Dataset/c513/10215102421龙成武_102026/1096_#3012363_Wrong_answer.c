#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int order[101];
int main()
{
    int T,n,i,a,b,flag=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            if(order[a]==0) order[a]=1;
            else
            {
                flag=0;
            }
            if(order[b]==0) order[b]=1;
            else
            {
                flag=0;
            }
        }
        if(flag) printf("Lucky dxw!");
        else printf("Poor dxw!");
    }
    return 0;
}
