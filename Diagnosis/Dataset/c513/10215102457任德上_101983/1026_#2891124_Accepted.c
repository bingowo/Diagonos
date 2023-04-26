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
    int e1,e2;
    e1=atoi(m1);
    e2=atoi(m2);
    if(e1>e2)return 1;
    else return -1;

}
int main(){
    int n;
    long long int sum=0;
    scanf("%d",&n);
    char *s,**t,c;
    c=getchar();
    s=(char *)malloc(15*n*sizeof(char));
    t=(char **)malloc(n*sizeof(char*));
    gets(s);
    split(s,t);
    qsort(t,n,sizeof(char *),cmp);
    for(int i=0;i<n/2;i++){
        int e1,e2;
        e1=atoi(*(t+2*i));
        e2=atoi(*(t+2*i+1));
        sum+=abs(e1-e2);
    }
    printf("%lld",sum);
    free(s);
    for(int i=0;i<n;i++)free(*(t+i));
    free(t);
    return 0;

}