#include<stdio.h>
#include<string.h>
int main()
{
    char s[51];
    int i ,a[50],b[10],m = 0,j;
    scanf("%s",s);
    for(i = 0;i<strlen(s);i++)
    {
        a[i] = 0;
        if(s[i]=='I') a[i] = 1;
        if(s[i]=='V') a[i] = 5;
        if(s[i]=='X') a[i] = 10;
        if(s[i]=='L') a[i] = 50;
        if(s[i]=='C') a[i] = 100;
        if(s[i]=='D') a[i] = 500;
        if(s[i]=='M') a[i] = 1000;
        if(s[i]=='(') {b[m] = i;m++;}
    }
    long long int res = a[i-1];
    for(j = i-1;j>=1;j--)
    {
        if(a[j]>a[j-1]&&a[j-1]!=0) res = res - a[j-1];
        else if(a[j-1]!=0) res = res + a[j-1];
        if(j==b[m]) {res*=1000;m--;}
    }
    printf("%lld",res);
    return 0;
}
