#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char* p=(char*)malloc(sizeof(char)*1000000);
    long int i=0;
    while(scanf("%c",p[i])!=EOF)i++;
    char mll[128];
    int len=1;
    int r=1,s=2;
    for(long int j=0;j<i;j++){
        long int k=j+1;
        for(long int m=j;m<k;m++){
            if(p[k]!=p[m])k=k+1;
            else {
                break;
            }
        }
        if((k-j)>len){
            r=k;
            s=j;
        }
    }
    for(;r<s;r++){
        printf("%c",p[r]);
    }
}