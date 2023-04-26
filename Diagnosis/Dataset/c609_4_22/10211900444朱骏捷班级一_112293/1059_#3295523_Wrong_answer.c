#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1000
typedef struct
{
    char num[MAXLEN];
    int sign;
    int int_len;
    char integer[MAXLEN / 2];
    char fraction[MAXLEN / 2];
} FLOAT;

int cmp(const void *a, const void *b)
{
    FLOAT *f1 = (FLOAT *)a, *f2 = (FLOAT *)b;
    if (f1->sign != f2->sign)
        return f1->sign - f2->sign;
    else
    {
        if (f1->sign == -1 && f2->sign == -1)
        {
            if (f1->int_len != f2->int_len)
                return f1->int_len < f2->int_len;
            else
            {
                int x;
                if (x = strcmp(f1->integer, f2->integer))
                    return x;
                else
                    return strcmp(f1->fraction, f2->fraction);
            }
        }
        else if (f1->sign == 0 && f2->sign == 0)
        {
            if (f1->int_len != f2->int_len)
                return f1->int_len > f2->int_len;
            else
            {
                int x;
                if (x = strcmp(f1->integer, f2->integer))
                    return x;
                else
                    return strcmp(f1->fraction, f2->fraction);
            }
        }
    }
}

void check(char *s, FLOAT *arr)
{
    char t[MAXLEN];
    strcpy(t, s);
    if (s[0] == '-')
    {
        strcpy(arr->integer, "");
        char *p = strstr(t, "-");
        if (p != NULL)
        {
            char delims[] = "-";
            char *s1 = NULL;
            char *s2 = NULL;
            s1 = strtok(t, delims);
            s2 = strtok(NULL, delims);
            strcpy(arr->integer, s1);
        }
    }
    else if (s[0] == '+')
    {
        // printf("0");
        strcpy(arr->integer, "");
        // printf("#%s\n", t);
        char *p = strstr(t, "+");
        if (p != NULL)
        {
            char delims[] = "+";
            char *s1 = NULL;
            char *s2 = NULL;
            s1 = strtok(t, delims);
            s2 = strtok(NULL, delims);
            strcpy(arr->integer, s1);
        }
    }
}

int main()
{
    FLOAT arr[MAXLEN];
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++)
    {
        char str[MAXLEN], s[MAXLEN];
        scanf("%s", str);
        strcpy(arr[i].num, str);
        strcpy(s, str);
        arr[i].sign = 0;
        if (str[0] == '-')
            arr[i].sign = -1;

        char *p = strstr(s, "."); // <=> char *p = strchr(s, '.');
        if (p != NULL)
        {
            char delims[] = ".";
            char *s1 = NULL;
            char *s2 = NULL;
            s1 = strtok(s, delims);
            s2 = strtok(NULL, delims);
            strcpy(arr[i].integer, s1);
            strcpy(arr[i].fraction, s2);
        }
        else
        {
            strcpy(arr[i].integer, str);
            strcpy(arr[i].fraction, "0");
        }
        // printf("%s\n", arr[i].integer);
        check(arr[i].integer, &arr[i]);
        arr[i].int_len = strlen(arr[i].integer);
    }

    qsort(arr, n, sizeof(FLOAT), cmp);
    for (int i = 0; i != n; i++)
    {
        printf("%s\n", arr[i].num);
        // printf("%s\n", arr[i].integer);
        // printf("%s\n", arr[i].fraction);
        // printf("\n");
    }

    return 0;
}