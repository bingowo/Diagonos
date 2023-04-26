#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
    char letter[200];
} WORD;
double count(char s,double *abc){
    double n=abc[toupper(s) - 'A'];
    return n;
}
int cmp(const void *a,const void *b){
    char ua=*(char*)a;
    char ub=*(char*)b;
    double a1=count(ua,abc);
    double b1=count(ub,abc);
    if(a1==b1){
         return ua<ub?-1:1;
    }
    else{
        return b1-a1;
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
        int n=strlen(s);
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