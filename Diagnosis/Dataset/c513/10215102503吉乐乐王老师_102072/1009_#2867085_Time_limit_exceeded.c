#include<stdio.h>
#include<string.h>
int numone(char a){
    int ret=0;
    for(int i=0;i<8;i++){
        if(a&1)ret++;
        a=a>>1;
    }
    return ret;
}
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char ch;
        int sumof1=0,sum=0,len=0;
        while(ch=getchar()&&ch!='\n'){
            sumof1+=numone(ch);
            len++;
        }
        sum=len*8;
        int GCD=gcd(sumof1,sum);
        printf("%d/%d",sumof1/GCD,sum/GCD);
    }
}