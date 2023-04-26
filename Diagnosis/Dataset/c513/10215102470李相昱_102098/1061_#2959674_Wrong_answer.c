#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char s[16];
    int s2[16];
    int alb[127];
    int num;
}vec;
int cmp(const void *p1,const void *p2){
    vec * a= (vec *)p1;
    vec * b= (vec *)p2;
    if(a->num == b->num){
        return strcmp(a->s,b->s);
    }
    return a->num-b->num;
}
int main() {
    int N;
    scanf("%d",&N);
    vec a[N];
    for(int i=0;i<N;i++){
        scanf("%s",a[i].s);
        memset(a[i].alb,0,127*sizeof(int));
        int len = strlen(a[i].s);
        int m=2;
        if(len>=2){
            int sign=0;
            a[i].num=0;
            a[i].s2[0] =1;
            a[i].alb[a[i].s[0]] = 1;
            for(int j=1;j<len;j++){
                if(a[i].alb[a[i].s[j]]==0){
                    if(sign ==0){
                        a[i].alb[a[i].s[j]]=0;
                        sign=1;
                    }else{
                        a[i].alb[a[i].s[j]]=m;
                        m++;
                    }
                }
                a[i].s2[j] = a[i].alb[a[i].s[j]];
            }
            for(int p=0;p<len;p++){
                a[i].num = a[i].s2[p]+a[i].num*m;
            }
        }else{
            a[i].num =0;
        }
    }
    qsort(a,N,sizeof(vec),cmp);
    for(int t=0;t<N;t++){
        printf("%s\n",a[t].s);
    }
    return 0;
}
