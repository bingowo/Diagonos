#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long arr[3];

void funcint(char *s)
{
    long long n = 0, m = 1;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i)
    {
        int k;
        if (s[i] == '2')
            k = -1;
        if (s[i] == '0')
            k = 0;
        if (s[i] == '1')
            k = 1;
        n += k * m;
        m *= 3;
    }
    arr[0] = n;
}

void funcdec(char *s)
{
    long long numerator = 0, denominator = 1;
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        int k;
        if (s[i] == '2')
            k = -1;
        if (s[i] == '0')
            k = 0;
        if (s[i] == '1')
            k = 1;
        numerator += k;
        arr[1] = numerator;
        numerator *= 3;
        denominator *= 3;
        arr[2] = denominator;
    }
}

int main()
{
    char s[32];
    scanf("%s", s);

    char *p = strstr(s, ".");
    if (p != NULL)
    {
        char delims[] = ".";
        char *s1 = NULL;
        char *s2 = NULL;
        s1 = strtok(s, delims);
        s2 = strtok(NULL, delims);
        // printf("%s %s", s1, s2);
        funcint(s1);
        funcdec(s2);
        if (arr[0] < 0 && arr[1] > 0)
        {
            arr[0] += 1;
            arr[1] = arr[2] - arr[1];
        }

        else if (arr[0] > 0 && arr[1] < 0)
        {
            arr[0] -= 1;
            arr[1] = arr[2] + arr[1];
        }
        else if (arr[0] < 0 && arr[1] < 0)
        {
            arr[1] = -arr[1];
        }
        if (arr[0])
            printf("%d %d %d", arr[0], arr[1], arr[2]);
        else
            printf("%d %d", arr[1], arr[2]);
    }
    else
    {
        printf("%s", s);
        funcint(s);
        printf("%d", arr[0]);
    }
    return 0;
}