#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char str[16];
    long long int num;
}node;
long long int trs(char str[]){
    char alb[128];memset(alb,-1,128);
    char *p=str;
    alb[*p]=1;
    p++;int digit=0;
    while(*p){
        if(alb[*p]==-1){
            alb[*p]=digit;
            digit=digit?digit+1:2;
        }
        p++;
    }
    if(digit<2)digit=2;
    long long int ret=0;
    p=str;
    while(*p){
        ret=ret*digit+alb[*p];
        p++;
    }
    return ret;
}
int cmp(const void *a,const void *b){
    node x=*(node*)a;
    node y=*(node*)b;
    if(x.num==y.num)return strcmp(x.str,y.str);
    return x.num-y.num;
}
int main(){
    int n;scanf("%d",&n);getchar();
    node *s=(node*)malloc(sizeof(node)*n);
    for(int i=0;i<n;i++){
        gets(s[i].str);
        s[i].num=trs(s[i].str);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",s[i].str);
    }
}