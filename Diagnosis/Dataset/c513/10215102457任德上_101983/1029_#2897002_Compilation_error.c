#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    char *s1,*s2;
    s1=(char *)a;
    s2=(char *)b;
    return (int)(*s1-*s2);

}
int main(){
    int T;
    scanf("%d",&T);
    char c;
    c=getchar();
    for(int i=0;i<T;i++){
        char s[201],t[201];
        int len=0;
        gets(s);
        while(*s){
            if(isalpha(*s)){*t=*s;t++;}
            s++;
        }
        len=strlen(t);
        qsort(t,len,sizeof(char),cmp);
        while(*s){
            if(isalpha(*s)){*s=*t;t++;}
            s++;
        printf("case #%d:\n%s",i,s);

    }
    return 0;



}