#include <stdio.h>
int main()
{
    char ch = getchar();
    int len = 1;
    int maxLen = 1;
    char tmp = ch;
    while((ch = getchar())!=EOF)
    {
        if(maxLen < len) { maxLen = len;}
        if(ch == tmp) {len = 1;}
        else {len++;}
        tmp = ch;
    }
    printf("%d\n",maxLen);
    return 0;
}