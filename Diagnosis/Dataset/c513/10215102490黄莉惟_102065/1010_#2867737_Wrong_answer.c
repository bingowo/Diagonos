#include<stdio.h>
#include<string.h>
int main(){
    char s[500];
    int i,t,j,n;
    scanf("%s",s);
    printf("0001");
    int num=strlen(s);
    for(i=9;i>-1;i--) printf("%d",(unsigned)num<<(31-i)>>31);
    n=num/3;
    if(num%3==0);
    for(j=0;j<n/3;j+=3){
        t=(int)s[j]*100+(int)s[j+1]*10*+(int)s[j+2];
        for(i=9;i>-1;i--){ printf("%d",(unsigned)t<<(31-i)>>31);}
    }
}
