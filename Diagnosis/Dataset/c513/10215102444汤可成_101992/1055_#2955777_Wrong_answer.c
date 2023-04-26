#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100] = {0};
    char c = 0;
    char arr[123] = {0};
    int i =0;
    while((c = getchar())!='\n')
    {
        if(arr[c] == 0)
        {
            arr[c] = 1;
            s[i++] = c;
        }
    }
    printf("%s", s);
    return 0;
}
