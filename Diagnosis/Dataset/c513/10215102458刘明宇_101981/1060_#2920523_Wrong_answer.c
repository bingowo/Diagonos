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
        if(*p >= '0' && *p <= '9'){
            char *p2 = p-1;
            if((*p2 >= 'a' && *p2 <= 'z') || (*p2 >='A' && *p2 <= 'Z')){
                p++;
                break;
            }
            sum++;
            char *p1 = p+1;
            while(*p1 >= '0' && *p1 <= '9'){
                p1++;
                sum++;
            }
            p++;
        }
        max = max > sum?max:sum;
        if((*p >= 'a' && *p <= 'z') || (*p >='A' && *p <= 'Z')){
            p++;
        }
    }
    printf("%d",max);
}
