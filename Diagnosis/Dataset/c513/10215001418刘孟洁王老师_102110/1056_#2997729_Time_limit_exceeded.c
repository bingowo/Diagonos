#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[4007][17],ss[5007],ans[4007][17],t[5007];
int main()
{
    int n,i,j,k,sum,flag,h;
    scanf("%d",&n);
    for(i = 0; i < n; i++)scanf("%s",s[i]);
    scanf("%s",t);
    int l = strlen(t);
    for(i = l-1,k = 0,sum = 0; i >= k;)
    {
        strcpy(ss,t+k);
        h = strlen(ss);
        flag = 0;
        for(j = n-1; j >= 0; j--)
           if(strcmp(ss,s[j]) == 0)
              {
                  strcpy(ans[sum++],ss);
                  k += strlen(ss);
                  break;
              }
        if(k == l)break;
        else for(i = h-1; i >= 0; i--)
        {
            if(i == 0)
            {
                ans[sum][0] = t[k];
                ans[sum++][1] = '\0';
                k += 1;
                i = l;
                break;
            }
            ss[i] = '\0';
            if(i == 1 && j == n)
           {
            ans[sum][0] = t[k];
            ans[sum++][1] = '\0';
            k += 1;
            i = l;
            break;
           }
            for(j = 0; j < n; j++)
               if(strcmp(ss,s[j]) == 0)
               {
                  strcpy(ans[sum++],ss);
                  k += strlen(ss);
                  flag = 1;
                  i = l;
                  break;
               }
           if(flag == 1)break;
        }
    }
    for(j = 0; j < sum; j++)printf("%s%c",ans[j],j == sum-1?'\n':' ');
    return 0;
}
