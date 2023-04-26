#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
    char letter[200];
} WORD;
int cmp(const void *a,const void *b){
    char ua=*(char*)a;
    char ub=*(char*)b;
    if(abc[toupper(ua) - 'A']>abc[toupper(ub) - 'A']){
         return ua<ub?-1:1;
    }
    else{
        return strcmp(ua,ub);
    }
    
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        double abc[26];
        char s[100];
        memset(abc,0,sizeof(abc));
        memset(s,0,sizeof(s));
        for(j = 0 ; j < 26; j ++){
            scanf("%lf", &abc[j]);
        }
        scanf("%s",s);
        int n=strlen(s)
        WORD a[n];
        for(j=0;j<n;j++){
            a[j].letter=s[j];
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for (j = 0; j < n; j++){
            printf("%c", a[j].letter);
        }
        printf("\n");
        
        
    }
}