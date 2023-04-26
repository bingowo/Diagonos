#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char *line = malloc(1000000 * sizeof(char));
    gets(line);
    bool success = false;
    bool flag = true;
    for(char *begin = line, *end = line + strlen(line);
            begin < end;
            begin++) {
        if((*begin == '0') && *(begin + 1) == 'x') {
            char *end_ptr = NULL;
            long long k = strtol(begin + 2, &end_ptr, 16);
            if(end_ptr != begin + 2) {
                success = true;
                if(!flag) {
                    printf(" ");
                } else {
                    flag = false;
                }
                printf("%ld", k);
                begin = end_ptr;
            }
        }
            }
    if(success) {
        printf("-1");
    }
    printf("\n");
    return 0;
}