#include<stdio.h>
#include<string.h>
#include<math.h>.
typedef struct{
    int bin[505];
    int nim[505];
    int bp,np;
}bdou;
long long trans(long long num){
    if(num<100)return num;
    char s[20];
    sprintf(s,"%lld",num);
    return ((s[0]-'0')*10+s[1]-'0');
}

int main(){
    while(1){
        long long n;scanf("%lld",&n);
        if(n!=0){
            double num=n*log10(n);
            num=num-(int)num;
            num=pow(10,num);
            printf("%d\n",(int)num);
        }
        else break;
    }
    return 0;
}
