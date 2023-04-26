#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    long long int zi,mu;
}point;

long long int gcd(long long int a,long long int b){//最大公约数
    return b==0?a:gcd(b,a%b);
}

long long int god(long long int a,long long int b){//最小公倍数
    long long int c=gcd(a,b);
    a/=c;
    return a*b;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int a=0;a<t;a++){
        char s[17],s1[17],s2[17],s3[17];
        scanf("%s",s);
        printf("case #%d:\n",a);
        int l=strlen(s),p=0,le=0,ri=0,l1=0,l2=0,l3=0;
        long long int zh=0;
        point p1,p2;
        p1.zi=0;p2.zi=0;
        p1.mu=1;p2.mu=1;
        for(int i=0;i<l;i++){
            if(s[i]=='.')p=i;
            else if(s[i]=='[')le=i;
            else if(s[i]==']')ri=i;
        }
        if(p==0)printf("%s\n",s);
        else{
            l1=p;
            strncpy(s1,s,l1);
            s1[l1]=0;
            zh=atoll(s1);
            if(le==0){
                l2=l-p-1;
                strncpy(s2,s+p+1,l2);
                s2[l2]=0;
                p1.zi=atoll(s2);
                for(int i=0;i<l2;i++)p1.mu*=10;
            }
            else{
                l3=ri-le-1;
                strncpy(s3,s+le+1,l3);
                s3[l3]=0;
                p2.zi=atoll(s3);
                for(int i=0;i<l3;i++)p2.mu*=10;
                p2.mu--;
                if(le>p+1){
                    l2=le-p-1;
                    strncpy(s2,s+p+1,l2);
                    s2[l2]=0;
                    p1.zi=atoll(s2);
                    for(int i=0;i<l2;i++)p1.mu*=10;
                    p2.mu-=(p1.mu-1);
                }
            }
        }
        long long int g1=gcd(p1.mu,p1.zi),g2=gcd(p2.mu,p2.zi);
        p1.mu/=g1;p1.zi/=g1;p2.mu/=g2;p2.zi/=g2;
        if(p!=0){
            if(le==0){
                p1.zi+=zh*p1.mu;
                printf("%lld/%lld\n",p1.zi,p1.mu);
            }
            else{
                if(p1.zi==0){
                    p2.zi+=zh*p2.mu;
                    printf("%lld/%lld\n",p2.zi,p2.mu);
                }
                else{
                    long long int g3=god(p1.mu,p2.mu);
                    long long int x=g3/p1.mu,y=g3/p2.mu;
                    p1.zi*=x;p2.zi*=y;
                    p1.mu=g3;p1.zi+=p2.zi;
                    long long int g4=gcd(p1.mu,p1.zi);
                    p1.mu/=g4;p1.zi/=g4;
                    p1.zi+=zh*p1.mu;
                    printf("%lld/%lld\n",p1.zi,p1.mu);
                }
            }
        }
    }
}

