#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int k,n,i,j,len,l,m,tmp;
    int s[57][107];
    for(i = 0; i < 27; i++)memset(s[i],0,sizeof(s[i]));
    len = 1;
    s[0][0] = 0;s[1][0] = 1;
    scanf("%d%d",&k,&n);
    m = 0;
    for(i = 2; i < n; i++)
    {
        for(j = i-k; j < i; j++)
        {
            if(j < 0)continue;
            else
            {
                for(l = 0; l < len; l++)
                {
                    tmp = s[i][l] + s[j][l] + m;
                    s[i][l] = tmp%10;
                    m = tmp/10;
                }
                while(m)
                {
                    s[i][len++] = m%10;
                    m /= 10;
                }
            }
        }
    }
    for(i = len-1; i >= 0; i--)printf("%d",s[n-1][i]);
    return 0;
}