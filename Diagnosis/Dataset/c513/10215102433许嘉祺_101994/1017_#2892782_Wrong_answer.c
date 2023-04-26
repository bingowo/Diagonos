#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[51];
    int a[255];
    a['I']=1;
    a['X']=10;
    a['C']=100;
    a['V']=5;
    a['L']=50;
    a['D']=500;
    a['M']=1000;
    int t=1;
    int n=0,i;
    scanf("%s",s);
    for  ( i=0;i<strlen(s)-1;i++){
        if (s[i]=="(") t=t*1000;
        else if(s[i]==')') t=t/1000;
        else if (s[i+1]=='('||s[i+1]==')') n=n+t*a[s[i]];
        else if (a[s[i]]<a[s[i+1]]&&(a[s[i]]==1||a[s[i]]==10||a[s[i]]==100) )  n=n-t*a[s[i]];
        else n=n+t*a[s[i]];
    }
    if (s[i]!='('&&s[i]!=')') n=n+t*a[s[i]];
    printf("%d\n",n);
    return 0;
}