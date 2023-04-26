#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cas,i,j,a,b,n;
    int s[107][2];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        int flag = 1;
        scanf("%d",&n);
        for(j = 0; j < 107; j++)memset(s[j],0,sizeof(s[j]));
        for(j = 0; j < n; j++)
        {
            scanf("%d%d",&a,&b);
            s[a][0]++;
            s[b][1]++;
        }
        for(j = 0; j < 107; j++)
        {
            if((s[j][0]>=1&&s[j][1]>=1)||s[j][0]>=2)flag = 0;
        }
        if(flag == 1)printf("Lucky dxw!\n");
        else if(flag == 0)printf("Poor dxw!\n");
    }
    return 0;
}