#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,l,x=0,t;
    char s[60];
    scanf("%s",s);
    l=1;
    t=s[0];
    for(i=1;i<strlen(s);i++){
        if(s[i]!=t) {
            l++;
            t=s[i];
        }
        else {
            if(l>x) x=l;
            l=1;
        }
    }
    printf("%d",x);
    return 0;
}
