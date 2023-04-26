#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int res=1,R=0;
    for(int i=0;i<strlen(s);i++){
        for(int m=i;m<strlen(s);m++){
            if(s[m]=='-'){
            if(s[m+1]=='|')res++;
            else break;
            }
            if(s[m]=='|'){
            if(s[m+1]=='-')res++;
            else break;
            }
        }
        if(res>R)R=res;
        res=1;
    }
    printf("%d",R);
    return 0;
}
