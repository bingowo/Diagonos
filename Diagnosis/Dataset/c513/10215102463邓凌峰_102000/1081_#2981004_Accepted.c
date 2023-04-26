#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 150

void add(int *a,int *b){
    for(int i=LEN-1;i;i--){
        a[i]+=b[i];
        for(int k=i;a[k]>9;k--){
            a[k-1]+=a[k]/10;
            a[k]%=10;
        }
    }
}

void multi(int *a,int x){
    int tmp[LEN];
    memmove(tmp,a,sizeof(tmp));
    for(int i=1;i<x;i++){
        add(a,tmp);
    }
}

void outPut(int *ans){
    int idx=0;
    for(;ans[idx]==0;idx++);
    for(;idx<LEN;idx++){
        printf("%d",ans[idx]);
    }
    printf("\n");
}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,n;scanf("%d%d",&a,&n);
        int ans[LEN]={[LEN-1]=1};
        for(int i=0;i<n;i++){
            multi(ans,a);
        }
        printf("case #%d:\n",i);
        outPut(ans);

    }


    return 0;

}

