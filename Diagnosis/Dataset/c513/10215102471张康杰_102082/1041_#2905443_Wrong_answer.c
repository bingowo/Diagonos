#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[51],ch;
    int i = 0;
    int longest_cur = 0,longest_max = 0;
    while((ch = getchar())!= EOF)
    {
        input[i] = ch;
        if(i == 0)
            longest_cur++;
        else
        {
            if(ch != input[i - 2])
                longest_cur++;
            else
            {
                if(longest_cur > longest_max)
                    longest_max = longest_cur;
                longest_cur = 0;
            }
        }
        i++;
    }
    printf("%d",longest_max);

    return 0;
}