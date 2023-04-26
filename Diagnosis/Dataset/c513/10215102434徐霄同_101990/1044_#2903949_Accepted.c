#include <stdio.h>
#include <string.h>
#include <ctype.h>
int i,l;
char s[100001];
unsigned num(int x)
{
    unsigned n=0;
    i=x;
    while(i<l && (isdigit(s[i]) || (s[i]>='a' && s[i]<='f'))){
        if(isdigit(s[i]))
            n=n*16+s[i]-'0';
        else
            n=n*16+s[i]-'a'+10;
        i++;
    }
    return n;
}
int main()
{
    unsigned a[100001];
    int j,n;
    scanf("%s",s);
    l=strlen(s);
    n=0;
    i=0;
    while(i<l){
        if(i<=l-3 && s[i]=='0' && s[i+1]=='x' && (isdigit(s[i+2]) || (s[i+2]>='a' && s[i+2]<='f'))){
            a[n]=num(i+2);
            n++;
        }
        else
            i++;
    }
    if(n==0)
        printf("-1\n");
    else
        for(j=0;j<n;j++){
            printf("%u",a[j]);
            if(j==n-1)
                printf("\n");
            else
                printf(" ");
        }
    return 0;
}
