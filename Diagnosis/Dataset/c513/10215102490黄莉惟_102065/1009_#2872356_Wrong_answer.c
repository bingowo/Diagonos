#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    i=0;
    char c = getchar();	
    char s[200];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        num=0;
        gets(s);
        i=len(s);
        printf("%d",i);
        m++;
        
    }
}
int len(char s[])
{  
    char *p=s;
    while(*p){
        p++;
    }
    return p;
}