#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char* f(int n,int r){
    char s[20],a;
    int i=0,j=0;
    if(r<11){
        while(n!=0){
            s[i]=n%r+48;
            n=n/r;
            i++;
        }
    }
    else {
        while(n){
            if(n%r<10) s[i]=n%r+48;
            else s[i]=n%r+97-10;
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
    char* s;
    int a[t*2];
    while(i<t*2) {
        scanf("%d",&a[i]);
        i++;}
    for(i=0;i<t;i++){
        n=a[2*i];
        r=a[2*i+1];
        s=f(n,r);
        printf("%s",s);
        printf('\n');
    }
    return 0;
}
