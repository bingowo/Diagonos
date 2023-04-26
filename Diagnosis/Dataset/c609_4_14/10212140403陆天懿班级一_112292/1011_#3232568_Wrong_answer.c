#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

ll a,b=1,t;
int mode=0;

ll GCD(int x,int y){
    if(!x) return y;
    while(y){
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}

int main(){
    char s[50];
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='.'){
            mode=1;
            continue;
        }
        t=s[i]-'0';
        a=a*3+(t==2?-1:t);
        if(mode) b*=3;
    }
    if(a<0){
        printf("-");
        a=-a;
    }
    t=GCD(a,b);
    a/=t,b/=t;
    if(a%b==0)
        printf("%lld",a/b);
    else if(a/b==0)
        printf("%lld %lld",a%b,b);
    else
        printf("%lld %lld %lld",a/b,a%b,b);

    return 0;
}
