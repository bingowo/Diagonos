#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b){
    char *s1,*s2;
    s1=*(char (*)[40])a;
    s2=*(char (*)[40])b;
    int x1=0,x2=0;
    int sign1=0,sign2=0;
    for(int i=0;*(s1+i);i++){
        if(*(s1+i)>='0'&&*(s1+i)<='9'){
            sign1=1;
            x1=10*x1+*(s1+i)-'0';
        }
    }
    for(int i=0;*(s2+i);i++){
        if(*(s2+i)>='0'&&*(s2+i)<='9'){
            sign2=1;
            x2=10*x2+*(s2+i)-'0';
        }
    }
    if(sign1!=sign2) return sign1-sign2;
    else if(sign1*sign2==0) return strcmp(s1,s2);
    else return x1-x2;
}

int main(){
    char s[101][40];
    int i=0;
    while(scanf("%s",s[i++])!=EOF);
    i--;
    qsort(s,i,sizeof(s[0]),cmp);
    for(int t=0;t<i;t++)
        printf("%s ",s[t]);
    printf("%s\n",s[i]);
    return 0;
}