#include <stdio.h>
#include <string.h>
int main() {
    char s[60];
    scanf("%s",s);
    int maxlen = strlen(s);
    int len =1,len1=1;
    for(int i=0;i<maxlen-1;i++){
        while (s[i]!=s[i+1]){
            len1 ++;
            i++;
        }
        if(len1 > len){
            len = len1;
        }
    }
    printf("%d",len);
    return 0;
}
