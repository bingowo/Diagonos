#include <stdio.h>




int main(){
    int n,j=0;
    char a[10][120];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        gets(a[i]);
    }
    for(int i=0;i<n+1;i++){
        printf("%s\n",a[i]);
    }
    return 0;
}


