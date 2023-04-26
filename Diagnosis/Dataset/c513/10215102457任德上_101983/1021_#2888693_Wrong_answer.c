#include<stdio.h>
#include<string.h>
char rule[30];
int k[128];
int co(char *a,char *b){
    if(!*a)return 1;
    if(!*b)return -1;
    if(k[*a]==k[*b])return co(a+1,b+1);
    else return k[*a]-k[*b];
}
int cmp(const void *a,const void *b){
    char *p1,*p2;
    p1=*(char**)a;
    p2=*(char**)b;
    return co(p1,p2);
}
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
int main(){
    char *t[110],s[1000],*q,rule[30],c;
    int num;
    while((c=getchar())!=EOF){
        ungetc(c,stdin);
        scanf("%s",rule);
        c=getchar();
        q=rule;
        for(int m=0;*q;q++,m++){
            k[*q]=m;
            k[*q+32]=m;
        }
        gets(s);
        num=split(s,t);
        qsort(t,num,sizeof(*t),cmp);
        for(int n=0;n<num-1;n++)printf("%s ",*(t+n));
        printf("%s\n",*(t+num-1));

    }
    return 0;
}