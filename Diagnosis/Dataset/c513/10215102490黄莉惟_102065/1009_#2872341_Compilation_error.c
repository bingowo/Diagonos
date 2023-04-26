#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    i=0;
    char c = getchar();	
    scanf("%d",&n);
    int m=0;
    while(m<n){
        num=0;
        gets(s);
        printf("%d\n",len(s));
        m++;
        
    }
}
int len(char s[])
{  
    char *p=s;
    while(*p){
        p++;
    }
    return p-s;
}