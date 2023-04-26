#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    size_t len;
    char s[1000];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        gets(s);
        len=str(s);
        printf("%d\n",len);
        m++;
    }
}