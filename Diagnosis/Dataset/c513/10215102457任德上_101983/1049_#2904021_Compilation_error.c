#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int split(char *s,char **t){
    char *m1,*p,*m2;
    int i=0,len=0;
    m1=s,m2=s;
    while(*m1){
        if(!isalpha(*m1)){
            p=(char*)malloc(len+1);
            strncpy(p,m2,len);
            *(p+len)=0;
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
    *(p+len)=0;
    *(t+i)=p;
    return i+1;
}
int cmp(const void *a,const void *b){
    char *m1,*m2;
    m1=*(char **)a;
    m2=*(char **)b;
    return strcmp(m1,m2);
}
int main(){
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        char s[501],*t1[500],*t2[500];
        gets(s);
        int num=split(s,t1);
        int dif=0;
        for(int m=0;m<num;m++){
            int same=0;
            for(int n=m+1;n<num;n++){
                if(strcmp(t1[m],t1[n])==0){
                    same=1;
                    break;
                }
            }
            if(same==0)t2[dif++]=t1[m];
        }
        qsort(t2,dif,sizeof(char *),cmp);
        printf("case #%d:\n%s",i,q);
        for(int m=1;m<dif-1;m++)printf("%s ",*(t2+m));
        printf("%s\n",*(t2+dif-1));




    }
    return 0;





}