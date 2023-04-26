#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //a做为对照的组
    char a[1000]={0};
    char s[100000]={0};
    char max[100000]={0};
    char str[1000001];
    int i=0,j=0,r=0;
    char t;
    char ch;
    gets(str);
    while(str[r])
    {
        t=str[r];
        if(a[t] == 0 )
            s[i++]=str[r];

        else
        {
            if(strlen(s) > strlen(max))
                strcpy(max,s);

            r=r-strlen(s)+1;
            t=str[r];

            //初始化s
            j=0;
            while(s[j] != 0) s[j++] = 0;

            //初始化a
            for(j=0;j<200;j++)
                a[j] = 0;

            //从上一个非重复字符串的第一个字母的下一个字母开始读
            i=0;
            s[i++]=str[r];
        }
        a[t] = '1';
        r++;
    }

    if(max[0] == 0) strcpy(max,s);
    printf("%s",max);
    return 0;
}
