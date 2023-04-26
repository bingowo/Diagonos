#include <stdio.h>
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
    int a[4];
    int ans[41][41];
    int i,j,l,x,y,p;
    p=0;
    while(scanf("%s",s)!=EOF){
        if(p==1)
            printf("\n");
        p=1;
        l=strlen(s);
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        i=5;
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
        for(i=-20;i<=20;i++){
            j=a[3]*i*i*i+a[2]*i*i+a[1]*i+a[0];
            if(j>=-20&&j<=20)
                ans[20-j][i+20]=1;
        }
        for(i=0;i<41;i++){
            for(j=0;j<41;j++){
                if(ans[i][j]==1)
                    printf("*");
                else if(i==0&&j==20)
                    printf("^");
                else if(i!=20&&j==20)
                    printf("|");
                else if(i==20&&j!=20&&j!=40)
                    printf("-");
                else if(i==20&&j==20)
                    printf("+");
                else if(i==20&&j==40)
                    printf(">");
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    return 0;
}
