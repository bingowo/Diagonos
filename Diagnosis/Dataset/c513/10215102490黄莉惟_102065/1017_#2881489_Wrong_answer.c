#include<stdio.h>
#include<string.h>
int sw(char x){
    switch(x){
    case 'I':return 1;break;
    case 'V':return 5;break;
    case 'X':return 10;break;
    case 'L':return 50;break;
    case 'C':return 100;break;
    case 'D':return 500;break;
    case 'M':return 1000;break;
    case '(':return 0;break;
    default:break;  
    }
    
}
int main(){
    char s[1000];
    long long int sum=0;
    long long int k=0;
    long long int num=1;
    int i=0;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='('){
            num*=1000;
            sum+=k;
            k=0;
        }else if(s[i]==')'){
            sum+=(k*num);
            k=0;
            num=1;
        }else{
            k+=sw(s[i]);
            if((sw(s[i])<sw(s[i+1]))&&(sw(s[i])!=0)&&s[i+1]!=')'){
                k=k-2*sw(s[i]);
            }
        }
    }
    sum+=k;
    printf("%lld",sum);
}