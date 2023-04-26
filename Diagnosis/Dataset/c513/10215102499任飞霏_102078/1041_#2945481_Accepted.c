#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int max=1,res=1;
    char c=s[0];
    for(int i=1;i<strlen(s);i++){
        if(s[i]!=c){
            max++;
            c=s[i];
        }
        else
            max=1;
        if(res<max)res=max;
    }
    printf("%d",res);
    return 0;
}
