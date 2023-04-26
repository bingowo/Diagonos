#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *I,*begin, *stop;
    int len, n = -1, i;
    int out;
    I = (char *)malloc(sizeof(char) * 100000);
    scanf("%s", I);
    len = strlen(I);
    for (i = 0;i < len;i++){
        if (I[i] == '0'){
            if (I[i + 1] == 'x'){
                begin  = &I[i + 2];
                out = strtol(begin, &stop, 16);
                n += 1;
                printf("%d ", out);
            }
        }
    }
    if (n == -1){
        printf("-1");
    }
    return 0;
}