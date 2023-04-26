#include<stdio.h>
#include<string.h>
int gcd(int a,int b){
    int r;
    if(a>b){
        if((a%b)==0) r=b;
        else {
            while((a%r)&&(b%r)) r-=1;
        }
    }
    else if(a=b) r=b;
    else{
        if((b%a)==0) r=a;
        else {
            while((a%r)&&(b%r)) r-=1;
        }
    }
    return r;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[120];
        scanf("%s",s);
        int len=strlen(s),num=0;
        for(int j=0;j<len;j++){
            int m=s[j]-'0';
            int count[len],sum=0;
            while(m){
                if((m&1)==1) count[j]++;
                m>>=1;
                sum++;
            }
        num+=count[j];
        }
        int GCD;
        GCD=gcd(num,len*8);
        printf("%d/%d\n",num/GCD,(len*8)/GCD);
    }
}