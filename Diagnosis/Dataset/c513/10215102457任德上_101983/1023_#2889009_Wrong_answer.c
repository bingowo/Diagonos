#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
int split(char *s,char **t);
int findnum(char *s);
int cmp(const void *a,const void *b);
int split(char *s,char **t){
    char *m1,*p,*m2;
    int i=0,len=0;
    m1=s,m2=s;
    while(*m1){
        if(*m1==' '){
            p=(char*)malloc(len+1);
            strncpy(p,m2,len);
            *(t+i)=p;
            m2=m1+1;
            len=0;
            i++;
        }
        else len++;
        m1++;
    }
    p=(char*)malloc(len+1);
    strncpy(p,m2,len);
    *(t+i)=p;
    return i+1;    //返回所有的单词个数
}
int findnum(char *s){
    char *m,t[10];
    m=s;
    int len,i=0,n=0,num=0;
    len=strlen(s);
    for(;i<len;i++){
        if(isdigit(*(m+i))){num=1;break;}
    }
    if(num==0)return 0;
    m=m+i;
    while(isdigit(*m))n++,m++;
    strncpy(t,m-n,n);
    *(t+n)=0;
    num=atoi(t);
    return num;
}
int cmp(const void *a,const void *b){
    int p1,p2;
    char *s1,*s2;
    s1=*(char**)a,s2=*(char**)b;
    p1=findnum(s1);
    p2=findnum(s2);
    if(p1==p2)return strcmp(s1,s2);
    else return (p1-p2);
}
int main(){
    char s[3000],*t[102];
    int len;
    gets(s);
    len=split(s,t);
    qsort(t,len,sizeof(*t),cmp);
    for(int i=0;i<len-1;i++)printf("%s ",*(t+i));
    printf("%s",*(t+len-1));
    for(int i=0;i<len;i++)free(*(t+i));
    return 0;


}