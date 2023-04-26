#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double r[26];

int cmp(const void *a,const void *b){
    char g1=*(char*)a,g2=*(char*)b;
   
}
    
int main(){
    int t,a=0;char s[110];
    scanf("%d",&t);
    while(a<t){
        for(int i=0;i<26;i++)scanf("%lf",&r[i]);
        gets(s);int l=strlen(s);
        qsort(s,l,sizeof(char),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<l;i++)printf("%c",s[i]);
        printf("\n");
    }
}