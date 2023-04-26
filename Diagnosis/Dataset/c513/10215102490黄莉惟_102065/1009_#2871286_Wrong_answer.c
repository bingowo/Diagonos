#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    i=0;
    char s[1000];
    scanf("%d",&n);
    int m=0;
    while(m<n){
        scanf("%s",s);
        printf("%d",len(s));
        m++;
    }
}
int len(char *s)
{  
    int n;
    char *p=s;
    while(*p) p++;
    return p;
}
