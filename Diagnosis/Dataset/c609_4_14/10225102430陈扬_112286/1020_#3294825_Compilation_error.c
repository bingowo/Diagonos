#include<stdio.h>
#include<string.h>
int main(){
    char* p[101],po;
    char c;
    int i=0;
    scanf("%c",&c);
    while(c!=EOF){
        p[++i]=&c;
    }
    for(int j=0;j<i;j++){
        po=p[j];
        while(po!=p[j]+strlen(*(p[j])))
    }
    return 0;
}