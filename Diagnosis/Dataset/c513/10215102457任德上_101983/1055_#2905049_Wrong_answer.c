#include<stdio.h>
#include<string.h>
int main(){
    char s[1000001],c,*m1,*m2,k[1000001]={'\0'};
    scanf("%s",s);
    k[0]=*s;
    m1=s;
    m1++;
    m2=k;
    while(*m1!=*m2){
        m2++;
        *m2=*m1;
        m1++;
    }
    printf("%s",k);
    return 0;
}