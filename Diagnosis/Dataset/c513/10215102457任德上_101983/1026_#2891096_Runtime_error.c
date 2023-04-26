#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
void split(char *s,char **t){
    char *m1,*p,*m2;
    int i=0,len=0;
    m1=s,m2=s;
    while(*m1){
        if(*m1==' '){
            p=(char*)malloc(len+1);
            strncpy(p,m2,len);
            *(t+i)=p;
            *(p+len)=0;
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
}
int cmp(const void *a,const void *b){
    char *m1,*m2;
    m1=*(char **)a;
    m2=*(char **)b;
    if(*m1>*m2)return 1;
    else return -1;

}
int main(){
    int n;
    long long int sum=0;
    scanf("%d",&n);
    char *s,**t,c;
    c=getchar();
    s=(char *)malloc(2*n*sizeof(char));
    t=(char **)malloc(2*n*sizeof(char*));
    gets(s);
    split(s,t);
    qsort(t,n,sizeof(char *),cmp);
    for(int i=0;i<n/2;i++){
        sum+=abs(**(t+2*i)-**(t+2*i+1));
    }
    printf("%lld",sum);
    return 0;

}