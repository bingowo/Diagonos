#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100] = {0};
    char tmp[100] = {0};
    char c = 0;
    char arr[123] = {0};
    int i =0;
    int num = 0;
    int max = 0;
    int flag = 0;
    while((c = getchar())!='\n')
    {
        if(arr[c] == 0 && flag == 0)
        {
            arr[c] = 1;
            tmp[num++] = c;
            flag = 1;
        }
        else if(arr[c] == 0)
        {
            arr[c] = 1;
            tmp[num++] = c;
        }
        else
        {
            if(num>max)
            {
                strcpy(s, tmp);
                max = num;
            }
            flag = 0;
            num = 0;
            for(int i = 0; i<123; i++) arr[i] = 0;
            arr[c] = 1;
            tmp[num++] = c;
            flag = 1;
        }

    }
    if(num>max)
    {
        strcpy(s, tmp);
    }
    printf("%s", s);
    return 0;
}
