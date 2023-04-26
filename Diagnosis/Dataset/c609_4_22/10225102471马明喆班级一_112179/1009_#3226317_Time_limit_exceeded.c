#include <stdio.h>
#include <string.h>

int GCD(int m,int n){
    int max,min;
    if(m>n){
        min=n;
        max=m;}
    else{
        min=m;
        max=n;}
    if(max%min==0)
        return min;
    else
        return GCD(min,max%min);
}

int main(){
    int n;
    int a,b=0;
    int t;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        char s[1000];
        fgets(s,1000,stdin);
        a=strlen(s)-1;
        for(int x=0;x<a;x++){
            while(s[x]>0){
                b=b+s[x]&1;
                s[x]>>1;
            }
            }
        a=a*8;
        int gcd=GCD(a,b);
        printf("%d/%d\n",b/gcd,a/gcd);
    }
return 0;
}