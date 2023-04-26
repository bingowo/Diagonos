#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(int p)
{
    int m = 0;
    while(p)
    {
        m = m*10+p%10;
        p = p/10;
    }
    return m;
}

int h(int n)
{
    char s[15] = {0};
    itoa(n, s, 10);
    int len = strlen(s);
    int flag = 1;
    char* left = s;
    char* right = s+len-1;
    while(left < right)
    {
        if(*left != *right)
        {
            flag = 0;
            break;
        }
        left++;
        right--;
    }
    return flag;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    int num = 0;
    int m = 0;
    int s = 0;
    m = convert(n);
    s = m+n;
    num++;
    while(h(s)==0)
    {
        n = s;
        m = convert(n);
        s = m+n;
        num++;
    }
    printf("%d %d", num, s);
    return 0;
}
