#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num=1;
    int res=0;
    char s[51];
    scanf("%s",s);
    for(int i=0;i<strlen(s)-1;i++){
        if((s[i]=='-'&&s[i+1]=='|')||(s[i]=='|'&&s[i+1]=='-')) {num++;}
        else num=0;
        res=res>num?res:num;
    }
    printf("%d",res+1);
    return 0;
}