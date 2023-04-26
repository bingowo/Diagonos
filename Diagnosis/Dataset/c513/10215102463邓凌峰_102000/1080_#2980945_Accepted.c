#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 150

int isZero(int *num,int len){
    for(int i=0;i<len;i++){
        if(num[i]!=0) return 0;
    }
    return 1;
}

int div_2(int *num,int len){
    int idx=0;
    for(;num[idx]==0;idx++);
    int tmp=0;
    for(int i=idx;i<len;i++){
        tmp=tmp*10+num[i];
        num[i]=tmp/2;
        tmp%=2;
    }
    return tmp;
}


void add(int *a,int *b){
    for(int i=LEN-1;i;i--){
        a[i]+=b[i];
        for(int j=i;a[j]>9;j--){
            a[j-1]+=a[j]/10;
            a[j]%=10;
        }
    }
}

void multi(int *ans,int x){
    int b[LEN];
    memmove(b,ans,sizeof(b));
    for(int i=1;i<x;i++){
        add(ans,b);
    }
}

void outPut(int *ans){
    int idx=0;
    for(;ans[idx]==0 && idx<LEN-1;idx++);
    for(;idx<LEN;idx++){
        printf("%d",ans[idx]);
    }
}



int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        char snum[LEN]={0};scanf("%s",snum);
        int len=strlen(snum);
        int num[len];
        for(int j=0;j<len;j++) num[j]=snum[j]-'0';
        int num_2[350],cnt=0;
        memset(num_2,-1,sizeof(num_2));
        for(int j=0;!isZero(num,len);j++){
            cnt++;
            num_2[j]=div_2(num,len);
        }

        int ans[LEN]={0},plus[LEN]={0};
        for(int j=0;j<cnt;j++){
            multi(ans,2);
            plus[LEN-1]=num_2[j];
            add(ans,plus);
        }
        printf("case #%d:\n",i);
        outPut(ans);
        printf("\n");
    }


    return 0;

}

