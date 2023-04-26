#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    int a=0,num,number=0,sum=0,gcd,i;
    char now[121]; 
    scanf("%d\n",&num);
    while(a<num){
        gets(now);
        for(i=0;i<strlen(now);i++){
            number+=8;
            while(now[i]!=0){
                if(now[i]&1) sum+=1;
                now[i]=now[i]>>1;
            }
        }
        gcd=GCD(sum,number);
        sum/=gcd;
        number/=gcd;
        printf("%d/%d\n",sum,number);
        number=0;
        sum=0;
        for(i=0;i<120;i++) now[i]='\0';
        a++;
    }