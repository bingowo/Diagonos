#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deal(int n,char *s)
{
    int i = 0,j;
    if(n < 0)n = -n;
    while(n)
    {
        s[i++] = n%10 + '0';
        n /= 10;
    }
    for(j = 0; j <= (i-1)/2; j++)
    {
        char d = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = d;
    }
    s[i] = '\0';
}

int main()
{
    int cas,i,j,k,l,n,len;
    char ans[1007],s[1007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        memset(ans,0,sizeof(ans));
        k = 0;
        for(j = 0; j < 9; j++)
        {
            scanf("%d",&n);
            if(n == 0)continue;
            else if(n)
            {
                if(n == 1)
                {
                    if(k)ans[k++] = '+';
                    if(j < 7)
                    {
                        ans[k++] = 'x';
                        ans[k++] = '^';
                        ans[k++] = (8-j) + '0';
                    }
                    else if(j == 7)ans[k++] = 'x';
                    else if(j == 8)ans[k++] = '1';
                }
                else if(n == -1)
                {
                    ans[k++] = '-';
                    if(j < 7)
                    {
                        ans[k++] = 'x';
                        ans[k++] = '^';
                        ans[k++] = (8-j) + '0';
                    }
                    else if(j == 7)ans[k++] = 'x';
                    else if(j == 8)ans[k++] = '1';
                }
                else if(n > 0)
                {
                    if(k)ans[k++] = '+';
                    memset(s,0,sizeof(s));
                    deal(n,s);
                    len = strlen(s);
                    for(l = 0; l < len; l++,k++)ans[k] = s[l];
                    if(j < 7)
                    {
                        ans[k++] = 'x';
                        ans[k++] = '^';
                        ans[k++] = (8-j) + '0';
                    }
                    else if(j == 7)ans[k++] = 'x';
                    else if(j == 8)continue;

                }
                else if(n < 0)
                {
                    ans[k++] = '-';
                    memset(s,0,sizeof(s));
                    deal(n,s);
                    len = strlen(s);
                    for(l = 0; l < len; l++,k++)ans[k] = s[l];
                    if(j < 7)
                    {
                        ans[k++] = 'x';
                        ans[k++] = '^';
                        ans[k++] = (8-j) + '0';
                    }
                    else if(j == 7)ans[k++] = 'x';
                    else if(j == 8)continue;
                }
            }
        }
        ans[k] = '\0';
        if(!strlen(ans)){ans[0] = '0';ans[1] = '\0';}
        printf("case #%d:\n",i);
        printf("%s\n",ans);
    }
    return 0;
}