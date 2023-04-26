#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[500];
    scanf("%s",s);
    int l=strlen(s);
    long long a,b=0;
    if(s[l-1]=='i'){
        if(s[l-2]=='+')b=1;
        else if(s[l-2]=='-')b=-1;
        else{
            int i=l-2;
            while(i>=0&&isdigit(s[i]))i--;i++;
            char bi[500];memset(bi,0,sizeof(bi));
            strncpy(bi,s+i,l-1-i);
            b=atoll(bi);
        }
    }
    printf("%lld",b);
}