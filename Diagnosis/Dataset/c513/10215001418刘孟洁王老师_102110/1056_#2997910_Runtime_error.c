#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 233

int turn(long long sum)
{
    while(sum>4000)
    {
        sum = sum/4000 + sum%4000;
    }
    return sum;
}
int hash[10000007] = {0};
int main()
{
    int n,i,j,k,sum,num,h;
    char s[17],ss[5007],t[5007];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        for(j = 0,sum = 0; j < len; j++)
        {
            if(s[j] <= 'z' && s[j] >= 'a')
               sum = sum*p + s[j]-'a'+3;
            else if(s[j] <= 'Z' && s[j] >= 'A')
                sum = sum*p + s[j]-'A'+3;
        }
        hash[turn(sum)] = 1;
    }
    scanf("%s",t);
    int l = strlen(t);
    for(i = l-1,k = 0,sum = 0; k <= l;)
    {
        strcpy(ss,t+k);
        h = strlen(ss);
        for(j = 0,num = 0; j < h; j++)
        {
            if(ss[j] <= 'z' && ss[j] >= 'a')num = num*p + ss[j]-'a'+3;
            else if(ss[j] <= 'Z' && ss[j] >= 'A')num = num*p + ss[j]-'A'+3;
        }
        if(hash[turn(sum)] == 1)
        {
            k += strlen(ss);
            printf("%s ",ss);
        }
        if(k == l)break;
        else
            for(i = h-1; i >= 0; i--)
          {
              if(i == 0)
              {
                  printf("%c ",ss[0]);
                  k += 1;
                  break;
              }
              else
              {
                  ss[i] = '\0';
                  for(j = 0,num = 0; j < i; j++)
                 {
                   if(ss[j] <= 'z' && ss[j] >= 'a')num = num*p + ss[j]-'a'+3;
                   else if(ss[j] <= 'Z' && ss[j] >= 'A')num = num*p + ss[j]-'A'+3;
                  }
                  if(hash[turn(sum)] == 1)
                 {
                   k += strlen(ss);
                   printf("%s ",ss);
                   break;
                 }
                 else if(i == 1)
                 {
                   k += 1;
                   printf("%s ",ss);
                   break;
                 }
                 else continue;
              }

          }
    }
    return 0;
}