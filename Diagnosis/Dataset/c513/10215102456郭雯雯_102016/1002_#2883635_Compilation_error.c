#include<stdio.h>
#include<string.h>

int main(){
    int t,o=0,ans=0;
    char a[60],b[62]="1023456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",s[60];
    scanf("%d",&t);
    while(o<t){
        scanf("%s",a);
        int len=strlen(a),n=1;
        strcpy(s,a);
        s[0]=b[0];
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(a[j]==a[i])s[j]=s[i];
                else{
                    s[j]=b[n];n++;
                }
            }
        }
        while(len>=0){
            if(s[l-1]>='0'&&s[l-1]<='9')ans=ans*n+(s[l-1]-'0');
            if(s[l-1]>='a'&&s[l-1]<='z')ans=ans*n+(s[l-1]-'a'+10);
            if(s[l-1]>='A'&&s[l-1]<='Z')ans=ans*n+(s[l-1]-'A'+37);
            len--;
        }
        printf("case#%d:\n%s\n",o,ans);
        o++;
    }
    return 0;
}