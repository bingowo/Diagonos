#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[51];
    gets(s);
    int len=strlen(s);
    int max=1,x=1;
    for(int i=1;i<len;i++){
        if(s[i]!=s[i-1]){
            x++;
        }
        else{
            if(x>max){
                max=x;
                //x=1;
            }
            x=1;
        }
    }
    printf("%d",max);
}
