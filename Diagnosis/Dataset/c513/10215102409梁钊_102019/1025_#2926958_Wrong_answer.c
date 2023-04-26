#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct string
{
    int cout ;
    char s[21] ;
} string ;

int cmp(const void* _a , const void* _b)
{
    string* a =(string*)_a ; string* b =(string*)_b ;
    if((*a).cout==(*b).cout) return strcmp((*a).s,(*b).s) > 0 ? 1 : -1 ;
    else return (*a).cout - (*b).cout > 0 ? 1 : -1 ;
}

int main()
{
    int t ;
    scanf("%d",&t) ;
    for(int i = 0 ; i != t ; i++){
        int n ;
        scanf("%d",&n) ;
        string string[n] ;
        for(int j = 0 ; j != n ; j++){
            scanf("%s",&string[j].s) ;
            string[j].cout = 0 ;
        }
        for(int j = 0 ; j != n ; j++){
            char table[91] = {0} ;
            int len = strlen(string[j].s) ;
            for(int k = 0 ; k != len ; k++){
                if(table[string[j].s[k]] == '1') ;
                else{
                    table[string[j].s[k]] = '1' ;
                    string[j].cout++ ;
                }
            }
        }
        qsort(string,n,sizeof(string[0]),cmp) ;
        printf("case #%d:\n",i) ;
        for(int j = 0 ; j != n ; j++)
            printf("%s\n",string[j].s) ;
    }
}