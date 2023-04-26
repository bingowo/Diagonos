#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
    char letter;
    double number;
} WORD;
double cmp(const void *a,const void *b){
    WORD v1=*(WORD*)a;
    WORD v2=*(WORD*)b;
	double num1,num2;
	num1=v1.number;
	num2=v2.number;
	return num2-num1;
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
            //printf("%.2f\n",a[j].number);
           // printf("%c\n",a[j].letter);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for (j = 0; j < n; j++){
            printf("%c", a[j].letter);
        }
        printf("\n");
        
        
    }
}