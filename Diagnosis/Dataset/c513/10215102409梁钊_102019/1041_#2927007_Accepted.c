#include<stdio.h>
#include<string.h>

int main()
{
    char n[51] = {0} ;
    scanf("%s",&n) ;
    int longest = 0 ;
    char* p = n ;
    while(p-n<strlen(n)){
        int cout = 1 ;
        while(*p == *(++p)) ;
        while(*p != *(p-1) && p - n < strlen(n)){
            cout ++ ;
            p++ ;
        }
        if(cout>longest) longest = cout ;
    }
    if(strlen)
    printf("%d",longest) ;
}