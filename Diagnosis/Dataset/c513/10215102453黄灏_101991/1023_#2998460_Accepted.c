#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int number(char *s){
    int sum=0,flag=0;
    int len= strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9') {
            sum = sum*10 + s[i]-48;
            flag=1;
        }
    }
    if(flag == 0) sum=-1;
    return sum;
}

int strnumcmp(const void *a,const void *b){
    int number1,number2;
    char *str1,*str2;
    str1 = *(char(*)[31])a;str2 = *(char(*)[31])b;
    number1= number(str1);
    number2= number(str2);
    if(number1 == number2) return strcmp(str1,str2);
    else return number1-number2;
}

int main() {
    char str[101][31];
    int count=0;
    while (scanf("%s",str[count]) != EOF) count++;
    qsort(str,count,sizeof(str[0]),strnumcmp);
    for(int i=0;i<count;i++){
        printf("%s%c",str[i],i==count-1?'\n':' ');
    }
    return 0;
}
