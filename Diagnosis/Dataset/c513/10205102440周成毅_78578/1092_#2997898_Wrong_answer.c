#include <stdio.h>

int mul(int *n,int a,int l){
    int carry=0,i;
    for(i=0;i<l;i++){
        n[i]*=a;
        n[i]+=carry;
        carry=n[i]/10;
        n[i]%=10;
    }
    while(carry!=0){
        n[i++]=carry%10;
        carry/=10;
    }
    return i+1;
}

int main(){
    char s[1001];
    scanf("%s",s);
    int n[10000];
    memset(n,0,sizeof(n));
    n[0]=1;
    int l=strlen(s),ln=1;
    if(l>1){
        if(s[0]!=s[1])ln=mul(n,2,ln);
        else ln=mul(n,1,ln);
        if(s[l-2]!=s[1-1])ln=mul(n,2,ln);
        else ln=mul(n,1,ln);
        for(int i=1;i<l-1;i++){
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
                if(s[i-1]!=s[i+1])ln=mul(n,3,ln);
                else ln=mul(n,2,ln);
            }
            else if(s[i]!=s[i-1]&&s[i]==s[i+1])ln=mul(n,2,ln);
            else if(s[i]==s[i-1]&&s[i]!=s[i+1])ln=mul(n,2,ln);
            else ln=mul(n,1,ln);
        }
    }
    for(int i=ln-1;i>=0;i--)printf("%d",n[i]);
}
