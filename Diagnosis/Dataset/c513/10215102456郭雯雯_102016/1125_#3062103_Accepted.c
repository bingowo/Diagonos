#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}

long long int god(long long int a,long long int b){//最小公倍数
    long long int c=gcd(a,b);
    a/=c;
    return a*b;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        printf("case #%d:\n",a);
        a++;
        char s[17],zh[17],xi1[17],xi2[17];
        memset(s,0,sizeof(s));memset(zh,0,sizeof(zh));
        memset(xi1,0,sizeof(xi1));memset(xi2,0,sizeof(xi2));
        scanf("%s",s);
        int l=strlen(s),p=0,le=0,ri=0;
        for(int i=0;i<l;i++){
            if(s[i]=='.')p=i;
            if(s[i]=='[')le=i;
            if(s[i]==']')ri=i;
        }
        long long it,sm1,sm2,z1,m1,z2,m2;
        if(p==0)strncpy(zh,s,l);
        else strncpy(zh,s,p);
        it=atoll(zh);
        if(le==0&&ri==0)strncpy(xi1,s+p+1,l-p-1);//0.5
        else if(le==p+1)strncpy(xi2,s+le+1,ri-le-1);//0.[8]
        else{//11.0[8]
            strncpy(xi1,s+p+1,le-p-1);
            strncpy(xi2,s+le+1,ri-le-1);
        }
        if(p==0)printf("%lld\n",it);
        else if(le==0&&ri==0){
            z1=atoll(xi1);m1=1;
            for(int i=0;i<l-p-1;i++)m1*=10;
            long long g=gcd(m1,z1);
            z1/=g;m1/=g;
            if(m1==1)printf("%lld\n",it+z1);
            else{
                z1+=it*m1;
                printf("%lld/%lld\n",z1,m1);
            }
        }
        else if(le==p+1){
            z2=atoll(xi2);m2=1;
            for(int i=0;i<ri-le-1;i++)m2*=10;
            m2--;
            long long g=gcd(m2,z2);
            z2/=g;m2/=g;
            if(m2==1)printf("%lld\n",it+z2);
            else{
                z2+=it*m2;
                printf("%lld/%lld\n",z2,m2);
            }
        }
        else{
            z1=atoll(xi1);m1=1;
            for(int i=0;i<le-p-1;i++)m1*=10;
            long long g=gcd(m1,z1);
            z1/=g;m1/=g;
            z2=atoll(xi2);m2=1;
            for(int i=0;i<ri-le-1;i++)m2*=10;
            m2--;
            for(int i=0;i<le-p-1;i++)m2*=10;
            g=gcd(m2,z2);
            z2/=g;m2/=g;
            long long m=god(m1,m2),z=m/m1*z1+m/m2*z2;
            g=gcd(m,z);
            z/=g;m/=g;
            if(m==1)printf("%lld\n",it+z);
            else{
                z+=it*m;
                printf("%lld/%lld\n",z,m);
            }
        }
    }
}