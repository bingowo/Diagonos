#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    char x[1000];
    int answer = 0;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%s", x);
        int len = strlen (x);

        for (int k = 0; k < len; k++)
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
        printf(":\n");
        printf("%d", answer);

        answer = 0;
    }

    return 0;
}

