#include <stdio.h>
#include<stdlib.h>
#include <string.h>
char order[27];
int compare(const void* a, const void* b)
{
    char* str_a = (char*) a;
    char* str_b = (char*) b;

    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    for (int i = 0; i < len_a && i < len_b; i++) {
        int index_a = strchr(order, str_a[i]) - order;
        int index_b = strchr(order, str_b[i]) - order;

        if (index_a < index_b) {
            return -1;
        } else if (index_a > index_b) {
            return 1;
        }
    }
    if (len_a < len_b) {
        return -1;
    } else if (len_a > len_b) {
        return 1;
    }

    return 0;
}

int main()
{
    while (scanf("%s", order) != EOF) {
        char strings[101][21];  
        int n = 0;              

        char input[21];
        while (scanf("%s", input) && strcmp(input, "#") != 0) {
            strcpy(strings[n], input);
            n++;
        }

        qsort(strings, n, sizeof(char) * 21, compare);
        for (int i = 0; i < n; i++) {
            printf("%s ", strings[i]);
        }
        printf("\n");
    }

    return 0;
}