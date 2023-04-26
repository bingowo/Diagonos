#include <stdio.h>
#include <stdlib.h>
typedef struct{
   int cnt;
   long long num;
}bin;
int cmp(const void*a,const void*b){
   bin x=*(bin*)a;
   bin y=*(bin*)b;
   if(x.cnt!=y.cnt)return y.cnt-x.cnt;
   else{
    if(x.num>y.num)return 1;
    else return -1;
   }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        bin a[10000];
        for(int j=0;j<n;j++){
            scanf("%lld",%a[j].num);
            a[j].cnt=0;
            for(int k=0;k<64;k++){
                if(((a[j].num>>k)&1)==1)a[j].cnt++;
            }
        }
        sqort(a,n,sizeof(bin),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++){
            printf("lld",a[j].num);
        }
        printf("\n");
    }
    return 0;
}
