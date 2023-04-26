#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        char s1[81] = {0};
        char s2[81] = {0};
        char s[200] = {0};
        scanf("%s %s %s", s1, s2, s);
        printf("case #%d:\n", i);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int len = strlen(s);
        char* left = strstr(s, s1);
        char* right = strstr(s, s2);
        if(left == NULL || right == NULL)
        {
            printf("0\n");
            continue;
        }
        char* tmpl = left;
        char* tmpr = right;
        right = right+len2-1;
        char* c = 0;
        while(left+1-s <= len-len1 && (c = strstr(left+1, s1))!= NULL)
        {
            left = c;
        }
        int ret = left-right-1;
        left = tmpl;
        right = tmpr;
        left = left+len1-1;
        while(right+1-s <= len-len2 && (c = strstr(right+1, s2))!= NULL)
        {
            right = c;
        }
        ret = ret<(right-left-1)? (right-left-1):ret;
        if(ret>0) printf("%d\n",ret);
        else printf("0\n");
    }
    return 0;
}
