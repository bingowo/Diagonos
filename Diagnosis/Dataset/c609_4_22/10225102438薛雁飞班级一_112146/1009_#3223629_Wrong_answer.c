#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int m,int n)
{
    int a;
    if(m<n){a=m;m=n;n=a;}
    if(n==0)return(m);
    else return(gcd(n,m%n));
}
int main()
{
    char s[33];
    scanf("%s",s);
    int i=0,m=0,j;
    char r[10000];
    for(j=0;j<strlen(s);j++){
        do{
            r[i]=s[j]%2+'0';
            s[j]=s[j]/2;
            i++;
        }while(s[j]);
    }
    for(int k=0;k<i;k++){
        if(r[k]=='1')m++;
    }
    int g=gcd((8*j),m);
    i=(8*j)/g;
    m=m/g;
    printf("%d/%d",m,i);
    return 0;
}
