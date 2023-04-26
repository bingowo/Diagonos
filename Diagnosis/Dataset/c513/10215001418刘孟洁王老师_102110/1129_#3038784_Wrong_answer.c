#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i,num,k;
    char s[1007],ss[10007];
    scanf("%s",s);
    int len = strlen(s);
    for(i = 0,k = 0; i < len; )
    {
        if(!isdigit(s[i])){ss[k++] = s[i];i++;}
        else if(isdigit(s[i]))
        {
            ss[k] = 0;
            for(num = 0; isdigit(s[i])&&i < len; i++)num = num*10 + s[i]-'0';
            for(k = 0; k < num; k++)
            {
               printf("%s",ss);//每次直接输出就好；
            }
            k = 0;
            memset(ss,0,sizeof(ss));
        }
    }
    return 0;
}
