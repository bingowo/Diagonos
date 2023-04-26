#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 1000
#define BigNUm 10007
#define N 100000



int main() {
    char s[51];scanf("%s",s);

    int Roma[128]={0};
    Roma['I']=1;Roma['V']=5;
    Roma['X']=10;Roma['L']=50;
    Roma['C']=100;Roma['D']=500;
    Roma['M']=1000;

    long long data[100];
    long long flag=1;
    int cnt=0;
    for(int i=0; s[i]; i++) {
        switch(s[i]) {
        case '(':
            flag=flag*1000;
            break;
        case ')':
            flag=flag/1000;
            break;
        default:
            data[cnt++]=Roma[s[i]]*flag;
            break;
        }
    }

    long long ans=0;
    for(int i=0; i<cnt-1; i++) {
        if(data[i]<data[i+1]){
            ans-=data[i];
        }
        else ans+=data[i];
    }
    ans+=data[cnt-1];
    printf("%lld",ans);


    return 0;
}

