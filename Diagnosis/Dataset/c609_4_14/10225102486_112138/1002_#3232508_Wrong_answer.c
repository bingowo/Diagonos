#include<stdio.h>

int max_len(long long a){
    int rem=a%2, sec;
    int cnt=1,tmp=1;
    while(a){
        a>>=1;
        sec=a%2;
        if(sec!=rem)
            tmp++;
        else{
            if(tmp>cnt)
                cnt=tmp;
            tmp=1;
        }
        rem=sec;
    }
    if(tmp>cnt)
        cnt=--tmp;
    return cnt;
}
int main(){
    int T;
    scanf("%d",&T);
    long long x;
    for(int i=0;i<T;i++){
        scanf("%d",&x);
        printf("case #%d:\n%d\n",i,max_len(x));
    }
    return 0;
}
