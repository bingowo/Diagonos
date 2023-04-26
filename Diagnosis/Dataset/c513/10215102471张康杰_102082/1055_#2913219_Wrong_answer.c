#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*s1,const void*s2)
{
    return *(int*)s2 - *(int*)s1;
}
int main()
{
    char input[1000000];
    char output[1000000];
    char*temp;
    temp = (char*)malloc(1000000);
    scanf("%s",input); 
    int table[256],len = strlen(input),i,count = 0;
    int longest_cur = 0,longest_max = 0;
    memset(table,-1,sizeof(int)*256);
    for(i = 0;i < len;i++)
    {
        if(table[input[i]] == -1)
        {
            longest_cur++;
            table[input[i]] = i; 
            temp[count++] = input[i];
        }
        else
        {
            if(longest_cur > longest_max)
            {
                longest_max = longest_cur;
            }
            longest_cur = 1;
            temp[count] = '\0';
            count = 0;
            strncpy(output,temp,longest_max);
            memset(table,-1,sizeof(int)*256);
            table[input[i]] = i;
            temp = (char*)malloc(1000000);
        }

    }
    if(longest_cur > longest_max)
    {
        longest_max = longest_cur;
        temp[count] = '\0';
        strncpy(output,temp,longest_max);
    }
    printf("%s",output);
    

}