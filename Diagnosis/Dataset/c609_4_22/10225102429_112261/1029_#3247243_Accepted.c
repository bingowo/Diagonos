#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int ord,val;
}num;
#define N 555;
int cmp(const void*a, const void* b){
    int Va = (*(num*)a).val,Vb = (*(num*)b).val,Oa = (*(num*)a).ord,Ob = (*(num*)b).ord;
    if(Oa!=Ob){
        return Oa-Ob;
    }
    return Va-Vb;
}
int main(){
    int n,m;
    scanf("%d",&n);
    int a[1001];
    for(int i  =0; i<1001; i++){
        a[i] = N;
    }
    for(int i = 0; i<n; i++){
        int k;
        scanf("%d",&k);
        a[k] = i;
    }
    scanf("%d",&m);
    num b[m];
    for(int i = 0; i<m; i++){
        scanf("%d",&b[i].val);
        b[i].ord = a[b[i].val];
    }
    qsort(b,m,sizeof(num),cmp);
    for(int i = 0; i<m; i++){
        printf("%d ",b[i].val);
    }
    return 0;
}