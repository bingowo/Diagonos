#include <stdio.h>
#include <stdlib.h>

void solveint(int n) {
    int c = sizeof(n);
    unsigned char* p = (unsigned char*)&n;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}

void solvedouble(double d){
    int c = sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}


int main()
{
    char str;
    int n;
    double d;
    while (scanf("%s", &str)!=EOF){
        if(atof(str)){
            n = atof(str);
            solveint(n);
        }
        else{
            d = atof(str);
            solvedouble(d);
        }
    }

    return 0;
}
