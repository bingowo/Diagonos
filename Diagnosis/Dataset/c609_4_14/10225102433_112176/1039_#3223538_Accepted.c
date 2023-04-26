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
        if((strcmp(s1,s2) == 0) && (strcmp(s1,s) == 0))
        {
            printf("0\n");
            continue;
        }
        char *p1b = strstr(s,s1);
        if(p1b == NULL)
        {
            printf("0\n");
            continue;
        }
        char *p2b = strstr(s,s2);
        if(p2b == NULL)
        {
            printf("0\n");
            continue;
        }
        int dis1 = p1b-s;
        dis1 += strlen(s1);
        int dis3 = p2b-s;
        dis3 += strlen(s2);
        reverse(s);
        reverse(s2);
        reverse(s1);
        char *p2e = strstr(s,s2);
        int dis2 = p2e-s;
        dis2 += strlen(s2);
        char *p1e = strstr(s,s1);
        int dis4 = p1e-s;
        dis4 += strlen(s1);
        int length1 = dis1 + dis2;
        int length2 = dis3 + dis4;
        int length = length1 <= length2 ? length1 : length2;
        unsigned len = strlen(s);
        printf("%d\n",len-length);
    }
    return 0;
}