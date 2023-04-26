#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char str[55];
    scanf("%s",str);
    int cou = 1;
    int sum = 0;
    for (int i = 0;i<strlen(str)-1;++i)
    {
        if (str[i] != str[i+1])  cou++;
        else
        {
            cou = 1;
        }
        sum = sum > cou ? sum:cou;
    }
    printf("%d",sum);
    return 0;
}
