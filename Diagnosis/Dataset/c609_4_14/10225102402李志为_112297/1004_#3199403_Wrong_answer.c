#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[50]={0},b[50]={0},z[16]={"0123456789ABCDEFG"};
    int n,m,i=0,sum=0;
    char*p=a;
    scanf("%d",&n);
    scanf("%s",&a);
    scanf("%d",&m);
    if(a=='0') printf("%d",0);
    while(*p){
        if(*p>='A'&&*p<='Z') sum=sum*n+*p-'A'+10;
        else if(*p>='a'&&*p<='z') sum = sum*n+*p-'a'+10;
        else sum=sum*n+*p-'0';
        p++;
    }
    while(sum){
        b[i]=z[sum%m];
        i++;
        sum=sum/m;
    }
    i--;
    for(;i>=0;i--){
        printf("%c",b[i]);
    }
    return 0;
}