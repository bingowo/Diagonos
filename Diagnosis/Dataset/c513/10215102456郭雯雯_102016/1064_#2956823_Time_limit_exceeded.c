#include<stdio.h>

int main(){
    char s[50];
    double num[100];
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char c=getchar();
        for(int i=0;i<49&&!isdigit(c);i++){
            if(c!=' ')s[i]=c;
            else {
                c=getchar();s[i]=c;
            }
        }
    }
}