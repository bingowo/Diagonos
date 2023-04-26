#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 150

typedef struct{
    char snum[LEN];
    int num[LEN];
    int isFu;
}N;

N stod(N Num){
    int cnt=0;
    int i=0;
    for(;i<LEN-strlen(Num.snum);i++) Num.num[i]=0;
    if(Num.snum[i]=='-'){Num.isFu=1;i++;}
    for(;i<LEN;i++) Num.num[i]=Num.snum[cnt++]-'0';
    return Num;
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
    return strcmp(pa.num,pb.num);
}



int main()
{
    int T;scanf("%d",&T);
    N nums[T];
    for(int i=0;i<T;i++){
        scanf("%s",nums[i].snum);
        nums[i]=stod(nums[i]);
    }

    printf("done");
    return 0;

}

