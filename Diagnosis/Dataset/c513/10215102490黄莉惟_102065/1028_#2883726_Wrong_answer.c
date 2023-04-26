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
    int num=i;
    for(i=0;i<num;i++){
        printf("%d",a[i]);
    }
}