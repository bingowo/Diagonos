#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    int t;
    int i,n,j;
    char a[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for (j=0;j<n;j++) scanf("%s",a+j);
        printf("%s%c",a[j],j!=n-1?' ':'\n');
    }
}