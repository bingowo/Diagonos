#include<stdio.h>
#include<string.h>

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int same(char *s){
    int l=strlen(s);
    for(int i=0;i<l-1;i++){
        if(s[i]==s[i+1])return 1;
    }
    return 0;
}

int dlt(char *s){
    int l=strlen(s);
    while(same(s)){
        for(int i=0;i<l-1;i++){
            if(s[i]==s[i+1]){
                int n=i+1;
                while(s[n]==s[i])n++;
                for(int j=i,k=n;k<l;j++,k++)s[j]=s[k];
                l-=(n-i);
                s[l]='\0';
            }
        }
    }
    return strlen(s);
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s0[110],s[110];
        scanf("%s",s0);memset(s,0,sizeof(s));
        int l=strlen(s0),ans=0;
        for(int i=0;i<=l;i++){
            for(char c='A';c<'D';c++){
                s[i]=c;
                strncpy(s,s0,i);
                strncpy(s+i+1,s0+i,l-i);
                s[l+i]='\0';
                ans=max(ans,l+1-dlt(s));
            }
        }
        printf("case #%d:\n",a);
        printf("%d\n",ans);
        a++;
    }
}