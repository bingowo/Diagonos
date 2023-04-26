#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cas,i,j,a,b,n,k,f,max,maxx;
    int s[107][2],sa[107],sb[107];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        max = 0;
        int flag = 1;
        scanf("%d",&n);
        for(j = 0; j < 107; j++)memset(s[j],0,sizeof(s[j]));
        for(j = 0; j < n; j++)
        {
            f = 0;
            scanf("%d%d",&a,&b);
            if(a == b)continue;
            else
            {
                for(k = 0; k < j; k++)
                {
                    if(a == sa[k] && b == sb[k])
                    {
                        f = 1;
                        break;
                    }
                }
                if(f == 1)continue;
                else
                {
                    sa[j] = a; sb[j] = b;
                    s[a][0]++;s[b][1]++;
                }
                maxx = a > b?a:b;
                if(max < maxx)max = maxx;
            }
        }
        for(j = 0; j <= max; j++)
        {
            if((s[j][0]>=1&&s[j][1]>=1)||s[j][0]>=2)flag = 0;//in一次以上并且out一次以上或者in两次以上都会出现不公平现象
        }
        if(flag == 1)printf("Lucky dxw!\n");
        else if(flag == 0)printf("Poor dxw!\n");
    }
    return 0;
}