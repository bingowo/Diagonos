#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solve_int(int n){ 
    int c = sizeof(n);
    unsigned char* p = (unsigned char*)&n;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}

void solve_double(double d){
    int c = sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}

int main()
{ 
    char s[31];
    while (scanf("%s", s) != EOF)
    if (strchr(s, '.') == 0)
        solve_int(atoi(s));
    else 
        solve_double(atof(s));
    return 0;
}