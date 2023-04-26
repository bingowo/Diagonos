#include<stdio.h>
#include<string.h>
#define L 500

int main(){
    char x1[L+1];
    scanf("%s",x1);
    int l=strlen(x1);
    int x[l],bi[4*l];
    for(int i=0;i<4*l;i++)bi[i]=0;
    for(int i=2,j=0;i<l;i++,j++){
        if(x1[i]>='0'&&x1[i]<='9')x[j]=x1[i]-'0';
        else if(x1[i]>='A'&&x1[i]<='X')x[j]=x1[i]-'A'+10;
    }
    l-=2;//x长度
    for(int i=0,j=3;i<l;i++,j+=4){
        int k=j,m=x[i];
        while(m>0){
            bi[k--]=m%2;
            m/=2;
        }
    }
    l*=4;//bi长度
    long long m=0,n=0,a,b;
    for(int i=0;i<l;i++){
        a=bi[i]-m-n;b=m-n;
        m=a;n=b;
    }
    if(b==0)printf("%lld",a);
    else if(a==0&&b==1)printf("i");
    else if(a==0&&b==-1)printf("-i");
    else if(b==1)printf("%lld+i",a);
    else if(b==-1)printf("%lld-i",a);
    else if(b>1)printf("%lld+%lldi",a);
    else if(b<-1)printf("%lld%lldi",a,b);
}