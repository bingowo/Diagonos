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
    long long res=0,r1=0,time=1,flag=0;
    char s[30];scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(isalpha(s[i])&&flag==0){
            if(n[s[i]]>=n[s[i+1]])res+=n[s[i]];
            else res-=n[s[i]];
        }
        if(s[i]=='('){
            flag=1;
            time*=1000;
        }
        if(isalpha(s[i])&&flag==1){
            if(n[s[i]]>=n[s[i+1]])r1+=n[s[i]];
            else r1-=n[s[i]];
        }
        if(s[i]==')'&&flag==1){
            flag=0;
            res+=r1*time;
            time=1;
        }
    }
    printf("%lld",res);
}

