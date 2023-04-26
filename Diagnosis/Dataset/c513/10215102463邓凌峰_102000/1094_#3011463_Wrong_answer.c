#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 150
#define BigNUm 10007

typedef struct{
    char snum[LEN];
    int num[LEN];
    int isFu;
}N;

void stod(int *num,char *snum){
    int cnt=0;
    int start=0;
    int len=strlen(snum);
    if(snum[cnt]=='-'){
            len--;
            cnt++;
    }
    start=LEN-len;
    for(;start<LEN;start++) num[start]=snum[cnt++]-'0';
}

int cmpNum(int *a,int *b){
    int idxa=0,idxb=0;
    for(;a[idxa]==0;idxa++);
    for(;b[idxb]==0;idxb++);
    if(idxa!=idxb) return idxa>idxb?-1:1;
    else{
        int i=idxa;
        for(;i<LEN;i++){
            if(a[i]>b[i]) return 1;
            if(a[i]<b[i]) return -1;
        }
    }
    return 0;
}

int numCmp(N a,N b){
    if(a.isFu==1 && b.isFu!=1) return -1;
    else if(a.isFu!=1 && b.isFu==1) return 1;
    else if(a.isFu==1 && b.isFu==1){
        if(cmpNum(a.num,b.num)==1) return -1;
        else return 1;
    }
    else{
        if(cmpNum(a.num,b.num)==1) return 1;
        else return -1;
    }

}

int cmp(const void *a,const void *b){
    N pa=*(N*)a,pb=*(N*)b;
    return numCmp(pa,pb);
}

N Get(N m,N Num){
    m.isFu=Num.isFu;
    for(int i=0;i<LEN;i++){
        m.num[i]=Num.num[i];
    }
    return m;
}

void sub(int *ans,int *a,int *b){
    for(int i=LEN-1;i;i--){
        if(a[i]>=b[i]) ans[i]=a[i]-b[i];
        else{
            a[i-1]-=1;
            ans[i]=a[i]+10-b[i];
        }
    }
}

void add(int *ans,int *a,int *b){
    for(int i=LEN-1;i;i--){
        ans[i]=a[i]+b[i];
        if(ans[i]>9){
            ans[i-1]+=ans[i]/10;
            ans[i]%=10;
        }
    }
}

void findLen(int *ans,N max,N min){
    if(max.isFu==0 && min.isFu==0) sub(ans,max.num,min.num);
    if(max.isFu==0 && min.isFu==1) add(ans,max.num,min.num);
    if(max.isFu==1 && min.isFu==1) sub(ans,min.num,max.num);
}

void outPut(int *ans){
    int idx=0;
    for(;ans[idx]==0;idx++);
    for(;idx<LEN;idx++)
        printf("%d",ans[idx]);
}

N nums[50]={0};

int main(){
    int T;scanf("%d",&T);

    for(int i=0;i<T;i++){
        scanf("%s",nums[i].snum);
        if(nums[i].snum[0]=='-') nums[i].isFu=1;
        stod(nums[i].num,nums[i].snum);
    }
    qsort(nums,T,sizeof(N),cmp);
    N maxNum=Get(maxNum,nums[T-1]),minNum=Get(minNum,nums[0]);

    int maxLen[LEN]={0};
    findLen(maxLen,maxNum,minNum);
    outPut(maxLen);

    return 0;
}
