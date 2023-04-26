#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 90;

char * reverse(char *s)
{
    unsigned len = strlen(s);
    for(int i = 0;i < len>>1;i++)
    {
        char c = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = c;
    }
    return s;
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        char s[90] = {0};
        char s1[90] = {0};
        char s2[90] = {0};
        printf("case #%d:\n",i);
        scanf("%s %s %s",s1,s2,s);
        char *p = strstr(s,s1);
        int dis = p-s;
        dis += strlen(s1);
        reverse(s);
        reverse(s2);
        char *p1 = strstr(s,s2);
        int dis2 = p1-s;
        dis2 += strlen(s2);
        unsigned len = strlen(s);
        printf("%d\n",len-dis-dis2);
    }
    return 0;
}