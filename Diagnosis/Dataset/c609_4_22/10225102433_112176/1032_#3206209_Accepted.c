#include <stdio.h>
#include <string.h>

int main()
{
    char c,res;
    int cnt = 1;
    int max = 0;
    res = getchar();
    while(1)
    {
        c = getchar();
        if(c == '\n')
            break;
        if(c == res)
        {
            max = cnt > max ? cnt : max;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        res = c;
    }
    max = cnt > max ? cnt : max;
    printf("%d",max);
    return 0;
}