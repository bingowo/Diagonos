#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,a[110]={0},b[110]={0};
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i],&b[i]);
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(flag==1) break;
            for(int j=0;j<n;j++)
            {
                if(a[i]==b[j] || (a[i]==a[j] && i!=j))
                {
                    printf("Poor dxw!\n");
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0) printf("Lucky dxw!\n");
    }
    return 0;
}