#include<stdio.h>
#include<string.h>
int main()
{
    int A,B,dec=0;
    char n[1000],table[]="123456789abcdefghijklmnopqrstuvwxyz";
    scanf("%d%s%d",&A,n,&B);
    for(int i=0;i<strlen(n);i++)
    {
        int j=0;
        if(n[i]>96)n[i]-=32;
        while(n[i]!=table[j])j++;
        dec=dec*A+j;
    }
    int k=0;
    char a[33];
    do{
        int r=dec%B;
        a[k++]=table[r];
        dec/=B;
    }
    while(dec);
    for(k--;k>0;k--)printf("%c",a[k]);
    return 0;
}