#include <stdio.h>
#include <string.h>
int main() {
    char s[60];
    scanf("%s",s);
    int maxlen = strlen(s);
    int len=1,len1;
    for(int i=0;i<maxlen-1;i++){
        len1=1;
        while ((s[i]!=s[i+1])&&(i<maxlen-1)){
            len1 ++;
            i++;
        }
        
    }
    printf("%d",len);
    return 0;
}