#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num(char p[]){//字符串中不同字符的个数
    int len=strlen(p);
    for(int i=1;i<len;i++)
        for(int j=0;j<i;j++)
            if(p[i]==p[j]){
                for(int k=i;k<len;k++)
                    p[k]=p[k+1];
                len--;	//提高代码执行效率，降低时间复杂度
                i--;    //不加这一句的话，会跳着比较查找，漏掉一些字符
           }
           return len;
}
char* trans(char b[],char a[]){//变换字符串的排列
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
    return b;
}
int main(){
    int t,j=0,ans=0;
    char s[60],a[60];
    scanf("%d",&t);
    while(j<t){
        scanf("%s",s);
        int i=strlen(s);
        //for(;(c=getchar())!='\n';i++)s[i]=c;
        //s[i]='\0';
        trans(a,s);
        //num(s);
        int m=num(s);
        if(m==1)m=2;
        while(i>0){
            if(a[i-1]>='0'&&a[i-1]<='9')ans=ans*m+a[i-1];
            if(a[i-1]>='a'&&a[i-1]<='z')ans=ans*m+(a[i-1]-'a'+10);
            if(a[i-1]>='A'&&a[i-1]<='Z')ans=ans*m+(a[i-1]-'A'+37);
            i--;
        }
        printf("case#%d:\n%d\n",j,ans);
        j++;
    }
    return 0;
}
