#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 101

int judgeAndFind(int* num){
    int idx=0;
    for(;num[idx]==0;idx++);
    int tmp=num[idx];
    for(int i=idx+1;i<LEN;i++){
        if(num[i]==tmp) return i;
        tmp=num[i];
    }
    return -1;
}

void addOne(int *num,int begin){
    num[begin]+=1;
    for(int i=begin+1;i<LEN;i++) num[i]=0;
    for(int i=begin;num[i]>9;i--){
        num[i-1]+=1;
        num[i]%=10;
    }
}



int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int num[LEN]={0};
        char snum[LEN+1];scanf("%s",snum);
        for(int i=LEN-strlen(snum),cnt=0;i<LEN;i++){
            num[i]=snum[cnt++]-'0';
        }
        int begin=LEN-1;
        do{
            addOne(num,begin);
            begin=judgeAndFind(num);
        }while(judgeAndFind(num)!=-1);

        printf("case #%d:\n",i);
        int idx=0;
        for(;num[idx]==0;idx++);
        for(;idx<LEN;idx++){
            printf("%d",num[idx]);
        }
        printf("\n");
    }


    return 0;
}
