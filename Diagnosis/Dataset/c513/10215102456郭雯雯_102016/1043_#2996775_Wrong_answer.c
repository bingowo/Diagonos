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

int dlt(char *s0){
    char s[110];
    strcpy(s,s0);
    int l=strlen(s);
    while(same(s)){
        for(int i=0;i<l-1;i++){
            if(s[i]==s[i+1]){
                int n=i+1;
                while(s[n]==s[i]&&n<l)n++;
                for(int j=i,k=n;k<l;j++,k++)s[j]=s[k];
                l=l-(n-i);
                s[l]='\0';
            }
        }
    }
    return l;
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
                if(i>0)strncpy(s,s0,i);
                if(i<l)strncpy(s+i+1,s0+i,l-i);
                s[l+1]='\0';
                ans=max(ans,l+1-dlt(s));
            }
        }
        printf("case #%d:\n",a);
        printf("%d\n",ans);
        a++;
    }
}