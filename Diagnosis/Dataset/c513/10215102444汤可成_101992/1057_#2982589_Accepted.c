#include <stdio.h>
#include <stdlib.h>

int main()
{
    char w[4001] = {0};
    char* left = w+2000;
    char* right = w+2000;
    char ch = getchar();
    if(ch>='a' && ch<='z') ch -= 'a'-'A';
    *left = ch;
    while((ch = getchar()) != '\n')
    {
        if(ch>='a' && ch<='z')
        {
            ch -= 'a'-'A';
        }
        if(*left <= ch)
        {
            left--;
            *left = ch;
        }
        else
        {
            right++;
            *right = ch;
        }
    }
    int i = 0;
    while(w[i] == 0) i++;
    printf("%s\n", &w[i]);
    return 0;
}
