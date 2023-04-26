#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int k=0;
int reverse(char *s){
    int a1,a2;
    char s1[21],*s2,*s3;
    s2=s+strlen(s)-1;
    s3=s1;
    while(s2>=s){
        *s3=*s2;
        s3++;
        s2--;
    }
    
    *s3=0;
    if(strcmp(s1,s)==0)return atoi(s);
    k++;
    a1=atoi(s);
    a2=atoi(s1);
    a1=a1+a2;
    char s4[21];
    sprintf(s4,"%d",a1);
    reverse(s4);
}
int main(){
    char s[20];
    scanf("%s",s);
    int n;
    n=reverse(s);
    printf("%d %d",k,n);
    return 0;
}