#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 40

typedef struct string{
    int cout ;
    char s[N];
}string;

int cmp(const void* _a , const void* _b)
{
    string* a = (string*)_a ; string* b = (string*)_b ;
    if( (*a).cout == 0 && (*b).cout != 0 )
        return -1 ;
    else
        if( (*a).cout != 0 && (*a).cout == 0 )
        return 1 ;
    if( (*a).cout == (*b).cout )
        return strcmp((*a).s,(*b).s) > 0 ? 1 : -1 ;
    else
        return (*a).cout - (*b).cout > 0 ? 1 : -1 ;
}

int main()
{
    int n = 0 , i = 0 ;
    string str[100] ;
    while( scanf("%s",&str[n++].s)!=EOF && getchar()!='\n') ;
    for(int i = 0; i != n; i++){
        str[i].cout = 0 ;
    }
    for(int i = 0; i != n; i++){
        for(int j = 0; j != strlen(str[i].s); j++){
            if(str[i].s[j] >= '0' && str[i].s[j] <= '9'){
                str[i].cout ++ ;
            }
        }
    }
    qsort(str,n,sizeof(str[0]),cmp) ;
    for(int i = 0; i != n; i++)
        printf("%s ",str[i].s) ;
}