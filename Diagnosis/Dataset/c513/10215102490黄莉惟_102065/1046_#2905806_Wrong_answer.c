#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    int t;
    int i;
    char s[1000];
    scanf("%d",&t);
    char c = getchar();	
    for(i=0;i<t;i++){
        gets(s);
        printf("%s",s);
    }
}