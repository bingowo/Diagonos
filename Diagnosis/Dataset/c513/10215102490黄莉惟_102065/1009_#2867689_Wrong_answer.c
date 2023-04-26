#include<stdio.h>
#include<string.h>
int main(){
    int n;
    char s[120];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        scanf("%s",s);
        printf("%d",s[0]<<31);
        m++;
    }
}