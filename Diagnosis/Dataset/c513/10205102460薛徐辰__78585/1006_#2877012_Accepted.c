#include<stdio.h>
#include<string.h>
int trans(char* s){
    int l=strlen(s);
    int a=pow(3,l-1),ans=0;
    for(int i=0;i<l;i++){
        if(s[i]=='1')ans+=a;
        else if(s[i]=='-')ans-=a;
        a=a/3;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[1000];
        scanf("%s",s);
        int x=trans(s);
        printf("case #%d:\n%d\n",i,x);
    }
    return 0;
}