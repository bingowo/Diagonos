#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int find1_9(char *s)
{
    int len = strlen(s),k;
    for(k = 0; k < len; k++)
        if(s[k] == '9')break;
    return k;
}

int main()
{
    char s[1007],ss[1007];
    int i,j,k = 0,m,tmp,len,sum;
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
        s[len++] = m%10 + '0';
        sum = sum + s[len-1]-'0';
    }
    s[len] = '\0';
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
                  k = find1_9(s);
                  s[k]++;
                  for(j = 0; j < k; j++)s[j] = '0';
                  for(j = 0,sum = 0; j < len; j++)
                  {
                     tmp = s[j]-'0' + m;
                     s[j] = tmp%10 + '0';
                     m = tmp/10;
                     sum = sum + s[j]-'0';
                  }
                  while(m)
                    {
                       s[len++] = m%10 + '0';
                       sum = sum + ss[len-1]-'0';
                       m /= 10;
                    }
                    s[len] = '\0';
                  if(find_9(s) && sum%9 != 0)
                  {
                     reverse(s);
                     printf("%s\n",s);
                     break;
                  }

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
                       s[len++] = m%10 + '0';
                       sum = sum + s[len-1]-'0';
                       m /= 10;
                    }
                    s[len] = '\0';
                  }
            }
    }
    return 0;
}