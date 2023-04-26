#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num(char a[]){//字符串中不同字符的个数
    int len=strlen(a),n=len;
    char s[n];
    strcpy(s,a);
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
            if(s[j]==s[i]){
                n--;break;
            }
    return n;
}

int main(){
    int t,j=0,ans=0;
    char s[60],a[60],b[61]="023456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&t);
    while(j<t){
        scanf("%s",a);
        int n=strlen(a);
        s[0]='1';
        int k=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                if(a[j]==a[i])
                    s[j]=s[i];
                else{
                    s[j]=b[k];
                    k++;
                }
            }
        int m=num(a);
        if(m==1)m=2;
        while(n>0){
            if(s[n-1]>='0'&&s[n-1]<='9')ans=ans*m+s[n-1];
            if(s[n-1]>='a'&&s[n-1]<='z')ans=ans*m+(s[n-1]-'a'+10);
            if(s[n-1]>='A'&&s[n-1]<='Z')ans=ans*m+(s[n-1]-'A'+37);
            n--;
        }
        printf("case#%d:\n%d\n",j,m);
        j++;
    }
    return 0;
}
