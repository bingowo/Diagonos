#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 1000001
int main()
{
    char input[L];
    char output[L];
    char temp[L];
    int table[256];
    int i,len = 0,len_cur = 0;
    scanf("%s",input);
    memset(table,-1,256*sizeof(int));
    for(i = 0;i < strlen(input);i++)
    {
        if(table[input[i]] == -1)
        {
            temp[len_cur++] = input[i];
            table[input[i]] == 0;
        }
        else
        {
            memset(table,-1,256*sizeof(int));
            table[input[i]] == 0;
            temp[len_cur] = '\0';
            if(len_cur > len)
            {
                strcpy(output,temp);
            }
            len_cur = 0;
            temp[len_cur++] = input[i];
        }
    }
    if(len_cur > len)
    {
        temp[len_cur] = '\0';
        strcpy(output,temp);
    }
    printf("%s\n",output);

}