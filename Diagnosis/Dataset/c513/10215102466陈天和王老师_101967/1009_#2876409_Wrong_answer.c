#include <stdio.h>




int main(){
    int n,j=0;
    char a[10][120];
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        j=0;
        while((c=getchar())!=-1){a[i][j]=c;j++;}
    }
    for(int i=0;i<n;i++){
        printf("%s\n",a[i]);
    }
    return 0;
}


