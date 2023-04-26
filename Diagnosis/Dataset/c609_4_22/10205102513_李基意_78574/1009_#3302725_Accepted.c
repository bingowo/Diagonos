#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

void solve(){
    char s[122];
    int i,fz=0,fm=0,len,g;
    fgets(s,122,stdin);
    len=strlen(s)-1;
    fm=8*len;
    for(int i=0;i<len;i++){
        unsigned char c=s[i];
        while(c>0){
            if(c&1) fz++;
            c>>=1;
        }
    }
    g=gcd(fm,fz);
    printf("%d/%d\n",fz/g,fm/g);
}

int main(){
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
        solve();
    return 0;
}
