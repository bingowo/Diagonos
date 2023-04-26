#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float alpha_freq[26] ;

float get_freq(char a)
{
    char tmp[1] = {a} ; 
    if(tmp[0] >= 'A' && tmp[0] <= 'Z')
        tmp[0] = tmp[0] - 'A' + 'a' ;
    return alpha_freq[tmp[0] - 'a'] ;
}

int cmp(const void *_a , const void *_b)
{
    char *a = (char*)_a , *b = (char*)_b ;
    float a_freq = get_freq(*a) , b_freq = get_freq(*b) ;
    if(a_freq == b_freq){
        if(abs((int)*a - (int)*b) == 32)
            return *b > *a ;
        return *a > *b ;  
    }
    return b_freq - a_freq > 0 ? 1 : -1 ;
}

int main()
{
    int t ;
    int time = 0 ;
    char s[101] = {0} ;
    scanf("%d",&t) ;
    while(t--){
        for(int i=0; i<26; i++)
            scanf("%f",&alpha_freq[i]) ;
        scanf("%s",&s) ;
        qsort(s,strlen(s),sizeof(s[0]),cmp) ;
        printf("case #%d:\n",time++) ;
        for(int i=0; i<strlen(s); i++)
            printf("%c",s[i]) ;
        printf("\n") ;
    }
}