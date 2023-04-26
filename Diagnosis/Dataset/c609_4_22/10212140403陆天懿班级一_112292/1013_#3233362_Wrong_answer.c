#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

ll x,y,x0,y0;

void Trans(int d){
    x0=x,y0=y;
    x=-x0-y0;
    y=x0-y0;
    if(d) x+=1;
}

void Print(){
    printf("%lld",x);
    if(y!=0){
        if(y>0) printf("+");
        if(y==1) printf("i");
        else if(y==-1) printf("-i");
        else printf("%lldi",y);
    }
    printf("\n");
}

int main(){
    char s[500];
    scanf("%s",s);
    for(int i=2,d;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9')
            d=s[i]-'0';
        else
            d=s[i]-'A'+10;
        for(int j=0;j<4;j++,d<<=1)
            Trans(d&8);
    }
    Print();

    return 0;
}
