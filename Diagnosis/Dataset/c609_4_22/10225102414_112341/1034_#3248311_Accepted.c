#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *I,*begin, *stop;
    int len, n = -1, i;
    unsigned int out;
    I = (char *)malloc(sizeof(char) * 100000);
    scanf("%s", I);
    len = strlen(I);
    for (i = 0;i < len - 2;i++){
        if (I[i] == '0'){
            if (I[i + 1] == 'x'){
                begin  = &I[i + 2];
                out = strtol(begin, &stop, 16);
                if (out != 0){
                    n += 1;
                    printf("%u ", out);
                }else if(i + 2 < len && I[i + 2] == '0'){
                    n += 1;
                    printf("0 ");
                }
                i = stop - I;
            }
        }
    }
    if (n == -1){
        printf("-1");
    }
    return 0;
}