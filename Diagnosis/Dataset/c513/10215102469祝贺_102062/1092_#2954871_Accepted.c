#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct{
    int num[500];
    int p;
}bint;
void mul(bint* a,int n){
    for(int i=0;i<a->p ;i++){
        a->num[i]*=n;
    }
    long long carry=0, i=0;
    for(;i<a->p || carry!=0;i++){
        long long tmp=a->num[i]+carry;
        a->num[i]=tmp%10;
        carry=tmp/10;
    }
    a->p=i;
}

int main(){
    char s[1020];scanf("%s",s);
    bint ans={{1},1};
    if(strlen(s)==2){
        if(s[0]!=s[1]) mul(&ans,4);
    }
    else if(strlen(s)>=3){
        if(s[0]!=s[1]) mul(&ans,2);
        if(s[strlen(s)-1]!=s[strlen(s)-2]) mul(&ans,2);
        for(int i=1;i<strlen(s)-1;i++){
            if(s[i-1]==s[i+1] && s[i]!=s[i-1])mul(&ans,2);
            else if(s[i-1]!=s[i+1]){
                if(s[i]!=s[i-1] && s[i]!=s[i+1])mul(&ans,3);
                else if(s[i]==s[i-1] || s[i]==s[i+1])mul(&ans,2);
            }
        }
    }
    for(int i=ans.p-1;i>=0;i--)printf("%d",ans.num[i]);
    return 0;
}
