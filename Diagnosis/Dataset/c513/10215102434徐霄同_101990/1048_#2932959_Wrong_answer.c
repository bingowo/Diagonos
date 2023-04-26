#include <stdio.h>
#include <string.h>
#include <ctype.h>
int f(char s[],int x)
{
    int i,l,n,t;
    l=strlen(s);
    i=x;
    if(s[x]=='x')
        return 1;
    else if(s[x]=='-'&&s[x+1]=='x')
        return -1;
    if(s[x]=='-'){
        t=-1;
        i++;
    }
    else{
        t=1;
        if(s[x]=='+')
            i++;
    }
    n=0;
    while(i<l&&isdigit(s[i])){
        n=n*10+s[i]-'0';
        i++;
    }
    return n*t;
}
int main()
{
    char s1[101],s2[101];
    int a[51],b[51],c[101];
    int i,l1,l2,n1,n2,x,y;
    while(scanf("%s%s",s1,s2)!=EOF){
        l1=strlen(s1);
        l2=strlen(s2);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        i=0;
        while(i<l1&&s1[i]!='^')
            i++;
        if(i==l1){
            i=0;
            while(i<l1&&s1[i]!='x')
            i++;
            if(i==l1)
                n1=0;
            else
                n1=1;
        }
        else{
            i++;
            n1=f(s1,i);
        }
        i=0;
        while(i<l1){
            x=f(s1,i);
            i++;
            while(i<l1&&s1[i]!='+'&&s1[i]!='-'&&s1[i]!='^')
                i++;
            if(s1[i]=='^'){
                i++;
                y=f(s1,i);
                a[y]=x;
                while(i<l1&&s1[i]!='+'&&s1[i]!='-')
                    i++;
            }
            else if(s1[i]=='+'||s1[i]=='-')
                a[1]=x;
            else
                a[0]=x;

        }
        for(i=n1;i>=0;i--)
            printf("%d ",a[i]);
    }
    return 0;
}
