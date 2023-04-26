#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num(char a[]){//字符串中不同字符的个数
    int n=strlen(a);
    char s[n];
    strcpy(s,a);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(s[j]==s[i]){
                n--;break;
            }
}
char* trans(char b[],char a[]){//变换字符串的排列
    int r=num(a),n=strlen(a);
    b[0]='1';
    //for (int i=1;i<n;i++)
    //  if((a+i)!=(a+0)){
    //      b+i='0';
      //      break;
        //}
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
    return b;
}
int main(){
    int t,j=0,ans=0;
    char s[60],c,a[60];
    scanf("%d",&t);
    while(j<t){
        int i=0;
        for(;(c=getchar())!='\n';i++)s[i]=c;
        s[i]='\0';
        trans(a,s);
        int m=num(s);
        while(i>0){
            if(a[i-1]>'0'&&a[i-1]<'9')ans=ans*m+a[i-1];
            if(a[i-1]>'a'&&a[i-1]<'z')ans=ans*m+(a[i-1]-'a'+10);
            if(a[i-1]>'A'&&a[i-1]<'Z')ans=ans*m+(a[i-1]-'A'+37);
            i--;
        }
        printf("case#%d:\n%d\n",j,ans);
        j++;
    }
    return 0;
}
