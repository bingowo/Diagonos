
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IntLayout(int num)
{
    int c = sizeof(num);
    //得到每个byte的地址，这样之后可以答应出对应字节的数据，而不是手动去运算数据 
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

int main(void)
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