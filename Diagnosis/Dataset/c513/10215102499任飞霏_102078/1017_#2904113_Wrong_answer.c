#include <stdio.h>
#include <stdlib.h>

int toint(char a)
{
    switch(a)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
    return 0;
}


int main()
{
    int ans = 0;
    char s[100];
    scanf("%s",s);
    for(int i = 0;i < strlen(s);i++){
        //char c = toint(s[i]);
        int a = toint(s[i]);
        if(i == strlen(s) - 1||toint(s[i])<=a){
            ans += a;
        }
        else{
            ans -= a;
        }
    }
    printf("%d",ans);
    return 0;
}
