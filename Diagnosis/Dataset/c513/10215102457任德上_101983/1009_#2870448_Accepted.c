#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int binary(char a){
    int m=0;
    char n = 1;
    for(int i = 8;i>0;i--,a=a>>1)m+=(a&n);
    return m;
}
int GCD(int m,int n){
    int a,b,c;
    if(m>n)a=n;
    else
        a=m;
    for(b=2;b<=a;b++){
        if(m%b==0&&n%b==0)return b*GCD(m/b,n/b);
    }
    return 1;
}
int main(){
    int n,i=0;
    scanf("%d\n",&n);
    while(n-->0){
        int p,q=0,m;
        char *s1,s[121];
        gets(s);
        s1=s;
        while(*s1){
            p=binary(*s1);
            q+=p;
            s1++;
        }
        m=GCD(q,8*strlen(s));
        printf("%d/%d\n",q/m,8*strlen(s)/m);
    }
    return 0;
}



