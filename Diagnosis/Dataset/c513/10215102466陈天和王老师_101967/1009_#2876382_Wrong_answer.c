#include <stdio.h>




int main(){
    int n;
    char a[10][120];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s\n",a[i]);
    }
    for(int i=0;i<n;i++){
        printf("%s\n",a[i]);
    }
    return 0;
}


