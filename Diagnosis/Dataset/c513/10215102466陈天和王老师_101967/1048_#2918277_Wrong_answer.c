#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)==2){
        printf("%s\n",s1);
        printf("%s\n",s2);
    }//scanf只要遇到空格就停止该字符串的输入

    return 0;
}
