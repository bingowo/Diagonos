#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>

 int main(){
    char s[50];
    scanf("%s",s);
    int length = strlen(s);
    int depth = 0;
    int sum = 0;
    for(int i = 0; i <length;i++){
        if(s[i] == '('){
            depth++;
           }else if(s[i] == ')'&& s[i-1] =='('){
                sum+=pow(2,depth-1);
                depth--;
           }else if(s[i] == ')' && s[i-1] ==')'){
                depth--;
           }
    }

    printf("%d",sum);
 }
