#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000000

int cmp(const void* _a , const void* _b)
{
    char *a1,*a2,*b1,*b2 ;
    a1 = *((char**)_a) ; b1 = *((char**)_b) ;
    int i = 0 ;
    while (*(a1+i)!='@') i++ ;
    a2 = a1 + i + 1 ;
    i = 0 ; 
    while (*(b1+i)!='@') i++ ;
    b2 = b1 + i + 1 ;
    if(strcmp(a2,b2)==0) return strcmp(b1,a1) > 0 ? 1 : -1 ;
    return strcmp(a2,b2) > 0 ? 1 : -1 ;

}

int main()
{
    int n ;
    scanf("%d",&n) ;
    char **email ;
    email = (char**)malloc(n*sizeof(char*)) ;
    for(int i=0; i<n; i++){
        char tmp[N+1] = {0} ;
        scanf("%s",&tmp) ;
        int len = strlen(tmp) ;
        char* p = (char*)malloc(len+1) ;
        strcpy(p,tmp) ;
        *(email+i) = p ;
    }
    qsort(email,n,sizeof(email[0]),cmp) ;
    for(int i=0; i<n; i++){
        printf("%s\n",email[i]) ;
        char *p = email[i] ;
        free (p) ;
    }
    free(email) ;

}