#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isNotWord(char s[])
{
    int len = strlen(s);
    char *s1 = s;
    for(int i = 0;i<len;i++)
    {
        if((s1[i]>='A')&&(s1[i]<='Z'))
        {
            s1[i]+=32;
        }
    }
    //printf("s1 = %s\n",s1);
    if((strcmp(s1,"the")==0)||(strcmp(s1,"a")==0)
    ||(strcmp(s1,"an")==0)||(strcmp(s1,"of")==0)
    ||strcmp(s1,"for")==0||strcmp(s1,"and")==0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    getchar();
    for(int i = 0;i<T;i++)
    {
        char s[110];memset(s,0,110*sizeof(char));
        char ss[100][20];memset(ss,0,100*20*sizeof(char));
        gets(s);
        int j = 0,cnt = 0,slen = strlen(s),k = 0;
        for(j = 0;j<slen;j++)
        {
            if(isalpha(s[j])||(s[j]=='\''))
            {
                ss[cnt][k] = s[j];
                k++;
            }
            else
            {
                k = 0;
                cnt++;
            }
        }
        int n = cnt+1;
        for(int j = 0;j<=cnt;j++)
        {
            if(isNotWord(ss[j])==1)
            {
                n--;
            }
        }

        printf("case #%d:\n",i);
        //printf("cnt = %d\n",cnt);
        printf("%d\n",n);

    }
    return 0;
}
