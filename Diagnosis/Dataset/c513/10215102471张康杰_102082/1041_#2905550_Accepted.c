#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[51],ch;
    int i = 0;
    //int flag = 1;
    int longest_cur = 0,longest_max = 0;
    while((ch = getchar()) != '\n')
    {
        input[i] = ch;
        if(i == 0)
        {
            longest_cur++;
            //flag = 0;
        }
            
        else
        {
            if(ch != input[i - 1])
                longest_cur++;
            else
            {
                if(longest_cur > longest_max)
                {
                    longest_max = longest_cur;
                }
                longest_cur = 1;
                //flag = 1;
                //longest_cur = 0;
            }
        }
        i++;
    }
    if(longest_cur > longest_max)
        longest_max = longest_cur;
    printf("%d",longest_max);

    return 0;
}