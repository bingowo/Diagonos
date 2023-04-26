#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define L 1001

int main()
{
    char word[L],output[2 * L + 1];
    scanf("%s",word);
    int len = strlen(word);
    int i,start,end;
    start = end = L;
    output[L] = toupper(word[0]);
    for(i = 1;i < len;i++)
    {
        if(toupper(word[i]) > toupper(output[start]))
        {
            output[start - 1] = toupper(word[i]);
            start--;
        }
        else
        {
            output[end + 1] = toupper(word[i]);
            end++;
        }
    }
    output[end + 1] = '\0';
    printf("%s",output + start + 1);
    return 0;
}