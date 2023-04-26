#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char* s,int k,int len)
{
    if (k>=len) return ;
    static char t[50] = {}; static int l = 0;
    for (int i=k;i<len;i++)
    {
        t[l++] = s[i];
        printf("%s\n",t);
        dfs(s,i+1,len);
        t[--l] = '\0';
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
    {
        int table[128] = {};
        int c;
        while ((c = getchar())!='\n') if (table[c]==0) table[c]++;
        char s[128]; int len = 0;
        for (int i=0;i<128;i++) if (table[i]) s[len++] = i;
        printf("case #%d:\n",i);
        dfs(s,0,len);
    }
    return 0;
}