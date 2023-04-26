#include<stdio.h>
#include<string.h>
int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[100];
        scanf("%s",s);
        int l=strlen(s),ans=0;
        for(int i=0;i<l;i++){
            if(s[i]=='-')ans=ans*3-1;
            else if(s[i]=='0')ans=ans*3;
            else ans=ans*3+1;
        }
        printf("case #%d:\n%d\n",a,ans);
        a++;
    }
}