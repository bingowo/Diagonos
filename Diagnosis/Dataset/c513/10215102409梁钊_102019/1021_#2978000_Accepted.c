#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rank_21[26] ;

int cmp(const void* _a , const void *_b)
{
    char *a , *b , ch1 , ch2 ;
    a = *(char(*)[21])_a ; b = *(char(*)[21])_b ;
    while(*a && *b){
        ch1 = (*a) >= 'a' ? *a - 32 : *a ;
        ch2 = (*b) >= 'a' ? *b - 32 : *b ;
        if(rank_21[ch1-'A'] != rank_21[ch2-'A'])
            return rank_21[ch1-'A'] - rank_21[ch2-'A'] ;
        else{
            a++ ; 
            b++ ;
        }
    }
    return *a == 0 ? -1 : 1 ; 
}

int main()
{
    char alpha[27] ;
    while(scanf("%s",alpha)!=EOF){
        getchar() ;
        for(int i=0; i<26; i++)
            rank_21[alpha[i]-'A'] = i ;
        char s[100][21] = {0} ;
        int count = 0 ,idx = 0 ;
        char tmp ;
        do{
            tmp = getchar() ;
            if(tmp != ' ' && tmp != '\n'){
                s[count][idx++] = tmp ;
            }
            else{
                count ++ ;
                idx = 0 ;
            }
        }while(tmp != '\n') ;
        qsort(s,count,sizeof(s[0]),cmp) ;
        for(int i=0; i<count; i++){
            printf("%s ",s[i]);
        }
        printf("\n") ;
    }

}