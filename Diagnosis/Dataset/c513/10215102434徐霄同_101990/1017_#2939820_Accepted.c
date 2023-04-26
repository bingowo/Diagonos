#include <stdio.h>
#include <string.h>
int a[50];
int l;
long long f(int x)
{
    long long n,n0;
    int i,p;
    n=0;
    i=x;
    while(i<l&&a[i]!=-2){
        if(a[i]==-1){
            n0=f(i+1)*1000;
            if(n==0||n>=n0)
                n=n+n0;
            else
                n=n0-n;
            p=1;
            while(p>0){
                i++;
                if(a[i]==-1)
                    p++;
                else if(a[i]==-2)
                    p--;
            }
        }
        else if(i==l-1||a[i+1]==-2||a[i]>=a[i+1])
            n=n+a[i];
        else{
            n=n+(a[i+1]-a[i]);
            i++;
        }
        i++;
    }
    return n;
}
int main()
{
    char s[51];
    int i;
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)
        if(s[i]=='I')
            a[i]=1;
        else if(s[i]=='V')
            a[i]=5;
        else if(s[i]=='X')
            a[i]=10;
        else if(s[i]=='L')
            a[i]=50;
        else if(s[i]=='C')
            a[i]=100;
        else if(s[i]=='D')
            a[i]=500;
        else if(s[i]=='M')
            a[i]=1000;
        else if(s[i]=='(')
            a[i]=-1;
        else
            a[i]=-2;
        printf("%lld\n",f(0));
    return 0;
}
