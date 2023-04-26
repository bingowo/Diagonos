#include<stdio.h>
#include<string.h>
int sw(char x){
    case 'I':return 1;break;
    case 'V':return 5;break;
    case 'X':return 10;break;
    case 'L':return 50;break;
    case 'C':return 100;break;
    case 'D':return 500;break;
    case 'M':return 1000;break;
    default:break;
}
int main(){
    char s[1000];
    long long int sum=0;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        sum+=sw(s[i]);
        if(sw(s[i])<sw(s[i+1])){
            sum=sum-2*sw(s[i]);
        }
    }
    printf("%lld",sum);
}