#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a, b) (a > b) ? (a) : (b)
#define maxl 2000
// maxl is the max length of the number
// should be changed according to the problem
void sub(char *s, char *t, char *u)
{
    /*pre condition:s and t are two numbers
   every character in s and t contain only '0'-'9'
   s and t should be positive numbers
   s,t satisfy s>t
   post condition:u is s+t
   make sure u has a length smaller than maxl
   since s>t, we have u>0
   */
    int i, j;
    int lens = strlen(s), lent = strlen(t);
    int k = max(lens, lent);
    for (i = 0; i < lens; i++)
        s[i] -= '0';
    for (i = 0; i < lent; i++)
        t[i] -= '0';
    int cc = 0, p = lens - 1, q = lent - 1;
    int c[maxl];
    memset(c, 0, sizeof(c));
    for (i = k; i >= 0; i--)
    {
        int x = -cc;
        if (p >= 0)
            x += s[p], p--;
        if (q >= 0)
            x -= t[q], q--;
        if (x < 0)
        {
            cc = 1;
            c[i] = x + 10;
        }
        else
        {
            cc = 0;
            c[i] = x;
        }
    }
    p = 0;
    while (c[p] == 0)
        p++;
    for (i = p, j = 0; i <= k; i++, j++)
        u[j] = c[i] + '0';
    u[j] = '\0';
    if (strlen(u) == 0)
    {
        u[0] = '0', u[1] = '\0';
    }
}
int main()
{
    char s[maxl];
    char t[maxl];
    char u[maxl];
    while (scanf("%s%s", s, t) != EOF)
    {
        sub(s, t, u);
        printf("%s\n", u);
    }
    return 0;
}