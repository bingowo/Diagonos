#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char flag;
    scanf("%c",flag);
    int number[1001] , i;
    for( i = 0 ; i <1001 ; i++)
        number[i] = 0;

    while((scanf("%d", &i)) != EOF)
        number[i]++;

    if(flag == 'A')
    {
        for(i = 0; i < 1001 ; i++)
            if(number[i] > 0)
                printf("%d ", i);
    }
    else
    {
        for(i = 1001; i > 0 ; i--)
            if(number[i] > 0)
                printf("%d ", i);
    }
    printf("\n");
}

