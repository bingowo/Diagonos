#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct num{
    char s[16];
    long long int k;

};
long long int find_num(char *s){
    char *m;
    int c[127],R=0;
    for(int i=0;i<127;i++)c[i]=-1;
    c[*s]=1;
    m=s+1;
    while(*m){
        if(c[*m]==-1){
            c[*m]=R;
            if(R==0)R=2;
            else R++;
        }
        m++;
    }
    long long int n=0;
    m=s;
    while(*m){
        n=n*R+c[*m];
        m++;
    }
    return n;
}
int cmp(const void *a,const void *b){
    struct num *m1,*m2;
    m1=(struct num*)a;
    m2=(struct num*)b;
    if(m1->k==m2->k)return strcmp(m1->s,m2->s);
    if((m1->k-m2->k)>0ll)return 1;
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    struct num *m;
    m=(struct num*)malloc(n*sizeof(struct num));
    for(int i=0;i<n;i++){
        scanf("%s",(m+i)->s);
        (m+i)->k=find_num((m+i)->s);
    }
    qsort(m,n,sizeof(struct num),cmp);
    for(int i=0;i<n;i++)printf("%s\n",(m+i)->s);
    free(m);
    return 0;



}
