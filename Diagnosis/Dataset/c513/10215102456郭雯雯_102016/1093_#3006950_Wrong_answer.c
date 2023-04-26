#include<stdio.h>
#include<string.h>

int isn(int* s,int l){
    int ans=0;
    for(int i=0;i<l;i++)ans+=s[i];
    if(ans%9==0)return 1;
    return 0;
}

int add(int *s,int l){
    s[0]++;
    int i;
    for(i=0;i<l-1;i++){
        int c=s[i]/10;
        s[i]%=10;
        s[i+1]+=c;
    }
    if(s[i]<10)return l;
    else{
        s[i+1]=s[i]/10;
        s[i]%=10;
        l++;
        return l;
    }
}

int main(){
    char s[105];
    int num[105];
    scanf("%s",s);memset(num,0,sizeof(num));
    int l=strlen(s),ln=l;
    for(int i=l-1,j=0;i>=0;i--,j++)num[j]=s[i]-'0';
    while(isn(num,ln)!=1)ln=add(num,ln);
    for(int i=ln-1;i>=0;i--)printf("%d",num[i]);
}