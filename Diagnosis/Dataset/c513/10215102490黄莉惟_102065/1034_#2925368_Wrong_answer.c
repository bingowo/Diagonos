#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
    char letter;
    double number;
} WORD;
int cmp(const void *a,const void *b){
    WORD * pa = (WORD *)a;
	WORD * pb = (WORD *)b;
	if(pa->number != pb->number){
		return pb->number - pa->number;
	}else{
	    if(toupper(pa)!=toupper(pb)){
	        return strcmp(pa,pb);
	    }else{
	        return pa->letter - pb->letter;
	    }
		
	}
    
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        printf("case #%d:\n", i);
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
            a[j].number=abc[toupper(s[j]) - 'A'];
            printf("%.2f\n",a[j].number);
        }
        qsort(a,n,sizeof(a[0]),cmp);
    /*    for (j = 0; j < n; j++){
            printf("%c", a[j].letter);
        }
        printf("\n");*/
        
        
    }
}