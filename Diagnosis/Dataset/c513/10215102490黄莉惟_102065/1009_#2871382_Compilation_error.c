#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    char s[1000];
    size_t len;
    scanf("%d",&n);
    int m=0;
    while(m<n){
        gets(s);
        len=str(s);
        printf("%d\n",len);
        m++;
    }
}