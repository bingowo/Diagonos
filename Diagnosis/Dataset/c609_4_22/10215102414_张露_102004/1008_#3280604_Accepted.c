#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showMemory(void* a, size_t size)
{
    unsigned char* p = (unsigned char*)a;
    for (size_t i = 0; i < size; i++)
    {
        printf("%02x ", *(p++));
    }
    printf("\n");
}

int main()
{
    char s[100];
    while (scanf("%s", s) != EOF)
    {
        if (strchr(s, '.') == NULL)
        {
            int a = atoi(s);
            showMemory(&a, sizeof(a));
        }
        else
        {
            double a = atof(s);
            showMemory(&a, sizeof(a));
        }
    }
    return 0;
}
