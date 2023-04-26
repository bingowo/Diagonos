
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
    //int len = strlen(s);
    //for(int i = 0;i < len;i++){
    //    printf("%c ",s[i]);
    //}
    int sum = 1;
    int max = 1;
    for(int i = 0,k = 1;i < j -1 && k < j;i++,k++){
        if(s[i] != s[k]){
            char *p1 = &s[i];
            char *p2 = &s[k];
            sum = 2;
            p1++;
            p2++;
            while(*(p1) != *(p2) && *(++p2) && *p1){
                p1++;
                p2++;
                sum++;
            }
        }
        max = max > sum?max:sum;
    }
    printf("%d",max);

}