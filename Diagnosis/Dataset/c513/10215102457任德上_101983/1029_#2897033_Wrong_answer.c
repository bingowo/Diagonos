#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b){
    char *s1,*s2;
    s1=(char *)a;
    s2=(char *)b;
    return (*s1-*s2);

}
int main(){
    int T;
    scanf("%d",&T);
    char c;
    c=getchar();
    for(int i=0;i<T;i++){
        char s[2000],t[2000],*m1,*n1,*m2,*n2;
        m1=t;
        int len=0;
        gets(s);
        n1=s;
        while(*n1){
            if(isalpha(*n1)){*m1=*n1;m1++;}
            n1++;
        }
        len=strlen(t);
        qsort(t,len,sizeof(char),cmp);
        n2=s;
        m2=t;
         while(*n2){
            if(isalpha(*n2)){*n2=*m2;m2++;}
            n2++;
        }
        printf("case #%d:\n%s\n",i,s);

    }
    return 0;



}
