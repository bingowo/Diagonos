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
    int T;
    scanf("%d\n",&T);
    for(int n=0;n<T;n++){
        char s[33];
        int a,b=0;
        char r[10000];
        while(scanf("%c",&s[b])&&s[b]!='\n')b++;
        s[b]='\0';
        int i=0,m=0,j;
        for(j=0;j<strlen(s);j++){
            a=s[j];
            do{
                r[i]=a%2+'0';
                a=a/2;
                i++;
            }while(a);
        }
        for(int k=0;k<i;k++){
            if(r[k]=='1')m++;
        }
        int g=gcd((8*j),m);
        i=(8*j)/g;
        m=m/g;
        printf("%d/%d\n",m,i);
    }
    return 0;
}
