#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    char c1;
    int a[100];
    scanf("%c",&c1);
    int m;
    int i=0;
    while(scanf("%d",&m)!=EOF){
        a[i]=m;
        i++;
    }
    a[i]='\0';
    printf("%d",strlen(a));
}