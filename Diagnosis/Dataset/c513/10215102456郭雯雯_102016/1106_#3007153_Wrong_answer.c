#include<stdio.h>
#include<string.h>

int main(){
    char s[1001];
    scanf("%s",s);
    int n=1,M=1000000007;
    int l=strlen(s);
    if(l>1){
        if(s[0]!=s[1]){n=((n%M)*2)%M;}
        if(s[l-2]!=s[l-1]){n=((n%M)*2)%M;}
        for(int i=1;i<l-1;i++){
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
                if(s[i-1]!=s[i+1]){n=((n%M)*3)%M;}
                else{n=((n%M)*2)%M;}
            }
            else if(s[i]!=s[i-1]&&s[i]==s[i+1]){n=((n%M)*2)%M;}
            else if(s[i]==s[i-1]&&s[i]!=s[i+1]){n=((n%M)*2)%M;}
            else{n=((n%M)*1)%M;}
        }
    }
    printf("%d",n);
}