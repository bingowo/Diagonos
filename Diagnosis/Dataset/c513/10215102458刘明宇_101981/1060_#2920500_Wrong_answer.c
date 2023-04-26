#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);//输入字符串；
    char *p = s;
    int max = 0;
    while(*p){
        int sum = 0;
        if(*p >= '1' && *p <= '9'){
            sum++;
            char *p1 = p+1;
            while(*p1 >= '1' && *p1 <= '9'){
                p1++;
                sum++;
            }
            p++;
        }
        max = max > sum?max:sum;
        if((*p >= 'a' && *p <= 'z') || (*p >='A' && *p <= 'Z') || *p == '0'){
            p++;
        }
    }
    printf("%d",max);
}
