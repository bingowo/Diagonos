#include <stdio.h>
#include <string.h>

int
main()
{
    char c[51] = {'\0'};
    scanf("%s",c);
    int temp = 1;
    int maxl = 1;
    
    for (int i=1; i<strlen(c); i++)
    {
        if ( *(c+i) != *(c+i-1))
        {
            temp++;
        }
        else
        {
            if (maxl < temp)
            {
                maxl = temp;
            }
            temp = 1;
        }
    }
    if (maxl < temp)
    {
        maxl = temp;
    }
    printf("%d\n",maxl);
    
    return 0;
}