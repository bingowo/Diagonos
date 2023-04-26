#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b);
int main(){
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int N=0;
        scanf("%d\n",&N);
        char a[10001][20];
        for(int n=0;n<N;n++){
            scanf("%s\n",a[n]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        for(int n=0;n<N;n++){
            printf("%s\n",a[n]);
        }
    }
    return 0;
}
int cmp(const void*a,const void*b){
    char *s1,*s2,*p,*q;
    s1=(char*)a;
    s2=(char*)b;
    
    s1+=2,s2+=2;
    while(*s1<'0' && *s1>'9') s1++;
    while(*s2<'0' && *s2>'9') s2++;
    while(*s1 && *s2){
        if(*s1==*s2) {
            s1++;
            s2++;}
        else return *s1-*s2;
    }
    p=(char*)a;
    q=(char*)b;
    return *p-*q;
    
}