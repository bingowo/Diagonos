
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IntLayout(int num)
{
    int c = sizeof(num);
    unsigned char *p = (unsigned char *) &num;
    while(c --){
        printf("%02x%c", *(p ++), c == 0 ? '\n': ' ');
    }
}

void DoubleLayout(double num)
{
    int c = sizeof(num);
    unsigned char *p = (unsigned char *) &num;
    while(c --){
        printf("%02x%c", *(p ++), c == 0 ? '\n': ' ');
    }
}

int main()
{
    char s[100];
    while(scanf("%s", s) != EOF){
        if(strchr(s, '.')){
            DoubleLayout(atof(s));
        }else{
            IntLayout(atoi(s));
        }
    }
		
    return 0;
} 