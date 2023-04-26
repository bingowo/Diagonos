#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s)
{
    int len = strlen(s)-1;
    for(int i = 0; i <= len/2; i++)
    {
        char tmp = s[i];
        s[i] = s[len-i];
        s[len-i] = tmp;
    }
    s[len+1] = '\0';
}

int main()
{
    int n,i,j,k,sum;
    char s[1007][27],ss[27],ans[1007][27],t[5007];
    scanf("%d",&n);
    for(i = 0; i < n; i++)scanf("%s",s[i]);
    scanf("%s",t);
    int l = strlen(t);
    for(i = l-1,k = 0,sum = 0; i >= k; i--)
    {
        strcpy(ss,t+k);
        for(j = 0; j < n; j++)
           if(strcmp(t+k,s[j]) == 0){strcpy(ans[sum++],ss);break;}
        ss[i-k] = '\0';
        for(j = 0; j < n; j++)
           if(strcmp(ss,s[j]) == 0)
           {
               strcpy(ans[sum++],ss);
               k = i;
               i = l;
               break;
           }
        if(i == k && j == n)
        {
            ans[sum][0] = t[k];
            ans[sum++][1] = '\0';
            k = i+1;
            i = l;
        }
    }
    for(j = 0; j < sum; j++)printf("%s%c",ans[j],j == sum-1?'\n':' ');
    return 0;
}
