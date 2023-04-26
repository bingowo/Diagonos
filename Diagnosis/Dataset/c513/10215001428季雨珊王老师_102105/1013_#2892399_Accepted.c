#include<stdio.h>
#include<math.h>
#include<string.h>
int gcd(int a,int b){
    if(b!=0)
        return gcd(b,a%b);
    else return a;
}
int main(){
    char num[50];
    gets(num);
    int length=strlen(num);
    long long int a=0;
    long long int b=0,c=0;
    int k=length;
    for(int i=0;i<length;i++){
        if(num[i]=='.'){
            k=i;
            break;
        }
    }//²éÕÒÐ¡Êýµã
    for(int i=0;i<length;i++){
        if(i<k){
            if(num[i]=='0')
                a=a;
            else if(num[i]=='1')
                a+=pow(3,k-1-i);
            else if(num[i]=='2')
                a-=pow(3,k-1-i);
        }
        else if(i>k){
            c=pow(3,length-k-1);
            if(num[i]=='0')
                b=b;
            else if(num[i]=='1')
                b+=pow(3,length-1-i);
            else if(num[i]=='2')
                b-=pow(3,length-1-i);
        }
    }
    int x=abs(gcd(b,c));
    if(x!=0){
        b/=x;
        c/=x;
    }
    if(b>c){
        b-=c;
        a+=1;
    }
    else if(b==c&&b!=0){
        b=0;
        c=0;
        a+=1;
    }
    else if(b<0&&a!=0){
        for(int i=1;b<c;i++){
            if(b+i*c>=0){
                b=b+i*c;
                a-=i;
                break;
            }
        }
    }
    else if(a<0&&b>0){
        a+=1;
        b=c-b;
    }
    if(a==0&&b!=0){
        printf("%lld %lld",b,c);
    }
    if(b==0&&a!=0){
        printf("%lld",a);
    }
    if(a!=0&&b!=0){
        printf("%lld %lld %lld",a,b,c);
    }
    if(a==0&&b==0){
        printf("%lld",a);
    }
    return 0;
}
