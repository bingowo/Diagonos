#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Reload(char s[], int a[])
{
    int i = 0, j = 0;
    while (s[i] != ' ')
    {
        if (s[i] != ',')
        {
            int k = s[i];
            a[j] = k;
            j++;
        }
        else;
        i++;
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        char s[100];
        int a[26] = { 0 };
        int b[26] = { 0 };
        int c[26] = { 0 };
        scanf("%s", s);
        Reload(s, a);
        printf("%s", a[0]);
    }
    return 0;
}