#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char xdigits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void x2y(int A, char *s, int B)
{
    int dec = 0;
    int len = strlen(s), m = 1;
    for (int i = len - 1; i >= 0; --i)
    {
        int k;
        if (s[i] >= '0' && s[i] <= '9')
            k = s[i] - '0';
        if (s[i] >= 'A' && s[i] <= 'Z')
            k = s[i] - 'A' + 10;
        if (s[i] >= 'a' && s[i] <= 'z')
            k = s[i] - 'a' + 10;
        dec += k * m;
        m *= A;
    }
    char str[32];
    int i = 0;
    do
    {
        str[i++] = xdigits[dec % B];
    } while (dec /= B);
    str[i] = '\0';
    /*int c, j = 0, k;
    for (k = j - 1; j < k; ++j, --k)
    {
        c = str[j];
        str[j] = str[k];
        str[k] = c;
    }
    */
    for (i; i >= 0; --i)
        printf("%c", str[i]);
    // printf("%s", str);
}

int main()
{
    int A, B;
    char s[32];
    scanf("%d %s %d", &A, s, &B);
    x2y(A, s, B);
    return 0;
}