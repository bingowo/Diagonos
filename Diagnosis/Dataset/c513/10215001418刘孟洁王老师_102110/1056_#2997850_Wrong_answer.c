#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 233
int hash[10000007] = {0};
int main()
{
    int n,i,j,k,h;
    long long sum,num;
    char s[17],ss[5007],ans[107][17],t[5007];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        for(j = 0,sum = 0; j < len; j++)
        {
            if(s[j] <= 'z' && s[j] >= 'a')
               sum = sum*p%10000007 + s[j]-'a'+1;
            else if(s[j] <= 'Z' && s[j] >= 'A')
                sum = sum*p%10000007 + s[j]-'A'+1;
        }
        hash[sum%10000007] = 1;
    }
    scanf("%s",t);
    int l = strlen(t);
    for(i = l-1,k = 0,sum = 0; k <= l;)
    {
        strcpy(ss,t+k);
        h = strlen(ss);
        for(j = 0,num = 0; j < h; j++)
        {
            if(ss[j] <= 'z' && ss[j] >= 'a')num = num*p%10000007 + ss[j]-'a'+1;
            else if(ss[j] <= 'Z' && ss[j] >= 'A')num = num*p%10000007 + ss[j]-'A'+1;
        }
        if(hash[num%10000007] == 1)
        {
            k += strlen(ss);
            strcpy(ans[sum++],ss);
        }
        if(k == l)break;
        else
            for(i = h-1; i >= 0; i--)
          {
              if(i == 0)
              {
                  ans[sum][0] = ss[0];
                  ans[sum++][1] = '\0';
                  k += 1;
                  break;
              }
              ss[i] = '\0';
              for(j = 0,num = 0; j < i; j++)
             {
               if(ss[j] <= 'z' && ss[j] >= 'a')num = num*p%10000007 + ss[j]-'a'+1;
               else if(ss[j] <= 'Z' && ss[j] >= 'A')num = num*p%10000007 + ss[j]-'A'+1;
             }
               if(hash[num%10000007] == 1)
             {
               k += strlen(ss);
               strcpy(ans[sum++],ss);
               break;
             }
             else if(i == 1)
             {
                 k += 1;
                 strcpy(ans[sum++],ss);
                 break;
             }
          }
    }
    for(j = 0; j < sum; j++)printf("%s%c",ans[j],j == sum-1?'\n':' ');
    return 0;
}
