#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[110],num[15],fu[100];
        double n[100];
        gets(s);
        int l=strlen(s),i=0;
        for(int j=0;i<l;i++){//符号
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){fu[j]=s[i];j++;}
            if(isdigit(s[i]))break;
        }
        for(int j=0,k=0;i<l;i++){//数字
            if(s[i]!=' ')num[j++]=s[i];
            if(s[i]==' '){
                j=0;n[k]=atof(num);
                k++;
            }
        }
        a++;
    }
}