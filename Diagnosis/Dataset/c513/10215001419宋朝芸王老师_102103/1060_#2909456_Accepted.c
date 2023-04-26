#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char in[101];
    scanf("%s",in);

    char *p = in;
    int len = 0, temp = 0;
    while(*p){
        while(isdigit(*p) == 0) p++;
        while(*p == '0') p++;
        while(isdigit(*p)){
            temp++;
            p++;
        }
        len = len > temp ? len : temp;
        temp = 0;
    }

    printf("%d",len);

    return 0;
}
