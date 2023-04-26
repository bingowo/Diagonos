#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef long long int lli;
int isprime(int i){
    if(i==1)return 0;
    if(i==2)return 1;
    if(i%2==0)return 0;
    for(int j=3;j<i;j++){
        if(i%j==0)return 0;
    }
    return 1;
}
int main(){
    int prime[100];int idx=0;
    for(int i=0;i<100;i++){
        if(isprime(i))prime[idx++]=i;
    }
    int t;int cas=0;
    scanf("%d",&t);
    getchar();
    while(t--){
        lli a[100],b[100];
        int lena=0,lenb=0;
        while(scanf("%lld",&a[lena++])){
            char ch=getchar();
            if(ch==',')continue;
            if(ch==' ')break;}
        while(scanf("%lld",&b[lenb++])){
            char ch=getchar();
            if(ch==',')continue;
            if(ch=='\n')break;}
        lli ret[100];
        idx=0;int carry=0;
        while(lena>0&&lenb>0){
            ret[idx]=(a[lena-1]+b[lenb-1]+carry)%prime[idx];
            carry=(a[lena-1]+b[lenb-1]+carry)/prime[idx];
            idx++;lena--;lenb--;
        }
        if(lena){
            ret[idx]=(a[lena-1]+carry)%prime[idx];
            carry=(a[lena-1]+carry)/prime[idx];
            lena--;idx++;
        }
        if(lenb){
            ret[idx]=(b[lenb-1]+carry)%prime[idx];
            carry=(b[lenb-1]+carry)/prime[idx];
            lenb--;idx++;
        }
        if(carry)ret[idx]=carry;
        printf("case #%d:\n",cas++);
        for(int j=idx;j>=0;j--){
            printf("%lld",ret[j]);
            if(j==0)putchar('\n');
            else putchar(',');
        }
    }
}