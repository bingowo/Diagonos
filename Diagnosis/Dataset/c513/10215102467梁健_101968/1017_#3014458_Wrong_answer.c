#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int n[128]={0};
    n['I']=1,n['V']=5,n['X']=10,n['L']=50,n['C']=100;
    n['D']=500,n['M']=1000;
    int res=0,time=1;
    char s[30];scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='(')time*=1000;
        if(isalpha(s[i])){
            if(n[s[i]]>=n[s[i+1]])res+=n[s[i]];
            else res-=n[s[i]];
        }
    }
    printf("%d",res*time);
}

