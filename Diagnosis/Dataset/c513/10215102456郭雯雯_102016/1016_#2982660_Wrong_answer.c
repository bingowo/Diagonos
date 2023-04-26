#include<stdio.h>
#include<string.h>
#define L 50

int main(){
    int n,r,y;
    scanf("%d %d",&n,&r);
    char c[20]="0123456789ABCDEFGHIJ",s[L];
    memset(s,0,sizeof(s));
    int i=0;
    if(n==0)printf("0");
    while(n!=0){
        if(n<0&&n%r!=0){
            y=n%r+r;
            n=n/r+1;
        }
        else{
            y=n%r;
            n=n/r;
        }
        s[i]=c[y];
        i++;
    }
    for(int j=i-1;j>=0;j--)printf("%c",s[j]);
}