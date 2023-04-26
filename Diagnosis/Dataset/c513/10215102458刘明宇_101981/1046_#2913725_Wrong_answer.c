#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        char s[100];
        gets(s);
        int sum = 0;
        char *p = s;
        while(*p){
            if(*p == ' ') sum++;
            p++;
        }
        printf("case #%d:\n", cnt);
        printf("%d\n",sum+1);
        cnt++;
    }
}
