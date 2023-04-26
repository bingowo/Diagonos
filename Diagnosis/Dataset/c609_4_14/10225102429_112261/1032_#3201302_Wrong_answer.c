#include <stdio.h>
#include <string.h>
int main()
{
    int max = 1,cnt = 1;
    char s[55] = {0};
    scanf("%s",s);
    for(int i = 0; i<strlen(s)-1; i++){
        if(s[i]==s[i+1]) {max = max>cnt?max:cnt;cnt = 1;}
        else{cnt++;}
    }
    printf("%d\n",max);
    return 0;
}