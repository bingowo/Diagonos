#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int find(long long int b){
    char buffer[20];
    sprintf(buffer,"%lld",b);
    int len=strlen(buffer);
    for(int i=len;i>0;i--){
        if(buffer[len-i]=='9')return i-1;
    }
    return -1;
}
int len(long long int a){
    if(a==0LL)return 1;
    int len=0;
    while(a>0){
        len++;
        a/=10LL;
    }
    return len;
}
int main(){
    long long int a,b,num=0LL,i;
    int k;
    scanf("%lld%lld",&a,&b);
    i=a;
    while(i<=b){
        k=find(i);
        if(i%9LL!=0LL&&k==-1)num++;
        else if(k!=-1){
            long long int p=pow(10,k);
            i+=p;
            i=i/p*p;
        }
        if(k==-1)i++;
    }
    printf("%lld",num);
    return 0;
}