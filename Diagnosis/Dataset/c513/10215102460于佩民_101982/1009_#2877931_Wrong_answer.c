#include <stdio.h>
#include <string.h>

int GCD(int m,int n){
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
    int a=0,num,number=0,sum=0,gcd,i,len,temp;
    char now[121];
    scanf("%d\n",&num);
    while(a<num){
        gets(now);
        len=strlen(now);
        for(i=0;i<len;i++){
            number+=8;
            temp=now[i];
            while(temp){
                temp=temp&(temp-1);
                sum+=1;
            }
        }
        gcd=GCD(sum,number);
        sum/=gcd;
        number/=gcd;
        printf("%d/%d\n",sum,number);
        number=0;
        sum=0;
        char now[121]={'0'};
        a++;
    }
    return 0;
}