#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    long long int num;
    int one;
}node;
int cmp(const void *a,const void *b){
    node *x=(node*)a,*y=(node*)b;
    if(x->one==y->one)
        return x->num>y->num?1:-1;
    return x->one<y->one?1:-1;
}
int main(){
    int t;
    scanf("%d",&t);
    int cas=0;
    node data[10000];
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&data[i].num);
            data[i].one=0;
            long long int temp=data[i].num;
            for(int j=0;j<64;j++){
                if(temp&1)data[i].one++;
                    temp>>=1;
            }
        }
        qsort(data,n,sizeof(data[0]),cmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<n;i++){
            printf("%lld ",data[i].num);
        }
        putchar('\n');
    }
}
