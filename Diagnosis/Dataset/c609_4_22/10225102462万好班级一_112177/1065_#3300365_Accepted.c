#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

double cal()
{
    char s[30];
    scanf("%s",s);
    if(s[0]=='+')
        return cal()+cal();
    else if(s[0]=='-')
        return cal()-cal();
    else if(s[0]=='*')
        return cal()*cal();
    else if(s[0]=='/')
        return cal()/cal();
    else
        return atof(s);
}

int main(){
    int loop;
    scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {
        printf("case #%d:\n%f\n",i,cal());
    }
    return 0;
}