#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[4007][17],ss[5007],ans[4007][17],t[5007];
int main()
{
    int n,i,j,k,sum,h;
    scanf("%d",&n);
    for(i = 0; i < n; i++)scanf("%s",s[i]);
    scanf("%s",t);
    int l = strlen(t);
    for(i = l-1,k = 0,sum = 0; i >= k; i--)
    {
        strcpy(ss,t+k);
        for(j = 0; j < n; j++)
           if(strcmp(ss,s[j]) == 0){strcpy(ans[sum++],ss);k += strlen(ss);break;}
        if(k == l)break;
        //h = strlen(ss);
        ss[i-k] = '\0';
        for(j = 0; j < n; j++)
           if(strcmp(ss,s[j]) == 0)
           {
               strcpy(ans[sum++],ss);
               k += strlen(ss);
               i = l;
               break;
           }
        if(i == k && j == n)
        {
            ans[sum][0] = t[k];
            ans[sum++][1] = '\0';
            k += 1;
            i = l;
        }
    }
    for(j = 0; j < sum; j++)printf("%s%c",ans[j],j == sum-1?'\n':' ');
    return 0;
}