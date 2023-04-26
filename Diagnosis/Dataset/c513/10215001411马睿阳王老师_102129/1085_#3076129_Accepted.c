#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s)
{
    int len = strlen(s) - 1;
    for(int i = 0; i <= len/2; i++)
    {
        char p = s[i];
        s[i] = s[len-i];
        s[len-i] = p;
    }
    s[len+1] = '\0';
}

void minus(char *s1,char *s2,char *ans)
{
    int i;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = len1>len2?len1:len2;
    for(i = 0; i < len; i++)ans[i] = s1[i] - s2[i] + '0';
    
    for(i = 0; i < len-1; i++)
    {
        if(ans[i] < '0')
        {
            ans[i+1] -= 1;
            ans[i] += 10;
        }
    }
    ans[len] = '\0';
    //printf("%s\n",ans);
}

int main()
{
    char s1[1007],s2[1007],ans[1007],ans1[1007];
    int i,j,len1,len2,k;
    int len;
    memset(s1,'0',sizeof(s1));memset(s2,'0',sizeof(s2));
   while(scanf("%s%s",s1,s2)!=EOF)
    {
        if(strcmp(s1,s2) == 0){printf("0\n");continue;}
        memset(ans,'0',sizeof(ans));memset(ans1,'0',sizeof(ans1));
        len1 = strlen(s1);len2 = strlen(s2);
        len = len1>len2?len1:len2;
        char tmp[1007];
        memset(tmp,'0',sizeof(tmp));
        if((len1 < len2)||(len1 == len2 && strcmp(s1,s2) < 0))
       {
          strcpy(tmp,s1);
          strcpy(s1,s2);
          strcpy(s2,tmp);
          k = 1;
          reverse(s1);reverse(s2);
       for(i = len2; i < len; i++)s1[i] = '0';
       for(i = len1; i < len; i++)s2[i] = '0';
       s1[len] = '\0';s2[len] = '\0';
       }

       else
       {
            reverse(s1);reverse(s2);
            for(i = len1; i < len; i++)s1[i] = '0';
            for(i = len2; i < len; i++)s2[i] = '0';
            s1[len] = '\0';s2[len] = '\0';
            k = 0;
       }
       minus(s1,s2,ans);
       reverse(ans);
       len = strlen(ans);
       int flag = 1;
       for(i = 0,j = 0; i < len; i++)
        {
           if(flag && ans[i] == '0')continue;
           flag = 0;
           ans1[j] = ans[i];
           j++;
        }
        ans1[j] = '\0';
       if(k == 1)printf("-%s\n",ans1);
       else if(k == 0) printf("%s\n",ans1);
       //printf("%s %s\n",s1,s2);
    }
    return 0;
}