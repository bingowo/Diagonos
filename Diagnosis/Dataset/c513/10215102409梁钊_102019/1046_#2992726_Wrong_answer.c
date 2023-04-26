#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char ineff[12][4] = {"the","a","an","of"
,"for","and","THE","A","AN","OF","FOR","AND",} ;

int iseff(char* a)
{
    for(int i=0; i<12; i++){
        if(strcmp(a,ineff[i])==0)
            return 0 ;
    }
    return 1 ;
}

int main()
{
    int t = 0 ;
    scanf("%d",&t) ;
    getchar() ;
    for(int i=0; i<t; i++){
        char word[20] = {0} ;
        int count = 0 , idx = 0;
        char tmp ;
        while(1){
            tmp = getchar() ;
            if(tmp == ' ' || tmp == '\n'){
                word[idx] = '\0' ;
                if(iseff(word))
                    count ++ ;
                idx = 0 ;
                if(tmp == '\n')
                    break ;
            }
            else
                word[idx++] = tmp ;
        }
        printf("case #%d:\n%d\n",i,count) ;
    }
}