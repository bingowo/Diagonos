#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[51],ch;
    int i = 0;
    int count = 0;
    while((ch = getchar())!= EOF)
    {
        input[i++] = ch;
        if(i == 1)
            count++;
        else
        {
            if(ch != input[i - 2])
                count++;
            else
                count = 0;
        }
    }
    printf("%d",count);

    return 0;
}