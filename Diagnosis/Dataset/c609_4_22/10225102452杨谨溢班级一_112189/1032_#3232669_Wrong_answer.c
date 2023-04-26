#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char str[55];
    scanf("%s",str);
    int cou = 1;
    int sum = 0;
    for (int i = 0;i<strlen(str);++i)
    {
        if (str[i] != str[i+1])  cou++;
        else
        {
            sum = sum >cou?sum:cou;
            cou = 1;
        }
    }
    printf("%d",sum);
    return 0;
}
