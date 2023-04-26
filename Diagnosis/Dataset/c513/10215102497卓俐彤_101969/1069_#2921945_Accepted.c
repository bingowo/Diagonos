#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isback(int n){
    char s[11]={0};
    for(int i=10;i>=0;i--){
        s[i]='0'+n%10;
        n/=10;
    }
    int k=0,flag=1;
    while(s[k++]=='0');
    k--;
    for(int t=10;k<11;k++,t--){
        if(s[k]!=s[t]){
            flag=0;
            break;
        }
    }
    return flag;
}

int backnum(int n){
    char s[11]={0},r[11];
    for(int i=10;i>=0;i--){
        s[i]='0'+n%10;
        n/=10;
    }
    int k=0,len=0;
    while(s[k++]=='0');
    k--;
    len=11-k;
    for(int i=len-1;i>=0;i--){
        r[i]=s[k++];
    }
    r[len]='\0';
    return atoi(r);
}

int main(){
    int count=0;
    int n;
    scanf("%d",&n);
    while(!isback(n)){
        count++;
        n+=backnum(n);
    }
    printf("%d %d\n",count,n);
    return 0;
}

