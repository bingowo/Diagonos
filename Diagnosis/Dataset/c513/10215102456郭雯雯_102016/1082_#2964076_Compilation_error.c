#include<stdio.h>
#include<string.h>
#define L 500

void input(int *a){
    char s[L+1];
    scanf("%s",s);
    int l=strlen(s),i=0;
    while(i<l&&s[i]!='.')i++;//小数点位
    for(int j=i-1,k=L;j>=0;j--,k--)a[k]=s[j]-'0';
    for(int j=i+1,k=L+1;j<l;j++,k++)a[k]=s[j]-'0';
}

int main(){
    int a[2*L+1]={0},b[2*L+1]={0},n;
    input(a);input(b);
    scanf("%d",&n);
    add(a,b,n);
    output(a,n);
}