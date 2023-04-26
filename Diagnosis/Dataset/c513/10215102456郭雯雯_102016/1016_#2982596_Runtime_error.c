#include<stdio.h>
#include<string.h>
#define L 50

int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    char c[20]="0123456789ABCDEFGHIJ",s[L];
    memset(s,0,sizeof(s));
    int i=L-1;
    while(n>0){
        int y=n%r;
        y=abs(y);
        n/=r;
        s[i]=c[y];
        i--;
    }
    int m=0;
    while(s[m]==0)m++;
    for(int j=m;j<L;j++)printf("%c",s[j]);
}