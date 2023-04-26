#include<stdio.h>
#include<string.h>

char s[1005]={0};

int func(int i){
    int res=0;
    if (s[i-1]!=s[i]){
        if (s[i-1]!=s[i+1] && s[i]!=s[i+1]) res=3;
        else res = 2;
    }
    else {
        if (s[i]==s[i+1]) res=1;
        else res=2;
    }
    return res;
}

int main(){
    gets(s+1);
    int slen=strlen(s+1),res=1;
    s[0]=s[1];
    s[slen+1]=s[slen];
    for (int i=1; i<=slen; i++){
        int temp = func(i);
        res*=temp;
        res%=1000000007;
    }
    printf("%d\n", res);
    return 0;
}