#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

int a,b,g;
char s[150];

void Stat(char c){
    b+=8;
    while(c){
        if(c&1) a++;
        c>>=1;
    }
}

int GCD(int x, int y){
    if(!x) return y;
    int t;
    while(y){
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}

int main(){
    int cnt;
    scanf("%d",&cnt);
    gets(s);
    while(cnt--){
        a=b=0;
        gets(s);
        for(int i=0;s[i]!='\0';i++)
            Stat(s[i]);
        g=GCD(a,b);
        a/=g,b/=g;
        printf("%d/%d\n",a,b);
    }

    return 0;
}
