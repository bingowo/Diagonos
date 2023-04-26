#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int t = 0 ;
    scanf("%d",&t) ;
    for(int i=0; i<t; i++){
        char s[1000] = {0} ;
        char res[1000] = {0} ;
        char *p = res ;
        scanf("%s",&s) ;
        for(int j=0; j<strlen(s); j++){
            int count = 1 ;
            while(s[j] == s[j+1]){
                count++ ;
                j++ ;
            }
            while(count > 255){
                p += sprintf(p, "%d%c", 255, s[j]) ;
                count -= 255 ;
            }
            p += sprintf(p, "%d%c", count, s[j]) ;
        }
        printf("case #%d:\n%s\n",i,res) ;
    }
}