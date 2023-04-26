#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    scanf("%s", a);
    int len = strlen(a);
    int enclosure = 1;
    int count = 1;
    for (int i = 0; i < len - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            count++;
        }
        else
        {
            if (count > enclosure)
            {
                enclosure = count;
            }
            count = 1;
        }
    }
    if (count > enclosure)
    {
        enclosure = count;
    }
    printf("%d\n", enclosure);
    return 0;
}
