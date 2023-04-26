#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

void solve(){
    char s[300];
    int i,fz=0,fm,l,g;
    fgets(s,300,stdin);
    l=strlen(s);
    fm=8*l;
    for(i=0;i<l;i++){
        unsigned char c=(unsigned char)s[i];
        while(c>0){
            if(c&1) fz++;
            c>>=1;
        }
    }
    g=gcd(fm,fz);
    printf("%d/%d\n",fz/g,fm/g);
}

int main()
{   int tot;
    scanf("%d",&tot);
    for(int i=0;i<tot;i++) solve();
    return 0;
}
