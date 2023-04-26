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
int cs(char s[])
{
    int i,l,n;
    l=strlen(s);
    i=0;
    while(i<l&&s[i]!='^')
        i++;
    if(i==l){
        i=0;
        while(i<l&&s[i]!='x')
        i++;
        if(i==l)
            n=0;
        else
            n=1;
    }
    else{
        i++;
        n=f(s,i);
    }
    return n;
}
int main()
{
    char s1[101],s2[101];
    int a[51],b[51],c[101];
    int i,j,l1,l2,n1,n2,x,y,t;
    while(scanf("%s%s",s1,s2)!=EOF){
        l1=strlen(s1);
        l2=strlen(s2);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        n1=cs(s1);
        n2=cs(s2);
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
        i=0;
        while(i<l2){
            x=f(s2,i);
            i++;
            while(i<l2&&s2[i]!='+'&&s2[i]!='-'&&s2[i]!='^')
                i++;
            if(s2[i]=='^'){
                i++;
                y=f(s2,i);
                b[y]=x;
                while(i<l2&&s2[i]!='+'&&s2[i]!='-')
                    i++;
            }
            else if(s2[i]=='+'||s2[i]=='-')
                b[1]=x;
            else
                b[0]=x;
        }
        t=0;
        for(i=0;i<=n1;i++)
            for(j=0;j<=n2;j++){
                c[i+j]+=a[i]*b[j];
                if(c[i+j]!=0)
                    t++;
                else
                    t--;
            }
        for(i=n1+n2;i>=0;i--){
            if(c[i]!=0){
                printf("%d",c[i]);
                t--;
            }
            if(t==0)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
