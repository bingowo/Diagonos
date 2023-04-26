#include<stdio.h>
#include<string.h>
#define L 500

void input(int *a){
    char s[L+1];
    scanf("%s",s);
    int l=strlen(s);
    for(int j=0;j<l;j++)a[j]=s[j]-'0';//转换成的数组没有小数点
}

int max(int *a,int *b){
    int i=0;
    while(i<L+1&&a[i]==b[i])i++;
    if(a[i]>b[i])return 1;
    else if(a[i]<b[i])return 0;
    
}

void minu(int a[],int b[]){   
    int i;
    for(i=L;i>0;i--){
        if(a[i]>=b[i])a[i]-= b[i];
        else{a[i]=a[i]+10-b[i];a[i-1]--;}
    }
}

void output(int a[])
{
    int i=0;
    while(i<L&& a[i]==0) i++;  //跳过前置0
    while(i<=L) printf("%d",a[i++]); //整数部分
    printf("\n");
}

int main(){
    int a[L+1]={0},b[L+1]={0},n;
    char s1[L+1],s2[L+1];
    while(scanf("%s %s",s1,s2)!=EOF){
        int l1=strlen(s1),l2=strlen(s2);
        for(int j=L;j>=0;j--)a[j]=s1[j]-'0';
        for(int j=L;j>=0;j--)b[j]=s2[j]-'0';
        scanf("%d",&n);
        if(max(a,b)){minu(a,b);output(a);}
        else {minu(b,a);printf("-");output(b);}
    }
    
}