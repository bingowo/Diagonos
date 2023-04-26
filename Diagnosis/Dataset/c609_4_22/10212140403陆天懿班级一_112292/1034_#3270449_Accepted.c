#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

int IsNum(char c);
inline int IsNum(char c){
    return c>='0'&&c<='9'||c>='a'&&c<='f';
}

ll ToNum(char c);
inline ll ToNum(char c){
    if(c>='0'&&c<='9')
        return c-'0';
    else
        return 10+c-'a';
}


int main(){
    ll n;
    char s[100005];
    int mode=0;
    int has=0;
    scanf("%s",s);
    strcat(s,"z");
    for(int i=0;s[i]!='\0';i++){
        if(mode){
            if(IsNum(s[i])){
                n=n*16+ToNum(s[i]);
            }
            else{
                printf("%lld ",n);
                mode=0;
            }
        }
        else{
            if(s[i]=='0'&&s[i+1]=='x'&&IsNum(s[i+2])){
                i++;
                mode=1;
                has=1;
                n=0;
            }
        }
    }
    if(!has) printf("-1");
    printf("\n");

    return 0;
}
