#include <stdio.h>
#include <string.h>
#include <ctype.h>
long long f(char s[],int x)
{
    int i,l;
    long long n,f;
    l=strlen(s);
    i=x;
    f=1;
    if(s[i]=='-'){
        f=-1;
        i++;
    }
    else if(s[i]=='+')
        i++;
    if(s[i]=='i')
        return f;
    n=0;
    while(i<l&&isdigit(s[i])){
        n=n*10+s[i]-'0';
        i++;
    }
    return n*f;
}
long long abs(long long a)
{
    if(a>=0)
        return a;
    else
        return -a;
}
int main()
{
    char s[50];
    int i,l,n;
    long long a,b,t;
    int ans[1000];
    scanf("%s",s);
    l=strlen(s);
    if(s[l-1]!='i'){
        b=0;
        a=f(s,0);
    }
    else{
        i=0;
        if(s[i]=='+'||s[i]=='-')
            i++;
        while(isdigit(s[i]))
            i++;
        if(s[i]=='i'){
            a=0;
            b=f(s,0);
        }
        else{
            a=f(s,0);
            b=f(s,i);
        }
    }
    n=0;
    while(a!=0||b!=0){
        if(abs(a)%2==abs(b)%2){
            ans[n]=0;
            n++;
            printf("0\n");
        }
        else{
            a--;
            ans[n]=1;
            n++;
            printf("1\n");
        }
        t=a;
        a=(b-t)/2;
        b=(-t-b)/2;
    }
    if(n==0)
        printf("0\n");
    else{
        for(i=n-1;i>=0;i--)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}