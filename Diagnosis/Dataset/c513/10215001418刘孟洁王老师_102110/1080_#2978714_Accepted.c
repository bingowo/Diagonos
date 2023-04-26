#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cas,i,j,k,d,m,tmp;
    int bin[1007],rebin[1007],ans[1007];
    char ch[1007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        memset(bin,0,sizeof(bin));
        memset(rebin,0,sizeof(rebin));
        memset(ans,0,sizeof(ans));
        scanf("%s",ch);
        int len = strlen(ch);
        int cnt = 0;
        for(j = 0; j < len;)
        {
            int rest = 0;
            for(k = j; k < len; k++)
            {
                tmp = rest*10 + ch[k]-'0';
                rest = tmp%2;
                ch[k] = tmp/2 + '0';
            }
            bin[cnt++] = rest;
            while(ch[j] == '0'){j++;}
        }
        j = 0;
        while(bin[j] == 0){j++;}
        for(k = 0; j < cnt; k++,j++)rebin[k] = bin[j];
        len = k;
        int len1 = 1;
        for(j = 0; j < len; j++)
        {
            m = rebin[j];
            for(k = 0; k < len1; k++)
            {
                tmp = ans[k]*2 + m;
                ans[k] = tmp%10;
                m = tmp/10;
            }
            while(m)
            {
                ans[len1] = m%10;
                m /= 10;
                len1++;
            }
        }
        printf("case #%d:\n",i);
        for(j = len1-1; j >= 0; j--)printf("%d",ans[j]);
        printf("\n");
    }
    return 0;
}