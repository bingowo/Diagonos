#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int number(char *str);
int strnumcmp(const void *a,const void *b);

int main()
{
    int cnt = 0;
    char str[101][31];
    while(scanf("%s",str[cnt]) != EOF) cnt++;
    qsort(str,cnt,sizeof(str[0]),strnumcmp);
    for(int i = 0;i < cnt - 1;i++){
        printf("%s ",str[i]);
    }
    printf("%s\n",str[i]);
}

int number(char *str){
    int len,l,sum = 0,flag = 0;
    len = strlen(str);
    for(int i = 0;i < len;i++){
        if(str[i] >='0' && str[i] <= '9'){
            sum = 10*sum + str[i] - 48;
            flag = 1;
        }
    }
    if(flag == 0) sum = -1;
    return sum;
}

int strnumcmp(const void *a,const void *b){
    int s1,s2;
    char *str1,*str2;
    str1 = (char*)a;
    str2 = (char*)b;
    s1 = number(str1);
    s2 = number(str2);
    if(s1 == s2) return strcmp(str1, str2);
    else{
        if(s1 > s2) return 1;
        else return -1;
    }
}