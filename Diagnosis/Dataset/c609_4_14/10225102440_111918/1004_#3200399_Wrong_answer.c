#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ctoi(char a){
    int x;
    if(a>='0'&&a<='9') x=a-'0';
    else if(a>='a'&&a<='z') x=a-'a'+10;
    else if(a>='A'&&a<='Z') x=a-'A'+10;
    return x;
}
char itoc(int x){
    char a;
    if(x<10) a=x+'0';
    else a=x+'A'-10;
    return a;
}
int main()
{
    int a,b,l,i,x=1,j;
    char t;
    long long int n=0;
    char s[50],y[50]={0};
    scanf("%d %s %d",&a,s,&b);
    l=strlen(s);
    for(i=l-1;i>=0;i--){
        n += ctoi(s[i])*x;
        x *= a;
    }
    i=0;
    if(n==0){
        y[i]=0;
        i++;
    }
    while(n){
        y[i]=itoc(n%b);
        n=n/b;
        i++;
    }
    i--;
    for(j=0;j<i-j;j++) t=y[j],y[j]=y[i-j],y[i-j]=t;
    printf("%s",y);
    return 0;
}
