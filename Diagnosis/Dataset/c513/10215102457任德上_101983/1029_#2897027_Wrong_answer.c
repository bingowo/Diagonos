#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
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
        char s[2000],t[2000],*m,*n;
        m=t;
        int len=0;
        gets(s);
        n=s;
        while(*n){
            if(isalpha(*n)){*m=*n;m++;}
            n++;
        }
        len=strlen(t);
        qsort(t,len,sizeof(char),cmp);
        n=s;
        m=t;
         while(*n){
            if(isalpha(*n)){*n=*m;m++;}
            n++;
        }
        printf("case #%d:\n%s\n",i,s);

    }
    return 0;



}
