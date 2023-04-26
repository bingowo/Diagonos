#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int n;
    scanf("%d ",&n);
    for (int i=0;i<n;i++)
    {
        char *res = (char*)malloc(10);
        char s[501] = {};
        char *t = (char*)malloc(501);
        memset(t,0,sizeof(t));
        gets(s);
        int index = 0;
        char ch = s[index];
        int cnt = 0;
        while (s[index])
        {
            while (s[index]==s[index+1]&&cnt<254) {index++; cnt++;}
            index++, cnt++;
            sprintf(res,"%d",cnt);
            strcat(t,res);
            sprintf(res,"%c",ch);
            strcat(t,res);
            ch = s[index];
            cnt = 0;
        }
        printf("#case #%d:\n%s\n",i,t);
    }
    return 0;
}