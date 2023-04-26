#include<stdio.h>
#include<string.h>
#define L 500

int main(){
    char x1[L+1];
    int x[L+1],b[4*L+1];
    scanf("%s",x);
    int l=strlen(x);
    for(int i=2,j=0;i<l;i++,j++){
        if(x1[i]>='0'&&x1[i]<='9')x[j]=x1[i]-'0';
        else if(x1[i]>='A'&&x1[i]<='X')x[j]=x1[i]-'A'+10;
    }
    for(int i=0;i<l+2;i++)printf("%d ",x[i]);
}