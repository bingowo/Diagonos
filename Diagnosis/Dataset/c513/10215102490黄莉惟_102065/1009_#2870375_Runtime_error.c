#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    i=0;
    char s[300];
    char c1;
    scanf("%d",&n);
    int m=0;
    while(m<n){
        num=0;
        i=0;
        while(scanf("%c",c1)!=EOF){
            s[i]=c1;
            i++;
        }
        printf("%d\n",strlen(s));
        m++;
    }
}