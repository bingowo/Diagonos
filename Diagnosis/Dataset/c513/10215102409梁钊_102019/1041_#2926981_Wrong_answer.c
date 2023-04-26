#include<stdio.h>
#include<string.h>

int main()
{
    char n[51] = {0} ;
    scanf("%s",&n) ;
    int longest = 0 ;
    for(int i=0;i!=strlen(n);i++){
        int cout = 0 ;
        char* p = &n[i] ;
        while(*p == *(p+1)) p++;
        while(*p != *(p+1)){
            if(cout==0) cout++ ;
            cout ++ ;
            p++ ;
        }
        if(cout>longest) longest = cout ;
    }
    printf("%d",longest) ;
}