#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void myultoa(char *p,unsigned long long int a){
    do{
        *p=a%10+'0';
        a/=10;
        p++;
    }while(a);
    *p='\0';
}
int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    int cnt=0;
    while(a<=b){
        char s[30];
        char *p=s;
        myultoa(p,a);
        int flag=0;
        int temp=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='9'){flag=1;break;}
            else temp+=s[i]-'0';
        }
        if(temp%9==0)flag=1;
        if(flag==0)cnt++;
        a+=1;
    }
    printf("%d",cnt);
}