#include<stdio.h>
#include<string.h>
int numone(char b){
    int ret=0;
    int a=(int)b;
    for(int i=0;i<8;i++){
        if(a&1)ret++;
        a=a>>1;
    }
    return ret;
}
int gcd(int a,int b){
    if(a<b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        char ch;
        int sumof1=0,sum=0,len=0;
        char s[120];
        char *p;int idx=0;p=s;
        while(ch=getchar()){
            if(ch=='\n')break;
            *(p+idx)=ch;
            idx++;
        }
        *(p+idx)='\0';
        for(int i=0;i<strlen(s);i++){
            sumof1+=numone(s[i]);
        }
        sum=strlen(s)*8;
        int GCD=gcd(sumof1,sum);
        printf("%d/%d\n",sumof1/GCD,sum/GCD);
    }
}