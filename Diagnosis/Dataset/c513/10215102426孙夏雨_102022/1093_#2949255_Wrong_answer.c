#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int len=strlen(s);
    int jinwei=1;
    for(int i=len-1;i>=0;i--){
        if(jinwei==1){
            if(s[i]=='8') s[i]='0';
            else {
                s[i]=s[i]+jinwei;
                jinwei=0;
            }
        }
    }
    if (jinwei==1) printf("1");
    printf("%s\n",s);
    return 0;
}
