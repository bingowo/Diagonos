#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    char s[1000];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        gets(s);
        i=sizeof(s);
        printf("%d",i);
        m++;
    }
}