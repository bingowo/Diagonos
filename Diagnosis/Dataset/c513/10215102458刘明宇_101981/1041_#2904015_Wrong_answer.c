#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[51];
    char ch;
    int j = 0;
    while((ch = getchar())!='\n'){
        s[j] = ch;
        j++;
    }
    int sum = 1;
    int max = 1;
    char *p1 = &s[j-1];
    for(int i = 0;i < j - 1;i++){
        if(s[i] != s[i+1]){
            char *p2 = &s[i];
            char *p3 = &s[i+1];
            sum++;
            while(*(p2++) != *(p3++) && *p3 != *p1 &&*p2 != *p1){
                sum++;
            }
        }
        max = max > sum?max:sum;
    }
    printf("%d",max);
}