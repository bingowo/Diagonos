#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char C[]="0123456789ABCDEF";
void trans(long long int n,int r){
    if(n){
        trans(n/r,r);
        putchar(C[n%r]);
    }
} 
int main()
{
    int A,B;
    char n[35];
    scanf("%d %s %d",&A,n,&B);
    int len=strlen(n);
    long long int r,i=0;
    for(i=0;i<len;i++){
         if(isdigit(n[i])) r=r*A+n[i]-'0';
         else r=r*A+10+(n[i]<'a'?n[i]-'A':n[i]-'a');
     }
    if(r==0)putchar('0');
    trans(r,B);
    return 0;
}
