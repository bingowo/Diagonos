#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[100];
    gets(s);
    int sum=0;
    int max=0;
    for(int i=0;i<strlen(s);i++){
        if(isdigit(s[i])&&s[i]!='0')sum=sum+1;
        else sum=0;
        if(sum>max)max=sum;
    }
    printf("%d",max);
    return 0;
}
