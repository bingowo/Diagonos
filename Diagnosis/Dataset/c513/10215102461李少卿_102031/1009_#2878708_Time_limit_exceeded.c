#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int GCD(int m,int n){
    int a,b,c;
    if(m>n)a=n;
    else
        a=m;
    for(b=2;b<=a;b++){
        if(m%b==0&&n%b==0)return b*GCD(m/b,n/b);
    }
    return 1;
}
int main(){
    int a=0,num,number=0,sum=0,gcd,i,len;
    char now[121];
    scanf("%d\n",&num);
    while(a<num){
        gets(now);
        len=strlen(now);
        for(i=0;i<len;i++){
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
        a++;
    }
    return 0;
}