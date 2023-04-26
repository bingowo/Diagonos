#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    scanf("%s",s);
    int max = 1;
    int l = 0,r = 0;
    int len = strlen(s);
    for(;r < len - 1;r++){
        if(s[r] == s[r+1]) {
            if(r-l+1 > max) max = r-l+1;
            r++;
            l = r;
        }
        else{
            if(r-l+2 > max) max = r-l+2;
        };
    }
    printf("%d",max);
    return 0;
}