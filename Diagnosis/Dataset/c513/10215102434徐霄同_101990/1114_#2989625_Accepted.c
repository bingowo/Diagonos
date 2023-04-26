#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int f(char s[],int x)
{
    int i,l,n,t;
    l=strlen(s);
    i=x;
    if(s[i]=='x'||(s[i]=='+'&&s[i+1]=='x'))
        return 1;
    else if(s[i]=='-'&&s[i+1]=='x')
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
    char s[100];
    int a[3];
    int i,j,l,x,y,a0,b,c,d,p;
    scanf("%s",s);
    l=strlen(s);
    memset(a,0,sizeof(a));
    i=0;
    while(i<l){
        x=f(s,i);
        i++;
        while(i<l&&s[i]!='+'&&s[i]!='-'&&s[i]!='^')
            i++;
        if(s[i]=='^'){
            i++;
            y=f(s,i);
            a[y]=x;
            while(i<l&&s[i]!='+'&&s[i]!='-')
                i++;
        }
        else if(s[i]=='+'||s[i]=='-'||(i==l&&s[l-1]=='x'))
            a[1]=x;
        else
            a[0]=x;
    }
    p=0;
    for(i=1;i<=a[2]/2+1;i++){
        if(a[2]%i==0){
            a0=i;
            c=a[2]/i;
            if(a[0]==0){
                if(a[1]%a0==0){
                    b=0;
                    d=a[1]/a0;
                    p=1;
                }
                else if(a[1]%c==0){
                    d=0;
                    b=a[1]/c;
                    p=1;
                }
            }
            else{
                for(j=-abs(a[0]);j<=abs(a[0]);j++){
                    if(j==0||a[0]%j!=0)
                        continue;
                    if(a0*(a[0]/j)+j*c==a[1]){
                        b=j;
                        d=a[0]/j;
                        p=1;
                        break;
                    }
                }
            }
            if(p==1)
                break;
        }
    }
    if(p==1){
        if(a0==c&&b>d){
            x=b;
            b=d;
            d=x;
        }
        printf("%d %d %d %d\n",a0,b,c,d);
    }
    else
        printf("No Answer!\n");
    return 0;
}
