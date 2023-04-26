#include <stdio.h>

unsigned int TriToDec(char s[])
{
    unsigned int ret = 0;
    char *p = s;
    while(*p){
        if(*p == '1'){
            ret = ret * 3 + 1;
        }else if(*p == '0'){
            ret = ret * 3 + 0;
        }else if(*p == '-'){
            ret = ret * 3 - 1;
        }
		
        p ++;
    }
	
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        char s[30];
        unsigned int n;
        scanf("%s", s);
        n = TriToDec(s);
        printf("case #%d:\n", i);
        printf("%u\n", n);
    }