#include <stdio.h>
#include <string.h>
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int n,a[100],b[100];
        scanf("%d",&n);
        for(j = 0;j<n;j++)
            scanf("%d %d",&a[j],&b[j]);
        int flag = 0;
        for(j = 0;j<n;j++)
        {
            for(k = 0;k<n;k++)
            {if(a[j]==b[k]) {flag = 1;break;}}
            if(flag==1) {printf("Poor dxw!\n");break;}
        }
        if(flag==0) printf("Lucky dxw!\n");
    }
    return 0;
}
