#include <stdio.h>
#include <stdlib.h>
char* f(int n,int r){
    char* s,a;
    int i=0,j=0;
    if(n<11){
        while(n){
            s[i]=n%r+'0';
            n=n/r;
            i++;
        }
    }
    else {
        while(n){
            if(n%r<10) s[i]=n%r+'0';
            else s[i]=n%r+'A'-10;
            n=n/r;
            i++;
        }
    }
    s[i]=0;
    i--;
    while(j<i-j) {
        a=s[j],s[j]=s[i-j],s[i-j]=a;
        j++;}
    return s;
}
int main()
{
    int t,i=0,n,r;
    scanf("%d",&t);
    char* s[t];
    int a[t*2];
    while(i<t*2) {
        scanf("%d",&a[i]);
        i++;}
    for(i=0;i<t;i++){
        n=a[2*i];
        r=a[2*i+1];
        printf("%s",f(n,r));
        printf('\n');
    }
    return 0;
}
