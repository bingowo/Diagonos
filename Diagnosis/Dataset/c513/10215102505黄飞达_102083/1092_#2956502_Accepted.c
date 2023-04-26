#include<stdio.h>
#include<string.h>

int res[1000]={1};
char s[1005]={0};

void multi(int n){
    int index=999;
    while(res[index]==0) index--;
    for (int i=0; i<=index; i++) res[i]*=n;
    for (int i=0; i<=index; i++){
        if (res[i]>=10) {
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
    }
            
    return;
}

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
    int slen=strlen(s+1);
    s[0]=s[1];
    s[slen+1]=s[slen];
    for (int i=1; i<=slen; i++){
        int temp = func(i);
        multi(temp);
    }
    int index=999;
    while(res[index]==0) index--;
    for (int i=index; i>=0; i--) printf("%d", res[i]);
    printf("\n");
    return 0;
}