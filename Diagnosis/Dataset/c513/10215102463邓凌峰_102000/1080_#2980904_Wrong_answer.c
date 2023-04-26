#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void add(int *ans,int x){
     ans[109]+=x;
     for(int i=109;ans[i]>9;i--){
        ans[i-1]+=ans[i]/10;
        ans[i]%=10;
    }
}

void addSelf(int *ans){
    for(int i=109;i;i--){
        ans[i]*=2;
        for(int j=i;ans[j]>9;j--){
            ans[j-1]+=ans[i]/10;
            ans[j]%=10;
        }
    }
}

void multi(int *ans,int x){
    for(int i=1;i<x;i++){
        addSelf(ans);
    }
}

void outPut(int *ans){
    int idx=0;
    for(;ans[idx]==0 && idx<109;idx++);
    for(;idx<110;idx++){
        printf("%d",ans[idx]);
    }
}



int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        char snum[110]={0};scanf("%s",snum);
        int len=strlen(snum);
        int num[len];
        for(int j=0;j<len;j++) num[j]=snum[j]-'0';
        int num_2[350],cnt=0;
        memset(num_2,-1,sizeof(num_2));
        for(int j=0;!isZero(num,len);j++){
            cnt++;
            num_2[j]=div_2(num,len);
        }

        int ans[110]={0};
        for(int j=0;j<cnt;j++){
            multi(ans,2);
            int tmp=num_2[j];
            add(ans,tmp);
        }
        printf("case #%d:\n",i);
        outPut(ans);
        printf("\n");
    }







    return 0;

}
