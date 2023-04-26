#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[4007][17],ss[5007],ans[4007][17],t[5007];
int main()
{
    int n,i,j,k,flag,h,max;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s[i]);
        int len = strlen(s[i]);
        max = max > len?max:len;
    }
    scanf("%s",t);
    int l = strlen(t);
    for(i = max-1,k = 0; k <= l;)
    {
        strcpy(ss,t+k);
        h = strlen(ss);
        flag = 0;
        for(i = h; i >= 0; i--)
        {
            if(i == 0||i == 1)
            {
                printf("%c ",ss[0]);
                k += 1;
                i = max+k < l?max+k:l;
                break;
            }
            ss[i] = '\0';
            for(j = 0; j < n; j++)
               if(strcmp(ss,s[j]) == 0)
               {
                  printf("%s ",s[j]);
                  k += strlen(ss);
                  flag = 1;
                  i = max+k < l?max+k:l;
                  break;
               }
           if(flag == 1)break;
        }
    }
    return 0;
}