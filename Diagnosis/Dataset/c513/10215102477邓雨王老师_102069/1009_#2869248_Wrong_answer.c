#include<stdio.h>
#include<string.h>
int club(char s){
    int m='s';
    int sum=0;
    while(m>0){
        if(m%2==0) sum=sum+1;
        m=m/2;
    }
    return sum;
}
int GCD(int m,int n)
{
    int i=1,x; //x即代表最大公约数
    if(m%n==0){  //若成立，则说明m>=n,且n是m的一个约数
        return n;
    }
    return GCD(n,m%n);
    
}
int main(){
    int chance;
    scanf("%d",&chance);
    int i;
    for(i=0;i<chance;i++){
        int n=0;
        char s[100];
        scanf("%s",&s);
        int j;
        for(j=0;j<strlen(s);j++){
            n=n+club(s[j]);
        }
        int t=strlen(s)*8;
        int x=n/GCD(t,n);
        int y=t/GCD(t,n);
        printf("%d/%d\n",x,y);
    }
}