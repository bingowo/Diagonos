#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char ans[100000007];
char s[10007],ss[100000007];
int main()
{
    int len1,l,i,num,k;
    scanf("%s",s);
    int len = strlen(s);
    for(i = 0,k = 0; i < len; )
    {
        if(!isdigit(s[i])){ss[k++] = s[i];i++;}
        else if(isdigit(s[i]))
        {
            for(num = 0; isdigit(s[i])&&i < len; i++)num = num*10 + s[i]-'0';
            len1 = strlen(ans);
            l = strlen(ss);
            for(k = 0; k < num; k++)
            {
                strcpy(ans+len1,ss);
                len1 += l;
            }
            k = 0;
            memset(ss,0,sizeof(ss));
        }
    }
    printf("%s",ans);
    return 0;
}