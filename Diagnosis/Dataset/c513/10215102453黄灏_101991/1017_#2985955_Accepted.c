#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rome[128]={0};

int main() {
    rome['I']=1;rome['V']=5;rome['X']=10;
    rome['L']=50;rome['C']=100;rome['D']=500;rome['M']=1000;
    char s[51];
    scanf("%s",s);
    long long data[100];
    int cnt=0;
    long long line=1;

    for(int i=0;s[i];i++){
        switch (s[i]) {
            case '(': line = line*1000;break;
            case ')': line = line/1000;break;
            default:data[cnt++] = rome[s[i]]*line;break;
        }
    }
    long long ans = 0;
    for(int i=0;i<cnt-1;i++){
        if(data[i] <data[i+1]) ans -= data[i];
        else ans += data[i];
    }
    ans += data[cnt-1];
    printf("%lld\n",ans);
    return 0;
}