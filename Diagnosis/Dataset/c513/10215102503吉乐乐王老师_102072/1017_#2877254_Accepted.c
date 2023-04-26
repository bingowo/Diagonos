#include<stdio.h>
#include<string.h>
#include<ctype.h>
int trans(char a){
    int res;
    if(a=='I')res=1;
    else if(a=='V')res=5;
    else if(a=='X')res=10;
    else if(a=='L')res=50;
    else if(a=='C')res=100;
    else if(a=='D')res=500;
    else if(a=='M')res=1000;
    return res;
}
int main(){
    char s[1000];
    scanf("%s",s);
    int n=strlen(s);
    long long int ret[1000]={0};
    long long int digit=1;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            char pre;
            if(i-1>=0)pre=i-1;
            while(s[i]=='('){
                digit*=1000;i++;
            }
            long long int temp=0;
            while(s[i]!=')'){
                if((s[i]=='I'||s[i]=='X'||s[i]=='C')&&isalpha(s[i+1])&&trans(s[i+1])>trans(s[i]))temp-=trans(s[i]);
                else temp+=trans(s[i]);
                i++;
            }
            temp*=digit;digit=1;
            if(temp>ret[pre])ret[pre]=-ret[pre];
            ret[i]=temp;
            continue;
        }
        if(s[i]==')')continue;
        if((s[i]=='I'||s[i]=='X'||s[i]=='C')&&isalpha(s[i+1])&&trans(s[i+1])>trans(s[i]))ret[i]=-trans(s[i]);
        else ret[i]=trans(s[i]);
    }
    long long int res=0;
    for(int i=0;i<n;i++){
        res+=ret[i];
    }
    printf("%lld",res);
}

