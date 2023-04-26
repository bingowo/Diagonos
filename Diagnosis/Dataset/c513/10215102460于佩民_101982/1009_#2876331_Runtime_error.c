#include <stdio.h>
int GCD(int m,int n)
{
    int a,b,temp;
    if(m==n){
        return m;}
    else if(m>n){
        a=m;
        b=n;}
    else if(m<n){
        a=n;
        b=m;}
    temp=a%b;
    if(temp==0){
        return b;}
    else if(temp!=0){
        return GCD(b,temp);}
}

int main(){
    int a=0,num,number=0,sum=0,gcd;
    char now;
    scanf("%d",&num);
    while(a<num){
        while((now=getchar())!=EOF){
            number+=8;
            while(now!=0){
                if(now&1) sum++;
                now=now>>1;
            }
        }
        gcd=GCD(sum,number);
        sum/=gcd;
        number/=gcd;
        printf("%d/%d\n",sum,number);
        number=0;
        sum=0;
        a++;
    }
    return 0;
}