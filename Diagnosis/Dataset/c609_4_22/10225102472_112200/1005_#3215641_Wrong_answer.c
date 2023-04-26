#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    char x[10000];
    int answer = 0;
    int i = 0, k = 0;

    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%s", x);


        for (k = 0; x[k] != '\0'; k++)
        {
            if (x[k] == '-')
            {
                answer = answer * 3 - 1;
                continue;
            }
            if (x[k] == '0')
            {
                answer = answer * 3;
                continue;
            }
            if (x[k] == '1')
            {
                answer = answer * 3 + 1;
                continue;
            }
        }

        printf("case #");
        printf("%d", i);
        printf(" \n");
        printf("%d\n", answer);

        k = 0;
    }

    return 0;
}

