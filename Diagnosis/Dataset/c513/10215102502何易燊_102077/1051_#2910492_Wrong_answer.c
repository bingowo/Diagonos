#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void getbyte(char ch,char s[])
{
    int r = strlen(s);
    for (int i=7;i>=0;i--) s[r++] = ((ch>>i)&1)+'0';
}

main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char ans[50] = {}; int index = 0;
        char s[101] = {}; scanf("%s",s);
        char store[5001] = {};
        for (int j=0;s[j];j++) getbyte(s[j],store);
        if (strlen(store)%6!=0)
        {
            int complete = 6-strlen(store)%6;
            int p = strlen(store);
            for (int j=0;j<complete;j++) store[p+j] = '0';
        }
        for (int j=0;store[j];j+=6)
        {
            char t[7] = {};
            for (int k=0;k<6;k++) t[k] = store[j+k];
            ans[index++] = table[strtol(t,NULL,2)];
        }
        if (index<=4) for (int j=3;ans[j]=='\0';j--) ans[j] = '=';
        printf("case #%d:\n%s\n",i,ans);
    }
    system("pause");
    return 0;
}