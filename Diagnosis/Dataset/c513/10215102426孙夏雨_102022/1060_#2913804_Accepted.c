#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int len=strlen(s),l=0,r=0,yes=0,max=0;
    for(;r<len;r++){
        if(isdigit(s[r])&&(s[r]-'0')>0){
            if(yes==0){
                yes=1;
                l=r;
            }
        }
        else if(isalpha(s[r])&&(yes==1)){
            yes=0;
            if(max<(r-l)) max=r-l;
        }
        if((r==len-1)&&(yes==1)){
            if(max<(r-l+1)) max=r-l+1;
        }
    }
    printf("%d",max);
    return 0;
}
