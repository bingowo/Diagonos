#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
struct data{
    int *m;
    int num;

};
int find(char *s){
    char *m;
    int i=0;
    m=s;
    while(*m){
        if(*m==' ')i+=1;
        m++;
    }
    return i;

}
int cmp(const void *a,const void *b){
    struct data *m1,*m2;
    m1=(struct data*)a;
    m2=(struct data*)b;
    int i;
    if(m1->num>m2->num)i=m2->num;
    else i=m1->num;
    for(int n=0;n<i;n++){
        if(*(m1->m+n)==*(m2->m+n))continue;
        else if(*(m1->m+n)>*(m2->m+n))return -1;
        else return 1;
    }
    return -1;
}
void split(int num,char *s,struct data *t,int fre){
    int i=0,len=0;
    (t+fre)->m=(int *)malloc(num*sizeof(int));
    char *m1,*p,*m2;
    m1=s,m2=s;
    while(*m1){
        if(*m1==' '){
            p=(char*)malloc(len+1);
            strncpy(p,m2,len);
            *((t+fre)->m+i)=atoi(p);
            free(p);
            m2=m1+1;
            len=0;
            i++;
        }
        else len++;
        m1++;
    }
}


int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N,num;
        scanf("%d",&N);
        char s[10000],c;
        c=getchar();
        struct data *t;
        t=(struct data *)malloc(N*sizeof(struct data));
        for(int m=0;m<N;m++){
            gets(s);
            num=find(s);
            (t+m)->num=num;
            split(num,s,t,m);
        }
        qsort(t,N,sizeof(struct data),cmp);
        for(int m=0;m<N;m++){
            for(int n=0;n<(t+m)->num;n++)printf("%d ",*((t+m)->m+n));
            printf("\n");
        }
        free(t);
    }
}