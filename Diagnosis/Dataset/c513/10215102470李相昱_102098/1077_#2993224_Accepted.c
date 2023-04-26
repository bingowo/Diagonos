#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int num;
    int pos;
}vec;
int cmp(const void *p1,const void *p2){
    vec *a=(vec *)p1;
    vec *b=(vec *)p2;
    if(a->pos>b->pos){
        return 1;
    }
    if((a->pos==1001)&&(b->pos==1001)){
        return a->num-b->num;
    }
    return -1;
}
int main() {
    int m,n;
    int a[500]={0},sign[1001]={0};
    vec b[500];
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
        sign[a[i]]=i+1;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i].num);
        if(sign[b[i].num]!=0){
            b[i].pos=sign[b[i].num];
        }else{
            b[i].pos=1001;
        }
    }
    qsort(b,n,sizeof(vec),cmp);
    for(int p=0;p<n;p++){
        printf("%d%c",b[p].num,p==n-1?'\n':' ');
    }
    return 0;
}
