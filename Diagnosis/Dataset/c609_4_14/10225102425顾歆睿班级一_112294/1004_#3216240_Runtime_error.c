#include<stdio.h>
#include<string.h>
int main()
{
    int A,B,dec=0,t;
    char n[1000],table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d %s %d",&A,n,&B);
    t=A;
    printf("%s",table[0]);
    return 0;
    //转十进制
    for(int i=0;i<strlen(n);i++){
        if(n[0]=='-'){
            printf("-");continue;
        }
        int j=0;
        if(n[i]>96)n[i]-=32;
        while(n[i]!=table[j])j++;
        printf("%s",table);/*这个j到底为什么岿然不动*/
        return 0;
        dec+=j*t;
        t*=A;
    }
    //转B进制
    int k=0,a[33];
    do{
        int r=dec%B;
        a[k++]=table[r];
        dec/=B;
    }while(dec);
    for(k-=1;k>=0;k--)printf("%c",a[k]);
    return 0;
}

