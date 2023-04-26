#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int cmp(const void *a,const void *b){
    char c=*(char *)a,d=*(char *)b;
    int t=c-d;
    return t;
}

int main(){
    int t,a=0;
    while(a<t){
        char s[210];gets(s);
        char r[210];
        memset(r,0,sizeof(r));
        int m=0,l=strlen(s);
        for(int i=0;i<l;i++)
            if(isalpha(s[i]))r[m++]=s[i];
        qsort(r,m,sizeof(char),cmp);
        m=0;
        for(int i=0;i<l;i++)
            if(isalpha(s[i]))s[i]=r[m++];
        printf("case #%d:\n",a);
        //printf("%s\n",s);
        a++;
    }
}