#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char *s)
{
    int i;
    int len = strlen(s);
    for(i = 0; i < len-1; i++)
    {
        if(s[i] == s[i+1])break;
    }
    if(i == len-1)return 0;
    else return 1;
}

void reverse(char *s)
{
    int len = strlen(s)-1;
    for(int i = 0; i <= len/2; i++)
    {
        char p = s[i];
        s[i] = s[len-i];
        s[len-i] = p;
    }
    s[len+1] = '\0';
}

void add(char *s)
{
  int len = strlen(s);
  int m = 1;
  for(int i = 0; i < len; i++)
  {
     int tmp = s[i]-'0' + m;
     s[i] = tmp%10 + '0';
     m = tmp/10;
  }
  while(m)
    {
        s[len] = m%10 + '0';
        len++;
        m /= 10;
  }
  s[len] = '\0';
  //printf("%s\n",s);
}

int main()
{
    int n;
    char s[1007];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s",s);
        if(strlen(s) == 1)
        {
            if(s[0] < '9'){s[0]++;printf("case #%d:\n%s\n",i,s);continue;}
            else if(s[0] == '9'){printf("case #%d:\n10\n",i);continue;}
        }
        else
        {
            reverse(s);
            add(s);
            while(judge(s) == 1)
            {add(s);}
            reverse(s);
            printf("case #%d:\n",i);
            printf("%s\n",s);
        }
    }
    return 0;
}