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
void trans(char b[],char a[]){//变换字符串的排列
    int n=strlen(a);
    b[0]='1';
    char s[61]="023456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int m=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i])
                b[j]=b[i];
            else{
                b[j]=s[m];
                m++;
            }
        }
    }
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
        while(i>0){
            if(a[i-1]>='0'&&a[i-1]<='9')ans=ans*m+a[i-1];
            if(a[i-1]>='a'&&a[i-1]<='z')ans=ans*m+(a[i-1]-'a'+10);
            if(a[i-1]>='A'&&a[i-1]<='Z')ans=ans*m+(a[i-1]-'A'+37);
            i--;
        }
        printf("case#%d:\n%s\n",j,a);
        j++;
    }
    return 0;
}
