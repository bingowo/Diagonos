#include <stdio.h>
#include<string.h>
int main(){
    int t;
    int n;
    char s[100];
    scanf("%d",&t);
    int m=0;
    while(m<t){
        scanf("%d",&n);
        itob(n,s);
        printf("%s",s);
        m++;
    }
    
}
int itob(int n,char *s){
    int r;
    int i;int j;
    char c1;
    i=0;
    while(n!=0){
        r=n%2;
        c1=r+48;
        s[i]=c1;
        n=n/2;
        i=i+1;
        } 
    s[i]='\0';
    char t[100];
    n=strlen(s);
    for(i=n-1,j=0;i>=0,j<n;i--,j++){
        t[j]=s[i];
    }
    for(i=0;i<n;i++){
        s[i]=t[i];
    }
    s[++i]='\0';
}