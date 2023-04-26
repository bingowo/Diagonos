#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t,i=0,k,j,n,r;
    scanf("%d",&t);
    char s[t][20],b;
    int a[t*2];
    while(i<t*2) {
        scanf("%d",&a[i]);
        i++;}
    for(i=0;i<t;i++){
        j=0,k=0;
        n=a[2*i];
        r=a[2*i+1];
        if (n<0){
            n=-n;
            s[i][j]='-';
            j++;
            k=1;
        }
        if(r<11){
            while(n!=0){
                s[i][j]=n%r+48;
                n=n/r;
                j++;
            }
        }
        else {
            while(n){
                if(n%r<10) s[i][j]=n%r+48;
                else s[i][j]=n%r+55;
                n=n/r;
                j++;
            }
        }
        j--;
        while(k<j-k) {
            b=s[i][k],s[i][k]=s[i][j-k],s[i][j-k]=b;
            k++;}
        s[i][++j]=0;
        printf("%s\n",s[i]);
    }
    return 0;
}