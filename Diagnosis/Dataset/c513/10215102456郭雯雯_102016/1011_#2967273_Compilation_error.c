#include<stdio.h>
#include<string.h>
#define L 500

int main(){
    char x1[L+1];
    scanf("%s",x1);
    int l=strlen(x1);
    int x[l],b[4*l];
    for(int i=0;i<4*l;i++)b[i]=0;
    for(int i=2,j=0;i<l;i++,j++){
        if(x1[i]>='0'&&x1[i]<='9')x[j]=x1[i]-'0';
        else if(x1[i]>='A'&&x1[i]<='X')x[j]=x1[i]-'A'+10;
    }
    l-=2;//x长度
    for(int i=0,j=3;i<l;i++,j+=4){
        int k=j,m=x[i];
        while(m>0){
            b[k--]=m%2;
            m/=2;
        }
    }
    l*=4;//b长度
    long long m=0,n=0,a,b;
    for(int i=0;i<l;i++){
        a=b[i]-m-n;b=m-n;
        m=a;n=b;
    }
    if(b==0)printf("%lld",a);
    else if(a==0)printf("%lldi",b);
    else printf("%lld+%lldi",a,b);
}