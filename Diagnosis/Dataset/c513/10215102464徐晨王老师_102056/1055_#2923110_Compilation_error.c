#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char* p=(char*)malloc(sizeof(char)*1000000);
    long int i=0;
    while(scanf("%c",p[i])!=EOF)i++;
    char mll[128];
    for(long int j=0;j<i;j++){
        long int k=1;
        for(long int m=j;m<k;m++){
            if(p[k]!=p[m])continue;
            else {
                k=k+1;
                break;
            
        }
    }
}