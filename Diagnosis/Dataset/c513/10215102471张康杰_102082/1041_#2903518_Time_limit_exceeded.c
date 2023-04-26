#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[51],ch;
    int i = 0;
    int count = 0;
    ch = getchar();
    while(ch != EOF)
    {
        input[i++] = ch;
        if(i == 1)
            count++;
        else
        {
            if(ch != input[i - 1])
                count++;
            else
                count = 0;
        }
    }
    printf("%d",count);

    return 0;
}
