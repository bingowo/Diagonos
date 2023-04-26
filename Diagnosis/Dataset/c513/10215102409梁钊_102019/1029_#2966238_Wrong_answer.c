#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* _a , const void* _b)
{
    char* a = (char*)_a ;  char* b = (char*)_b ;
    return *a - *b > 0 ? 1 : -1 ;
}

int main()
{  
    int t ;
    scanf("%d",&t) ;
    for(int i=0;i!=t;i++){
        getchar() ;
        char s[201] = {0} ;
        gets(s) ;
        int len = strlen(s) ;
        char alpha[201] = {0} ;
        char nonalpha[201] = {0} ;
        for(int j=0; j!=len; j++)
            nonalpha[j] = 'a' ;
        int k = 0 , count = 0 ;
        for(int j=0; j!=len; j++){
            if(s[j]>='A'&&s[j]<='Z'){
                alpha[k++] = s[j] ;
                count ++ ;
            }
            else
                nonalpha[j] = s[j] ;
        }
        qsort(alpha,count,sizeof(alpha[0]),cmp) ;
        k = 0 ;
        for(int j=0; j!=len; j++){
            if(nonalpha[j]=='a')
                nonalpha[j] = alpha[k++] ;
        }
        printf("case #%d:\n",i) ;
        for(int j=0; j!=len; j++)
            printf("%c",nonalpha[j]) ;
        printf("\n") ;
    }
}