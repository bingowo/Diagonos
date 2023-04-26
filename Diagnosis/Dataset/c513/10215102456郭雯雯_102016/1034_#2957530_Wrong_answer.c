#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double r[26];

double cmp(const void *a,const void *b){
    char g1=*(char*)a,g2=*(char*)b;
    double t1,t2,t;
    if(g1>='A'&&g1<='Z')t1=r[g1-'A'];
    if(g1>='a'&&g1<='z')t1=r[g1-'a'];
    if(g2>='A'&&g2<='Z')t2=r[g2-'A'];
    if(g2>='a'&&g2<='z')t2=r[g2-'a'];
    t=t2-t1;
    if(t!=0.0)return t;
    return g1-g2;
}
    
int main(){
    int t,a=0;char s[110];
    scanf("%d",&t);
    while(a<t){
        for(int i=0;i<26;i++)scanf("%lf",&r[i]);
        gets(s);gets(s);int l=strlen(s);
        qsort(s,l,sizeof(char),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<l;i++)printf("%c",s[i]);
        printf("\n");
        a++;
    }
}