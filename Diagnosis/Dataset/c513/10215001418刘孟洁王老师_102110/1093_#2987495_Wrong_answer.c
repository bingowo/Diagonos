#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int k = 0;
void reverse(char *s)
{
    int len = strlen(s);
    for(int i = 0; i <= (len-1)/2; i++)
    {
        char p = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = p;
    }
    s[len] = '\0';
}

int find_9(char *s)
{
    int flag = 1;
    int len = strlen(s);
    for(int k = 0; k < len; k++)
        if(s[k] == '9'){flag = 0;break;}
    return flag;
}

int main()
{
    char s[1007],ss[1007];
    int i,j,m,tmp,len1,len,sum1,sum;
    scanf("%s",s);
    len = strlen(s);
    reverse(s);
    s[0]++;
    m = 0;
    for(i = 0; i < len; i++)
    {
        tmp = s[i]-'0' + m;
        s[i] = tmp%10 + '0';
        m = tmp/10;
        sum = sum + s[i]-'0';
    }
    while(m)
    {
        s[len++] = m%10;
        sum = sum + s[len-1]-'0';
    }
    if(find_9(s) && sum%9 != 0)
    {
        reverse(s);
        printf("%s\n",s);
    }
    else
    {
            while(1)
            {
               if(find_9(s) && sum%9 != 0)
                  {
                     reverse(s);
                     printf("%s\n",s);
                     break;
                  }
               else if(!find_9(s))
               {
                  memset(ss,0,sizeof(ss));
                  strcpy(ss,s);
                  len1 = len;
                  ss[k+1]++;
                  for(j = 0; j <= k; j++)ss[j] = '0';
                  for( ; j < len1; j++)
                  {
                     tmp = ss[j]-'0' + m;
                     ss[j] = tmp%10 + '0';
                     m = tmp/10;
                     sum1 = sum1 + ss[j]-'0';
                  }
                  while(m)
                    {
                       ss[len1++] = m%10;
                       sum1 = sum1 + ss[len1-1]-'0';
                       m /= 10;
                    }
                  if(find_9(ss) && sum1%9 != 0)
                  {
                     reverse(ss);
                     printf("%s\n",ss);
                     break;
                  }
                  else
                  {
                      s[0]++;
                      for(i = 0,sum = 0; i < len; i++)
                       {
                          tmp = s[i]-'0' + m;
                          s[i] = tmp%10 + '0';
                          m = tmp/10;
                          sum = sum + s[i]-'0';
                       }
                      while(m)
                    {
                       s[len++] = m%10;
                       sum = sum + s[len-1]-'0';
                       m /= 10;
                    }
                    i = 0;
                  }
               }
            }
    }
    return 0;
}