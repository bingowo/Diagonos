#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    
    while (1){
        char s[10] = {0}, res[10]={0};
        gets(s);
        if (strcmp(s, "0")==0) break;
        memmove(s+2, s+1, strlen(s)-1);
        s[1]='.';
        double num = atof(s), temp = pow(num, num);
        gcvt(temp, 1, res);
        printf("%c\n", res[0]);
    }
    return 0;

}