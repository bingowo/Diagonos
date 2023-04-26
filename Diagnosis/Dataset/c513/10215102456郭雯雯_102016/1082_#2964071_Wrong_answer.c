#include<stdio.h>
#include<string.h>
#define L 500

void Input(int a[]){
    char s[L+1];
    scanf("%s",s);
    int l=strlen(s),i=0;
    while(i<l&&s[i]!='.')i++;//小数点位
    for(int j=i-1,k=L;j>=0;j--,k--)a[k]=s[j]-'0';
    for(int j=i+1,k=L+1;j<l;j++,k++)a[k]=s[j]-'0';
}

int main(){
    char a[500],b[500];
    int n;
    scanf("%s %s %d",a,b,&n);
}