#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef long long int lli;
int prime[1000];
int isprime(int i){
    if(i==1)return 0;
    if(i==2)return 1;
    if(i%2==0)return 0;
    for(int j=3;j<i;j++){
        if(i%j==0)return 0;
    }
    return 1;
}
void create(int* prime){
    int idx=0;
    *(prime+idx++)=1;
    for(int i=1;i<1000;i++){
        if(isprime(i))*(prime+idx++)=i;
    }
}
int cal(int *ret,int num,int idx);
int main(){
    create(prime);
    int idx=0;
    int in[1000]={0};
    while(scanf("%d",&in[idx++])){
        char ch=getchar();
        if(ch==',')continue;
        if(ch=='\n')break;
    }
    int inlen=idx;
    int ret[1000]={0};
    int retlen;
    idx=1;
    for(int i=inlen-1;i>=0;i--){
        retlen=cal(ret,in[i],idx);
        idx++;
    }
    ret[retlen]=-1;int i=0;
    for(int i=retlen-1;i>=0;i--){
        printf("%d",ret[i]);
    }
}
int cal(int *ret,int num,int idx)
{
    int quan[1000]={0};
    int quanlen=0;
    long int t=1;
    for(int i=0;i<idx;i++){
        t*=prime[i];
    }
    while(t){
        quan[quanlen++]=t%10;
        t/=10;
    }
    int carry=0;int i,j;
    for(j=0;j<num;j++){
        for(i=0;i<quanlen;i++){
            ret[i]=(carry+ret[i]+quan[i])%10;
            carry=ret[i]/10;}
        while(carry){
            ret[i]=(ret[i]+carry)%10;
            carry=ret[i]/10;
            i++;
        }
    }
    return i;
}