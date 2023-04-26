#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    char *x = "\0";
    int answer = 0;
    int len;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%s", x);
        len = strlen (x);
        for (int k = 0; k < len; k++)
        {
            if (x[k] == '-')
            {
                answer = answer * 3 - 1;
            }
            else if (x[k] == '0')
            {
                answer = answer * 3;
            }
            else
            {
                answer = answer * 3 + 1;
            }
        }

        printf("%d", answer);
    }
    return 0;
}

